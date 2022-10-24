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

%token <stringValue> ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE 
%token <stringValue> STRLIT INTLIT RESERVED BOOLLIT ID REALLIT
%type <node> Program DeclMult MethodDecl FieldDecl COMID Type MethodHeader FormalParams COMTYPID MethodBody BODY VarDecl Statement MethodInvocation COMMAExpr Assignment ParseArgs Expr

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

Program: CLASS ID LBRACE DeclMult RBRACE          {;}   
;

DeclMult:  DeclMult MethodDecl                    {;}
        |  DeclMult FieldDecl                     {;}
        |  DeclMult SEMICOLON                     {;} 
        |                                         {;}
        ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {;}
;

FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {;}
         | error SEMICOLON                        {;}
;

COMID: COMID COMMA ID                             {;}
    |                                             {;}
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

FormalParams: Type ID COMTYPID                    {;}
            | STRING LSQ RSQ ID                   {;}
;

COMTYPID: COMTYPID COMMA Type ID                  {;}
|                                                 {;}
;

MethodBody: LBRACE BODY RBRACE                    {;}
        |   LBRACE RBRACE                         {;}
;

BODY: Statement                                   {;}
    | VarDecl                                     {;}
;

VarDecl:Type ID COMID SEMICOLON                   {;}
;

Statement: LBRACE Statement RBRACE                {;}
    | LBRACE RBRACE                               {;}
    | IF LPAR Expr RPAR Statement                 {;}
    | IF LPAR Expr RPAR Statement ELSE Statement  {;}
    | WHILE LPAR Expr RPAR Statement              {;}
    | RETURN SEMICOLON                            {;}
    | RETURN Expr SEMICOLON                       {;}
    | MethodInvocation SEMICOLON                  {;}
    | Assignment SEMICOLON                        {;}
    | ParseArgs SEMICOLON                         {;}
    | SEMICOLON                                   {;}
    | PRINT LPAR Expr RPAR SEMICOLON              {;}
    | PRINT LPAR STRLIT RPAR SEMICOLON            {;}
    | error SEMICOLON                             {;}
    ;

MethodInvocation: ID LPAR RPAR                    {;}
    | ID LPAR Expr COMMAExpr RPAR                 {;}
    | ID LPAR error RPAR                          {;}
    ;

COMMAExpr: COMMAExpr COMMA Expr                   {;}
|                                                 {;}
;

Assignment: ID ASSIGN Expr                        {;}
;

ParseArgs:
    PARSEINT LPAR ID LSQ Expr RSQ RPAR            {;}
    |PARSEINT LPAR error RPAR                     {;}
    ;

Expr:
    Expr OR Expr                                  {;}
    |Expr XOR Expr                                {;}
    |Expr LSHIFT Expr                             {;}
    |Expr RSHIFT Expr                             {;}
    |Expr AND Expr                                {;} 
    |Expr LT Expr                                 {;}
    |Expr GT Expr                                 {;}
    |Expr EQ Expr                                 {;}
    |Expr NE Expr                                 {;}
    |Expr LE Expr                                 {;}
    |Expr GE Expr                                 {;}
    |Expr PLUS Expr                               {;}
    |Expr MINUS Expr                              {;}
    |Expr STAR Expr                               {;}
    |Expr DIV Expr                                {;}
    |Expr MOD Expr                                {;}
    |NOT Expr        %prec UNARY                  {;}
    |MINUS Expr      %prec UNARY                  {;}
    |PLUS Expr       %prec UNARY                  {;}
    |INTLIT                                       {;}
    |REALLIT                                      {;}
    |ID                                           {;}
    |ID DOTLENGTH                                 {;}
    |BOOLLIT                                      {;}
    |LPAR Expr RPAR                               {;}
    |LPAR error RPAR                              {;}
    |MethodInvocation                             {;}
    |Assignment                                   {;}
    |ParseArgs                                    {;}

;

%%