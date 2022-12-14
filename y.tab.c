/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "jucompiler.y"

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
    

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 19 "jucompiler.y"

    char *stringValue;
    int col_yacc;
    struct Node *node;

#line 248 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    51,    52,    53,    54,    57,    60,    61,
      64,    65,    68,    69,    70,    73,    74,    75,    76,    79,
      80,    84,    85,    88,    91,    92,    93,    96,   104,   109,
     113,   126,   138,   155,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   174,   179,   182,   183,   184,   187,   188,
     191,   194,   195,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   229,   230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ELSE", "DOTLENGTH", "DOUBLE", "AND",
  "ASSIGN", "STAR", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE",
  "LPAR", "LSQ", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE",
  "RPAR", "RSQ", "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "BOOL",
  "CLASS", "IF", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "STRLIT", "INTLIT", "RESERVED", "BOOLLIT",
  "ID", "REALLIT", "UNARY", "$accept", "Program", "DeclMult", "MethodDecl",
  "FieldDecl", "COMID", "Type", "MethodHeader", "FormalParams", "COMTYPID",
  "MethodBody", "BODY", "VarDecl", "COMIDVAR", "Statement",
  "StatementHelper", "MethodInvocation", "COMMAExpr", "Assignment",
  "ParseArgs", "Expr", "ExprHelper", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -28,   -41,    12,     9,   -50,     4,    -1,     4,     7,    27,
       4,     4,   -50,   -50,    40,   -50,   -50,   -50,   -50,   -50,
     -50,    32,    35,    74,    69,    33,   137,   -50,     8,    45,
     127,    73,    84,   157,   -50,    98,    99,   100,   188,   102,
      31,    75,   110,   137,   137,   108,   109,   111,   -50,   124,
      78,   117,   136,   -50,   121,   -50,   -50,   157,   132,   236,
     201,     2,   106,   243,   243,   243,   -50,   -50,   -50,    82,
     -50,   -50,   -50,   -50,   288,   131,   236,   236,    71,   140,
     -50,   -50,   -50,   -50,   -50,   -50,   134,   155,   -50,   -50,
     -50,   -50,   -50,   141,   142,   150,   152,   163,   158,   161,
      95,   -50,   -50,   -50,   -50,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   -50,   162,   -50,   164,   -50,   174,   147,   170,   159,
      41,   -50,   165,   171,   183,   -50,   236,   -50,   -50,   340,
     -50,   -50,   389,    72,    72,    72,    72,    20,   -50,   389,
     315,    20,   211,   211,   365,   165,   -50,   236,   187,   140,
     -50,   -50,   166,   186,   -50,   -50,   191,   -50,   174,   -50,
     -50,   155,   165,   196,   -50,   -50,   -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    14,    12,
      13,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    11,    16,     0,     8,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    72,    76,    74,
      73,    78,    81,    79,    82,     0,     0,     0,     0,    29,
      23,    25,    24,    36,    37,    38,     0,    22,    17,    10,
      15,    43,    30,     0,     0,     0,     0,     0,     0,     0,
      74,    70,    69,    71,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,    50,     0,    45,    49,     0,     0,     0,
       0,    19,     0,     0,     0,    52,     0,    80,    77,    57,
      66,    67,    60,    63,    59,    62,    58,    65,    68,    61,
      53,    64,    55,    56,    54,     0,    47,     0,     0,    29,
      27,    20,     0,    31,    41,    40,     0,    33,    49,    46,
      28,    22,     0,     0,    48,    21,    32,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,    68,   -50,   -50,   139,    -4,   -50,   194,    56,
     -50,    61,   -50,    70,   -32,   175,   -26,    60,   -24,   -22,
     -49,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    11,    31,    41,    23,    51,   131,
      27,    42,    43,   128,    44,    58,    71,   158,    72,    73,
      74,    75
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    57,    46,    96,    47,     6,     1,    45,     3,    46,
      22,    47,     4,    18,   101,   102,   103,    45,    45,    46,
      46,    47,    47,     5,    50,    57,    50,    12,   106,    -6,
     107,    45,     7,    46,    48,    47,    93,    95,    77,    99,
     114,    19,    29,     8,    20,    18,    18,    78,    14,    30,
      49,    97,    15,   122,   123,   126,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   124,    19,    19,    13,    20,    20,    16,    17,
     106,    24,   107,    21,    25,    28,   104,    62,    26,    77,
      63,   113,   114,    64,    52,    65,   117,   125,    78,   104,
     163,    55,   118,   119,    81,    82,    45,    98,    46,    37,
      47,    78,    56,   166,    59,    60,    61,    67,    76,    68,
      69,    70,    62,   167,    79,    63,   162,    87,    64,    45,
      65,    46,    18,    47,   168,    80,    83,    84,    32,    85,
     176,    86,    18,    88,    37,    29,    45,    90,    46,   127,
      47,    33,    67,    53,    68,    69,    70,    92,    32,   121,
      19,   129,   -26,    20,   130,    34,    32,   132,   133,    49,
      19,    33,    35,    20,    36,    37,   134,    38,   135,    33,
     136,    39,   -44,   157,   137,    34,    40,   138,   155,   172,
     156,    89,    35,    34,    36,    37,   159,    38,   160,   164,
      35,    39,    36,    37,    62,    38,    40,    63,   161,    39,
      64,   165,    65,   169,    40,   171,    66,    62,   173,   106,
      63,   107,   177,    64,    54,    65,    37,   175,   174,   170,
     113,   114,    91,     0,    67,   117,    68,    69,    70,    37,
       0,     0,     0,     0,     0,     0,    94,    67,     0,    68,
      69,    70,    62,     0,     0,    63,     0,     0,    64,    62,
      65,     0,    63,     0,     0,    64,     0,    65,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,    37,    67,     0,    68,    69,    70,     0,     0,    67,
       0,    68,   100,    70,   105,     0,   106,     0,   107,   108,
     109,   110,     0,   111,     0,     0,   112,   113,   114,   115,
       0,   116,   117,     0,     0,     0,     0,     0,   118,   119,
     120,   105,     0,   106,     0,   107,   108,   109,   110,     0,
     111,     0,     0,   112,   113,   114,   115,     0,     0,   117,
       0,     0,     0,     0,     0,   118,   119,   120,   106,     0,
     107,   108,   109,   110,     0,   111,     0,     0,   112,   113,
     114,   115,     0,     0,   117,     0,     0,     0,     0,     0,
     118,   119,   120,   106,     0,   107,   108,   109,   110,     0,
     111,     0,     0,   112,   113,   114,   115,     0,     0,   117,
       0,     0,     0,     0,     0,   118,   119,   106,     0,   107,
       0,   109,   110,     0,   111,     0,     0,   112,   113,   114,
       0,     0,     0,   117,     0,     0,     0,     0,     0,   118,
     119
};

static const yytype_int16 yycheck[] =
{
      26,    33,    26,     1,    26,     1,    34,    33,    49,    33,
      14,    33,     0,     5,    63,    64,    65,    43,    44,    43,
      44,    43,    44,    14,    28,    57,    30,    28,     8,    25,
      10,    57,    28,    57,    26,    57,    59,    60,     7,    62,
      20,    33,     9,    39,    36,     5,     5,    16,    41,    16,
      42,    49,    25,    76,    77,    78,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     1,    33,    33,     7,    36,    36,    10,    11,
       8,    49,    10,    43,    49,    16,     4,    16,    14,     7,
      19,    19,    20,    22,    49,    24,    24,    26,    16,     4,
     132,    28,    30,    31,    43,    44,   132,     1,   132,    38,
     132,    16,    28,   136,    16,    16,    16,    46,    16,    48,
      49,    50,    16,   155,    49,    19,   130,    49,    22,   155,
      24,   155,     5,   155,   157,    25,    28,    28,     1,    28,
     172,    17,     5,    26,    38,     9,   172,    26,   172,     9,
     172,    14,    46,    26,    48,    49,    50,    25,     1,    28,
      33,    27,    25,    36,     9,    28,     1,    26,    26,    42,
      33,    14,    35,    36,    37,    38,    26,    40,    26,    14,
      17,    44,    25,     9,    26,    28,    49,    26,    26,     3,
      26,    52,    35,    28,    37,    38,    49,    40,    28,    28,
      35,    44,    37,    38,    16,    40,    49,    19,    49,    44,
      22,    28,    24,    26,    49,    49,    28,    16,    27,     8,
      19,    10,    26,    22,    30,    24,    38,   171,   168,   159,
      19,    20,    57,    -1,    46,    24,    48,    49,    50,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    16,    -1,    -1,    19,    -1,    -1,    22,    16,
      24,    -1,    19,    -1,    -1,    22,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    46,    -1,    48,    49,    50,    -1,    -1,    46,
      -1,    48,    49,    50,     6,    -1,     8,    -1,    10,    11,
      12,    13,    -1,    15,    -1,    -1,    18,    19,    20,    21,
      -1,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,     6,    -1,     8,    -1,    10,    11,    12,    13,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,     8,    -1,
      10,    11,    12,    13,    -1,    15,    -1,    -1,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,     8,    -1,    10,    11,    12,    13,    -1,
      15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,     8,    -1,    10,
      -1,    12,    13,    -1,    15,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    34,    53,    49,     0,    14,     1,    28,    39,    54,
      55,    56,    28,    54,    41,    25,    54,    54,     5,    33,
      36,    43,    58,    59,    49,    49,    14,    62,    16,     9,
      16,    57,     1,    14,    28,    35,    37,    38,    40,    44,
      49,    58,    63,    64,    66,    68,    70,    71,    26,    42,
      58,    60,    49,    26,    60,    28,    28,    66,    67,    16,
      16,    16,    16,    19,    22,    24,    28,    46,    48,    49,
      50,    68,    70,    71,    72,    73,    16,     7,    16,    49,
      25,    63,    63,    28,    28,    28,    17,    49,    26,    57,
      26,    67,    25,    73,    45,    73,     1,    49,     1,    73,
      49,    72,    72,    72,     4,     6,     8,    10,    11,    12,
      13,    15,    18,    19,    20,    21,    23,    24,    30,    31,
      32,    28,    73,    73,     1,    26,    73,     9,    65,    27,
       9,    61,    26,    26,    26,    26,    17,    26,    26,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    26,    26,     9,    69,    49,
      28,    49,    58,    66,    28,    28,    73,    66,    73,    26,
      65,    49,     3,    27,    69,    61,    66,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    55,    56,    56,
      57,    57,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     4,     5,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     5,     7,     5,     2,     3,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     3,     5,     4,     3,     0,
       3,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     1,     1,     2,     1,     3,     1,     1,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 48 "jucompiler.y"
                                                  {(yyval.node) = root = createNode("Program",NULL,createNode("Id",(yyvsp[-3].stringValue),NULL,(yyvsp[-1].node)),NULL);}
#line 1592 "y.tab.c"
    break;

  case 3:
#line 51 "jucompiler.y"
                                                  {if((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); if((yyvsp[0].node) != NULL){add_sibling((yyvsp[-1].node), (yyvsp[0].node));};}else{(yyval.node)=NULL;};}
#line 1598 "y.tab.c"
    break;

  case 4:
#line 52 "jucompiler.y"
                                                  {if((yyvsp[-1].node) != NULL){(yyval.node) = (yyvsp[-1].node); if((yyvsp[0].node) != NULL){add_sibling((yyvsp[-1].node), (yyvsp[0].node));};}else{(yyval.node)=NULL;};}
#line 1604 "y.tab.c"
    break;

  case 5:
#line 53 "jucompiler.y"
                                                  {if((yyvsp[0].node) != NULL){(yyval.node) = (yyvsp[0].node);}else{(yyval.node)=NULL;};}
#line 1610 "y.tab.c"
    break;

  case 6:
#line 54 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1616 "y.tab.c"
    break;

  case 7:
#line 57 "jucompiler.y"
                                                  {(yyval.node) = createNode("MethodDecl",NULL,createNode("MethodHeader",NULL,(yyvsp[-1].node),createNode("MethodBody",NULL,(yyvsp[0].node),NULL)),NULL);}
#line 1622 "y.tab.c"
    break;

  case 8:
#line 60 "jucompiler.y"
                                                  {Node *Fd = createNode("FieldDecl",NULL,(yyvsp[-3].node),NULL); Node *id = createNode("Id",(yyvsp[-2].stringValue), NULL, NULL);add_sibling((yyvsp[-3].node), id);(yyval.node)=Fd;add_sibling(Fd, (yyvsp[-1].node)); save_type(Fd, (yyvsp[-3].node));}
#line 1628 "y.tab.c"
    break;

  case 9:
#line 61 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1634 "y.tab.c"
    break;

  case 10:
#line 64 "jucompiler.y"
                                                  {(yyval.node) = createNode("FieldDecl",NULL,createNode("Id", (yyvsp[-1].stringValue), NULL, NULL),NULL);add_sibling((yyval.node), (yyvsp[0].node));}
#line 1640 "y.tab.c"
    break;

  case 11:
#line 65 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1646 "y.tab.c"
    break;

  case 12:
#line 68 "jucompiler.y"
                                                  {(yyval.node) = createNode("Bool",NULL,NULL,NULL);}
#line 1652 "y.tab.c"
    break;

  case 13:
#line 69 "jucompiler.y"
                                                  {(yyval.node) = createNode("Int",NULL,NULL,NULL);}
#line 1658 "y.tab.c"
    break;

  case 14:
#line 70 "jucompiler.y"
                                                  {(yyval.node) = createNode("Double",NULL,NULL,NULL);}
#line 1664 "y.tab.c"
    break;

  case 15:
#line 73 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[-4].node);(yyvsp[-4].node)->sibling = createNode("Id",(yyvsp[-3].stringValue),NULL,createNode("MethodParams",NULL,(yyvsp[-1].node),NULL));}
#line 1670 "y.tab.c"
    break;

  case 16:
#line 74 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[-3].node);(yyvsp[-3].node)->sibling = createNode("Id",(yyvsp[-2].stringValue),NULL,createNode("MethodParams",NULL,NULL,NULL));}
#line 1676 "y.tab.c"
    break;

  case 17:
#line 75 "jucompiler.y"
                                                  {(yyval.node) = createNode("Void",NULL,NULL,createNode("Id",(yyvsp[-3].stringValue),NULL,createNode("MethodParams",NULL,(yyvsp[-1].node),NULL)));}
#line 1682 "y.tab.c"
    break;

  case 18:
#line 76 "jucompiler.y"
                                                  {(yyval.node) = createNode("Void",NULL,NULL,createNode("Id",(yyvsp[-2].stringValue),NULL,createNode("MethodParams",NULL,NULL,NULL)));}
#line 1688 "y.tab.c"
    break;

  case 19:
#line 79 "jucompiler.y"
                                                  {(yyval.node) = createNode("ParamDecl",NULL,(yyvsp[-2].node),(yyvsp[0].node));Node *id =createNode("Id",(yyvsp[-1].stringValue),NULL,NULL); add_sibling((yyvsp[-2].node),id);}
#line 1694 "y.tab.c"
    break;

  case 20:
#line 80 "jucompiler.y"
                                                  {Node *id = createNode("Id", (yyvsp[0].stringValue), NULL,NULL); (yyval.node) = createNode("ParamDecl",NULL,createNode("StringArray",NULL,NULL,id),NULL);}
#line 1700 "y.tab.c"
    break;

  case 21:
#line 84 "jucompiler.y"
                                                  {(yyval.node) = createNode("ParamDecl",NULL,(yyvsp[-2].node),(yyvsp[0].node));Node *id =createNode("Id",(yyvsp[-1].stringValue),NULL,NULL); add_sibling((yyvsp[-2].node), id);}
#line 1706 "y.tab.c"
    break;

  case 22:
#line 85 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1712 "y.tab.c"
    break;

  case 23:
#line 88 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[-1].node);}
#line 1718 "y.tab.c"
    break;

  case 24:
#line 91 "jucompiler.y"
                                                  {if((yyvsp[-1].node) != NULL){ (yyval.node) = (yyvsp[-1].node);if((yyvsp[0].node) != NULL){add_sibling((yyvsp[-1].node),(yyvsp[0].node));}}else if((yyvsp[-1].node)==NULL){(yyval.node)=(yyvsp[0].node);}else{(yyval.node) = NULL;};}
#line 1724 "y.tab.c"
    break;

  case 25:
#line 92 "jucompiler.y"
                                                  {if((yyvsp[-1].node) != NULL){ (yyval.node) = (yyvsp[-1].node);if((yyvsp[0].node) != NULL){add_sibling((yyvsp[-1].node),(yyvsp[0].node));}}else if((yyvsp[-1].node)==NULL){(yyval.node)=(yyvsp[0].node);}else{(yyval.node) = NULL;};}
#line 1730 "y.tab.c"
    break;

  case 26:
#line 93 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1736 "y.tab.c"
    break;

  case 27:
#line 96 "jucompiler.y"
                                                  {(yyval.node) = createNode("VarDecl",NULL,NULL,(yyvsp[-1].node));
                                                   add_son((yyval.node), (yyvsp[-3].node));
                                                   Node *id = createNode("Id",(yyvsp[-2].stringValue),NULL,NULL); 
                                                   add_sibling((yyvsp[-3].node), id);
                                                   save_type((yyval.node), (yyvsp[-3].node));
                                                   
                                                }
#line 1748 "y.tab.c"
    break;

  case 28:
#line 104 "jucompiler.y"
                                                    {(yyval.node) = createNode("VarDecl",NULL,NULL,(yyvsp[0].node)); 
                                                    
                                                    Node *id = createNode("Id",(yyvsp[-1].stringValue),NULL,NULL);
                                                    add_son((yyval.node), id); 
                                                    }
#line 1758 "y.tab.c"
    break;

  case 29:
#line 109 "jucompiler.y"
                                                    {(yyval.node) = NULL;}
#line 1764 "y.tab.c"
    break;

  case 30:
#line 113 "jucompiler.y"
                                                        {Node * node = (yyvsp[-1].node);blockCount = 0; 
                                                        while(node){
                                                            blockCount++;
                                                            node = node->sibling;
                                                            
                                                        }
                                                        //printf("%d\n", blockCount);
                                                        if(blockCount >1){
                                                            (yyval.node) = createNode("Block", NULL, (yyvsp[-1].node), NULL);
                                                        }else{
                                                        (yyval.node) = (yyvsp[-1].node);
                                                        }
                                                        }
#line 1782 "y.tab.c"
    break;

  case 31:
#line 126 "jucompiler.y"
                                                        {(yyval.node) = createNode("If",NULL, (yyvsp[-2].node), NULL);
                                                            Node *block=createNode("Block",NULL,NULL, NULL);
                                                            Node *block2=createNode("Block",NULL,NULL, NULL);
                                                        if((yyvsp[0].node)!=NULL){
                                                            add_son((yyval.node), (yyvsp[0].node));
                                                            add_son((yyval.node), block);
                                                        }else{
                                                            add_son((yyval.node), (yyvsp[0].node));
                                                            add_son((yyval.node), block);
                                                            add_son((yyval.node), block2);

                                                        }}
#line 1799 "y.tab.c"
    break;

  case 32:
#line 138 "jucompiler.y"
                                                        {(yyval.node) = createNode("If",NULL, (yyvsp[-4].node), NULL);
                                                            Node *ifblock=createNode("Block",NULL, NULL,NULL);  
                                                            Node *ifblock2=createNode("Block",NULL, NULL,NULL);  
                                                            if((yyvsp[-2].node) !=NULL&& (yyvsp[0].node)!=NULL){
                                                                add_sibling((yyvsp[-4].node), (yyvsp[-2].node));
                                                                add_sibling((yyvsp[-2].node), (yyvsp[0].node));
                                                                }else if((yyvsp[-2].node)==NULL && (yyvsp[0].node)!=NULL){
                                                                    add_son((yyval.node), ifblock);
                                                                    add_son((yyval.node), (yyvsp[0].node));
                                                                }else if((yyvsp[-2].node)!=NULL && (yyvsp[0].node)==NULL){
                                                                    add_son((yyval.node), (yyvsp[-2].node));
                                                                    add_son((yyval.node), ifblock);
                                                                }else{
                                                                   add_son((yyval.node), ifblock);
                                                                   add_son((yyval.node), ifblock2);
                                                                }
                                                        }
#line 1821 "y.tab.c"
    break;

  case 33:
#line 155 "jucompiler.y"
                                                        {(yyval.node) = createNode2("While",NULL, (yyvsp[-2].node), NULL,(yyvsp[-3].col_yacc));
                                                            Node *whileblock=createNode("Block",NULL, NULL,NULL); 
                                                            if((yyvsp[0].node)!=NULL){
                                                                add_sibling((yyvsp[-2].node),(yyvsp[0].node));
                                                            }else{
                                                                add_sibling((yyvsp[-2].node),(yyvsp[0].node));
                                                                add_son((yyval.node), whileblock);
                                                            }
                                                        }
#line 1835 "y.tab.c"
    break;

  case 34:
#line 164 "jucompiler.y"
                                                        {(yyval.node) = createNode("Return",NULL,NULL,NULL);}
#line 1841 "y.tab.c"
    break;

  case 35:
#line 165 "jucompiler.y"
                                                        {(yyval.node) = createNode("Return",NULL,(yyvsp[-1].node),NULL);}
#line 1847 "y.tab.c"
    break;

  case 36:
#line 166 "jucompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1853 "y.tab.c"
    break;

  case 37:
#line 167 "jucompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1859 "y.tab.c"
    break;

  case 38:
#line 168 "jucompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1865 "y.tab.c"
    break;

  case 39:
#line 169 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 1871 "y.tab.c"
    break;

  case 40:
#line 170 "jucompiler.y"
                                                        {(yyval.node) = createNode2("Print",NULL,(yyvsp[-2].node),NULL,(yyvsp[-3].col_yacc));}
#line 1877 "y.tab.c"
    break;

  case 41:
#line 171 "jucompiler.y"
                                                        {(yyval.node) = createNode2("Print",NULL,createNode("StrLit",(yyvsp[-2].stringValue),NULL,NULL),NULL,(yyvsp[-3].col_yacc));}
#line 1883 "y.tab.c"
    break;

  case 42:
#line 172 "jucompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1889 "y.tab.c"
    break;

  case 43:
#line 174 "jucompiler.y"
                                                        {if((yyvsp[-1].node) == NULL){(yyval.node) = (yyvsp[0].node);}
                                                        else if((yyvsp[0].node) == NULL){(yyval.node) = (yyvsp[-1].node);}
                                                        else{(yyval.node) = (yyvsp[-1].node);
                                                        add_sibling((yyvsp[-1].node), (yyvsp[0].node));}
                                                        }
#line 1899 "y.tab.c"
    break;

  case 44:
#line 179 "jucompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1905 "y.tab.c"
    break;

  case 45:
#line 182 "jucompiler.y"
                                                        {Node *id = createNode("Id",(yyvsp[-2].stringValue),NULL,NULL); (yyval.node) = createNode("Call",NULL,id, NULL); }
#line 1911 "y.tab.c"
    break;

  case 46:
#line 183 "jucompiler.y"
                                                        {Node *id = createNode("Id",(yyvsp[-4].stringValue),NULL,(yyvsp[-2].node));add_sibling((yyvsp[-2].node),(yyvsp[-1].node));(yyval.node) = createNode("Call",NULL,id, NULL);}
#line 1917 "y.tab.c"
    break;

  case 47:
#line 184 "jucompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1923 "y.tab.c"
    break;

  case 48:
#line 187 "jucompiler.y"
                                                        {(yyval.node) = (yyvsp[-1].node); add_sibling((yyvsp[-1].node),(yyvsp[0].node));}
#line 1929 "y.tab.c"
    break;

  case 49:
#line 188 "jucompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1935 "y.tab.c"
    break;

  case 50:
#line 191 "jucompiler.y"
                                                        {(yyval.node) = createNode2("Assign",NULL,createNode("Id",(yyvsp[-2].stringValue),NULL,(yyvsp[0].node)),NULL,(yyvsp[-1].col_yacc));}
#line 1941 "y.tab.c"
    break;

  case 51:
#line 194 "jucompiler.y"
                                                        {(yyval.node) = createNode2("ParseArgs",NULL,createNode("Id",(yyvsp[-4].stringValue),NULL,(yyvsp[-2].node)),NULL,(yyvsp[-6].col_yacc));}
#line 1947 "y.tab.c"
    break;

  case 52:
#line 195 "jucompiler.y"
                                                        {(yyval.node) = NULL;}
#line 1953 "y.tab.c"
    break;

  case 53:
#line 198 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Or",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1959 "y.tab.c"
    break;

  case 54:
#line 199 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Xor",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1965 "y.tab.c"
    break;

  case 55:
#line 200 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Lshift",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1971 "y.tab.c"
    break;

  case 56:
#line 201 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Rshift",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1977 "y.tab.c"
    break;

  case 57:
#line 202 "jucompiler.y"
                                                  {(yyval.node) = createNode2("And",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1983 "y.tab.c"
    break;

  case 58:
#line 203 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Lt",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1989 "y.tab.c"
    break;

  case 59:
#line 204 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Gt",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 1995 "y.tab.c"
    break;

  case 60:
#line 205 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Eq",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2001 "y.tab.c"
    break;

  case 61:
#line 206 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Ne",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2007 "y.tab.c"
    break;

  case 62:
#line 207 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Le",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2013 "y.tab.c"
    break;

  case 63:
#line 208 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Ge",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2019 "y.tab.c"
    break;

  case 64:
#line 209 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Add",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2025 "y.tab.c"
    break;

  case 65:
#line 210 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Sub",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2031 "y.tab.c"
    break;

  case 66:
#line 211 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Mul",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2037 "y.tab.c"
    break;

  case 67:
#line 212 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Div",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2043 "y.tab.c"
    break;

  case 68:
#line 213 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Mod",NULL,(yyvsp[-2].node),NULL,(yyvsp[-1].col_yacc));add_sibling((yyvsp[-2].node),(yyvsp[0].node));}
#line 2049 "y.tab.c"
    break;

  case 69:
#line 214 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Not",NULL,(yyvsp[0].node),NULL, (yyvsp[-1].col_yacc));}
#line 2055 "y.tab.c"
    break;

  case 70:
#line 215 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Minus",NULL,(yyvsp[0].node),NULL,(yyvsp[-1].col_yacc));}
#line 2061 "y.tab.c"
    break;

  case 71:
#line 216 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Plus",NULL,(yyvsp[0].node),NULL,(yyvsp[-1].col_yacc));}
#line 2067 "y.tab.c"
    break;

  case 72:
#line 217 "jucompiler.y"
                                                  {(yyval.node) = createNode("DecLit",(yyvsp[0].stringValue),NULL,NULL);}
#line 2073 "y.tab.c"
    break;

  case 73:
#line 218 "jucompiler.y"
                                                  {(yyval.node) = createNode("RealLit",(yyvsp[0].stringValue),NULL,NULL);}
#line 2079 "y.tab.c"
    break;

  case 74:
#line 219 "jucompiler.y"
                                                  {(yyval.node) = createNode("Id",(yyvsp[0].stringValue), NULL,NULL);}
#line 2085 "y.tab.c"
    break;

  case 75:
#line 220 "jucompiler.y"
                                                  {(yyval.node) = createNode2("Length",NULL,createNode("Id",(yyvsp[-1].stringValue),NULL,NULL),NULL,(yyvsp[0].col_yacc));}
#line 2091 "y.tab.c"
    break;

  case 76:
#line 221 "jucompiler.y"
                                                  {(yyval.node) = createNode("BoolLit",(yyvsp[0].stringValue),NULL,NULL);}
#line 2097 "y.tab.c"
    break;

  case 77:
#line 222 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[-1].node);}
#line 2103 "y.tab.c"
    break;

  case 78:
#line 223 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[0].node);}
#line 2109 "y.tab.c"
    break;

  case 79:
#line 224 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[0].node);}
#line 2115 "y.tab.c"
    break;

  case 80:
#line 225 "jucompiler.y"
                                                  {(yyval.node) = NULL;}
#line 2121 "y.tab.c"
    break;

  case 81:
#line 229 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[0].node);}
#line 2127 "y.tab.c"
    break;

  case 82:
#line 230 "jucompiler.y"
                                                  {(yyval.node) = (yyvsp[0].node);}
#line 2133 "y.tab.c"
    break;


#line 2137 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 233 "jucompiler.y"
