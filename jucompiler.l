%{
 //bash test.sh ./run para correr tudo estando os testes na pasta em questao, na meta 1 era meta1
 //Anibal Rodrigues 2019224911 
 //Guilherme Junqueira 2019221958 
    #include <ctype.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    #include "struct.h"
   

    int svLine = 1;
    int linha =1;
    int coluna =1;
    int svPoint = 1;
    int fc = 0;
    bool ignoreSTR = false;
    Node *root;
    int col_yacc = 1;

      
%}

%option yylineno
%x STR COM1 COM2


letter          [A-Za-z]
digit           [0-9]+
intdigits       [1-9]({digit}|"_")*{digit}
realdigits      {digit}({digit}|"_")*{digit}|[0-9]
id_letter       {letter}|"_"|"$"
exp             ("E"|"e")("+"|"-")?{realdigits}

id              {id_letter}({id_letter}|{digit})*
intlit          [0-9]|{intdigits}
reallit         {realdigits}"."({realdigits}?{exp}?)|{realdigits}{exp}|"."{realdigits}{exp}?
strlit          ([^\n\r"\\]|\\n|\\f|\\r|\\\\|\\\"|\\t)*
whitespace      (" "|\t|\f)


reserved        "abstract"|"continue"|"for"|"new"|"switch"|"assert"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"this"|"break"|"implements"|"protected"|"throw"|"byte"|"import"|"throws"|"case"|"enum"|"instanceof"|"transient"|"catch"|"extends"|"short"|"try"|"char"|"final"|"interface"|"finally"|"long"|"strictfp"|"volatile"|"const"|"float"|"native"|"super"|"--"|"++"|"Integer"|"System"|"null"
boollit         "true"|"false"
and             "&&"
assign          "="
star            "*"
comma           ","
div             "/"
eq              "=="
ge              ">="
gt              ">"
lbrace          "{"
le              "<="
lpar            "("
lsq             "["
lt              "<"
minus           "-"
mod             "%"
ne              "!="
not             "!"
or              "||"
plus            "+"
rbrace          "}"
rpar            ")"
rsq             "]"
semicolon       ";"
arrow           "->"
lshift          "<<"
rshift          ">>"
xor             "^"
bool            "boolean"
class           "class"
dotlength       ".length"
double          "double"
else            "else"
if              "if"
int             "int"
print           "System.out.print"
parseint        "Integer.parseInt"
public          "public"
return          "return"
static          "static"
string          "String"
void            "void"
while           "while"
illseq          \\[^fnrt\\\"\r\n]?


%%


"/*"               {svPoint = coluna; svLine = linha;col_yacc = coluna; coluna += yyleng;BEGIN COM1;} 
<COM1>"*/"         {coluna += yyleng;col_yacc = coluna;BEGIN 0;}
<COM1>\n|\r\n|\r   {linha+=1;coluna = 1;col_yacc = coluna;}
<COM1><<EOF>>      {printf("Line %d, col %d: unterminated comment\n",svLine,svPoint);BEGIN 0;}
<COM1>.            {coluna += yyleng;col_yacc = coluna;}

"//"               {BEGIN COM2;} 
<COM2>\n|\r\n|\r   {linha +=1;coluna =1;col_yacc = coluna;BEGIN 0;}
<COM2>.            {coluna+=yyleng;col_yacc = coluna;}


\"                 {BEGIN STR;svPoint = coluna;col_yacc = coluna; coluna += yyleng;ignoreSTR = false;}
<STR>\"            {BEGIN 0; coluna += yyleng;col_yacc = coluna;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext);}else{char* str = malloc(yyleng+2);sprintf(str, "\"%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return STRLIT;}}
<STR>{strlit}\"    {BEGIN 0; coluna += yyleng;col_yacc = coluna;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext);}else{char* str = malloc(yyleng+2);sprintf(str, "\"%s", yytext); yytext = str; yylval.stringValue =  strdup(yytext);return STRLIT;}} //chekar isto do yyval, provavel tem de ter as condicoes do argumento da command line  
<STR>\r\n|\n|\r    {printf("Line %d, col %d: unterminated string literal\n",linha,svPoint); linha +=1; coluna = 1; col_yacc = svPoint; BEGIN 0;}
<STR>{illseq}      {printf("Line %d, col %d: invalid escape sequence (%s)\n",linha,coluna,yytext); col_yacc = coluna;coluna += yyleng; ignoreSTR = true;}                  
<STR><<EOF>>       {printf("Line %d, col %d: unterminated string literal\n",linha,svPoint);col_yacc = svPoint;BEGIN 0;}
<STR>.             {coluna += yyleng;col_yacc = coluna;}
<STR>{strlit}      {coluna += yyleng;col_yacc = coluna;}

{else}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("ELSE\n");}else return ELSE;}
{dotlength}       {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("DOTLENGTH\n");}else return DOTLENGTH;}
{intlit}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("INTLIT(%s)\n",yytext);}else  {char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return INTLIT;};}
{double}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("DOUBLE\n");}else return DOUBLE;}
{reserved}        {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RESERVED(%s)\n",yytext);}else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return RESERVED;};}
{and}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("AND\n");}else return AND;}
{assign}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("ASSIGN\n");}else return ASSIGN;}
{star}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("STAR\n");}else return STAR;}
{comma}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("COMMA\n");}else return COMMA;}
{div}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("DIV\n");}else return DIV;}
{eq}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("EQ\n");}else return EQ;}
{ge}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("GE\n");}else return GE;}
{gt}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("GT\n");}else return GT;}
{lbrace}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LBRACE\n");}else return LBRACE;}
{le}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LE\n");}else return LE;}
{lpar}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LPAR\n");}else return LPAR;}
{lsq}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LSQ\n");}else return LSQ;}
{lt}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LT\n");}else return LT;}
{minus}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("MINUS\n");}else return MINUS;}
{mod}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("MOD\n");}else return MOD;}
{ne}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("NE\n");}else return NE;}
{not}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("NOT\n");}else return NOT;}
{boollit}         {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("BOOLLIT(%s)\n",yytext);} else {char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext); return BOOLLIT;};}
{or}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("OR\n");}else return OR;}
{plus}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("PLUS\n");}else return PLUS;}
{rbrace}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RBRACE\n");}else return RBRACE;}
{rpar}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RPAR\n");}else return RPAR;}
{rsq}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RSQ\n");}else return RSQ;}
{semicolon}       {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("SEMICOLON\n");}else return SEMICOLON;}
{arrow}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("ARROW\n");}else return ARROW;}
{lshift}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("LSHIFT\n");}else return LSHIFT;}
{rshift}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RSHIFT\n");}else return RSHIFT;}
{xor}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("XOR\n");}else return XOR;}
{bool}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("BOOL\n");}else return BOOL;}
{class}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("CLASS\n");}else return CLASS;}
{if}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("IF\n");}else return IF;}
{int}             {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("INT\n");}else return INT;}
{print}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("PRINT\n");}else return PRINT;}
{parseint}        {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("PARSEINT\n");}else return PARSEINT;}
{public}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("PUBLIC\n");}else return PUBLIC;}
{return}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("RETURN\n");}else return RETURN;}
{static}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("STATIC\n");}else return STATIC;}
{string}          {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("STRING\n");}else return STRING;}
{void}            {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("VOID\n");}else return VOID;}
{while}           {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("WHILE\n");}else return WHILE;}
{whitespace}      {coluna += yyleng;col_yacc = coluna;}
{id}              {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("ID(%s)\n",yytext);}else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext); return ID;};}
\n|\r\n|\r        {coluna = 1;linha += 1;col_yacc = coluna;}
.                 {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("Line %d, col %d: illegal character (%s)\n",linha,coluna,yytext);}}
{reallit}         {coluna += yyleng;col_yacc = coluna;if(fc == 1){printf("REALLIT(%s)\n",yytext);} else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return REALLIT;};}

%%

int main(int argc, char** argv){
    
    for(int i = 1;i<argc;i++){
        if(strcmp(argv[i], "-l") == 0){
            fc = 1;
            yylex();
        }
        if(strcmp(argv[i], "-e1") == 0){
            fc = 2;
            yylex();
        }
        if(strcmp(argv[i], "-t") == 0){
            fc = 3;
            yyparse();
            print_tree(root, 0);                   
        }
         if(strcmp(argv[i], "-e2") == 0){
            fc = 3;
            yyparse();                 
        }
    }
    return 0;
}
   


int yywrap(){
    return 1;
}
 void yyerror(char* s){
    printf("Line %d, col %d: %s: %s\n", yylineno, col_yacc, s, yytext);
}