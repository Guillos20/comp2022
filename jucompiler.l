%{
 //bash test.sh ./run para correr tudo estando os testes na pasta em questao, na meta 1 era meta1
 //Anibal Rodrigues 2019224911 
 //Guilherme Junqueira 2019221958 
    #include <ctype.h>
    #include <stdbool.h>
    #include <string.h>
    #include "y.tab.h"
    #include "struct.h"
    #include "symtab.h"

    extern Table *symtab;
   

    int svLine = 1;
    int linha =1;
    int coluna =1;
    int svPoint = 1;
    int fc = 0;
    bool ignoreSTR = false;
    int col_yacc = 1;
    int error = 0;
      
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
newline         \n|\r\n|\r  

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
<COM1>"*/"         {col_yacc = coluna;coluna += yyleng;BEGIN 0;}
<COM1>{newline}    {col_yacc = coluna;linha+=1;coluna = 1;}
<COM1><<EOF>>      {printf("Line %d, col %d: unterminated comment\n",svLine,svPoint);BEGIN 0;}
<COM1>.            {col_yacc = coluna;coluna += yyleng;}

"//"               {BEGIN COM2;} 
<COM2>{newline}    {col_yacc = coluna;linha +=1;coluna =1;BEGIN 0;}
<COM2>.            {col_yacc = coluna;coluna += yyleng;}


\"                 {BEGIN STR;svPoint = coluna;col_yacc = svPoint; coluna += yyleng;ignoreSTR = false;}
<STR>\"            {BEGIN 0; coluna += yyleng;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext);}else if(fc == 3 && ignoreSTR == false){char* str = malloc(yyleng+2);strcat(str, "\"");strcat(str, yytext); yytext = str;yylval.stringValue =  strdup(yytext);return STRLIT;}}
<STR>{strlit}\"    {BEGIN 0; coluna += yyleng;if(fc == 1 && ignoreSTR == false){printf("STRLIT(\"%s)\n",yytext);}else if(fc == 3 && ignoreSTR == false){char* str = malloc(yyleng+2);strcat(str, "\"");strcat(str, yytext); yytext = str;yylval.stringValue =  strdup(yytext);return STRLIT;}} //chekar isto do yyval, provavel tem de ter as condicoes do argumento da command line  
<STR>{newline}     {BEGIN 0;printf("Line %d, col %d: unterminated string literal\n",linha,svPoint); linha++; coluna = 1; col_yacc = svPoint;}
<STR>{illseq}      {BEGIN STR;printf("Line %d, col %d: invalid escape sequence (%s)\n",yylineno,coluna,yytext); col_yacc = coluna;coluna += yyleng; ignoreSTR = true;}                  
<STR><<EOF>>       {BEGIN 0;printf("Line %d, col %d: unterminated string literal\n",yylineno,svPoint);coluna = 1;col_yacc = svPoint;}
<STR>.             {coluna += yyleng;}
<STR>{strlit}      {coluna += yyleng;}

{else}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("ELSE\n");}else return ELSE;}
{dotlength}       {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("DOTLENGTH\n");}else return DOTLENGTH;}
{double}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("DOUBLE\n");}else return DOUBLE;}
{and}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("AND\n");}else return AND;}
{assign}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("ASSIGN\n");}else return ASSIGN;}
{star}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("STAR\n");}else return STAR;}
{comma}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("COMMA\n");}else return COMMA;}
{div}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("DIV\n");}else return DIV;}
{eq}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("EQ\n");}else return EQ;}
{ge}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("GE\n");}else return GE;}
{gt}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("GT\n");}else return GT;}
{lbrace}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LBRACE\n");}else return LBRACE;}
{le}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LE\n");}else return LE;}
{lpar}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LPAR\n");}else return LPAR;}
{lsq}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LSQ\n");}else return LSQ;}
{lt}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LT\n");}else return LT;}
{minus}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("MINUS\n");}else return MINUS;}
{mod}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("MOD\n");}else return MOD;}
{ne}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("NE\n");}else return NE;}
{not}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("NOT\n");}else return NOT;}
{boollit}         {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("BOOLLIT(%s)\n",yytext);} else {char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext); return BOOLLIT;};}
{or}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("OR\n");}else return OR;}
{plus}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("PLUS\n");}else return PLUS;}
{rbrace}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RBRACE\n");}else return RBRACE;}
{rpar}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RPAR\n");}else return RPAR;}
{rsq}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RSQ\n");}else return RSQ;}
{semicolon}       {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("SEMICOLON\n");}else return SEMICOLON;}
{arrow}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("ARROW\n");}else return ARROW;}
{lshift}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("LSHIFT\n");}else return LSHIFT;}
{rshift}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RSHIFT\n");}else return RSHIFT;}
{xor}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("XOR\n");}else return XOR;}
{bool}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("BOOL\n");}else return BOOL;}
{class}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("CLASS\n");}else return CLASS;}
{if}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("IF\n");}else return IF;}
{int}             {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("INT\n");}else return INT;}
{print}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("PRINT\n");}else return PRINT;}
{parseint}        {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("PARSEINT\n");}else return PARSEINT;}
{public}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("PUBLIC\n");}else return PUBLIC;}
{return}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RETURN\n");}else return RETURN;}
{static}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("STATIC\n");}else return STATIC;}
{string}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("STRING\n");}else return STRING;}
{void}            {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("VOID\n");}else return VOID;}
{while}           {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("WHILE\n");}else return WHILE;}
{whitespace}      {col_yacc = coluna;coluna++;}
{intlit}          {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("INTLIT(%s)\n",yytext);}else  {char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return INTLIT;};}
{reserved}        {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("RESERVED(%s)\n",yytext);}else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return RESERVED;};}
{id}              {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("ID(%s)\n",yytext);}else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext); return ID;};}
{newline}         {col_yacc = coluna;coluna = 1;linha += 1;}
.                 {col_yacc = coluna;{printf("Line %d, col %d: illegal character (%s)\n",yylineno,coluna,yytext);}coluna += 1;}
{reallit}         {col_yacc = coluna;coluna += yyleng;if(fc == 1){printf("REALLIT(%s)\n",yytext);} else{char* str = malloc(yyleng);sprintf(str, "%s", yytext); yytext = str;yylval.stringValue =  strdup(yytext);return REALLIT;};}
<<EOF>>           {col_yacc = coluna;yyterminate();}  
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
            if(!error){
            print_tree(root, 0);
            }                   
        }
         if(strcmp(argv[i], "-e2") == 0){
            fc = 3;
            yyparse(); 
            yylex();                
        }
        if(strcmp(argv[i], "-s") == 0){
            fc = 3;
            yyparse();
            initTable(root);
            print_Table(symtab);
            print_tree(root, 0);
            
        }
       
    }
    return 0;
}
 void yyerror(char* s){
    error = 1;
    printf("Line %d, col %d: %s: %s\n", linha, col_yacc, s, yytext);
}

int yywrap() {
    return 1;
}
