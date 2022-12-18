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


#line 147 "y.tab.c"

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
    ARROW = 279
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
#define YYFINAL  55
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   523

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

#define YYUNDEFTOK  2
#define YYMAXUTOK   279


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
       2,     2,     2,     2,     2,     2,     2,    32,     2,     2,
      34,    38,    30,    28,    39,    29,    35,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,    42,
      44,    25,    43,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   124,   125,   126,   129,   130,   131,   132,
     133,   134,   135,   136,   143,   152,   153,   154,   157,   160,
     166,   172,   175,   178,   183,   189,   197,   202,   207,   214,
     217,   220,   223,   226,   227,   228,   231,   232,   233,   237,
     238,   241,   242,   245,   246,   249,   250,   253,   254,   255,
     256,   259,   260,   261,   264,   267,   268,   271,   272,   273,
     274,   277,   280,   281,   282,   285,   286,   289,   290,   293,
     294,   297,   300,   301,   302,   305,   306,   309,   310,   311,
     314,   315,   316,   317,   318,   321,   322,   323,   324,   325,
     326,   327,   328,   331,   332,   333,   334,   337,   338,   339,
     340,   341,   342,   343,   344,   345
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
  "ARROW", "'='", "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'T'",
  "'('", "'.'", "'{'", "'}'", "')'", "','", "'['", "']'", "';'", "'>'",
  "'<'", "$accept", "s", "cmds", "cmd_1", "cmd_2", "bloco", "funcao",
  "args", "arg", "empilha_escopo_func", "desempilha_escopo_func",
  "empilha_escopo", "desempilha_escopo", "atr", "atr_id", "atr_recursiva",
  "atr_obj", "prop", "atr_array", "rec", "matexp", "matrix", "indices",
  "decl", "objeto", "corpo_obj", "fim_decl", "loop", "separador",
  "while_loop", "for_loop", "condicional", "corpo", "condicao", "exp",
  "params", "val", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    63,    58,    43,    45,
      42,    47,    37,    84,    40,    46,   123,   125,    41,    44,
      91,    93,    59,    62,    60
};
# endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-106)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     232,  -122,   406,    11,    11,    11,  -122,  -122,  -122,   -15,
      18,    25,    22,   288,  -122,    33,   288,  -122,    65,  -122,
    -122,   232,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,   404,  -122,   288,  -122,  -122,   303,   311,    64,
     320,    79,    28,  -122,  -122,  -122,   288,   288,    70,  -122,
       0,   489,  -122,   471,   232,  -122,   174,  -122,  -122,   288,
     288,   288,   288,   288,   343,   181,    75,   489,     4,  -122,
     489,     3,    89,    62,    30,   419,   352,   135,    11,  -122,
      57,   384,    82,    61,    11,    71,    94,  -122,   129,  -122,
      98,  -122,  -122,   121,   121,   103,   103,   103,    -3,   109,
     435,   102,   311,   288,   288,   288,   131,   122,    26,  -122,
    -122,    97,  -122,   482,    46,   159,   126,   126,   447,  -122,
    -122,   288,   288,   288,   288,   266,   163,   128,   288,   196,
    -122,  -122,   288,  -122,   343,   343,  -122,  -122,   489,   427,
     181,   489,   288,  -122,    79,   164,   164,   352,   145,   137,
    -122,  -122,  -122,   266,   489,   489,   489,   489,   232,   133,
    -122,  -122,   147,   288,   143,   182,   266,    -8,  -122,   489,
    -122,  -122,  -122,  -122,   489,   122,   158,  -122,  -122,   223,
    -122,  -122,   152,  -122,   148,   360,   288,  -122,   266,   375,
    -122,   459,   184,  -122,   190,   101,   176,   185,   489,  -122,
    -122,  -122,  -122,   159,  -122,   186,   266,   193,  -122,  -122,
     266,   266,  -122,  -122,  -122,  -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    98,    97,     0,     0,     0,   101,   102,   103,     0,
       0,     0,     0,    13,   105,     0,     0,    31,     0,     2,
      70,     5,    17,    16,     6,    33,    34,    35,    10,    67,
      68,    15,    12,    91,     0,   104,    21,     0,     0,     0,
       0,     0,    66,     7,     8,     9,     0,     0,     0,    31,
      97,    14,    99,     0,     5,     1,     5,     4,    11,     0,
       0,     0,     0,     0,    95,    38,    22,    23,    97,    37,
      36,    90,     0,    97,     0,     0,     0,     0,     0,    58,
       0,    84,     0,     0,     0,     0,     0,    29,     0,   100,
       0,    69,     3,    85,    86,    87,    88,    89,    97,     0,
      94,     0,     0,     0,     0,     0,     0,    56,    97,    50,
      45,    48,    51,    47,    97,     0,    66,    66,    66,    65,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    32,     0,    54,    95,    95,    92,    40,    39,     0,
      42,    41,     0,    55,    54,     0,     0,     0,     0,     0,
      59,    60,    57,     0,    82,    83,    80,    81,     5,     0,
      79,    71,    43,     0,     0,    97,     0,     0,    25,    28,
      18,    96,    93,    44,    46,     0,    53,    52,    49,     0,
      61,    32,     0,    78,     0,     0,     0,    32,     0,     0,
      64,    63,    76,    77,     0,    97,     0,     0,    27,    20,
      30,    32,    24,     0,    31,     0,     0,     0,    19,    62,
       0,     0,    73,    74,    32,    72,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -122,  -122,   -16,     1,     2,  -122,   125,  -122,    39,  -122,
      21,   -43,  -121,   -36,  -122,   117,  -122,  -122,   -65,    96,
     -62,   -55,   -90,    40,    50,    43,    14,  -122,  -122,  -122,
    -122,  -122,  -112,   -40,   -13,    12,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,   159,   160,    22,    23,   167,   168,    86,
     199,    54,   200,    24,    25,    69,    26,    72,    27,   110,
     111,   112,    41,    43,   117,   149,    79,    28,    56,    29,
      30,    31,   161,    80,    32,   101,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    20,    21,    53,    74,    57,    87,    82,   133,    99,
     170,   109,    85,    35,   -43,    42,    35,   143,   144,    46,
      35,    65,    20,    21,    67,    70,    49,    75,   -43,   102,
     188,   189,    88,    81,    81,    88,    52,   132,    90,    88,
      92,   181,    35,   103,    44,    45,    93,    94,    95,    96,
      97,   100,    47,    77,   187,    20,    21,    20,    21,    48,
     192,    88,    35,   113,   118,    55,    40,    78,    71,    36,
      37,   106,    34,    34,    83,    84,   201,   153,    35,    99,
      99,    88,   109,   176,   177,   133,    38,    38,   164,   138,
     139,   140,   141,   216,   212,   120,   126,    39,   214,   215,
     104,    40,    40,  -105,    76,  -105,  -105,  -105,   154,   155,
     156,   157,    34,   128,   105,    81,   169,    35,   119,    75,
     125,   100,   100,   184,   127,   145,    38,   146,   129,   174,
     150,   151,   152,   130,   113,   131,   126,    64,     1,   114,
     136,    40,   182,     6,     7,     8,   171,   172,   134,   196,
      81,    61,    62,    63,    12,    64,   142,    14,   205,    20,
      21,   210,   132,   148,    15,    78,   191,   162,   175,    16,
     163,   115,   179,   198,   180,   183,   169,     1,     2,     3,
       4,     5,     6,     7,     8,   185,     9,   103,   146,   193,
     194,    10,    11,    12,    83,    13,    14,   204,    35,     1,
     165,   213,   116,    15,     6,     7,     8,   186,    16,    59,
      17,    61,    62,    63,   206,    64,    91,    88,    14,   137,
     -26,   -26,   208,   207,   211,    15,     1,    50,   202,   190,
      16,     6,     7,     8,   166,     1,     2,     3,     4,     5,
       6,     7,     8,   178,     9,    14,   209,     0,   197,    10,
      11,    12,    15,    13,    14,     0,     0,    16,     0,   115,
       0,    15,     0,     0,     0,     0,    16,     0,    17,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,    10,    11,    12,     0,    13,    14,     0,
       0,     1,    50,     0,     0,    15,     6,     7,     8,     0,
      16,     0,   158,     0,     0,     0,     1,    50,     0,     0,
      14,     6,     7,     8,     1,    68,     0,    15,     0,     6,
       7,     8,    16,     1,    73,    66,     0,     0,     6,     7,
       8,     0,    15,    14,     0,     0,     0,    16,     0,     0,
      15,     0,    14,     0,     0,    16,     1,    98,     0,    15,
       0,     6,     7,     8,    16,     1,   108,     0,     0,     0,
       6,     7,     8,     1,   195,    14,     0,     0,     6,     7,
       8,     0,    15,     0,    14,     0,     0,    16,     1,   165,
       0,    15,    14,     6,     7,     8,    16,     0,     0,    15,
       0,     0,     0,     0,    16,     0,     0,    14,   121,   122,
       0,     0,     0,     0,    15,     0,     0,     0,     0,    16,
       0,     0,    59,    60,    61,    62,    63,    34,    64,     0,
       0,     0,    35,     0,    58,     0,     0,   123,   124,    36,
      37,    38,    59,    60,    61,    62,    63,     0,    64,     0,
       0,    39,     0,     0,     0,     0,    40,    59,    60,    61,
      62,    63,     0,    64,     0,    59,    60,    61,    62,    63,
     107,    64,     0,    59,    60,    61,    62,    63,   173,    64,
       0,     0,     0,     0,   135,    59,    60,    61,    62,    63,
       0,    64,     0,     0,     0,     0,    78,    59,    60,    61,
      62,    63,     0,    64,     0,     0,     0,     0,   203,    59,
      60,    61,    62,    63,     0,    64,     0,   147,     0,    89,
      59,    60,    61,    62,    63,     0,    64,    59,    60,    61,
      62,    63,     0,    64
};

static const yytype_int16 yycheck[] =
{
      13,     0,     0,    16,    40,    21,    49,    47,    98,    64,
     131,    76,    48,    16,    11,     4,    16,   107,   108,    34,
      16,    34,    21,    21,    37,    38,     4,    40,    25,    25,
      38,    39,    35,    46,    47,    35,     3,    40,    54,    35,
      56,   153,    16,    40,     4,     5,    59,    60,    61,    62,
      63,    64,    34,    25,   166,    54,    54,    56,    56,    34,
     181,    35,    16,    76,    77,     0,    40,    39,     4,    23,
      24,    41,    11,    11,     4,     5,   188,   120,    16,   134,
     135,    35,   147,   145,   146,   175,    25,    25,   128,   102,
     103,   104,   105,   214,   206,    38,    35,    35,   210,   211,
      11,    40,    40,    28,    25,    30,    31,    32,   121,   122,
     123,   124,    11,    42,    25,   128,   129,    16,    78,   132,
      38,   134,   135,   163,    84,    28,    25,    30,    34,   142,
     116,   117,   118,     4,   147,    37,    35,    34,     3,     4,
      38,    40,   158,     8,     9,    10,   134,   135,    39,   185,
     163,    30,    31,    32,    19,    34,    25,    22,   194,   158,
     158,   204,    40,     4,    29,    39,   179,     4,     4,    34,
      42,    36,    27,   186,    37,    42,   189,     3,     4,     5,
       6,     7,     8,     9,    10,    42,    12,    40,    30,    37,
      42,    17,    18,    19,     4,    21,    22,    13,    16,     3,
       4,     8,    77,    29,     8,     9,    10,    25,    34,    28,
      36,    30,    31,    32,    38,    34,    42,    35,    22,   102,
      38,    39,   201,    38,    38,    29,     3,     4,   189,   179,
      34,     8,     9,    10,    38,     3,     4,     5,     6,     7,
       8,     9,    10,   147,    12,    22,   203,    -1,   185,    17,
      18,    19,    29,    21,    22,    -1,    -1,    34,    -1,    36,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    -1,
      -1,     3,     4,    -1,    -1,    29,     8,     9,    10,    -1,
      34,    -1,    36,    -1,    -1,    -1,     3,     4,    -1,    -1,
      22,     8,     9,    10,     3,     4,    -1,    29,    -1,     8,
       9,    10,    34,     3,     4,    22,    -1,    -1,     8,     9,
      10,    -1,    29,    22,    -1,    -1,    -1,    34,    -1,    -1,
      29,    -1,    22,    -1,    -1,    34,     3,     4,    -1,    29,
      -1,     8,     9,    10,    34,     3,     4,    -1,    -1,    -1,
       8,     9,    10,     3,     4,    22,    -1,    -1,     8,     9,
      10,    -1,    29,    -1,    22,    -1,    -1,    34,     3,     4,
      -1,    29,    22,     8,     9,    10,    34,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    22,    14,    15,
      -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    28,    29,    30,    31,    32,    11,    34,    -1,
      -1,    -1,    16,    -1,    20,    -1,    -1,    43,    44,    23,
      24,    25,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    40,    28,    29,    30,
      31,    32,    -1,    34,    -1,    28,    29,    30,    31,    32,
      41,    34,    -1,    28,    29,    30,    31,    32,    41,    34,
      -1,    -1,    -1,    -1,    39,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    39,    28,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    -1,    -1,    39,    28,
      29,    30,    31,    32,    -1,    34,    -1,    25,    -1,    38,
      28,    29,    30,    31,    32,    -1,    34,    28,    29,    30,
      31,    32,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      17,    18,    19,    21,    22,    29,    34,    36,    46,    47,
      48,    49,    50,    51,    58,    59,    61,    63,    72,    74,
      75,    76,    79,    81,    11,    16,    23,    24,    25,    35,
      40,    67,     4,    68,    68,    68,    34,    34,    34,     4,
       4,    79,     3,    79,    56,     0,    73,    47,    20,    28,
      29,    30,    31,    32,    34,    79,    22,    79,     4,    60,
      79,     4,    62,     4,    58,    79,    25,    25,    39,    71,
      78,    79,    78,     4,     5,    58,    54,    56,    35,    38,
      47,    42,    47,    79,    79,    79,    79,    79,     4,    66,
      79,    80,    25,    40,    11,    25,    41,    41,     4,    63,
      64,    65,    66,    79,     4,    36,    51,    69,    79,    68,
      38,    14,    15,    43,    44,    38,    35,    68,    42,    34,
       4,    37,    40,    67,    39,    39,    38,    60,    79,    79,
      79,    79,    25,    67,    67,    28,    30,    25,     4,    70,
      71,    71,    71,    56,    79,    79,    79,    79,    36,    48,
      49,    77,     4,    42,    78,     4,    38,    52,    53,    79,
      57,    80,    80,    41,    79,     4,    65,    65,    64,    27,
      37,    77,    47,    42,    78,    42,    25,    77,    38,    39,
      69,    79,    57,    37,    42,     4,    58,    81,    79,    55,
      57,    77,    53,    39,    13,    58,    38,    38,    55,    70,
      56,    38,    77,     8,    77,    77,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    49,    50,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    54,
      55,    56,    57,    58,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    66,    67,    67,    68,    68,    68,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    78,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     1,     2,     2,     2,
       1,     2,     1,     1,     2,     1,     1,     1,     5,     8,
       7,     2,     3,     3,     3,     1,     1,     3,     1,     1,
       1,     0,     0,     1,     1,     1,     3,     3,     3,     3,
       3,     5,     5,     1,     4,     4,     6,     1,     1,     3,
       1,     1,     3,     3,     2,     4,     3,     4,     2,     4,
       4,     3,     5,     3,     3,     2,     0,     1,     1,     2,
       0,     5,    10,     9,     9,    11,     7,     3,     2,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     4,     3,     1,     0,     3,     1,     1,     2,
       3,     1,     1,     1,     2,     1
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
#line 121 "mini_js.y"
         { print_prod("s -> cmds"); yyvsp[0].c = yyvsp[0].c + "." + funcoes; print_NPR(yyvsp[0].c); }
#line 1732 "y.tab.c"
    break;

  case 3:
#line 124 "mini_js.y"
                              { print_prod("cmds -> cmd_1 ; cmds"); yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1738 "y.tab.c"
    break;

  case 4:
#line 125 "mini_js.y"
                              { print_prod("cmds -> cmd_2 cmds"); yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1744 "y.tab.c"
    break;

  case 5:
#line 126 "mini_js.y"
                              { print_prod("cmds -> epsilon"); yyval.c = epsilon; }
#line 1750 "y.tab.c"
    break;

  case 6:
#line 129 "mini_js.y"
                      { print_prod("cmd_1 -> atr"); yyval.c = yyvsp[0].c + "^"; }
#line 1756 "y.tab.c"
    break;

  case 7:
#line 130 "mini_js.y"
                      { print_prod("cmd_1 -> LET decl"); yyval.c = yyvsp[0].c; }
#line 1762 "y.tab.c"
    break;

  case 8:
#line 131 "mini_js.y"
                      { print_prod("cmd_1 -> VAR decl"); yyval.c = yyvsp[0].c; }
#line 1768 "y.tab.c"
    break;

  case 9:
#line 132 "mini_js.y"
                      { print_prod("cmd_1 -> CONST decl"); yyval.c = yyvsp[0].c; }
#line 1774 "y.tab.c"
    break;

  case 10:
#line 133 "mini_js.y"
                      { print_prod("cmd_1 -> loop"); }
#line 1780 "y.tab.c"
    break;

  case 11:
#line 134 "mini_js.y"
                      { print_prod("cmd_1 -> exp ASM"); yyval.c = yyvsp[-1].c + yyvsp[0].c + "^"; }
#line 1786 "y.tab.c"
    break;

  case 12:
#line 135 "mini_js.y"
                      { print_prod("cmd_1 -> exp"); yyval.c = yyvsp[0].c; }
#line 1792 "y.tab.c"
    break;

  case 13:
#line 136 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        yyval.c = gera_retorno(); 
                      }
#line 1804 "y.tab.c"
    break;

  case 14:
#line 143 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN exp"); 
                        if(!pode_retornar.back()) {
                            cout << "Erro: Não é permitido 'return' fora de funções." << endl;
                            exit(1);
                        }
                        yyval.c = yyvsp[0].c + gera_retorno(); 
                      }
#line 1816 "y.tab.c"
    break;

  case 15:
#line 152 "mini_js.y"
                          { print_prod("cmd_2 -> condicional"); }
#line 1822 "y.tab.c"
    break;

  case 16:
#line 153 "mini_js.y"
                          { print_prod("cmd_2 -> funcao"); }
#line 1828 "y.tab.c"
    break;

  case 17:
#line 154 "mini_js.y"
                          { print_prod("cmd_2 -> bloco"); }
#line 1834 "y.tab.c"
    break;

  case 18:
#line 157 "mini_js.y"
                                                     { print_prod("bloco -> { empilha_escopo cmds } desempilha_escopo"); yyval.c = "<{" + yyvsp[-2].c + "}>"; }
#line 1840 "y.tab.c"
    break;

  case 19:
#line 160 "mini_js.y"
                                                                                   { 
                                          print_prod("funcao -> FUNCTION ID ( args ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-6].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-3].c + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-6].v, fim_func);
                                        }
#line 1851 "y.tab.c"
    break;

  case 20:
#line 166 "mini_js.y"
                                                                         {
                                          print_prod("funcao -> FUNCTION ID ( ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-5].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-5].v, fim_func);
                                        }
#line 1862 "y.tab.c"
    break;

  case 21:
#line 172 "mini_js.y"
                        { print_prod("funcao -> ID LAMBDA_NOVO_OBJ"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1870 "y.tab.c"
    break;

  case 22:
#line 175 "mini_js.y"
                        { print_prod("funcao -> ID ARROW BLOCO"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1878 "y.tab.c"
    break;

  case 23:
#line 178 "mini_js.y"
                        { print_prod("funcao -> ID ARROW exp"); 
                          // $$.c = gera_novo_objeto($1.v);
                        }
#line 1886 "y.tab.c"
    break;

  case 24:
#line 183 "mini_js.y"
                   { print_prod("args -> args , arg"); 
                      atualiza_variaveis_declaradas_escopo(yyvsp[0].v);
                      yyval.v = "";
                      yyval.n_args = yyvsp[-2].n_args + 1; 
                      yyval.c = yyvsp[-2].c + gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                  }
#line 1897 "y.tab.c"
    break;

  case 25:
#line 189 "mini_js.y"
                   { print_prod("args -> arg"); 
                     atualiza_variaveis_declaradas_escopo(yyvsp[0].v);
                     yyval.v = "";
                     yyval.n_args = 1;
                     yyval.c = gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                   }
#line 1908 "y.tab.c"
    break;

  case 26:
#line 197 "mini_js.y"
        { print_prod("arg -> ID");
          yyval.v = yyvsp[0].v;
          yyval.c = yyvsp[0].c;
          yyval.n_args = 1;
        }
#line 1918 "y.tab.c"
    break;

  case 27:
#line 202 "mini_js.y"
                 { print_prod("arg -> ID = exp");
                 yyval.v = yyvsp[-2].v;
                 yyval.c = yyvsp[-2].c + yyvsp[0].c + gera_inicializacao_de_argumento(yyvsp[-2].v, yyval.n_args);
                 yyval.n_args = 1;
               }
#line 1928 "y.tab.c"
    break;

  case 28:
#line 207 "mini_js.y"
          { print_prod("arg -> exp");
            yyval.v = yyvsp[0].v;
            yyval.c = yyvsp[0].c;
            yyval.n_args = 1;
          }
#line 1938 "y.tab.c"
    break;

  case 29:
#line 214 "mini_js.y"
                                    { print_prod("empilha_escopo_func -> empilha_escopo"); pode_retornar.push_back(true); }
#line 1944 "y.tab.c"
    break;

  case 30:
#line 217 "mini_js.y"
                                          { print_prod("desempilha_escopo_func -> desempilha_escopo"); pode_retornar.pop_back(); }
#line 1950 "y.tab.c"
    break;

  case 31:
#line 220 "mini_js.y"
                { print_prod("empilha_escopo -> "); ts.push_back(map<string, Simbolo>{}); eh_escopo = true; }
#line 1956 "y.tab.c"
    break;

  case 32:
#line 223 "mini_js.y"
                   { print_prod("desempilha_escopo -> "); ts.pop_back(); variaveis_declaradas_escopo.clear(); eh_escopo = false; }
#line 1962 "y.tab.c"
    break;

  case 33:
#line 226 "mini_js.y"
                    { print_prod("atr -> atr_id"); }
#line 1968 "y.tab.c"
    break;

  case 34:
#line 227 "mini_js.y"
                    { print_prod("atr -> atr_obj"); }
#line 1974 "y.tab.c"
    break;

  case 35:
#line 228 "mini_js.y"
                    { print_prod("atr -> atr_array"); }
#line 1980 "y.tab.c"
    break;

  case 36:
#line 231 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 1986 "y.tab.c"
    break;

  case 37:
#line 232 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 1992 "y.tab.c"
    break;

  case 38:
#line 233 "mini_js.y"
                              { verifica_variaveis_declaradas(yyvsp[-2].v); print_prod("atr_id -> ID ADD exp_id"); yyval.c = to_vector(yyvsp[-2].v) + to_vector(yyvsp[-2].v) + "@" + yyvsp[0].c + "+" + "="; }
#line 1998 "y.tab.c"
    break;

  case 39:
#line 237 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "=" + "^" + to_vector(yyvsp[-2].v) + "@"; }
#line 2004 "y.tab.c"
    break;

  case 40:
#line 238 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 2010 "y.tab.c"
    break;

  case 41:
#line 241 "mini_js.y"
                                 { verifica_variaveis_declaradas(yyvsp[-4].v); print_prod("atr_obj -> ID . prop = exp"); yyval.c = to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2016 "y.tab.c"
    break;

  case 42:
#line 242 "mini_js.y"
                                 { verifica_variaveis_declaradas(yyvsp[-4].v); print_prod("atr_obj -> ID . prop ADD exp"); yyval.c = to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + "[@]" + yyvsp[0].c + "+" + "[=]"; }
#line 2022 "y.tab.c"
    break;

  case 43:
#line 245 "mini_js.y"
                    { print_prod("prop -> ID"); }
#line 2028 "y.tab.c"
    break;

  case 44:
#line 246 "mini_js.y"
                    { print_prod("prop -> ID [ exp ]"); yyval.c = to_vector(yyvsp[-3].v) + "[@]" + yyvsp[-1].c; }
#line 2034 "y.tab.c"
    break;

  case 45:
#line 249 "mini_js.y"
                                  { verifica_variaveis_declaradas(yyvsp[-3].v); print_prod("atr_array -> ID indices = exp"); yyval.c = to_vector(yyvsp[-3].v) + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2040 "y.tab.c"
    break;

  case 46:
#line 250 "mini_js.y"
                                  { verifica_variaveis_declaradas(yyvsp[-5].v); print_prod("atr_array -> ID [ atr ] = exp"); yyval.c = to_vector(yyvsp[-5].v) + "@" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 2046 "y.tab.c"
    break;

  case 47:
#line 253 "mini_js.y"
                  { print_prod("rec -> ID indices = exp"); }
#line 2052 "y.tab.c"
    break;

  case 48:
#line 254 "mini_js.y"
                  { print_prod("rec -> matexp"); }
#line 2058 "y.tab.c"
    break;

  case 49:
#line 255 "mini_js.y"
                  { print_prod("rec -> exp = rec"); yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 2064 "y.tab.c"
    break;

  case 50:
#line 256 "mini_js.y"
                  { print_prod("rec -> atr_array"); }
#line 2070 "y.tab.c"
    break;

  case 51:
#line 259 "mini_js.y"
                        { print_prod("matexp -> matrix"); }
#line 2076 "y.tab.c"
    break;

  case 52:
#line 260 "mini_js.y"
                        { print_prod("matexp -> matexp * matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "[@]" + "*"; }
#line 2082 "y.tab.c"
    break;

  case 53:
#line 261 "mini_js.y"
                        { print_prod("matexp -> matexp + matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "+"; }
#line 2088 "y.tab.c"
    break;

  case 54:
#line 264 "mini_js.y"
                    { print_prod("matrix -> ID indices"); yyval.c = to_vector(yyvsp[-1].v) + "@" + yyvsp[0].c; }
#line 2094 "y.tab.c"
    break;

  case 55:
#line 267 "mini_js.y"
                             { print_prod("indices -> [ exp ] indices"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c; }
#line 2100 "y.tab.c"
    break;

  case 56:
#line 268 "mini_js.y"
                             { print_prod("indices -> [ exp ]"); yyval.c = yyvsp[-1].c; }
#line 2106 "y.tab.c"
    break;

  case 57:
#line 271 "mini_js.y"
                          { if(eh_escopo) atualiza_variaveis_declaradas_escopo(yyvsp[-3].v); else atualiza_variaveis_declaradas(yyvsp[-3].v); print_prod("decl -> ID = exp fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + yyvsp[-1].c + "=" + "^" + yyvsp[0].c; }
#line 2112 "y.tab.c"
    break;

  case 58:
#line 272 "mini_js.y"
                          { if(eh_escopo) atualiza_variaveis_declaradas_escopo(yyvsp[-1].v); else atualiza_variaveis_declaradas(yyvsp[-1].v);  print_prod("decl -> ID fim_decl"); yyval.c = to_vector(yyvsp[-1].v) + "&" + yyvsp[0].c; }
#line 2118 "y.tab.c"
    break;

  case 59:
#line 273 "mini_js.y"
                                 { print_prod("decl -> funcao fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + yyvsp[-1].c + yyvsp[0].c; }
#line 2124 "y.tab.c"
    break;

  case 60:
#line 274 "mini_js.y"
                                 { print_prod("decl -> ID = { corpo_obj } fim_decl"); yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + "{}" + yyvsp[-1].c + "=" + "^"; }
#line 2130 "y.tab.c"
    break;

  case 61:
#line 277 "mini_js.y"
                          { print_prod("objeto -> { corpo_obj }"); yyval.c = yyvsp[-1].c; }
#line 2136 "y.tab.c"
    break;

  case 62:
#line 280 "mini_js.y"
                                    { print_prod("corpo_obj -> ID : exp , corpo_obj"); yyval.c = to_vector(yyvsp[-4].v) + yyvsp[-2].c + "[<=]" + yyvsp[0].c; }
#line 2142 "y.tab.c"
    break;

  case 63:
#line 281 "mini_js.y"
                                 { print_prod("corpo_obj -> ID : exp ,"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "[<=]"; }
#line 2148 "y.tab.c"
    break;

  case 64:
#line 282 "mini_js.y"
                                    { print_prod("corpo_obj -> ID : objeto"); yyval.c = to_vector(yyvsp[-2].v) + "{}" + yyvsp[0].c + "[<=]"; }
#line 2154 "y.tab.c"
    break;

  case 65:
#line 285 "mini_js.y"
                       { print_prod("fim_decl -> , decl"); yyval.c = yyvsp[0].c; }
#line 2160 "y.tab.c"
    break;

  case 66:
#line 286 "mini_js.y"
                       { print_prod("fim_decl -> epsilon"); yyval.c = epsilon; }
#line 2166 "y.tab.c"
    break;

  case 67:
#line 289 "mini_js.y"
                        { print_prod("loop -> while_loop"); }
#line 2172 "y.tab.c"
    break;

  case 68:
#line 290 "mini_js.y"
                        { print_prod("loop -> for_loop"); }
#line 2178 "y.tab.c"
    break;

  case 69:
#line 293 "mini_js.y"
                                { print_prod("separador -> separador ;"); }
#line 2184 "y.tab.c"
    break;

  case 70:
#line 294 "mini_js.y"
                                { print_prod("separador -> epsilon"); yyval.c = epsilon; }
#line 2190 "y.tab.c"
    break;

  case 71:
#line 297 "mini_js.y"
                                         { print_prod("while_loop -> WHILE ( condicao ) corpo"); string inicio_while = gera_label("inicio_while"); string fim_while = gera_label("fim_while"); yyval.c = (":" + inicio_while) + yyvsp[-2].c + "!" + fim_while + "?" + yyvsp[0].c + inicio_while + "#" + (":" + fim_while); }
#line 2196 "y.tab.c"
    break;

  case 72:
#line 300 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2202 "y.tab.c"
    break;

  case 73:
#line 301 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + "^" + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2208 "y.tab.c"
    break;

  case 74:
#line 302 "mini_js.y"
                                                        { print_prod("for_loop -> FOR ( decl ; condicao ; val ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + "^" + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + "^" + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2214 "y.tab.c"
    break;

  case 75:
#line 305 "mini_js.y"
                                                                                                                     { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); string else_label = gera_label("else"); string fim_if = gera_label("fim_if"); yyval.c = yyvsp[-8].c + "!" + else_label + "?" + yyvsp[-5].c + fim_if + "#" + (":" + else_label) + yyvsp[-1].c + (":" + fim_if); }
#line 2220 "y.tab.c"
    break;

  case 76:
#line 306 "mini_js.y"
                                                                                          { print_prod("condicional -> IF (condicao) corpo"); string fim_if = gera_label("fim_if"); yyval.c = yyvsp[-4].c + "!" + fim_if + "?" + yyvsp[-1].c + (":" + fim_if);}
#line 2226 "y.tab.c"
    break;

  case 77:
#line 309 "mini_js.y"
                              { print_prod("corpo -> { cmds }"); yyval.c = yyvsp[-1].c; }
#line 2232 "y.tab.c"
    break;

  case 78:
#line 310 "mini_js.y"
                              { print_prod("corpo -> cmd_1 ;"); }
#line 2238 "y.tab.c"
    break;

  case 79:
#line 311 "mini_js.y"
                              { print_prod("corpo -> cmd_2"); }
#line 2244 "y.tab.c"
    break;

  case 80:
#line 314 "mini_js.y"
                        { print_prod("condicao -> exp > exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 2250 "y.tab.c"
    break;

  case 81:
#line 315 "mini_js.y"
                        { print_prod("condicao -> exp < exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 2256 "y.tab.c"
    break;

  case 82:
#line 316 "mini_js.y"
                        { print_prod("condicao -> exp IGUAL exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 2262 "y.tab.c"
    break;

  case 83:
#line 317 "mini_js.y"
                        { print_prod("condicao -> exp DIF exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "!="; }
#line 2268 "y.tab.c"
    break;

  case 84:
#line 318 "mini_js.y"
                        { print_prod("condicao -> exp"); yyval.c = yyvsp[0].c; }
#line 2274 "y.tab.c"
    break;

  case 85:
#line 321 "mini_js.y"
                        { print_prod("exp -> exp + exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 2280 "y.tab.c"
    break;

  case 86:
#line 322 "mini_js.y"
                        { print_prod("exp -> exp - exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 2286 "y.tab.c"
    break;

  case 87:
#line 323 "mini_js.y"
                        { print_prod("exp -> exp * exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 2292 "y.tab.c"
    break;

  case 88:
#line 324 "mini_js.y"
                        { print_prod("exp -> exp / exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 2298 "y.tab.c"
    break;

  case 89:
#line 325 "mini_js.y"
                        { print_prod("exp -> exp % exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 2304 "y.tab.c"
    break;

  case 90:
#line 326 "mini_js.y"
                        { print_prod("exp -> ID . ID"); yyval.c = to_vector(yyvsp[-2].v) + "@" + yyvsp[0].v + "[@]"; }
#line 2310 "y.tab.c"
    break;

  case 91:
#line 327 "mini_js.y"
                        { print_prod("exp -> val"); }
#line 2316 "y.tab.c"
    break;

  case 92:
#line 328 "mini_js.y"
                        { print_prod("exp -> exp ( params )"); yyval.c = yyvsp[-1].c + to_string(n_params) + yyvsp[-3].v + "@" + "$"; n_params = 0;}
#line 2322 "y.tab.c"
    break;

  case 93:
#line 331 "mini_js.y"
                       { print_prod("params -> exp , params"); yyval.c = yyvsp[-2].c + yyvsp[0].c; n_params++; }
#line 2328 "y.tab.c"
    break;

  case 94:
#line 332 "mini_js.y"
                       { print_prod("params -> exp"); yyval.c = yyvsp[0].c; n_params++; }
#line 2334 "y.tab.c"
    break;

  case 95:
#line 333 "mini_js.y"
                       { print_prod("params -> epsilon"); yyval.c = epsilon; }
#line 2340 "y.tab.c"
    break;

  case 96:
#line 334 "mini_js.y"
                       { print_prod("params -> matrix , params"); yyval.c = yyvsp[-2].c + yyvsp[0].c; n_params++; }
#line 2346 "y.tab.c"
    break;

  case 97:
#line 337 "mini_js.y"
                  { print_prod("val -> ID"); yyval.c = to_vector(yyvsp[0].v) + "@"; }
#line 2352 "y.tab.c"
    break;

  case 98:
#line 338 "mini_js.y"
                  { print_prod("val -> NUM"); }
#line 2358 "y.tab.c"
    break;

  case 99:
#line 339 "mini_js.y"
                  { print_prod("val -> - NUM"); yyval.c = to_vector("0") + yyvsp[0].c + "-" ; }
#line 2364 "y.tab.c"
    break;

  case 100:
#line 340 "mini_js.y"
                  { print_prod("val -> ( exp )"); yyval = yyvsp[-1]; }
#line 2370 "y.tab.c"
    break;

  case 101:
#line 341 "mini_js.y"
                  { print_prod("val -> OBJ"); }
#line 2376 "y.tab.c"
    break;

  case 102:
#line 342 "mini_js.y"
                  { print_prod("val -> ARRAY"); }
#line 2382 "y.tab.c"
    break;

  case 103:
#line 343 "mini_js.y"
                  { print_prod("val -> STRING"); }
#line 2388 "y.tab.c"
    break;

  case 104:
#line 344 "mini_js.y"
                  { print_prod("val -> ID INC"); yyval.c = to_vector(yyvsp[-1].v) + "@" + to_vector(yyvsp[-1].v) + to_vector(yyvsp[-1].v) + "@" + "1" + "+" + "=" + "^"; }
#line 2394 "y.tab.c"
    break;

  case 105:
#line 345 "mini_js.y"
                  { print_prod("val -> BLOCO VAZIO"); }
#line 2400 "y.tab.c"
    break;


#line 2404 "y.tab.c"

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
#line 348 "mini_js.y"


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
