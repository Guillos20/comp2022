%{
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>

    int yylex(void);
    void yyerror (const char *s);
    
%}

%union{
    char *stringValue;
    char* value;
    struct node *node;
}

%token ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE 
%token <stringValue> STRLIT INTLIT RESERVED BOOLLIT ID REALLIT
%type <node> Program DeclMult MethodDecl FieldDecl COMID Type MethodHeader FormalParams COMTYPID MethodBody BODY VarDecl Statement ParseArgs Expr
%%

Program: CLASS ID LBRACE DeclMult RBRACE          {;}
       | CLASS ID LBRACE RBRACE                   {;} 
;
DeclMult: MethodDecl                              {;}
        | FieldDecl                               {;}
        | SEMICOLON                               {;} 
;
MethodDecl: PUBLIC STATIC MethodHeader MethodBody {;}
;
FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {;}
         | PUBLIC STATIC Type ID SEMICOLON        {;} 
;
COMID: COMID COMMA ID

    |                                           {;}
;
Type: BOOL                                        {;}
    | INT                                         {;}
    | DOUBLE                                      {;}
;
MethodHeader: Type ID LPAR FormalParams RPAR      {;}
            | Type ID LPAR RPAR                   {;}
            | VOID ID LPAR FormalParams RPAR      {;}
            | VOID ID LPAR RPAR                   {;}
;
FormalParams: Type ID                             {;}
            | Type ID COMTYPID                    {;}
            | STRING LSQ RSQ ID                   {;}
;
COMTYPID: COMMA Type ID                           {;}
;
MethodBody: LBRACE BODY RBRACE                    {;}
        |   LBRACE RBRACE                         {;}
;
BODY: Statement                                   {;}
    | VarDecl                                     {;}
;
VarDecl:Type ID COMID SEMICOLON                {;}
    | Type SEMICOLON
;
Statement: LBRACE Statement RBRACE                {;}
    | LBRACE RBRACE                               {;}
    ;
ParseArgs:
    PARSEINT LPAR ID LSQ Expr RSQ RPAR {;}
    ;
Expr:
    Expr OR Expr                             {;}
    |Expr XOR Expr                             {;}
    |Expr LSHIFT Expr                             {;}
    |Expr RSHIFT Expr                             {;}
    |Expr AND Expr                           {;} 
    |Expr LT Expr                            {;}
    |Expr GT Expr                            {;}
    |Expr EQ Expr                            {;}
    |Expr NE Expr                            {;}
    |Expr LE Expr                            {;}
    |Expr GE Expr                            {;}
    |Expr PLUS Expr                          {;}
    |Expr MINUS Expr                          {;}
    |Expr STAR Expr                          {;}
    |Expr DIV Expr                          {;}
    |Expr MOD Expr                          {;}
    |NOT Expr                          {;}
    |MINUS Expr                          {;}
    |PLUS Expr                          {;}
    |INTLIT                          {;}
    |REALLIT                          {;}
    |ID DOTLENGTH                  {;}
    |BOOLLIT                       {;}
    |LPAR Expr RPAR                {;}
    |LPAR error RPAR                          {;}
;
%%