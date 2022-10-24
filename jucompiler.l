%{
 //bash test.sh ./run para correr tudo estando os testes na pasta em questao, na meta 1 era meta1
 //Anibal Rodrigues 2019224911 
 //Guilherme Junqueira 2019221958 
    #include <ctype.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"


    int svLine = 1;
    int linha =1;
    int coluna =1;
    int svPoint = 1;
    int fc = 0;
    bool ignoreSTR = false;
    int line_yacc = 0;
    int col_yacc = 0;
    int error = 0;
%}
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


"/*"               {svPoint = coluna; svLine = linha; coluna += yyleng;BEGIN COM1;} 
<COM1>"*/"         {coluna += yyleng;BEGIN 0;}
<COM1>\n|\r\n|\r   {linha+=1;coluna = 1;}
<COM1><<EOF>>      {printf("Line %d, col %d: unterminated comment\n",svLine,svPoint);BEGIN 0;}
<COM1>.            {coluna += yyleng;}

"//"               {BEGIN COM2;} 
<COM2>\n|\r\n|\r   {linha +=1;coluna =1;BEGIN 0;}
<COM2>.            {coluna=yyleng;}


\"                 {BEGIN STR;svPoint = coluna; coluna += yyleng;ignoreSTR = false;error = 0;}
<STR>\"            {BEGIN 0;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext); coluna += yyleng;}else{yylval.stringValue = (char*) strdup(yytext);}}
<STR>{strlit}\"    {BEGIN 0;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext);coluna += yyleng;}else{yylval.stringValue = (char*) strdup(yytext);}} //chekar isto do yyval, provavel tem de ter as condicoes do argumento da command line  
<STR>\r\n|\n|\r    {printf("Line %d, col %d: unterminated string literal\n",linha,svPoint); linha +=1; coluna = 1 ; BEGIN 0;}
<STR>{illseq}      {printf("Line %d, col %d: invalid escape sequence (%s)\n",linha,coluna,yytext); coluna+= yyleng; ignoreSTR = true;}                  
<STR><<EOF>>       {printf("Line %d, col %d: unterminated string literal\n",linha,svPoint);BEGIN 0;}
<STR>.             {coluna += yyleng;}
<STR>{strlit}      {coluna += yyleng;}

{else}            {coluna += yyleng;if(fc == 1){printf("ELSE\n");}}
{dotlength}       {coluna += yyleng;if(fc == 1){printf("DOTLENGTH\n");}}
{intlit}          {coluna += yyleng;if(fc == 1){printf("INTLIT(%s)\n",yytext);}}
{double}          {coluna += yyleng;if(fc == 1){printf("DOUBLE\n");}}
{reserved}        {coluna += yyleng;if(fc == 1){printf("RESERVED(%s)\n",yytext);}}
{and}             {coluna += yyleng;if(fc == 1){printf("AND\n");}}
{assign}          {coluna += yyleng;if(fc == 1){printf("ASSIGN\n");}}
{star}            {coluna += yyleng;if(fc == 1){printf("STAR\n");}}
{comma}           {coluna += yyleng;if(fc == 1){printf("COMMA\n");}}
{div}             {coluna += yyleng;if(fc == 1){printf("DIV\n");}}
{eq}              {coluna += yyleng;if(fc == 1){printf("EQ\n");}}
{ge}              {coluna += yyleng;if(fc == 1){printf("GE\n");}}
{gt}              {coluna += yyleng;if(fc == 1){printf("GT\n");}}
{lbrace}          {coluna += yyleng;if(fc == 1){printf("LBRACE\n");}}
{le}              {coluna += yyleng;if(fc == 1){printf("LE\n");}}
{lpar}            {coluna += yyleng;if(fc == 1){printf("LPAR\n");}}
{lsq}             {coluna += yyleng;if(fc == 1){printf("LSQ\n");}}
{lt}              {coluna += yyleng;if(fc == 1){printf("LT\n");}}
{minus}           {coluna += yyleng;if(fc == 1){printf("MINUS\n");}}
{mod}             {coluna += yyleng;if(fc == 1){printf("MOD\n");}}
{ne}              {coluna += yyleng;if(fc == 1){printf("NE\n");}}
{not}             {coluna += yyleng;if(fc == 1){printf("NOT\n");}}
{boollit}         {coluna += yyleng;if(fc == 1){printf("BOOLLIT(%s)\n",yytext);}}
{or}              {coluna += yyleng;if(fc == 1){printf("OR\n");}}
{plus}            {coluna += yyleng;if(fc == 1){printf("PLUS\n");}}
{rbrace}          {coluna += yyleng;if(fc == 1){printf("RBRACE\n");}}
{rpar}            {coluna += yyleng;if(fc == 1){printf("RPAR\n");}}
{rsq}             {coluna += yyleng;if(fc == 1){printf("RSQ\n");}}
{semicolon}       {coluna += yyleng;if(fc == 1){printf("SEMICOLON\n");}}
{arrow}           {coluna += yyleng;if(fc == 1){printf("ARROW\n");}}
{lshift}          {coluna += yyleng;if(fc == 1){printf("LSHIFT\n");}}
{rshift}          {coluna += yyleng;if(fc == 1){printf("RSHIFT\n");}}
{xor}             {coluna += yyleng;if(fc == 1){printf("XOR\n");}}
{bool}            {coluna += yyleng;if(fc == 1){printf("BOOL\n");}}
{class}           {coluna += yyleng;if(fc == 1){printf("CLASS\n");}}
{if}              {coluna += yyleng;if(fc == 1){printf("IF\n");}}
{int}             {coluna += yyleng;if(fc == 1){printf("INT\n");}}
{print}           {coluna += yyleng;if(fc == 1){printf("PRINT\n");}}
{parseint}        {coluna += yyleng;if(fc == 1){printf("PARSEINT\n");}}
{public}          {coluna += yyleng;if(fc == 1){printf("PUBLIC\n");}}
{return}          {coluna += yyleng;if(fc == 1){printf("RETURN\n");}}
{static}          {coluna += yyleng;if(fc == 1){printf("STATIC\n");}}
{string}          {coluna += yyleng;if(fc == 1){printf("STRING\n");}}
{void}            {coluna += yyleng;if(fc == 1){printf("VOID\n");}}
{while}           {coluna += yyleng;if(fc == 1){printf("WHILE\n");}}
{id}              {coluna += yyleng;if(fc == 1){printf("ID(%s)\n",yytext);}}
{whitespace}      {coluna += yyleng;}
\n|\r\n|\r        {coluna = 1;linha += 1;}
.                 {printf("Line %d, col %d: illegal character (%s)\n",linha,coluna,yytext); coluna += yyleng;}
{reallit}         {coluna += yyleng;if(fc == 1){printf("REALLIT(%s)\n",yytext);};}


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
            
        }
    }
    
    return 0;
    }
    void yyerror(char* s){
    printf("Line %d, column %d: %s: %s\n", line_yacc, col_yacc, s, yytext);
}


int yywrap(){
    return 1;
}
