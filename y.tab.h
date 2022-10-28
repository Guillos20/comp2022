/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ELSE = 258,
    DOTLENGTH = 259,
    DOUBLE = 260,
    AND = 261,
    ASSIGN = 262,
    STAR = 263,
    COMMA = 264,
    DIV = 265,
    EQ = 266,
    GE = 267,
    GT = 268,
    LBRACE = 269,
    LE = 270,
    LPAR = 271,
    LSQ = 272,
    LT = 273,
    MINUS = 274,
    MOD = 275,
    NE = 276,
    NOT = 277,
    OR = 278,
    PLUS = 279,
    RBRACE = 280,
    RPAR = 281,
    RSQ = 282,
    SEMICOLON = 283,
    ARROW = 284,
    LSHIFT = 285,
    RSHIFT = 286,
    XOR = 287,
    BOOL = 288,
    CLASS = 289,
    IF = 290,
    INT = 291,
    PRINT = 292,
    PARSEINT = 293,
    PUBLIC = 294,
    RETURN = 295,
    STATIC = 296,
    STRING = 297,
    VOID = 298,
    WHILE = 299,
    STRLIT = 300,
    INTLIT = 301,
    RESERVED = 302,
    BOOLLIT = 303,
    ID = 304,
    REALLIT = 305,
    UNARY = 306
  };
#endif
/* Tokens.  */
#define ELSE 258
#define DOTLENGTH 259
#define DOUBLE 260
#define AND 261
#define ASSIGN 262
#define STAR 263
#define COMMA 264
#define DIV 265
#define EQ 266
#define GE 267
#define GT 268
#define LBRACE 269
#define LE 270
#define LPAR 271
#define LSQ 272
#define LT 273
#define MINUS 274
#define MOD 275
#define NE 276
#define NOT 277
#define OR 278
#define PLUS 279
#define RBRACE 280
#define RPAR 281
#define RSQ 282
#define SEMICOLON 283
#define ARROW 284
#define LSHIFT 285
#define RSHIFT 286
#define XOR 287
#define BOOL 288
#define CLASS 289
#define IF 290
#define INT 291
#define PRINT 292
#define PARSEINT 293
#define PUBLIC 294
#define RETURN 295
#define STATIC 296
#define STRING 297
#define VOID 298
#define WHILE 299
#define STRLIT 300
#define INTLIT 301
#define RESERVED 302
#define BOOLLIT 303
#define ID 304
#define REALLIT 305
#define UNARY 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "jucompiler.y"

    char *stringValue;
    char* value;
    struct Node *node;

#line 165 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
