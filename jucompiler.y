%{
    //./jucompiler $flag < $path/$2.java $sort | diff $path/$2.out - -y
    //./yeet -t para verificares todos os testescasos da pasta
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "struct.h"
    #include "y.tab.h"

    int yylex(void);
    extern void yyerror(char *s);
    int blockCount = 0;
%}

%union{
    char *stringValue;
    char *value;
    struct Node *node;
}

%token ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE 
%token <stringValue> STRLIT INTLIT RESERVED BOOLLIT ID REALLIT
%type <node> Program DeclMult MethodDecl FieldDecl COMID Type MethodHeader FormalParams COMTYPID MethodBody BODY VarDecl COMIDVAR Statement StatementHelper SemicolonHelper MethodInvocation COMMAExpr Assignment ParseArgs Expr ExprHelper

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

DeclMult:  MethodDecl DeclMult                    {if($1 != NULL){$$ = $1; if($2 != NULL){$1->sibling = $2;};}else{$$=NULL;};} //not sur
        |  FieldDecl  DeclMult                    {if($1 != NULL){$$ = $1; if($2 != NULL){add_sibling($1, $2);};}else{$$=NULL;};}
        |  SEMICOLON  DeclMult                    {if($2 != NULL){$$ = $2;}else{$$=NULL;};} 
        |                                         {$$ = NULL;}
        ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {$$ = createNode("MethodDecl",NULL,createNode("MethodHeader",NULL,$3,createNode("MethodBody",NULL,$4,NULL)),NULL);}
;

FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {Node *Fd = createNode("FieldDecl",NULL,$3,NULL); Node *id = createNode("Id",$4, NULL, NULL);$3->sibling=id;$$=Fd;add_sibling(Fd, $5); save_type(Fd, $3);}
         | error SEMICOLON                        {$$ = NULL;}
;

COMID: COMMA ID COMID                             {$$ = createNode("FieldDecl",NULL,createNode("Id", $2, NULL, NULL),NULL);add_sibling($$, $3);}
    |                                             {$$ = NULL;}
;

Type: BOOL                                        {$$ = createNode("Bool",NULL,NULL,NULL);}
    | INT                                         {$$ = createNode("Int",NULL,NULL,NULL);}
    | DOUBLE                                      {$$ = createNode("Double",NULL,NULL,NULL);}
;

MethodHeader: Type ID LPAR FormalParams RPAR      {$$ = $1;$1->sibling = createNode("Id",$2,NULL,createNode("MethodParams",NULL,$4,NULL));} //fix type issue
            | Type ID LPAR RPAR                   {$$ = $1;$1->sibling = createNode("Id",$2,NULL,createNode("MethodParams",NULL,NULL,NULL));}
            | VOID ID LPAR FormalParams RPAR      {$$ = createNode("Void",NULL,NULL,createNode("Id",$2,NULL,createNode("MethodParams",NULL,$4,NULL)));}
            | VOID ID LPAR RPAR                   {$$ = createNode("Void",NULL,NULL,createNode("Id",$2,NULL,createNode("MethodParams",NULL,NULL,NULL)));}
;

FormalParams: Type ID COMTYPID                    {$$ = createNode("ParamDecl",NULL,$1,$3);Node *id =createNode("Id",$2,NULL,NULL); $1->sibling=id;}
            | STRING LSQ RSQ ID                   {Node *id = createNode("Id", $4, NULL,NULL); $$ = createNode("ParamDecl",NULL,createNode("StringArray",NULL,NULL,id),NULL);}
            
;

COMTYPID:  COMMA Type ID COMTYPID                 {$$ = createNode("ParamDecl",NULL,$2,$4);Node *id =createNode("Id",$3,NULL,NULL); $2->sibling=id;}
|                                                 {$$ = NULL;}
;

MethodBody: LBRACE BODY RBRACE                    {$$ = $2;}
;

BODY:Statement BODY                               {if($1 != NULL){ $$ = $1;if($2 != NULL){add_sibling($1,$2);}}else{$$ = NULL;};}   //body is no bueno aswell
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
                                                        if(blockCount !=1){
                                                            $$ = createNode("Block", NULL, $2, NULL);
                                                        }else{
                                                        $$ = $2;
                                                        }
                                                        }
    | IF LPAR ExprHelper RPAR Statement                 {$$ = createNode("If",NULL, $3, NULL);
                                                        if(blockCount<1){ 
                                                            Node *block=createNode("Block",NULL,NULL, $5);
                                                            add_sibling($3, block);
                                                        }else{
                                                            add_son($$, $5);
                                                            add_son($$, createNode("Block", NULL,NULL,NULL));}
                                                        }
    | IF LPAR ExprHelper RPAR Statement ELSE Statement  {$$ = createNode("If",NULL, $3, NULL); 
                                                            if(blockCount<1){
                                                                Node *ifblock=createNode("Block",NULL, NULL,$5); 
                                                                add_sibling($3, ifblock);
                                                                add_sibling(ifblock, $7);
                                                                }else{
                                                                    add_son($$, $5);
                                                                    add_son($$, $7);

                                                                }
                                                        
                                                         
                                                        
                                                        }
    | WHILE LPAR ExprHelper RPAR Statement              {$$ = createNode("While",NULL, $3, NULL) ;if($5 != NULL){$3->sibling = $5;}}
    | RETURN SEMICOLON                                  {$$ = createNode("Return",NULL,NULL,NULL);}
    | RETURN ExprHelper SEMICOLON                       {$$ = createNode("Return",NULL,$2,NULL);}
    | MethodInvocation SEMICOLON                        {$$ = $1;}
    | Assignment SEMICOLON                              {$$ = $1;}
    | ParseArgs SEMICOLON                               {$$ = $1;}
    | SemicolonHelper                                   {$$ = $1;}
    | PRINT LPAR ExprHelper RPAR SEMICOLON              {$$ = createNode("Print",NULL,$3,NULL);}
    | PRINT LPAR STRLIT RPAR SEMICOLON                  {$$ = createNode("Print",NULL,createNode("StrLit",$3,NULL,NULL),NULL);}
    | error SEMICOLON                                   {$$ = NULL;}
    ;
StatementHelper:Statement StatementHelper               {if($1 == NULL){$$ = $2;}
                                                        else if($2 == NULL){$$ = $1;}
                                                        else{$$ = $1;
                                                        add_sibling($1, $2);}
                                                        }
    |                                                   {$$ = NULL;}
;
SemicolonHelper:SEMICOLON                               {if(blockCount!=1){$$ = createNode("Block", NULL, NULL, NULL);} $$ = NULL;}    
;
MethodInvocation: ID LPAR RPAR                          {Node *id = createNode("Id",$1,NULL,NULL); $$ = createNode("Call",NULL,id, NULL); }
    | ID LPAR ExprHelper COMMAExpr RPAR                 {Node *id = createNode("Id",$1,NULL,$3);$3->sibling = $4;$$ = createNode("Call",NULL,id, NULL);} //this still needs work cuz is not calling the calls
    | ID LPAR error RPAR                                {$$ = NULL;}
    ;

COMMAExpr: COMMA ExprHelper COMMAExpr                   {$$ = $2; $2->sibling = $3;}//podera ter que se trocar os $
|                                                       {$$ = NULL;}
;

Assignment: ID ASSIGN ExprHelper                        {$$ = createNode("Assign",NULL,createNode("Id",$1,NULL,$3),NULL);}
;

ParseArgs:PARSEINT LPAR ID LSQ ExprHelper RSQ RPAR      {$$ = createNode("ParseArgs",NULL,createNode("Id",$3,NULL,$5),NULL);}
    |PARSEINT LPAR error RPAR                           {$$ = NULL;}
    ;

Expr:Expr OR Expr                                       {$$ = createNode("Or",NULL,$1,NULL);$1->sibling = $3;}
    |Expr XOR Expr                                      {$$ = createNode("Xor",NULL,$1,NULL);$1->sibling = $3;}
    |Expr LSHIFT Expr                             {$$ = createNode("Lshift",NULL,$1,NULL);$1->sibling = $3;}
    |Expr RSHIFT Expr                             {$$ = createNode("Rshift",NULL,$1,NULL);$1->sibling = $3;}
    |Expr AND Expr                                {$$ = createNode("And",NULL,$1,NULL);$1->sibling = $3;} 
    |Expr LT Expr                                 {$$ = createNode("Lt",NULL,$1,NULL);$1->sibling = $3;}
    |Expr GT Expr                                 {$$ = createNode("Gt",NULL,$1,NULL);$1->sibling = $3;}
    |Expr EQ Expr                                 {$$ = createNode("Eq",NULL,$1,NULL);$1->sibling = $3;}
    |Expr NE Expr                                 {$$ = createNode("Ne",NULL,$1,NULL);$1->sibling = $3;}
    |Expr LE Expr                                 {$$ = createNode("Le",NULL,$1,NULL);$1->sibling = $3;}
    |Expr GE Expr                                 {$$ = createNode("Ge",NULL,$1,NULL);$1->sibling = $3;}
    |Expr PLUS Expr                               {$$ = createNode("Add",NULL,$1,NULL);$1->sibling = $3;}
    |Expr MINUS Expr                              {$$ = createNode("Sub",NULL,$1,NULL);$1->sibling = $3;}
    |Expr STAR Expr                               {$$ = createNode("Mul",NULL,$1,NULL);$1->sibling = $3;}
    |Expr DIV Expr                                {$$ = createNode("Div",NULL,$1,NULL);$1->sibling = $3;}
    |Expr MOD Expr                                {$$ = createNode("Mod",NULL,$1,NULL);$1->sibling = $3;}
    |NOT Expr              %prec UNARY            {$$ = createNode("Not",NULL,$2,NULL);}
    |MINUS Expr            %prec UNARY            {$$ = createNode("Minus",NULL,$2,NULL);}
    |PLUS Expr             %prec UNARY            {$$ = createNode("Plus",NULL,$2,NULL);}
    |INTLIT                                       {$$ = createNode("DecLit",$1,NULL,NULL);}
    |REALLIT                                      {$$ = createNode("RealLit",$1,NULL,NULL);}
    |ID                                           {$$ = createNode("Id",$1, NULL,NULL);}
    |ID DOTLENGTH                                 {$$ = createNode("Length",NULL,createNode("Id",$1,NULL,NULL),NULL);}
    |BOOLLIT                                      {$$ = createNode("BoolLit",$1,NULL,NULL);}
    |LPAR ExprHelper RPAR                         {$$ = $2;}
    |MethodInvocation                             {$$ = $1;}
    |ParseArgs                                    {$$ = $1;}
    |LPAR error RPAR                              {$$ = NULL;}

;
ExprHelper: 
    Assignment                                   {$$ = $1;}    
    |Expr                                        {$$ = $1;}
;

%%