%{
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "arvore.h" 

    int yylex(void);
    void yyerror (const char *s);
    
%}

%union{
    char *stringValue;
    //struct node *node;
}

%token ELSE DOTLENGTH DOUBLE AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR BOOL CLASS IF INT  PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE 
%token <stringValue> STRLIT INTLIT RESERVED BOOLLIT ID REALLIT

%%

Program: CLASS ID LBRACE DeclMult RBRACE          {;}
       | CLASS ID LBRACE RBRACE                   {;} 

DeclMult: DeclMult                                {;}
        | MethodDecl                              {;}
        | FieldDecl                               {;}
        | SEMICOLON                               {;} 

MethodDecl: PUBLIC STATIC MethodHeader MethodBody {;}

FieldDecl: PUBLIC STATIC Type ID COMID SEMICOLON  {;}
         | PUBLIC STATIC Type ID SEMICOLON        {;} 

COMID: COMID                                      {;}
     | COMMA ID                                   {;}

Type: BOOL                                        {;}
    | INT                                         {;}
    | DOUBLE                                      {;}

MethodHeader: Type ID LPAR FormalParams RPAR      {;}
            | Type ID LPAR RPAR                   {;}
            | VOID ID LPAR FormalParams RPAR      {;}
            | VOID ID LPAR RPAR                   {;}

FormalParams: Type ID                             {;}
            | Type ID COMTYPID                    {;}
            | STRING LSQ RSQ ID                   {;}

COMTYPID: COMTYPID                                {;}
        | COMMA Type ID                           {;}

MethodBody: LBRACE BODY RBRACE                    {;}
        |   LBRACE RBRACE                         {;}

BODY: BODY                                        {;}
    | Statement                                   {;}
    | VarDecl                                     {;}

%%