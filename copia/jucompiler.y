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
%} 
 
%union{ 
    char *stringValue; 
    char *value; 
    struct Node *node; 
} 
 
%token ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE  
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
 
Program: CLASS ID LBRACE DeclMult RBRACE          {}    
; 
 
DeclMult:  MethodDecl DeclMult                    {} 
        |  FieldDecl  DeclMult                    {} 
        |  SEMICOLON  DeclMult                    {}  
        |                                         {} 
        ; 
 
MethodDecl: PUBLIC STATIC MethodHeader MethodBody {} 
; 
 
FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {}
         | error SEMICOLON                        {} 
; 
 
COMID: COMMA ID COMID                             {} 
    |                                             {} 
; 
 
Type: BOOL                                        {} 
    | INT                                         {} 
    | DOUBLE                                      {} 
; 
 
MethodHeader: Type ID LPAR FormalParams RPAR      {} //fix type issue 
            | Type ID LPAR RPAR                   {} 
            | VOID ID LPAR FormalParams RPAR      {} 
            | VOID ID LPAR RPAR                   {} 
; 
 
FormalParams: Type ID COMTYPID                    {} 
            | STRING LSQ RSQ ID                   {} 
             
; 
 
COMTYPID:  COMMA Type ID COMTYPID                 {} 
|                                                 {} 
; 
 
MethodBody: LBRACE BODY RBRACE                    {} 
; 
 
BODY:Statement BODY                               {}   //body is no bueno aswell 
    | VarDecl BODY                                {} 
    |                                             { } 
; 
 
VarDecl:Type ID COMIDVAR SEMICOLON                {}//ver como por vardecl sempre, o comid esta com fielddecl e temos de mandar o type para o irmao tambem  
; 
COMIDVAR:COMMA ID COMIDVAR                        {}  
    |                                             {} 
 
; 
 
Statement: LBRACE StatementHelper RBRACE          {}//if($2 != NULL){Node * block  = createNode("Block", NULL,$2,NULL);$$ = block;} statement is no bueno else{} 
    | IF LPAR ExprHelper RPAR Statement                 {}// Node *block=createNode("Block",NULL,$5, NULL); perguntar ao stor sobre os blocks  
    | IF LPAR ExprHelper RPAR Statement ELSE Statement  {} //Node *ifblock=createNode("Block",NULL,$5, NULL); $3->sibling = ifblock;Node *elseblock=createNode("Block",NULL,$5, NULL); ifblock->sibling = elseblock; 
    | WHILE LPAR ExprHelper RPAR Statement              {}
    | RETURN SEMICOLON                            {} 
    | RETURN ExprHelper SEMICOLON                       {} 
    | MethodInvocation SEMICOLON                  {} 
    | Assignment SEMICOLON                        {} 
    | ParseArgs SEMICOLON                         {} 
    | SEMICOLON                                   { }   //criar estado auxiliar maybe i wanna kommit die 
    | PRINT LPAR ExprHelper RPAR SEMICOLON              {} 
    | PRINT LPAR STRLIT RPAR SEMICOLON            {} 
    | error SEMICOLON                             {} 
    ; 
StatementHelper:StatementHelper Statement         {} 
|                                                 {} 
; 
MethodInvocation: ID LPAR RPAR                    {} 
    | ID LPAR ExprHelper COMMAExpr RPAR                 {} //this still needs work cuz is not calling the calls 
    | ID LPAR error RPAR                          {} 
    ; 
 
COMMAExpr: COMMA ExprHelper COMMAExpr                   {}//podera ter que se trocar os $ 
|                                                 {} 
; 
 
Assignment: ID ASSIGN ExprHelper                        {} 
; 
 
ParseArgs:PARSEINT LPAR ID LSQ ExprHelper RSQ RPAR      {} 
    |PARSEINT LPAR error RPAR                     {} 
    ; 
 
Expr:Expr OR Expr                                 {}
    |Expr XOR Expr                                {} 
    |Expr LSHIFT Expr                             {} 
    |Expr RSHIFT Expr                             {} 
    |Expr AND Expr                                {}  
    |Expr LT Expr                                 {} 
    |Expr GT Expr                                 {} 
    |Expr EQ Expr                                 {} 
    |Expr NE Expr                                 {} 
    |Expr LE Expr                                 {} 
    |Expr GE Expr                                 {} 
    |Expr PLUS Expr                               {} 
    |Expr MINUS Expr                              {} 
    |Expr STAR Expr                               {} 
    |Expr DIV Expr                                {} 
    |Expr MOD Expr                                {} 
    |NOT Expr                                     {} 
    |MINUS Expr                                   {} 
    |PLUS Expr                                    {} 
    |INTLIT                                       {} 
    |REALLIT                                      {} 
    |ID                                           {} 
    |ID DOTLENGTH                                 {} 
    |BOOLLIT                                      {} 
    |LPAR ExprHelper RPAR                         {} 
    |MethodInvocation                             {} 
    |ParseArgs                                    {} 
    |LPAR error RPAR                              {} 
 
; 
ExprHelper:  
    Assignment                                   {}     
    |Expr                                        {} 
; 
 
%% 