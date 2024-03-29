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
#line 1 "mini_js.y"

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

enum TipoVar { TIPO_LET, TIPO_VAR, TIPO_CONST };

struct Atributos {
  vector<string> c;
  string v;
  int n_args = 0;
};

struct Simbolo {
  int linha, coluna;
  TipoVar tipo;
};

// Tipo dos atributos: YYSTYPE eh o tipo usado para os atributos
#define YYSTYPE Atributos

// Atualizacao de linhas e colunas
#define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }

// Funcoes
int yylex();
int yyparse();
void yyerror(const char *);
void print_prod(const char *);
void atualiza_atributos_token(int token);
vector<string> concatena(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, vector<string> b);
vector<string> operator+(vector<string> a, string b);
vector<string> operator+(string a, vector<string> b);
vector<string> to_vector(string s);
string gera_label(string prefixo);
vector<string> resolve_enderecos(vector<string> entrada);
void atualiza_variaveis_declaradas(string var);
void verifica_variaveis_declaradas(string var);
void print_NPR(vector<string>);
vector<string> gera_inicializacao_de_argumento(string id, int n_args);
string trim(string s, string chars);
vector<string> tokeniza(string s);
vector<string> gera_funcao(string id, string label);
vector<string> gera_fim_funcao();
vector<string> gera_retorno();
void atualiza_variaveis_declaradas_escopo(string var);

// Variaveis
map<string, int> variaveis_declaradas;
map<string, int> variaveis_declaradas_escopo;
vector<string> epsilon;
vector<string> funcoes;
int n_params;
vector<bool> pode_retornar = { false };
bool eh_escopo = false;
vector<map<string, Simbolo>> ts = {};
int posicoes;


#line 148 "y.tab.c"

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
    NUM = 258,
    ID = 259,
    LET = 260,
    VAR = 261,
    CONST = 262,
    OBJ = 263,
    ARRAY = 264,
    STRING = 265,
    ADD = 266,
    IF = 267,
    ELSE = 268,
    IGUAL = 269,
    DIF = 270,
    INC = 271,
    WHILE = 272,
    FOR = 273,
    FUNCTION = 274,
    ASM = 275,
    RETURN = 276,
    BLOCO = 277,
    LAMBDA_NOVO_OBJ = 278,
    ARROW = 279,
    TRUE = 280,
    FALSE = 281
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define LET 260
#define VAR 261
#define CONST 262
#define OBJ 263
#define ARRAY 264
#define STRING 265
#define ADD 266
#define IF 267
#define ELSE 268
#define IGUAL 269
#define DIF 270
#define INC 271
#define WHILE 272
#define FOR 273
#define FUNCTION 274
#define ASM 275
#define RETURN 276
#define BLOCO 277
#define LAMBDA_NOVO_OBJ 278
#define ARROW 279
#define TRUE 280
#define FALSE 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);





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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

#define YYUNDEFTOK  2
#define YYMAXUTOK   281


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
       2,     2,     2,     2,     2,     2,     2,    34,     2,     2,
      36,    40,    32,    30,    41,    31,    37,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,    44,
      46,    27,    45,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   127,   128,   129,   132,   133,   134,   135,
     136,   137,   138,   139,   146,   155,   156,   157,   160,   163,
     169,   175,   181,   184,   187,   192,   198,   206,   211,   216,
     223,   226,   229,   232,   235,   236,   237,   240,   241,   242,
     246,   247,   250,   251,   254,   255,   258,   259,   262,   263,
     264,   265,   268,   269,   270,   273,   276,   277,   280,   281,
     282,   283,   286,   289,   290,   291,   294,   298,   298,   300,
     300,   301,   304,   305,   308,   309,   312,   313,   316,   319,
     320,   321,   324,   325,   328,   329,   330,   333,   334,   335,
     336,   337,   340,   341,   342,   343,   344,   345,   346,   347,
     350,   351,   352,   353,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "LET", "VAR", "CONST",
  "OBJ", "ARRAY", "STRING", "ADD", "IF", "ELSE", "IGUAL", "DIF", "INC",
  "WHILE", "FOR", "FUNCTION", "ASM", "RETURN", "BLOCO", "LAMBDA_NOVO_OBJ",
  "ARROW", "TRUE", "FALSE", "'='", "'?'", "':'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'T'", "'('", "'.'", "'{'", "'}'", "')'", "','", "'['",
  "']'", "';'", "'>'", "'<'", "$accept", "s", "cmds", "cmd_1", "cmd_2",
  "bloco", "funcao", "args", "arg", "empilha_escopo_func",
  "desempilha_escopo_func", "empilha_escopo", "desempilha_escopo", "atr",
  "atr_id", "atr_recursiva", "atr_obj", "prop", "atr_array", "rec",
  "matexp", "matrix", "indices", "decl", "objeto", "corpo_obj", "array",
  "corpo_array", "@1", "exps_array", "$@2", "fim_decl", "loop",
  "separador", "while_loop", "for_loop", "condicional", "corpo",
  "condicao", "exp", "params", "val", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    63,    58,
      43,    45,    42,    47,    37,    84,    40,    46,   123,   125,
      41,    44,    91,    93,    59,    62,    60
};
# endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,  -155,   138,    14,    14,    14,  -155,  -155,  -155,   -24,
     -14,    41,    38,   338,  -155,  -155,  -155,    68,   338,  -155,
     338,    81,  -155,  -155,   226,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,   526,  -155,   338,  -155,
    -155,   362,   386,    84,   410,    63,    43,  -155,  -155,  -155,
     338,   338,   113,  -155,    60,  -155,    25,   441,  -155,   417,
     226,    69,   441,  -155,   184,  -155,  -155,   338,   338,   338,
     338,   338,   434,   191,   165,   441,     9,  -155,   441,     6,
      26,    24,    86,   536,   458,   106,    14,  -155,    93,   519,
      95,   139,    14,    99,   109,   482,   143,  -155,   117,  -155,
     118,  -155,  -155,   180,   180,   124,   124,   124,     7,   123,
     345,   128,   386,   338,   338,   338,   145,   158,     8,  -155,
    -155,    44,  -155,   558,    62,   166,   167,   167,   369,  -155,
    -155,   338,   338,   338,   338,   266,   203,   173,   338,   290,
     142,    83,  -155,   441,  -155,  -155,   338,  -155,   338,  -155,
     434,   434,  -155,  -155,   441,   544,   191,   441,   338,  -155,
      63,   207,   207,   458,   189,   198,  -155,  -155,  -155,   266,
     441,   441,   441,   441,   226,   175,  -155,  -155,   197,   338,
     196,   266,   100,   338,   266,   482,  -155,   441,  -155,  -155,
    -155,   441,   158,   209,  -155,  -155,   314,  -155,  -155,   210,
    -155,   202,   506,  -155,   266,   441,  -155,  -155,   118,  -155,
     393,   229,  -155,   246,    71,   213,   214,  -155,  -155,  -155,
    -155,  -155,   166,  -155,   215,   266,   248,  -155,  -155,   266,
     266,  -155,  -155,  -155,  -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,   107,   106,     0,     0,     0,   110,   111,   112,     0,
       0,     0,    32,    13,   114,   104,   105,     0,     0,    32,
       0,     0,     2,    77,     5,    17,    16,     6,    34,    35,
      36,   115,    10,    74,    75,    15,    12,    98,     0,   113,
      22,     0,     0,     0,     0,     0,    73,     7,     8,     9,
       0,     0,     0,    32,     0,    30,   106,    14,   108,     0,
       5,     0,    67,     1,     5,     4,    11,     0,     0,     0,
       0,     0,   102,    39,    23,    24,   106,    38,    37,    97,
       0,   106,     0,     0,     0,     0,     0,    59,     0,    91,
       0,     0,     0,     0,     0,     0,     0,   109,     0,    66,
      71,    76,     3,    92,    93,    94,    95,    96,   106,     0,
     101,     0,     0,     0,     0,     0,     0,    57,   106,    51,
      46,    49,    52,    48,   106,     0,    73,    73,    73,    72,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,    26,    29,    97,    33,     0,    68,     0,    55,
     102,   102,    99,    41,    40,     0,    43,    42,     0,    56,
      55,     0,     0,     0,     0,     0,    60,    61,    58,     0,
      89,    90,    87,    88,     5,     0,    86,    78,    44,     0,
       0,     0,     0,     0,     0,     0,    18,    69,   103,   100,
      45,    47,     0,    54,    53,    50,     0,    62,    33,     0,
      85,     0,     0,    33,     0,    28,    33,    25,    71,    65,
      64,    83,    84,     0,   106,     0,     0,    20,    31,    33,
      21,    70,     0,    32,     0,     0,     0,    19,    63,     0,
       0,    80,    81,    33,    79,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,   -17,     3,     4,  -155,   174,   119,    75,   208,
    -154,   -19,  -129,   -39,  -155,   151,  -155,  -155,   -69,   102,
      -9,   -58,   -97,     5,    70,    45,  -155,  -155,  -155,    72,
    -155,   -21,  -155,  -155,  -155,  -155,  -155,  -150,   -49,   -12,
      35,    77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,   175,   176,    25,    26,   141,   142,    54,
     217,    55,   218,    27,    28,    77,    29,    80,    30,   120,
     121,   122,    45,    47,   127,   165,    31,    61,   100,   147,
     208,    87,    32,    64,    33,    34,    35,   177,    88,    36,
     111,    37
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    57,    90,    23,    24,    82,    59,    65,    62,    48,
      49,   149,    50,    93,   109,   119,   186,   -44,    46,   198,
     159,   160,    51,    39,    39,    39,    73,    23,    24,    75,
      78,   203,    83,   -44,   206,    38,   112,   114,    89,    89,
      39,    39,    53,    98,    96,    96,    96,   102,   113,   148,
      44,    42,   220,   115,   219,   103,   104,   105,   106,   107,
     110,    43,    96,    23,    24,   227,    44,    23,    24,   211,
      85,    58,   123,   128,   161,   231,   162,    52,    39,   233,
     234,    63,    38,   143,    86,    40,    41,    39,    79,   180,
      84,   129,   109,   109,   119,   149,    95,   137,    42,    96,
     154,   155,   156,   157,   235,   166,   167,   168,   136,     1,
     124,   169,    99,    44,     6,     7,     8,    91,    92,   170,
     171,   172,   173,   184,   185,    12,    89,   143,    14,   116,
     201,    15,    16,   130,   187,   135,    83,    17,   110,   110,
     204,   185,    18,   138,   125,   139,   191,   144,    20,    38,
      38,   123,   193,   194,    39,    60,   145,   199,    39,   146,
      72,    40,    41,   215,   150,    42,    42,    89,   152,   183,
     164,   205,   158,   143,   224,    43,   136,    23,    24,    96,
      44,    44,   -27,   -27,   210,   188,   189,     1,     2,     3,
       4,     5,     6,     7,     8,  -114,     9,  -114,  -114,  -114,
     148,    10,    11,    12,   229,    13,    14,   178,    86,    15,
      16,   192,    69,    70,    71,    17,    72,   179,   196,   200,
      18,    67,    19,    69,    70,    71,    20,    72,   101,     1,
       2,     3,     4,     5,     6,     7,     8,   197,     9,   113,
     202,   162,   223,    10,    11,    12,   213,    13,    14,   212,
      91,    15,    16,   225,   226,   230,   232,    17,   182,   126,
     207,    94,    18,   153,    19,   195,   209,   228,    20,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,   216,
     221,     0,     0,    10,    11,    12,     0,    13,    14,     0,
       0,    15,    16,     1,   140,     0,     0,    17,     6,     7,
       8,     0,    18,     0,   174,     0,     0,     0,    20,     0,
       0,     0,    14,     0,     0,    15,    16,     1,    56,     0,
       0,    17,     6,     7,     8,     0,    18,     0,     0,     0,
     181,     0,    20,     0,     0,     0,    14,     0,     0,    15,
      16,     1,    56,     0,     0,    17,     6,     7,     8,     0,
      18,     0,   125,     0,     0,     0,    20,     0,     0,     0,
      14,     0,     0,    15,    16,     1,    56,     0,     0,    17,
       6,     7,     8,     0,    18,    67,    68,    69,    70,    71,
      20,    72,     0,     0,    74,     0,   151,    15,    16,     1,
      76,     0,     0,    17,     6,     7,     8,     0,    18,    67,
      68,    69,    70,    71,    20,    72,     0,     0,    14,     0,
      86,    15,    16,     1,    81,     0,     0,    17,     6,     7,
       8,     0,    18,    67,    68,    69,    70,    71,    20,    72,
       0,     0,    14,     0,   222,    15,    16,     1,   108,     0,
       0,    17,     6,     7,     8,     0,    18,    67,    68,    69,
      70,    71,    20,    72,     0,     0,    14,    97,     0,    15,
      16,     1,   118,     0,     0,    17,     6,     7,     8,     0,
      18,    67,    68,    69,    70,    71,    20,    72,     0,     0,
      14,     0,     0,    15,    16,     1,   140,     0,     0,    17,
       6,     7,     8,     0,    18,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    14,     0,     0,    15,    16,     1,
     214,     0,     0,    17,     6,     7,     8,     0,    18,     0,
       0,     0,     0,     0,    20,     0,     0,     0,    14,     0,
       0,    15,    16,   131,   132,     0,     0,    17,     0,     0,
       0,     0,    18,     0,     0,     0,    66,     0,    20,    67,
      68,    69,    70,    71,     0,    72,    67,    68,    69,    70,
      71,     0,    72,     0,   133,   134,    67,    68,    69,    70,
      71,     0,    72,     0,    67,    68,    69,    70,    71,   117,
      72,     0,     0,     0,     0,   163,     0,   190,    67,    68,
      69,    70,    71,     0,    72
};

static const yytype_int16 yycheck[] =
{
      19,    13,    51,     0,     0,    44,    18,    24,    20,     4,
       5,   108,    36,    52,    72,    84,   145,    11,     4,   169,
     117,   118,    36,    16,    16,    16,    38,    24,    24,    41,
      42,   181,    44,    27,   184,    11,    27,    11,    50,    51,
      16,    16,     4,    60,    37,    37,    37,    64,    42,    42,
      42,    27,   206,    27,   204,    67,    68,    69,    70,    71,
      72,    37,    37,    60,    60,   219,    42,    64,    64,   198,
      27,     3,    84,    85,    30,   225,    32,    36,    16,   229,
     230,     0,    11,    95,    41,    23,    24,    16,     4,   138,
      27,    86,   150,   151,   163,   192,    36,    92,    27,    37,
     112,   113,   114,   115,   233,   126,   127,   128,    37,     3,
       4,   130,    43,    42,     8,     9,    10,     4,     5,   131,
     132,   133,   134,    40,    41,    19,   138,   139,    22,    43,
     179,    25,    26,    40,   146,    40,   148,    31,   150,   151,
      40,    41,    36,    44,    38,    36,   158,     4,    42,    11,
      11,   163,   161,   162,    16,   174,    39,   174,    16,    41,
      36,    23,    24,   202,    41,    27,    27,   179,    40,    27,
       4,   183,    27,   185,   213,    37,    37,   174,   174,    37,
      42,    42,    40,    41,   196,   150,   151,     3,     4,     5,
       6,     7,     8,     9,    10,    30,    12,    32,    33,    34,
      42,    17,    18,    19,   223,    21,    22,     4,    41,    25,
      26,     4,    32,    33,    34,    31,    36,    44,    29,    44,
      36,    30,    38,    32,    33,    34,    42,    36,    44,     3,
       4,     5,     6,     7,     8,     9,    10,    39,    12,    42,
      44,    32,    13,    17,    18,    19,    44,    21,    22,    39,
       4,    25,    26,    40,    40,    40,     8,    31,   139,    85,
     185,    53,    36,   112,    38,   163,   196,   222,    42,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,   202,
     208,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      -1,    25,    26,     3,     4,    -1,    -1,    31,     8,     9,
      10,    -1,    36,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    22,    -1,    -1,    25,    26,     3,     4,    -1,
      -1,    31,     8,     9,    10,    -1,    36,    -1,    -1,    -1,
      40,    -1,    42,    -1,    -1,    -1,    22,    -1,    -1,    25,
      26,     3,     4,    -1,    -1,    31,     8,     9,    10,    -1,
      36,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      22,    -1,    -1,    25,    26,     3,     4,    -1,    -1,    31,
       8,     9,    10,    -1,    36,    30,    31,    32,    33,    34,
      42,    36,    -1,    -1,    22,    -1,    41,    25,    26,     3,
       4,    -1,    -1,    31,     8,     9,    10,    -1,    36,    30,
      31,    32,    33,    34,    42,    36,    -1,    -1,    22,    -1,
      41,    25,    26,     3,     4,    -1,    -1,    31,     8,     9,
      10,    -1,    36,    30,    31,    32,    33,    34,    42,    36,
      -1,    -1,    22,    -1,    41,    25,    26,     3,     4,    -1,
      -1,    31,     8,     9,    10,    -1,    36,    30,    31,    32,
      33,    34,    42,    36,    -1,    -1,    22,    40,    -1,    25,
      26,     3,     4,    -1,    -1,    31,     8,     9,    10,    -1,
      36,    30,    31,    32,    33,    34,    42,    36,    -1,    -1,
      22,    -1,    -1,    25,    26,     3,     4,    -1,    -1,    31,
       8,     9,    10,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    22,    -1,    -1,    25,    26,     3,
       4,    -1,    -1,    31,     8,     9,    10,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    22,    -1,
      -1,    25,    26,    14,    15,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    20,    -1,    42,    30,
      31,    32,    33,    34,    -1,    36,    30,    31,    32,    33,
      34,    -1,    36,    -1,    45,    46,    30,    31,    32,    33,
      34,    -1,    36,    -1,    30,    31,    32,    33,    34,    43,
      36,    -1,    -1,    -1,    -1,    27,    -1,    43,    30,    31,
      32,    33,    34,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      17,    18,    19,    21,    22,    25,    26,    31,    36,    38,
      42,    48,    49,    50,    51,    52,    53,    60,    61,    63,
      65,    73,    79,    81,    82,    83,    86,    88,    11,    16,
      23,    24,    27,    37,    42,    69,     4,    70,    70,    70,
      36,    36,    36,     4,    56,    58,     4,    86,     3,    86,
      58,    74,    86,     0,    80,    49,    20,    30,    31,    32,
      33,    34,    36,    86,    22,    86,     4,    62,    86,     4,
      64,     4,    60,    86,    27,    27,    41,    78,    85,    86,
      85,     4,     5,    60,    56,    36,    37,    40,    49,    43,
      75,    44,    49,    86,    86,    86,    86,    86,     4,    68,
      86,    87,    27,    42,    11,    27,    43,    43,     4,    65,
      66,    67,    68,    86,     4,    38,    53,    71,    86,    70,
      40,    14,    15,    45,    46,    40,    37,    70,    44,    36,
       4,    54,    55,    86,     4,    39,    41,    76,    42,    69,
      41,    41,    40,    62,    86,    86,    86,    86,    27,    69,
      69,    30,    32,    27,     4,    72,    78,    78,    78,    58,
      86,    86,    86,    86,    38,    50,    51,    84,     4,    44,
      85,    40,    54,    27,    40,    41,    59,    86,    87,    87,
      43,    86,     4,    67,    67,    66,    29,    39,    84,    49,
      44,    85,    44,    84,    40,    86,    84,    55,    77,    71,
      86,    59,    39,    44,     4,    60,    88,    57,    59,    84,
      57,    76,    41,    13,    60,    40,    40,    57,    72,    58,
      40,    84,     8,    84,    84,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    53,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    55,
      56,    57,    58,    59,    60,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    71,    72,    72,    72,    73,    75,    74,    77,
      76,    76,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     1,     2,     2,     2,
       1,     2,     1,     1,     2,     1,     1,     1,     5,     8,
       7,     7,     2,     3,     3,     3,     1,     1,     3,     1,
       1,     1,     0,     0,     1,     1,     1,     3,     3,     3,
       3,     3,     5,     5,     1,     4,     4,     6,     1,     1,
       3,     1,     1,     3,     3,     2,     4,     3,     4,     2,
       4,     4,     3,     5,     3,     3,     3,     0,     3,     0,
       4,     0,     2,     0,     1,     1,     2,     0,     5,    10,
       9,     9,    11,     7,     3,     2,     1,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     4,
       3,     1,     0,     3,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     2,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 124 "mini_js.y"
         { print_prod("s -> cmds"); yyvsp[0].c = yyvsp[0].c + "." + funcoes; print_NPR(yyvsp[0].c); }
#line 1764 "y.tab.c"
    break;

  case 3:
#line 127 "mini_js.y"
                              { print_prod("cmds -> cmd_1 ; cmds"); yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1770 "y.tab.c"
    break;

  case 4:
#line 128 "mini_js.y"
                              { print_prod("cmds -> cmd_2 cmds"); yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1776 "y.tab.c"
    break;

  case 5:
#line 129 "mini_js.y"
                              { print_prod("cmds -> epsilon"); yyval.c = epsilon; }
#line 1782 "y.tab.c"
    break;

  case 6:
#line 132 "mini_js.y"
                      { print_prod("cmd_1 -> atr"); yyval.c = yyvsp[0].c + "^"; }
#line 1788 "y.tab.c"
    break;

  case 7:
#line 133 "mini_js.y"
                      { print_prod("cmd_1 -> LET decl"); yyval.c = yyvsp[0].c; }
#line 1794 "y.tab.c"
    break;

  case 8:
#line 134 "mini_js.y"
                      { print_prod("cmd_1 -> VAR decl"); yyval.c = yyvsp[0].c; }
#line 1800 "y.tab.c"
    break;

  case 9:
#line 135 "mini_js.y"
                      { print_prod("cmd_1 -> CONST decl"); yyval.c = yyvsp[0].c; }
#line 1806 "y.tab.c"
    break;

  case 10:
#line 136 "mini_js.y"
                      { print_prod("cmd_1 -> loop"); }
#line 1812 "y.tab.c"
    break;

  case 11:
#line 137 "mini_js.y"
                      { print_prod("cmd_1 -> exp ASM"); yyval.c = yyvsp[-1].c + yyvsp[0].c + "^"; }
#line 1818 "y.tab.c"
    break;

  case 12:
#line 138 "mini_js.y"
                      { print_prod("cmd_1 -> exp"); yyval.c = yyvsp[0].c + "^"; }
#line 1824 "y.tab.c"
    break;

  case 13:
#line 139 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        yyval.c = gera_retorno(); 
                      }
#line 1836 "y.tab.c"
    break;

  case 14:
#line 146 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN exp"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        yyval.c = yyvsp[0].c + gera_retorno(); 
                      }
#line 1848 "y.tab.c"
    break;

  case 15:
#line 155 "mini_js.y"
                          { print_prod("cmd_2 -> condicional"); }
#line 1854 "y.tab.c"
    break;

  case 16:
#line 156 "mini_js.y"
                          { print_prod("cmd_2 -> funcao"); }
#line 1860 "y.tab.c"
    break;

  case 17:
#line 157 "mini_js.y"
                          { print_prod("cmd_2 -> bloco"); }
#line 1866 "y.tab.c"
    break;

  case 18:
#line 160 "mini_js.y"
                                                     { print_prod("bloco -> { empilha_escopo cmds } desempilha_escopo"); yyval.c = "<{" + yyvsp[-2].c + "}>"; }
#line 1872 "y.tab.c"
    break;

  case 19:
#line 163 "mini_js.y"
                                                                                   { 
                                          print_prod("funcao -> FUNCTION ID ( args ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-6].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-3].c + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-6].v, fim_func);
                                        }
#line 1883 "y.tab.c"
    break;

  case 20:
#line 169 "mini_js.y"
                                                                         {
                                          print_prod("funcao -> FUNCTION ID ( ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-5].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-5].v, fim_func);
                                        }
#line 1894 "y.tab.c"
    break;

  case 21:
#line 175 "mini_js.y"
                                                                           {
                                          print_prod("funcao -> FUNCTION ( args ) corpo"); 
                                          string fim_func = gera_label("anonima"); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-3].c + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao("anonima", fim_func);
                                        }
#line 1905 "y.tab.c"
    break;

  case 22:
#line 181 "mini_js.y"
                        { print_prod("funcao -> ID LAMBDA_NOVO_OBJ"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1913 "y.tab.c"
    break;

  case 23:
#line 184 "mini_js.y"
                        { print_prod("funcao -> ID ARROW BLOCO"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1921 "y.tab.c"
    break;

  case 24:
#line 187 "mini_js.y"
                        { print_prod("funcao -> ID ARROW exp"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1929 "y.tab.c"
    break;

  case 25:
#line 192 "mini_js.y"
                   { print_prod("args -> args , arg"); 
                      atualiza_variaveis_declaradas_escopo(yyvsp[0].v);
                      yyval.v = "";
                      yyval.n_args = yyvsp[-2].n_args + 1; 
                      yyval.c = yyvsp[-2].c + gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                  }
#line 1940 "y.tab.c"
    break;

  case 26:
#line 198 "mini_js.y"
                   { print_prod("args -> arg"); 
                     atualiza_variaveis_declaradas_escopo(yyvsp[0].v);
                     yyval.v = "";
                     yyval.n_args = 1;
                     yyval.c = gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                   }
#line 1951 "y.tab.c"
    break;

  case 27:
#line 206 "mini_js.y"
        { print_prod("arg -> ID");
          yyval.v = yyvsp[0].v;
          yyval.c = yyvsp[0].c;
          yyval.n_args = 1;
        }
#line 1961 "y.tab.c"
    break;

  case 28:
#line 211 "mini_js.y"
                 { print_prod("arg -> ID = exp");
                 yyval.v = yyvsp[-2].v;
                 yyval.c = yyvsp[-2].c + yyvsp[0].c + gera_inicializacao_de_argumento(yyvsp[-2].v, yyval.n_args);
                 yyval.n_args = 1;
               }
#line 1971 "y.tab.c"
    break;

  case 29:
#line 216 "mini_js.y"
          { print_prod("arg -> exp");
            yyval.v = yyvsp[0].v;
            yyval.c = yyvsp[0].c;
            yyval.n_args = 1;
          }
#line 1981 "y.tab.c"
    break;

  case 30:
#line 223 "mini_js.y"
                                    { print_prod("empilha_escopo_func -> empilha_escopo"); pode_retornar.push_back(true); }
#line 1987 "y.tab.c"
    break;

  case 31:
#line 226 "mini_js.y"
                                          { print_prod("desempilha_escopo_func -> desempilha_escopo"); pode_retornar.pop_back(); }
#line 1993 "y.tab.c"
    break;

  case 32:
#line 229 "mini_js.y"
                { print_prod("empilha_escopo -> "); ts.push_back(map<string, Simbolo>{}); eh_escopo = true; }
#line 1999 "y.tab.c"
    break;

  case 33:
#line 232 "mini_js.y"
                   { print_prod("desempilha_escopo -> "); ts.pop_back(); variaveis_declaradas_escopo.clear(); eh_escopo = false; }
#line 2005 "y.tab.c"
    break;

  case 34:
#line 235 "mini_js.y"
                    { print_prod("atr -> atr_id"); }
#line 2011 "y.tab.c"
    break;

  case 35:
#line 236 "mini_js.y"
                    { print_prod("atr -> atr_obj"); }
#line 2017 "y.tab.c"
    break;

  case 36:
#line 237 "mini_js.y"
                    { print_prod("atr -> atr_array"); }
#line 2023 "y.tab.c"
    break;

  case 37:
#line 240 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 2029 "y.tab.c"
    break;

  case 38:
#line 241 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 2035 "y.tab.c"
    break;

  case 39:
#line 242 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID ADD exp_id"); yyval.c = to_vector(yyvsp[-2].v) + to_vector(yyvsp[-2].v) + "@" + yyvsp[0].c + "+" + "="; }
#line 2041 "y.tab.c"
    break;

  case 40:
#line 246 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "=" + "^" + to_vector(yyvsp[-2].v) + "@"; }
#line 2047 "y.tab.c"
    break;

  case 41:
#line 247 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 2053 "y.tab.c"
    break;

  case 42:
#line 250 "mini_js.y"
                                 { verifica_variaveis_declaradas(yyvsp[-4].v); print_prod("atr_obj -> ID . prop = exp"); yyval.c = to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2059 "y.tab.c"
    break;

  case 43:
#line 251 "mini_js.y"
                                 { verifica_variaveis_declaradas(yyvsp[-4].v); print_prod("atr_obj -> ID . prop ADD exp"); yyval.c = to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + "[@]" + yyvsp[0].c + "+" + "[=]"; }
#line 2065 "y.tab.c"
    break;

  case 44:
#line 254 "mini_js.y"
                    { print_prod("prop -> ID"); }
#line 2071 "y.tab.c"
    break;

  case 45:
#line 255 "mini_js.y"
                    { print_prod("prop -> ID [ exp ]"); yyval.c = to_vector(yyvsp[-3].v) + "[@]" + yyvsp[-1].c; }
#line 2077 "y.tab.c"
    break;

  case 46:
#line 258 "mini_js.y"
                                  { verifica_variaveis_declaradas(yyvsp[-3].v); print_prod("atr_array -> ID indices = exp"); yyval.c = to_vector(yyvsp[-3].v) + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2083 "y.tab.c"
    break;

  case 47:
#line 259 "mini_js.y"
                                  { verifica_variaveis_declaradas(yyvsp[-5].v); print_prod("atr_array -> ID [ atr ] = exp"); yyval.c = to_vector(yyvsp[-5].v) + "@" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 2089 "y.tab.c"
    break;

  case 48:
#line 262 "mini_js.y"
                  { print_prod("rec -> ID indices = exp"); }
#line 2095 "y.tab.c"
    break;

  case 49:
#line 263 "mini_js.y"
                  { print_prod("rec -> matexp"); }
#line 2101 "y.tab.c"
    break;

  case 50:
#line 264 "mini_js.y"
                  { print_prod("rec -> exp = rec"); yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 2107 "y.tab.c"
    break;

  case 51:
#line 265 "mini_js.y"
                  { print_prod("rec -> atr_array"); }
#line 2113 "y.tab.c"
    break;

  case 52:
#line 268 "mini_js.y"
                        { print_prod("matexp -> matrix"); }
#line 2119 "y.tab.c"
    break;

  case 53:
#line 269 "mini_js.y"
                        { print_prod("matexp -> matexp * matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "[@]" + "*"; }
#line 2125 "y.tab.c"
    break;

  case 54:
#line 270 "mini_js.y"
                        { print_prod("matexp -> matexp + matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "+"; }
#line 2131 "y.tab.c"
    break;

  case 55:
#line 273 "mini_js.y"
                    { print_prod("matrix -> ID indices"); yyval.c = to_vector(yyvsp[-1].v) + "@" + yyvsp[0].c; }
#line 2137 "y.tab.c"
    break;

  case 56:
#line 276 "mini_js.y"
                             { print_prod("indices -> [ exp ] indices"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c; }
#line 2143 "y.tab.c"
    break;

  case 57:
#line 277 "mini_js.y"
                             { print_prod("indices -> [ exp ]"); yyval.c = yyvsp[-1].c; }
#line 2149 "y.tab.c"
    break;

  case 58:
#line 280 "mini_js.y"
                          { if(eh_escopo) atualiza_variaveis_declaradas_escopo(yyvsp[-3].v); else atualiza_variaveis_declaradas(yyvsp[-3].v); print_prod("decl -> ID = exp fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + yyvsp[-1].c + "=" + "^" + yyvsp[0].c; }
#line 2155 "y.tab.c"
    break;

  case 59:
#line 281 "mini_js.y"
                          { if(eh_escopo) atualiza_variaveis_declaradas_escopo(yyvsp[-1].v); else atualiza_variaveis_declaradas(yyvsp[-1].v);  print_prod("decl -> ID fim_decl"); yyval.c = to_vector(yyvsp[-1].v) + "&" + yyvsp[0].c; }
#line 2161 "y.tab.c"
    break;

  case 60:
#line 282 "mini_js.y"
                                 { print_prod("decl -> funcao fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + yyvsp[-1].c + yyvsp[0].c; }
#line 2167 "y.tab.c"
    break;

  case 61:
#line 283 "mini_js.y"
                                 { print_prod("decl -> ID = { corpo_obj } fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + "{}" + yyvsp[-1].c + "=" + "^"; }
#line 2173 "y.tab.c"
    break;

  case 62:
#line 286 "mini_js.y"
                          { print_prod("objeto -> { corpo_obj }"); yyval.c = yyvsp[-1].c; }
#line 2179 "y.tab.c"
    break;

  case 63:
#line 289 "mini_js.y"
                                    { print_prod("corpo_obj -> ID : exp , corpo_obj"); yyval.c = to_vector(yyvsp[-4].v) + yyvsp[-2].c + "[<=]" + yyvsp[0].c; }
#line 2185 "y.tab.c"
    break;

  case 64:
#line 290 "mini_js.y"
                                 { print_prod("corpo_obj -> ID : exp ,"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "[<=]"; }
#line 2191 "y.tab.c"
    break;

  case 65:
#line 291 "mini_js.y"
                                    { print_prod("corpo_obj -> ID : objeto"); yyval.c = to_vector(yyvsp[-2].v) + "{}" + yyvsp[0].c + "[<=]"; }
#line 2197 "y.tab.c"
    break;

  case 66:
#line 294 "mini_js.y"
                             { print_prod("array -> [ corpo_array ]"); yyval.c = yyvsp[-1].c; }
#line 2203 "y.tab.c"
    break;

  case 67:
#line 298 "mini_js.y"
                  { posicoes++; }
#line 2209 "y.tab.c"
    break;

  case 68:
#line 298 "mini_js.y"
                                             { yyval.c = to_vector("0") + yyvsp[-2].c + "[<=]" + yyvsp[0].c; yyvsp[-2].c.clear(); yyvsp[-1].c.clear(); yyvsp[0].c.clear(); posicoes = 0; }
#line 2215 "y.tab.c"
    break;

  case 69:
#line 300 "mini_js.y"
                     { print_prod("exps_array -> , exp"); yyvsp[-1].c = to_vector(to_string(posicoes)) + yyvsp[0].c + "[<=]"; posicoes++; }
#line 2221 "y.tab.c"
    break;

  case 70:
#line 300 "mini_js.y"
                                                                                                                                          { yyval.c = yyvsp[-3].c + yyvsp[0].c; }
#line 2227 "y.tab.c"
    break;

  case 71:
#line 301 "mini_js.y"
    { print_prod("exps_array -> epsilon"); }
#line 2233 "y.tab.c"
    break;

  case 72:
#line 304 "mini_js.y"
                       { print_prod("fim_decl -> , decl"); yyval.c = yyvsp[0].c; }
#line 2239 "y.tab.c"
    break;

  case 73:
#line 305 "mini_js.y"
                       { print_prod("fim_decl -> epsilon"); yyval.c = epsilon; }
#line 2245 "y.tab.c"
    break;

  case 74:
#line 308 "mini_js.y"
                        { print_prod("loop -> while_loop"); }
#line 2251 "y.tab.c"
    break;

  case 75:
#line 309 "mini_js.y"
                        { print_prod("loop -> for_loop"); }
#line 2257 "y.tab.c"
    break;

  case 76:
#line 312 "mini_js.y"
                                { print_prod("separador -> separador ;"); }
#line 2263 "y.tab.c"
    break;

  case 77:
#line 313 "mini_js.y"
                                { print_prod("separador -> epsilon"); yyval.c = epsilon; }
#line 2269 "y.tab.c"
    break;

  case 78:
#line 316 "mini_js.y"
                                         { print_prod("while_loop -> WHILE ( condicao ) corpo"); string inicio_while = gera_label("inicio_while"); string fim_while = gera_label("fim_while"); yyval.c = (":" + inicio_while) + yyvsp[-2].c + "!" + fim_while + "?" + yyvsp[0].c + inicio_while + "#" + (":" + fim_while); }
#line 2275 "y.tab.c"
    break;

  case 79:
#line 319 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2281 "y.tab.c"
    break;

  case 80:
#line 320 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + "^" + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2287 "y.tab.c"
    break;

  case 81:
#line 321 "mini_js.y"
                                                        { print_prod("for_loop -> FOR ( decl ; condicao ; val ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + "^" + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + "^" + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2293 "y.tab.c"
    break;

  case 82:
#line 324 "mini_js.y"
                                                                                                                     { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); string else_label = gera_label("else"); string fim_if = gera_label("fim_if"); yyval.c = yyvsp[-8].c + "!" + else_label + "?" + yyvsp[-5].c + fim_if + "#" + (":" + else_label) + yyvsp[-1].c + (":" + fim_if); }
#line 2299 "y.tab.c"
    break;

  case 83:
#line 325 "mini_js.y"
                                                                                          { print_prod("condicional -> IF (condicao) corpo"); string fim_if = gera_label("fim_if"); yyval.c = yyvsp[-4].c + "!" + fim_if + "?" + yyvsp[-1].c + (":" + fim_if);}
#line 2305 "y.tab.c"
    break;

  case 84:
#line 328 "mini_js.y"
                              { print_prod("corpo -> { cmds }"); yyval.c = yyvsp[-1].c; }
#line 2311 "y.tab.c"
    break;

  case 85:
#line 329 "mini_js.y"
                              { print_prod("corpo -> cmd_1 ;"); }
#line 2317 "y.tab.c"
    break;

  case 86:
#line 330 "mini_js.y"
                              { print_prod("corpo -> cmd_2"); }
#line 2323 "y.tab.c"
    break;

  case 87:
#line 333 "mini_js.y"
                        { print_prod("condicao -> exp > exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 2329 "y.tab.c"
    break;

  case 88:
#line 334 "mini_js.y"
                        { print_prod("condicao -> exp < exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 2335 "y.tab.c"
    break;

  case 89:
#line 335 "mini_js.y"
                        { print_prod("condicao -> exp IGUAL exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 2341 "y.tab.c"
    break;

  case 90:
#line 336 "mini_js.y"
                        { print_prod("condicao -> exp DIF exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "!="; }
#line 2347 "y.tab.c"
    break;

  case 91:
#line 337 "mini_js.y"
                        { print_prod("condicao -> exp"); yyval.c = yyvsp[0].c; }
#line 2353 "y.tab.c"
    break;

  case 92:
#line 340 "mini_js.y"
                        { print_prod("exp -> exp + exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 2359 "y.tab.c"
    break;

  case 93:
#line 341 "mini_js.y"
                        { print_prod("exp -> exp - exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 2365 "y.tab.c"
    break;

  case 94:
#line 342 "mini_js.y"
                        { print_prod("exp -> exp * exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 2371 "y.tab.c"
    break;

  case 95:
#line 343 "mini_js.y"
                        { print_prod("exp -> exp / exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 2377 "y.tab.c"
    break;

  case 96:
#line 344 "mini_js.y"
                        { print_prod("exp -> exp % exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 2383 "y.tab.c"
    break;

  case 97:
#line 345 "mini_js.y"
                        { print_prod("exp -> ID . ID"); yyval.c = to_vector(yyvsp[-2].v) + "@" + yyvsp[0].c + "[@]"; }
#line 2389 "y.tab.c"
    break;

  case 98:
#line 346 "mini_js.y"
                        { print_prod("exp -> val"); }
#line 2395 "y.tab.c"
    break;

  case 99:
#line 347 "mini_js.y"
                        { print_prod("exp -> exp ( params )"); yyval.c = yyvsp[-1].c + to_string(n_params) + yyvsp[-3].c + "$"; n_params = 0;}
#line 2401 "y.tab.c"
    break;

  case 100:
#line 350 "mini_js.y"
                       { print_prod("params -> exp , params"); yyval.c = yyvsp[-2].c + yyvsp[0].c; n_params++; }
#line 2407 "y.tab.c"
    break;

  case 101:
#line 351 "mini_js.y"
                       { print_prod("params -> exp"); yyval.c = yyvsp[0].c; n_params++; }
#line 2413 "y.tab.c"
    break;

  case 102:
#line 352 "mini_js.y"
                       { print_prod("params -> epsilon"); yyval.c = epsilon; }
#line 2419 "y.tab.c"
    break;

  case 103:
#line 353 "mini_js.y"
                       { print_prod("params -> matrix , params"); yyval.c = yyvsp[-2].c + yyvsp[0].c; n_params++; }
#line 2425 "y.tab.c"
    break;

  case 104:
#line 356 "mini_js.y"
                { print_prod("val -> TRUE"); yyval.c = to_vector(yyvsp[0].v); }
#line 2431 "y.tab.c"
    break;

  case 105:
#line 357 "mini_js.y"
                 { print_prod("val -> FALSE"); yyval.c = to_vector(yyvsp[0].v); }
#line 2437 "y.tab.c"
    break;

  case 106:
#line 358 "mini_js.y"
                { print_prod("val -> ID"); yyval.c = to_vector(yyvsp[0].v) + "@"; }
#line 2443 "y.tab.c"
    break;

  case 107:
#line 359 "mini_js.y"
                  { print_prod("val -> NUM"); }
#line 2449 "y.tab.c"
    break;

  case 108:
#line 360 "mini_js.y"
                  { print_prod("val -> - NUM"); yyval.c = to_vector("0") + yyvsp[0].c + "-" ; }
#line 2455 "y.tab.c"
    break;

  case 109:
#line 361 "mini_js.y"
                  { print_prod("val -> ( exp )"); yyval = yyvsp[-1]; }
#line 2461 "y.tab.c"
    break;

  case 110:
#line 362 "mini_js.y"
                  { print_prod("val -> OBJ"); }
#line 2467 "y.tab.c"
    break;

  case 111:
#line 363 "mini_js.y"
                  { print_prod("val -> ARRAY"); }
#line 2473 "y.tab.c"
    break;

  case 112:
#line 364 "mini_js.y"
                  { print_prod("val -> STRING"); }
#line 2479 "y.tab.c"
    break;

  case 113:
#line 365 "mini_js.y"
                  { print_prod("val -> ID INC"); yyval.c = to_vector(yyvsp[-1].v) + "@" + to_vector(yyvsp[-1].v) + to_vector(yyvsp[-1].v) + "@" + "1" + "+" + "=" + "^"; }
#line 2485 "y.tab.c"
    break;

  case 114:
#line 366 "mini_js.y"
                  { print_prod("val -> BLOCO VAZIO"); }
#line 2491 "y.tab.c"
    break;

  case 115:
#line 367 "mini_js.y"
                  { print_prod("val -> array"); yyval.c = "[]" + yyvsp[0].c; }
#line 2497 "y.tab.c"
    break;


#line 2501 "y.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 370 "mini_js.y"


// Include do arquivo do lex - integracao
#include "lex.yy.c"

auto f = &yyunput;

void yyerror(const char* st) {
   puts(st); 
   printf("Proximo a: %s na linha %d, coluna %d\n", yytext, yylloc.first_line, yylloc.first_column);
   exit(1);
}

void print_NPR(vector<string> c) {
  c = resolve_enderecos(c);  
  for (string s : c) { 
    cout << s + " "; 
  } 
  cout << endl;
}

void print_prod(const char *s) {
  cout << s << endl;
}

vector<string> gera_retorno() {
  return to_vector("'&retorno'") + "@" + "~";
}

vector<string> gera_fim_funcao() {
  return to_vector("undefined") + "@" + "'&retorno'" + "@" + "~";
}

vector<string> gera_inicializacao_de_argumento(string id, int n_args) {
  int indice = n_args - 1;
  return to_vector(id) + "&" + id + "arguments" + "@" + to_string(indice) + "[@]" + "=" + "^";
}

vector<string> gera_funcao(string id, string label) {
  if (id == "anonima") return to_vector("{}") + "=" + "'&funcao'" + label + "[=]" + "^";
  return to_vector(id) + "&" + id + "{}" + "=" + "'&funcao'" + label + "[=]" + "^";
}

void atualiza_variaveis_declaradas(string var) {
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    variaveis_declaradas[var] = yylloc.first_line;
  } else {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas[var] << "." << endl;
    exit(1);
  }
}

void atualiza_variaveis_declaradas_escopo(string var) {
  auto it = variaveis_declaradas_escopo.find(var);

  if (it == variaveis_declaradas_escopo.end()) {
    variaveis_declaradas_escopo[var] = yylloc.first_line;
  } else {
    cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas_escopo[var] << "." << endl;
    exit(1);
  }
}

void verifica_variaveis_declaradas(string var) {

  if (!eh_escopo) {
    auto it = variaveis_declaradas.find(var);

    if (it == variaveis_declaradas.end()) {
      cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
      exit(1);
    }
  } else {
    auto it = variaveis_declaradas_escopo.find(var);

    if (it == variaveis_declaradas_escopo.end()) {
      cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
      exit(1);
    }
  }
}

vector<string> to_vector(string s) {
  vector<string> v;
  string aux = "";
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      v.push_back(aux);
      aux = "";
    } else {
      aux += s[i];
    }
  }
  v.push_back(aux);
  return v;
}

vector<string> concatena(vector<string> a, vector<string> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}

vector<string> operator+(vector<string> a, vector<string> b) {
  return concatena(a, b);
}

vector<string> operator+(vector<string> a, string b) {
  a.push_back(b);
  return a;
}

vector<string> operator+(string a, vector<string> b) {
  return epsilon + a + b;
}

string trim(string s, string chars) {
  string result;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != chars[0] && s[i] != chars[1]) {
      result += s[i];
    }
  }
  return result;
}

vector<string> tokeniza(string s) {
  string s1 = trim(s, "{}");
  vector<string> v;
  string aux = "";
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == ' ') {
      v.push_back(aux);
      aux = "";
    } else {
      aux += s1[i];
    }
  }
  v.push_back(aux);
  return v;
}

void atualiza_atributos_token(int token) {
  yylval.v = yytext;
  yylval.c.clear();
  yylval.c.push_back(yytext);
  // cout << 'Token: ' << token << "|" << yytext << "|" << endl;
}

string gera_label(string prefixo) {
  static int n = 0;
  return prefixo + "_" + to_string(++n) + ":";
}

vector<string> resolve_enderecos(vector<string> entrada) {
  map<string,int> label;
  vector<string> saida;

  for(int i = 0; i < entrada.size(); i++) 
    if(entrada[i][0] == ':') 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back(entrada[i]);
  
  for(int i = 0; i < saida.size(); i++) 
    if(label.count(saida[i]) > 0)
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

int main(int argc, char* argv[]) {
  yyparse();
  
  return 0;
}
