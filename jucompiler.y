%{
    //./jucompiler $flag < $path/$2.java $sort | diff $path/$2.out - -y
    //./yeet -t para verificares todos os testescasos da pasta
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "struct.h"
    #include "y.tab.h"
    #include "symtab.h"

    int yylex(void);
    extern void yyerror(char *s);
    int blockCount;
    extern int linha;
    
%}

%union{
    char *stringValue;
    char *value;
    int col_yacc;
    struct Node *node;
}

%token <col_yacc> ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE 
%token <stringValue> STRLIT INTLIT RESERVED BOOLLIT ID REALLIT
%type <node> Program DeclMult MethodDecl FieldDecl COMID Type MethodHeader FormalParams COMTYPID MethodBody BODY VarDecl COMIDVAR Statement StatementHelper MethodInvocation COMMAExpr Assignment ParseArgs Expr ExprHelper

%left ARROW
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left NE EQ
%left GE LE LT GT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT UNARY
%left RSQ LSQ RPAR LPAR

%nonassoc IF
%nonassoc ELSE

%%

Program: CLASS ID LBRACE DeclMult RBRACE          {$$ = root = createNode("Program",NULL,createNode("Id",$2,NULL,$4),NULL);}   
;

DeclMult:  MethodDecl DeclMult                    {if($1 != NULL){$$ = $1; if($2 != NULL){add_sibling($1, $2);};}else{$$=NULL;};} 
        |  FieldDecl  DeclMult                    {if($1 != NULL){$$ = $1; if($2 != NULL){add_sibling($1, $2);};}else{$$=NULL;};}
        |  SEMICOLON  DeclMult                    {if($2 != NULL){$$ = $2;}else{$$=NULL;};} 
        |                                         {$$ = NULL;}
        ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$ = createNode("MethodDecl",NULL,createNode("MethodHeader",NULL,$3,createNode("MethodBody",NULL,$4,NULL)),NULL);}
;

FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {Node *Fd = createNode("FieldDecl",NULL,$3,NULL); Node *id = createNode("Id",$4, NULL, NULL);add_sibling($3, id);$$=Fd;add_sibling(Fd, $5); save_type(Fd, $3);}
         | error SEMICOLON                        {$$ = NULL;}
;

COMID: COMMA ID COMID                             {$$ = createNode("FieldDecl",NULL,createNode("Id", $2, NULL, NULL),NULL);add_sibling($$, $3);}
    |                                             {$$ = NULL;}
;

Type: BOOL                                        {$$ = createNode("Bool",NULL,NULL,NULL);}
    | INT                                         {$$ = createNode("Int",NULL,NULL,NULL);}
    | DOUBLE                                      {$$ = createNode("Double",NULL,NULL,NULL);}
;

MethodHeader: Type ID LPAR FormalParams RPAR      {$$ = $1;$1->sibling = createNode("Id",$2,NULL,createNode("MethodParams",NULL,$4,NULL));} 
            | Type ID LPAR RPAR                   {$$ = $1;$1->sibling = createNode("Id",$2,NULL,createNode("MethodParams",NULL,NULL,NULL));}
            | VOID ID LPAR FormalParams RPAR      {$$ = createNode("Void",NULL,NULL,createNode("Id",$2,NULL,createNode("MethodParams",NULL,$4,NULL)));}
            | VOID ID LPAR RPAR                   {$$ = createNode("Void",NULL,NULL,createNode("Id",$2,NULL,createNode("MethodParams",NULL,NULL,NULL)));}
;

FormalParams: Type ID COMTYPID                    {$$ = createNode("ParamDecl",NULL,$1,$3);Node *id =createNode("Id",$2,NULL,NULL); add_sibling($1,id);}
            | STRING LSQ RSQ ID                   {Node *id = createNode("Id", $4, NULL,NULL); $$ = createNode("ParamDecl",NULL,createNode("StringArray",NULL,NULL,id),NULL);}
            
;

COMTYPID:  COMMA Type ID COMTYPID                 {$$ = createNode("ParamDecl",NULL,$2,$4);Node *id =createNode("Id",$3,NULL,NULL); add_sibling($2, id);}
|                                                 {$$ = NULL;}
;

MethodBody: LBRACE BODY RBRACE                    {$$ = $2;}
;

BODY:Statement BODY                               {if($1 != NULL){ $$ = $1;if($2 != NULL){add_sibling($1,$2);}}else if($1==NULL){$$=$2;}else{$$ = NULL;};}   
    | VarDecl BODY                                {if($1 != NULL){ $$ = $1;if($2 != NULL){add_sibling($1,$2);}}else if($1==NULL){$$=$2;}else{$$ = NULL;};}
    |                                             {$$ = NULL;}
;

VarDecl:Type ID COMIDVAR SEMICOLON                {$$ = createNode("VarDecl",NULL,NULL,$3);
                                                   add_son($$, $1);
                                                   Node *id = createNode("Id",$2,NULL,NULL); 
                                                   add_sibling($1, id);
                                                   save_type($$, $1);
                                                   
                                                }
;
COMIDVAR:COMMA ID COMIDVAR                          {$$ = createNode("VarDecl",NULL,NULL,$3); 
                                                    
                                                    Node *id = createNode("Id",$2,NULL,NULL);
                                                    add_son($$, id); 
                                                    } 
    |                                               {$$ = NULL;}

;

Statement: LBRACE StatementHelper RBRACE                {Node * node = $2;blockCount = 0; 
                                                        while(node){
                                                            blockCount++;
                                                            node = node->sibling;
                                                            
                                                        }
                                                        //printf("%d\n", blockCount);
                                                        if(blockCount >1){
                                                            $$ = createNode("Block", NULL, $2, NULL);
                                                        }else{
                                                        $$ = $2;
                                                        }
                                                        }
    | IF LPAR ExprHelper RPAR Statement                 {$$ = createNode("If",NULL, $3, NULL);
                                                            Node *block=createNode("Block",NULL,NULL, NULL);
                                                            Node *block2=createNode("Block",NULL,NULL, NULL);
                                                        if($5!=NULL){
                                                            add_son($$, $5);
                                                            add_son($$, block);
                                                        }else{
                                                            add_son($$, $5);
                                                            add_son($$, block);
                                                            add_son($$, block2);

                                                        }}
    | IF LPAR ExprHelper RPAR Statement ELSE Statement  {$$ = createNode("If",NULL, $3, NULL);
                                                            Node *ifblock=createNode("Block",NULL, NULL,NULL);  
                                                            Node *ifblock2=createNode("Block",NULL, NULL,NULL);  
                                                            if($5 !=NULL&& $7!=NULL){
                                                                add_sibling($3, $5);
                                                                add_sibling($5, $7);
                                                                }else if($5==NULL && $7!=NULL){
                                                                    add_son($$, ifblock);
                                                                    add_son($$, $7);
                                                                }else if($5!=NULL && $7==NULL){
                                                                    add_son($$, $5);
                                                                    add_son($$, ifblock);
                                                                }else{
                                                                   add_son($$, ifblock);
                                                                   add_son($$, ifblock2);
                                                                }
                                                        }
    | WHILE LPAR ExprHelper RPAR Statement              {$$ = createNode2("While",NULL, $3, NULL,$2);
                                                            Node *whileblock=createNode("Block",NULL, NULL,NULL); 
                                                            if($5!=NULL){
                                                                add_sibling($3,$5);
                                                            }else{
                                                                add_sibling($3,$5);
                                                                add_son($$, whileblock);
                                                            }
                                                        }
    | RETURN SEMICOLON                                  {$$ = createNode("Return",NULL,NULL,NULL);}
    | RETURN ExprHelper SEMICOLON                       {$$ = createNode("Return",NULL,$2,NULL);}
    | MethodInvocation SEMICOLON                        {$$ = $1;}
    | Assignment SEMICOLON                              {$$ = $1;}
    | ParseArgs SEMICOLON                               {$$ = $1;}
    | SEMICOLON                                   {$$ = NULL;}
    | PRINT LPAR ExprHelper RPAR SEMICOLON              {$$ = createNode2("Print",NULL,$3,NULL,$2);}
    | PRINT LPAR STRLIT RPAR SEMICOLON                  {$$ = createNode2("Print",NULL,createNode("StrLit",$3,NULL,NULL),NULL,$2);}
    | error SEMICOLON                                   {$$ = NULL;}
    ;
StatementHelper:Statement StatementHelper               {if($1 == NULL){$$ = $2;}
                                                        else if($2 == NULL){$$ = $1;}
                                                        else{$$ = $1;
                                                        add_sibling($1, $2);}
                                                        }
    |                                                   {$$ = NULL;}
;

MethodInvocation: ID LPAR RPAR                          {Node *id = createNode("Id",$1,NULL,NULL); $$ = createNode("Call",NULL,id, NULL); }
    | ID LPAR ExprHelper COMMAExpr RPAR                 {Node *id = createNode("Id",$1,NULL,$3);add_sibling($3,$4);$$ = createNode("Call",NULL,id, NULL);}
    | ID LPAR error RPAR                                {$$ = NULL;}
    ;

COMMAExpr: COMMA ExprHelper COMMAExpr                   {$$ = $2; add_sibling($2,$3);}
|                                                       {$$ = NULL;}
;

Assignment: ID ASSIGN ExprHelper                        {$$ = createNode2("Assign",NULL,createNode("Id",$1,NULL,$3),NULL,$2);}
;

ParseArgs:PARSEINT LPAR ID LSQ ExprHelper RSQ RPAR      {$$ = createNode2("ParseArgs",NULL,createNode("Id",$3,NULL,$5),NULL,$1);}
    |PARSEINT LPAR error RPAR                           {$$ = NULL;}
    ;

Expr:Expr OR Expr                                 {$$ = createNode2("Or",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr XOR Expr                                {$$ = createNode2("Xor",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr LSHIFT Expr                             {$$ = createNode2("Lshift",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr RSHIFT Expr                             {$$ = createNode2("Rshift",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr AND Expr                                {$$ = createNode2("And",NULL,$1,NULL,$2);add_sibling($1,$3);} 
    |Expr LT Expr                                 {$$ = createNode2("Lt",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr GT Expr                                 {$$ = createNode2("Gt",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr EQ Expr                                 {$$ = createNode2("Eq",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr NE Expr                                 {$$ = createNode2("Ne",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr LE Expr                                 {$$ = createNode2("Le",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr GE Expr                                 {$$ = createNode2("Ge",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr PLUS Expr                               {$$ = createNode2("Add",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr MINUS Expr                              {$$ = createNode2("Sub",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr STAR Expr                               {$$ = createNode2("Mul",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr DIV Expr                                {$$ = createNode2("Div",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |Expr MOD Expr                                {$$ = createNode2("Mod",NULL,$1,NULL,$2);add_sibling($1,$3);}
    |NOT Expr              %prec UNARY            {$$ = createNode2("Not",NULL,$2,NULL, $1);}
    |MINUS Expr            %prec UNARY            {$$ = createNode2("Minus",NULL,$2,NULL,$1);}
    |PLUS Expr             %prec UNARY            {$$ = createNode2("Plus",NULL,$2,NULL,$1);}
    |INTLIT                                       {$$ = createNode("DecLit",$1,NULL,NULL);}
    |REALLIT                                      {$$ = createNode("RealLit",$1,NULL,NULL);}
    |ID                                           {$$ = createNode("Id",$1, NULL,NULL);}
    |ID DOTLENGTH                                 {$$ = createNode2("Length",NULL,createNode("Id",$1,NULL,NULL),NULL,$2);}
    |BOOLLIT                                      {$$ = createNode("BoolLit",$1,NULL,NULL);}
    |LPAR ExprHelper RPAR                         {$$ = $2;}
    |MethodInvocation                             {$$ = $1;}
    |ParseArgs                                    {$$ = $1;}
    |LPAR error RPAR                              {$$ = NULL;}

;
ExprHelper: 
    Assignment                                    {$$ = $1;}    
    |Expr                                         {$$ = $1;}
;

%%