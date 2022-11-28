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

struct Atributos {
  vector<string> c;
  string v;
  int n_args = 0;
};

struct Simbolo {
  int linha;
  string tipo;
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
void atualiza_variaveis_declaradas(string var, string tipo);
void verifica_variaveis_declaradas(string var);
void print_NPR(vector<string>);
vector<string> gera_inicializacao_de_argumento(string id, int n_args);
string trim(string s, string chars);
vector<string> tokeniza(string s);
vector<string> gera_funcao(string id, string label);
vector<string> gera_fim_funcao();
vector<string> gera_retorno();
void atualiza_variaveis_declaradas_escopo(string var, string tipo);

// Variaveis
map<string, Simbolo> variaveis_declaradas;
map<string, Simbolo> variaveis_declaradas_escopo;
vector<string> epsilon;
vector<string> funcoes;
int n_params;
vector<bool> pode_retornar = { false };
vector<bool> escopos;


#line 144 "y.tab.c"

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
    OBJ_VAZIO = 277,
    ARRAY_VAZIO = 278,
    TRUE = 279
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
#define OBJ_VAZIO 277
#define ARRAY_VAZIO 278
#define TRUE 279

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

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
      34,    36,    30,    28,    39,    29,    35,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,    42,
      44,    25,    43,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
       0,   118,   118,   121,   122,   123,   126,   127,   128,   129,
     130,   131,   137,   143,   147,   150,   151,   152,   155,   156,
     157,   160,   163,   169,   177,   183,   191,   196,   201,   208,
     211,   214,   217,   220,   221,   222,   225,   226,   227,   231,
     232,   235,   236,   237,   240,   241,   244,   245,   246,   249,
     250,   251,   252,   255,   256,   257,   260,   263,   264,   267,
     277,   280,   281,   284,   285,   288,   289,   292,   295,   296,
     299,   309,   319,   320,   321,   324,   325,   326,   327,   328,
     329,   332,   333,   334,   335,   336,   337,   338,   339,   345,
     346,   347,   350,   351,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "LET", "VAR", "CONST",
  "OBJ", "ARRAY", "STRING", "ADD", "IF", "ELSE", "IGUAL", "DIF", "INC",
  "WHILE", "FOR", "FUNCTION", "ASM", "RETURN", "OBJ_VAZIO", "ARRAY_VAZIO",
  "TRUE", "'='", "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'T'",
  "'('", "'.'", "')'", "'{'", "'}'", "','", "'['", "']'", "';'", "'>'",
  "'<'", "$accept", "s", "cmds", "cmd_1", "tipo_var", "cmd_2", "bloco",
  "funcao", "args", "arg", "empilha_escopo_func", "desempilha_escopo_func",
  "empilha_escopo", "desempilha_escopo", "atr", "atr_id", "atr_recursiva",
  "atr_obj", "prop", "atr_array", "rec", "matexp", "matrix", "indices",
  "decl", "fim_decl", "loop", "separador", "while_loop", "for_loop",
  "condicional", "corpo", "condicao", "exp", "params", "param", "val", YY_NULLPTR
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
      42,    47,    37,    84,    40,    46,    41,   123,   125,    44,
      91,    93,    59,    62,    60
};
# endif

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     218,  -149,    27,  -149,  -149,  -149,  -149,  -149,  -149,    30,
      32,    53,    15,   292,  -149,  -149,  -149,    13,   292,  -149,
      88,  -149,  -149,    92,   218,  -149,    84,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,    93,  -149,   292,  -149,   309,
      95,   326,   343,   343,   275,  -149,     5,   292,   514,  -149,
     496,   218,  -149,   178,    35,  -149,  -149,  -149,   292,   292,
     292,   292,   292,   360,   292,    80,   452,    94,  -149,   514,
      44,    79,    70,   433,     2,  -149,    78,   405,    98,    92,
      74,   477,    86,  -149,   124,   505,   360,   100,    99,  -149,
    -149,   292,    92,  -149,   179,   179,   104,   104,   104,   173,
     514,   103,   107,   461,   377,   309,   292,   292,   292,   117,
     118,  -149,  -149,   292,   292,   292,   292,   253,   106,   343,
     141,  -149,  -149,   116,   150,  -149,   484,  -149,   292,   410,
     360,   115,    45,  -149,  -149,    11,  -149,   426,  -149,   514,
     469,   452,   514,   292,   292,   253,   514,   514,   514,   514,
     218,   119,  -149,  -149,   343,   127,    73,   253,   -22,  -149,
     514,  -149,   126,   132,  -149,  -149,   514,  -149,  -149,   326,
     169,   169,   377,  -149,   514,   514,  -149,   136,  -149,   134,
     326,   292,  -149,   253,   394,   292,   447,   115,   148,  -149,
    -149,   166,  -149,   326,   155,   514,  -149,  -149,  -149,  -149,
     514,   -15,  -149,   156,   253,  -149,   253,   253,  -149,  -149,
    -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    95,    94,    15,    16,    17,    98,    99,   100,     0,
       0,     0,     0,    11,   102,   103,   104,     0,     0,    31,
       0,     2,    66,     0,     5,    20,    14,     6,    33,    34,
      35,     8,    63,    64,    18,    10,    87,     0,   101,     0,
       0,     0,     0,     0,     0,    31,    94,     0,    12,    96,
       0,     5,     1,     5,    62,     7,     4,     9,     0,     0,
       0,     0,     0,    91,     0,     0,    38,    94,    37,    36,
      86,     0,     0,     0,    94,    80,     0,    79,     0,     0,
       0,     0,     0,    29,     0,     0,    91,    97,     0,    65,
       3,     0,     0,    60,    81,    82,    83,    84,    85,    94,
      92,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    97,     0,     0,    32,    62,    61,     0,    13,
      91,    58,    94,    52,    46,    50,    53,    49,    40,    39,
       0,    42,    41,     0,     0,     0,    77,    78,    75,    76,
       5,     0,    74,    67,     0,     0,    94,     0,     0,    25,
      28,    88,    44,     0,    21,    59,    93,    89,    57,     0,
       0,     0,     0,    45,    47,    48,    32,     0,    73,     0,
       0,     0,    32,     0,     0,     0,     0,     0,    55,    54,
      51,    71,    72,     0,     0,    27,    23,    30,    32,    24,
      43,    58,    31,     0,     0,    22,     0,     0,    69,    32,
      68,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,   -18,     3,  -149,    12,  -149,  -149,  -149,     9,
    -149,    -4,   -44,  -123,   -33,  -149,   101,  -149,    81,  -100,
      31,  -148,   -95,   -61,   -35,    90,  -149,  -149,  -149,  -149,
    -149,  -125,   -36,   -13,   -71,  -149,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,   151,    23,   152,    25,    26,   158,   159,
      82,   196,    51,   197,    27,    28,    68,    29,    71,    30,
     134,   135,    75,    65,    55,    93,    31,    53,    32,    33,
      34,   153,    76,    35,   101,   102,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    83,   164,    22,   133,    50,    56,    78,    72,   136,
     144,    80,    24,   111,   183,   123,    49,   184,    38,    45,
     176,    38,   188,   189,    66,    64,    69,    22,    73,    77,
      77,    81,   182,    88,    85,    90,    24,    84,    37,   170,
      84,   171,    64,    38,   118,    94,    95,    96,    97,    98,
     100,   103,    39,   191,    22,   -44,    22,   127,   198,   167,
      91,    38,    40,    24,    42,    24,    43,    41,   145,   -44,
     168,   111,   133,   100,    92,   136,   136,   136,   126,   208,
      84,   209,   210,   155,   106,   169,   211,    44,    52,    38,
     107,   137,   139,   140,   141,   142,    54,   -19,   181,    70,
     146,   147,   148,   149,   108,   104,    77,   160,    84,   -26,
      38,   109,   -26,    57,   112,   166,   119,   100,   179,   105,
     120,    58,    59,    60,    61,    62,   111,    63,   121,    84,
     174,   175,   177,    64,   117,   124,    72,   125,    86,   129,
     168,    77,   143,   144,     1,   156,   130,   194,   154,     6,
       7,     8,   161,    22,   162,    64,   186,   185,   206,   137,
     203,   178,    24,    14,    15,    16,   106,    81,   195,   180,
      17,   160,   200,   187,   192,    47,   193,   157,   171,   202,
      81,     1,     2,     3,     4,     5,     6,     7,     8,    38,
       9,   204,   207,   199,   205,    10,    11,    12,   128,    13,
      14,    15,    16,   190,     0,   163,   138,    17,    84,    60,
      61,    62,    18,    86,     0,    19,   165,     0,     0,     0,
      89,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,     0,    10,    11,    12,     0,    13,
      14,    15,    16,     0,     0,     0,     0,    17,     0,     0,
       0,     0,    18,     0,     0,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,     0,
      10,    11,    12,     0,    13,    14,    15,    16,     1,     2,
      79,     0,    17,     6,     7,     8,     0,    18,     0,     0,
     150,     0,     0,     0,     0,     1,    46,    14,    15,    16,
       6,     7,     8,     0,    17,     0,     0,     0,     0,    18,
       0,     0,     1,    67,    14,    15,    16,     6,     7,     8,
       0,    17,     0,     0,     0,     0,    47,     0,     0,     1,
       2,    14,    15,    16,     6,     7,     8,     0,    17,     0,
       0,     0,     0,    47,     0,     0,     1,    74,    14,    15,
      16,     6,     7,     8,     0,    17,     0,     0,     0,     0,
      18,     0,     0,     1,    99,    14,    15,    16,     6,     7,
       8,     0,    17,     0,     0,     0,     0,    47,     0,     0,
       1,   132,    14,    15,    16,     6,     7,     8,     0,    17,
       0,     0,     0,     0,    47,     0,     0,     1,   156,    14,
      15,    16,     6,     7,     8,     0,    17,     0,     0,     0,
       0,    47,     0,     0,     0,     0,    14,    15,    16,   113,
     114,     0,     0,    17,     0,     0,     0,     0,    47,     0,
     -88,     0,     0,    58,    59,    60,    61,    62,   -88,    86,
     -88,   -88,   -88,     0,     0,     0,     0,     0,   115,   116,
     -88,   172,     0,     0,    58,    59,    60,    61,    62,     0,
      86,    58,    59,    60,    61,    62,    64,    86,     0,     0,
       0,     0,     0,    64,   110,    58,    59,    60,    61,    62,
      58,    86,    60,    61,    62,     0,    86,    64,   201,    58,
      59,    60,    61,    62,     0,    86,     0,    58,    59,    60,
      61,    62,   131,    86,     0,    58,    59,    60,    61,    62,
     173,    86,    58,    59,    60,    61,    62,    64,    86,     0,
       0,     0,     0,    92,    58,    59,    60,    61,    62,     0,
      86,     0,    87,    58,    59,    60,    61,    62,     0,    86,
       0,   122,    58,    59,    60,    61,    62,     0,    86
};

static const yytype_int16 yycheck[] =
{
      13,    45,   125,     0,   104,    18,    24,    43,    41,   104,
      25,    44,     0,    74,    36,    86,     3,    39,    16,     4,
     145,    16,   170,   171,    37,    40,    39,    24,    41,    42,
      43,    44,   157,    51,    47,    53,    24,    35,    11,    28,
      35,    30,    40,    16,    79,    58,    59,    60,    61,    62,
      63,    64,    25,   176,    51,    11,    53,    92,   183,   130,
      25,    16,    35,    51,    34,    53,    34,    40,   112,    25,
     131,   132,   172,    86,    39,   170,   171,   172,    91,   204,
      35,   206,   207,   119,    40,    40,   209,    34,     0,    16,
      11,   104,   105,   106,   107,   108,     4,    13,    25,     4,
     113,   114,   115,   116,    25,    25,   119,   120,    35,    36,
      16,    41,    39,    20,    36,   128,    42,   130,   154,    25,
      34,    28,    29,    30,    31,    32,   187,    34,     4,    35,
     143,   144,   150,    40,    36,    35,   169,    38,    34,    36,
     201,   154,    25,    25,     3,     4,    39,   180,    42,     8,
       9,    10,    36,   150,     4,    40,   169,    25,   202,   172,
     193,    42,   150,    22,    23,    24,    40,   180,   181,    42,
      29,   184,   185,     4,    38,    34,    42,    36,    30,    13,
     193,     3,     4,     5,     6,     7,     8,     9,    10,    16,
      12,    36,    36,   184,   198,    17,    18,    19,    25,    21,
      22,    23,    24,   172,    -1,   124,   105,    29,    35,    30,
      31,    32,    34,    34,    -1,    37,   126,    -1,    -1,    -1,
      42,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    37,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,     3,     4,
       5,    -1,    29,     8,     9,    10,    -1,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,     3,     4,    22,    23,    24,
       8,     9,    10,    -1,    29,    -1,    -1,    -1,    -1,    34,
      -1,    -1,     3,     4,    22,    23,    24,     8,     9,    10,
      -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,     3,
       4,    22,    23,    24,     8,     9,    10,    -1,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,     3,     4,    22,    23,
      24,     8,     9,    10,    -1,    29,    -1,    -1,    -1,    -1,
      34,    -1,    -1,     3,     4,    22,    23,    24,     8,     9,
      10,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
       3,     4,    22,    23,    24,     8,     9,    10,    -1,    29,
      -1,    -1,    -1,    -1,    34,    -1,    -1,     3,     4,    22,
      23,    24,     8,     9,    10,    -1,    29,    -1,    -1,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    22,    23,    24,    14,
      15,    -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,
      20,    -1,    -1,    28,    29,    30,    31,    32,    28,    34,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    43,    44,
      40,    25,    -1,    -1,    28,    29,    30,    31,    32,    -1,
      34,    28,    29,    30,    31,    32,    40,    34,    -1,    -1,
      -1,    -1,    -1,    40,    41,    28,    29,    30,    31,    32,
      28,    34,    30,    31,    32,    -1,    34,    40,    41,    28,
      29,    30,    31,    32,    -1,    34,    -1,    28,    29,    30,
      31,    32,    41,    34,    -1,    28,    29,    30,    31,    32,
      41,    34,    28,    29,    30,    31,    32,    40,    34,    -1,
      -1,    -1,    -1,    39,    28,    29,    30,    31,    32,    -1,
      34,    -1,    36,    28,    29,    30,    31,    32,    -1,    34,
      -1,    36,    28,    29,    30,    31,    32,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    12,
      17,    18,    19,    21,    22,    23,    24,    29,    34,    37,
      46,    47,    48,    49,    50,    51,    52,    59,    60,    62,
      64,    71,    73,    74,    75,    78,    81,    11,    16,    25,
      35,    40,    34,    34,    34,     4,     4,    34,    78,     3,
      78,    57,     0,    72,     4,    69,    47,    20,    28,    29,
      30,    31,    32,    34,    40,    68,    78,     4,    61,    78,
       4,    63,    59,    78,     4,    67,    77,    78,    77,     5,
      59,    78,    55,    57,    35,    78,    34,    36,    47,    42,
      47,    25,    39,    70,    78,    78,    78,    78,    78,     4,
      78,    79,    80,    78,    25,    25,    40,    11,    25,    41,
      41,    68,    36,    14,    15,    43,    44,    36,    69,    42,
      34,     4,    36,    79,    35,    38,    78,    69,    25,    36,
      39,    41,     4,    64,    65,    66,    67,    78,    61,    78,
      78,    78,    78,    25,    25,    57,    78,    78,    78,    78,
      37,    48,    50,    76,    42,    77,     4,    36,    53,    54,
      78,    36,     4,    63,    58,    70,    78,    79,    68,    40,
      28,    30,    25,    41,    78,    78,    76,    47,    42,    77,
      42,    25,    76,    36,    39,    25,    78,     4,    66,    66,
      65,    58,    38,    42,    59,    78,    56,    58,    76,    54,
      78,    41,    13,    59,    36,    56,    57,    36,    76,    76,
      76,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    49,    50,    50,
      50,    51,    52,    52,    53,    53,    54,    54,    54,    55,
      56,    57,    58,    59,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      77,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    79,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     2,     0,     1,     2,     1,     2,
       1,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     5,     8,     7,     3,     1,     1,     3,     1,     1,
       1,     0,     0,     1,     1,     1,     3,     3,     3,     3,
       3,     5,     5,     7,     1,     4,     4,     6,     6,     1,
       1,     3,     1,     1,     3,     3,     2,     4,     3,     4,
       2,     2,     0,     1,     1,     2,     0,     5,    10,     9,
      11,     7,     3,     2,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     4,     3,
       1,     0,     1,     3,     1,     1,     2,     3,     1,     1,
       1,     2,     1,     1,     1
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
#line 118 "mini_js.y"
         { print_prod("s -> cmds"); yyvsp[0].c = yyvsp[0].c + "." + funcoes; print_NPR(yyvsp[0].c); }
#line 1732 "y.tab.c"
    break;

  case 3:
#line 121 "mini_js.y"
                              { print_prod("cmds -> cmd_1 ; cmds"); yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1738 "y.tab.c"
    break;

  case 4:
#line 122 "mini_js.y"
                              { print_prod("cmds -> cmd_2 cmds"); yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1744 "y.tab.c"
    break;

  case 5:
#line 123 "mini_js.y"
                              { print_prod("cmds -> epsilon"); yyval.c = epsilon; }
#line 1750 "y.tab.c"
    break;

  case 6:
#line 126 "mini_js.y"
                      { print_prod("cmd_1 -> atr"); yyval.c = yyvsp[0].c + "^"; }
#line 1756 "y.tab.c"
    break;

  case 7:
#line 127 "mini_js.y"
                      { print_prod("cmd_1 -> tipo_var decl"); if(escopos.size() > 0) atualiza_variaveis_declaradas_escopo(yyvsp[0].c[0], yyvsp[-1].v); else atualiza_variaveis_declaradas(yyvsp[0].c[0], yyvsp[-1].v); yyval.c = yyvsp[0].c; }
#line 1762 "y.tab.c"
    break;

  case 8:
#line 128 "mini_js.y"
                      { print_prod("cmd_1 -> loop"); }
#line 1768 "y.tab.c"
    break;

  case 9:
#line 129 "mini_js.y"
                      { print_prod("cmd_1 -> exp ASM"); yyval.c = yyvsp[-1].c + yyvsp[0].c + "^"; }
#line 1774 "y.tab.c"
    break;

  case 10:
#line 130 "mini_js.y"
                      { print_prod("cmd_1 -> exp"); yyval.c = yyvsp[0].c; }
#line 1780 "y.tab.c"
    break;

  case 11:
#line 131 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN"); 
                        if(!pode_retornar.back()) {
                            yyerror("Comando RETURN fora de funcao");
                        }
                        yyval.c = gera_retorno(); 
                      }
#line 1791 "y.tab.c"
    break;

  case 12:
#line 137 "mini_js.y"
                      { print_prod("cmd_1 -> RETURN exp"); 
                        if(!pode_retornar.back()) {
                            yyerror("Comando RETURN fora de funcao");
                        }
                        yyval.c = yyvsp[0].c + gera_retorno(); 
                      }
#line 1802 "y.tab.c"
    break;

  case 13:
#line 143 "mini_js.y"
                       { print_prod("cmd_1 -> exp '(' params ')'"); // chamada de funcao
                         yyval.c = yyvsp[-1].c + to_string(n_params) + yyvsp[-3].c + "$" + "^"; 
                         n_params = 0; 
                       }
#line 1811 "y.tab.c"
    break;

  case 14:
#line 147 "mini_js.y"
                       { print_prod("cmd_1 -> funcao"); }
#line 1817 "y.tab.c"
    break;

  case 15:
#line 150 "mini_js.y"
              { print_prod("tipo_var -> LET"); yyval.v = yyvsp[0].v; }
#line 1823 "y.tab.c"
    break;

  case 16:
#line 151 "mini_js.y"
        { print_prod("tipo_var -> VAR"); yyval.v = yyvsp[0].v; }
#line 1829 "y.tab.c"
    break;

  case 17:
#line 152 "mini_js.y"
          { print_prod("tipo_var -> CONST"); yyval.v = yyvsp[0].v; }
#line 1835 "y.tab.c"
    break;

  case 18:
#line 155 "mini_js.y"
                          { print_prod("cmd_2 -> condicional"); }
#line 1841 "y.tab.c"
    break;

  case 19:
#line 156 "mini_js.y"
                          { print_prod("cmd_2 -> funcao"); }
#line 1847 "y.tab.c"
    break;

  case 20:
#line 157 "mini_js.y"
                          { print_prod("cmd_2 -> bloco"); }
#line 1853 "y.tab.c"
    break;

  case 21:
#line 160 "mini_js.y"
                                                     { print_prod("bloco -> { empilha_escopo cmds } desempilha_escopo"); yyval.c = "<{" + yyvsp[-2].c + "}>"; }
#line 1859 "y.tab.c"
    break;

  case 22:
#line 163 "mini_js.y"
                                                                                   { 
                                          print_prod("funcao -> FUNCTION ID ( args ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-6].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-3].c + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-6].v, fim_func);
                                        }
#line 1870 "y.tab.c"
    break;

  case 23:
#line 169 "mini_js.y"
                                                                         {
                                          print_prod("funcao -> FUNCTION ID ( ) corpo"); 
                                          string fim_func = gera_label(yyvsp[-5].v); 
                                          funcoes = funcoes + (":" + fim_func) + yyvsp[-1].c + gera_fim_funcao();
                                          yyval.c = gera_funcao(yyvsp[-5].v, fim_func);
                                        }
#line 1881 "y.tab.c"
    break;

  case 24:
#line 177 "mini_js.y"
                   { print_prod("args -> args , arg"); 
                      atualiza_variaveis_declaradas_escopo(yyvsp[0].v, "let");
                      yyval.v = "";
                      yyval.n_args = yyvsp[-2].n_args + 1; 
                      yyval.c = yyvsp[-2].c + gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                  }
#line 1892 "y.tab.c"
    break;

  case 25:
#line 183 "mini_js.y"
                   { print_prod("args -> arg"); 
                     atualiza_variaveis_declaradas_escopo(yyvsp[0].v, "let");
                     yyval.v = "";
                     yyval.n_args = 1;
                     yyval.c = gera_inicializacao_de_argumento(yyvsp[0].v, yyval.n_args);
                   }
#line 1903 "y.tab.c"
    break;

  case 26:
#line 191 "mini_js.y"
        { print_prod("arg -> ID");
          yyval.v = yyvsp[0].v;
          yyval.c = yyvsp[0].c;
          yyval.n_args = 1;
        }
#line 1913 "y.tab.c"
    break;

  case 27:
#line 196 "mini_js.y"
                 { print_prod("arg -> ID = exp");
                 yyval.v = yyvsp[-2].v;
                 yyval.c = yyvsp[-2].c + yyvsp[0].c + gera_inicializacao_de_argumento(yyvsp[-2].v, yyval.n_args);
                 yyval.n_args = 1;
               }
#line 1923 "y.tab.c"
    break;

  case 28:
#line 201 "mini_js.y"
          { print_prod("arg -> exp");
            yyval.v = yyvsp[0].v;
            yyval.c = yyvsp[0].c;
            yyval.n_args = 1;
          }
#line 1933 "y.tab.c"
    break;

  case 29:
#line 208 "mini_js.y"
                                    { print_prod("empilha_escopo_func -> empilha_escopo"); pode_retornar.push_back(true); }
#line 1939 "y.tab.c"
    break;

  case 30:
#line 211 "mini_js.y"
                                          { print_prod("desempilha_escopo_func -> desempilha_escopo"); pode_retornar.pop_back(); }
#line 1945 "y.tab.c"
    break;

  case 31:
#line 214 "mini_js.y"
                { print_prod("empilha_escopo -> "); escopos.push_back(true); }
#line 1951 "y.tab.c"
    break;

  case 32:
#line 217 "mini_js.y"
                   { print_prod("desempilha_escopo -> "); variaveis_declaradas_escopo.clear(); escopos.pop_back(); }
#line 1957 "y.tab.c"
    break;

  case 33:
#line 220 "mini_js.y"
                    { print_prod("atr -> atr_id"); if(escopos.size() == 0) verifica_variaveis_declaradas(yyvsp[0].c[0]); }
#line 1963 "y.tab.c"
    break;

  case 34:
#line 221 "mini_js.y"
                    { print_prod("atr -> atr_obj"); if(escopos.size() == 0) verifica_variaveis_declaradas(yyvsp[0].c[0]); }
#line 1969 "y.tab.c"
    break;

  case 35:
#line 222 "mini_js.y"
                    { print_prod("atr -> atr_array"); if(escopos.size() == 0) verifica_variaveis_declaradas(yyvsp[0].c[0]); }
#line 1975 "y.tab.c"
    break;

  case 36:
#line 225 "mini_js.y"
                              { print_prod("atr_id -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 1981 "y.tab.c"
    break;

  case 37:
#line 226 "mini_js.y"
                              { print_prod("atr_id -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 1987 "y.tab.c"
    break;

  case 38:
#line 227 "mini_js.y"
                              { print_prod("atr_id -> ID ADD exp_id"); yyval.c = to_vector(yyvsp[-2].v) + to_vector(yyvsp[-2].v) + "@" + yyvsp[0].c + "+" + "="; }
#line 1993 "y.tab.c"
    break;

  case 39:
#line 231 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = exp"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "=" + "^" + to_vector(yyvsp[-2].v) + "@"; }
#line 1999 "y.tab.c"
    break;

  case 40:
#line 232 "mini_js.y"
                             { print_prod("atr_recursiva -> ID = atr_recursiva"); yyval.c = to_vector(yyvsp[-2].v) + yyvsp[0].c + "="; }
#line 2005 "y.tab.c"
    break;

  case 41:
#line 235 "mini_js.y"
                                 { print_prod("atr_obj -> ID . prop = exp"); yyval.c = yyvsp[-4].c + "@" + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2011 "y.tab.c"
    break;

  case 42:
#line 236 "mini_js.y"
                                 { print_prod("atr_obj -> ID . prop ADD exp"); yyval.c = yyvsp[-4].c + "@" + yyvsp[-2].c + to_vector(yyvsp[-4].v) + "@" + yyvsp[-2].c + "[@]" + yyvsp[0].c + "+" + "[=]"; }
#line 2017 "y.tab.c"
    break;

  case 43:
#line 237 "mini_js.y"
                                 { print_prod("atr_obj -> ID . prop = exp"); yyval.c = yyvsp[-5].c + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2023 "y.tab.c"
    break;

  case 44:
#line 240 "mini_js.y"
                    { print_prod("prop -> ID"); }
#line 2029 "y.tab.c"
    break;

  case 45:
#line 241 "mini_js.y"
                    { print_prod("prop -> ID [ exp ]"); yyval.c = to_vector(yyvsp[-3].v) + "[@]" + yyvsp[-1].c; }
#line 2035 "y.tab.c"
    break;

  case 46:
#line 244 "mini_js.y"
                                  { print_prod("atr_array -> ID indices = exp"); yyval.c = yyvsp[-3].c + yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 2041 "y.tab.c"
    break;

  case 47:
#line 245 "mini_js.y"
                                  { print_prod("atr_array -> ID [ atr ] = exp"); yyval.c = to_vector(yyvsp[-5].v) + "@" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 2047 "y.tab.c"
    break;

  case 48:
#line 246 "mini_js.y"
                                  { print_prod("atr_array -> ID [ exp ] = exp"); yyval.c = to_vector(yyvsp[-5].v) + "@" + yyvsp[-3].c + yyvsp[0].c + "[=]"; }
#line 2053 "y.tab.c"
    break;

  case 49:
#line 249 "mini_js.y"
                  { print_prod("rec -> ID indices = exp"); }
#line 2059 "y.tab.c"
    break;

  case 50:
#line 250 "mini_js.y"
                  { print_prod("rec -> matexp"); }
#line 2065 "y.tab.c"
    break;

  case 51:
#line 251 "mini_js.y"
                  { print_prod("rec -> exp = rec"); yyval.c = yyvsp[-2].c + yyvsp[-1].c; }
#line 2071 "y.tab.c"
    break;

  case 52:
#line 252 "mini_js.y"
                  { print_prod("rec -> atr_array"); }
#line 2077 "y.tab.c"
    break;

  case 53:
#line 255 "mini_js.y"
                        { print_prod("matexp -> matrix"); }
#line 2083 "y.tab.c"
    break;

  case 54:
#line 256 "mini_js.y"
                        { print_prod("matexp -> matexp * matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "[@]" + "*"; }
#line 2089 "y.tab.c"
    break;

  case 55:
#line 257 "mini_js.y"
                        { print_prod("matexp -> matexp + matexp"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c + "+"; }
#line 2095 "y.tab.c"
    break;

  case 56:
#line 260 "mini_js.y"
                    { print_prod("matrix -> ID indices"); yyval.c = to_vector(yyvsp[-1].v) + "@" + yyvsp[0].c; }
#line 2101 "y.tab.c"
    break;

  case 57:
#line 263 "mini_js.y"
                             { print_prod("indices -> [ exp ] indices"); yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c; }
#line 2107 "y.tab.c"
    break;

  case 58:
#line 264 "mini_js.y"
                             { print_prod("indices -> [ exp ]"); yyval.c = yyvsp[-1].c; }
#line 2113 "y.tab.c"
    break;

  case 59:
#line 267 "mini_js.y"
                          { print_prod("decl -> ID = exp fim_decl"); 
                            if (escopos.size() == 0) {
                              auto it = variaveis_declaradas.find(yyvsp[-3].v);
                              if (it == variaveis_declaradas.end()) { 
                                yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + yyvsp[-1].c + "=" + "^" + yyvsp[0].c;
                              } else {
                                yyval.c = to_vector(yyvsp[-3].v) + yyvsp[-1].c + "=" + "^" + yyvsp[0].c;
                              }
                            } else yyval.c = to_vector(yyvsp[-3].v) + "&" + to_vector(yyvsp[-3].v) + yyvsp[-1].c + "=" + "^" + yyvsp[0].c;                           
                          }
#line 2128 "y.tab.c"
    break;

  case 60:
#line 277 "mini_js.y"
                          { print_prod("decl -> ID fim_decl"); yyval.c = to_vector(yyvsp[-1].v) + "&" + yyvsp[0].c; }
#line 2134 "y.tab.c"
    break;

  case 61:
#line 280 "mini_js.y"
                       { print_prod("fim_decl -> , decl"); yyval.c = yyvsp[0].c; if (escopos.size() == 0) atualiza_variaveis_declaradas(yyvsp[0].c[0], "var"); }
#line 2140 "y.tab.c"
    break;

  case 62:
#line 281 "mini_js.y"
                       { print_prod("fim_decl -> epsilon"); yyval.c = epsilon; }
#line 2146 "y.tab.c"
    break;

  case 63:
#line 284 "mini_js.y"
                        { print_prod("loop -> while_loop"); }
#line 2152 "y.tab.c"
    break;

  case 64:
#line 285 "mini_js.y"
                        { print_prod("loop -> for_loop"); }
#line 2158 "y.tab.c"
    break;

  case 65:
#line 288 "mini_js.y"
                                { print_prod("separador -> separador ;"); }
#line 2164 "y.tab.c"
    break;

  case 66:
#line 289 "mini_js.y"
                                { print_prod("separador -> epsilon"); yyval.c = epsilon; }
#line 2170 "y.tab.c"
    break;

  case 67:
#line 292 "mini_js.y"
                                         { print_prod("while_loop -> WHILE ( condicao ) corpo"); string inicio_while = gera_label("inicio_while"); string fim_while = gera_label("fim_while"); yyval.c = (":" + inicio_while) + yyvsp[-2].c + "!" + fim_while + "?" + yyvsp[0].c + inicio_while + "#" + (":" + fim_while); }
#line 2176 "y.tab.c"
    break;

  case 68:
#line 295 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2182 "y.tab.c"
    break;

  case 69:
#line 296 "mini_js.y"
                                                          { print_prod("for_loop -> FOR ( decl ; condicao ; atr ) corpo"); string inicio_for = gera_label("inicio_for"); string fim_for = gera_label("fim_for"); yyval.c = yyvsp[-6].c + "^" + (":" + inicio_for) + yyvsp[-4].c + "!" + fim_for + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + inicio_for + "#" + (":" + fim_for); }
#line 2188 "y.tab.c"
    break;

  case 70:
#line 299 "mini_js.y"
                                                                                                                    { print_prod("condicional -> IF (condicao) corpo ELSE corpo"); 
                                                                                                                      string else_label = gera_label("else"); 
                                                                                                                      string fim_if = gera_label("fim_if"); 
                                                                                                                      if(escopos.size() > 0) {
                                                                                                                        yyval.c = yyvsp[-8].c + "!" + else_label + "?" + yyvsp[-5].c + fim_if + "#" + (":" + else_label) + yyvsp[-1].c + (":" + fim_if); 
                                                                                                                      }
                                                                                                                      else {
                                                                                                                        yyval.c = yyvsp[-8].c + "!" + else_label + "?" + "<{" + yyvsp[-5].c + "}>" + fim_if + "#" + (":" + else_label) + "<{" + yyvsp[-1].c + "}>" + (":" + fim_if); 
                                                                                                                      }
                                                                                                                    }
#line 2203 "y.tab.c"
    break;

  case 71:
#line 309 "mini_js.y"
                                                                                          { print_prod("condicional -> IF (condicao) corpo"); 
                                                                                      string fim_if = gera_label("fim_if"); 
                                                                                      if (escopos.size() > 0) {
                                                                                        yyval.c = yyvsp[-4].c + "!" + fim_if + "?" + yyvsp[-1].c + fim_if + "#" + (":" + fim_if);
                                                                                      } else {
                                                                                        yyval.c = yyvsp[-4].c + "!" + fim_if + "?" + "<{" + yyvsp[-1].c + "}>" + fim_if + "#" + (":" + fim_if);
                                                                                      }
                                                                                    }
#line 2216 "y.tab.c"
    break;

  case 72:
#line 319 "mini_js.y"
                              { print_prod("corpo -> { cmds }"); yyval.c = yyvsp[-1].c; }
#line 2222 "y.tab.c"
    break;

  case 73:
#line 320 "mini_js.y"
                              { print_prod("corpo -> cmd_1 ;"); }
#line 2228 "y.tab.c"
    break;

  case 74:
#line 321 "mini_js.y"
                              { print_prod("corpo -> cmd_2"); }
#line 2234 "y.tab.c"
    break;

  case 75:
#line 324 "mini_js.y"
                        { print_prod("condicao -> exp > exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 2240 "y.tab.c"
    break;

  case 76:
#line 325 "mini_js.y"
                        { print_prod("condicao -> exp < exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 2246 "y.tab.c"
    break;

  case 77:
#line 326 "mini_js.y"
                        { print_prod("condicao -> exp IGUAL exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 2252 "y.tab.c"
    break;

  case 78:
#line 327 "mini_js.y"
                        { print_prod("condicao -> exp DIF exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "!="; }
#line 2258 "y.tab.c"
    break;

  case 79:
#line 328 "mini_js.y"
                        { print_prod("condicao -> exp"); yyval.c = yyvsp[0].c; }
#line 2264 "y.tab.c"
    break;

  case 80:
#line 329 "mini_js.y"
                        { print_prod("condicao -> matrix"); yyval.c = yyvsp[0].c + "[@]"; }
#line 2270 "y.tab.c"
    break;

  case 81:
#line 332 "mini_js.y"
                        { print_prod("exp -> exp + exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 2276 "y.tab.c"
    break;

  case 82:
#line 333 "mini_js.y"
                        { print_prod("exp -> exp - exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 2282 "y.tab.c"
    break;

  case 83:
#line 334 "mini_js.y"
                        { print_prod("exp -> exp * exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 2288 "y.tab.c"
    break;

  case 84:
#line 335 "mini_js.y"
                        { print_prod("exp -> exp / exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 2294 "y.tab.c"
    break;

  case 85:
#line 336 "mini_js.y"
                        { print_prod("exp -> exp % exp"); yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 2300 "y.tab.c"
    break;

  case 86:
#line 337 "mini_js.y"
                        { print_prod("exp -> ID . ID"); yyval.c = to_vector(yyvsp[-2].v) + "@" + yyvsp[0].v + "[@]"; }
#line 2306 "y.tab.c"
    break;

  case 87:
#line 338 "mini_js.y"
                        { print_prod("exp -> val"); }
#line 2312 "y.tab.c"
    break;

  case 88:
#line 339 "mini_js.y"
                        { print_prod("exp -> exp ( params )"); 
                          yyval.c = yyvsp[-1].c + to_string(n_params) + yyvsp[-3].c + "$";
                          n_params = 0;
                        }
#line 2321 "y.tab.c"
    break;

  case 89:
#line 345 "mini_js.y"
                         { print_prod("params -> param , params"); yyval.c = yyvsp[-2].c + yyvsp[0].c; n_params++; }
#line 2327 "y.tab.c"
    break;

  case 90:
#line 346 "mini_js.y"
                         { print_prod("params -> param"); yyval.c = yyvsp[0].c; n_params++; }
#line 2333 "y.tab.c"
    break;

  case 91:
#line 347 "mini_js.y"
                         { print_prod("params -> epsilon"); yyval.c = epsilon; }
#line 2339 "y.tab.c"
    break;

  case 92:
#line 350 "mini_js.y"
               { print_prod("param -> exp"); }
#line 2345 "y.tab.c"
    break;

  case 93:
#line 351 "mini_js.y"
               { print_prod("param -> ID = exp");
                 yyval.v = yyvsp[-2].v;
                 yyval.c = yyvsp[-2].c + yyvsp[0].c + "=";
               }
#line 2354 "y.tab.c"
    break;

  case 94:
#line 357 "mini_js.y"
                  { print_prod("val -> ID"); yyval.c = to_vector(yyvsp[0].v) + "@"; }
#line 2360 "y.tab.c"
    break;

  case 95:
#line 358 "mini_js.y"
                  { print_prod("val -> NUM"); }
#line 2366 "y.tab.c"
    break;

  case 96:
#line 359 "mini_js.y"
                  { print_prod("val -> - NUM"); yyval.c = to_vector("0") + yyvsp[0].c + "-" ; }
#line 2372 "y.tab.c"
    break;

  case 97:
#line 360 "mini_js.y"
                  { print_prod("val -> ( exp )"); yyval = yyvsp[-1]; yyval.c = yyvsp[-1].c; }
#line 2378 "y.tab.c"
    break;

  case 98:
#line 361 "mini_js.y"
                  { print_prod("val -> OBJ"); }
#line 2384 "y.tab.c"
    break;

  case 99:
#line 362 "mini_js.y"
                  { print_prod("val -> ARRAY"); }
#line 2390 "y.tab.c"
    break;

  case 100:
#line 363 "mini_js.y"
                  { print_prod("val -> STRING"); }
#line 2396 "y.tab.c"
    break;

  case 101:
#line 364 "mini_js.y"
                  { print_prod("val -> ID INC"); yyval.c = to_vector(yyvsp[-1].v) + "@" + to_vector(yyvsp[-1].v) + to_vector(yyvsp[-1].v) + "@" + "1" + "+" + "=" + "^"; }
#line 2402 "y.tab.c"
    break;

  case 102:
#line 365 "mini_js.y"
                      { print_prod("val -> OBJ_VAZIO VAZIO"); yyval.c = to_vector("{}"); }
#line 2408 "y.tab.c"
    break;

  case 103:
#line 366 "mini_js.y"
                  { print_prod("val -> ARRAY_VAZIO"); yyval.c = to_vector("[]"); }
#line 2414 "y.tab.c"
    break;

  case 104:
#line 367 "mini_js.y"
                  { print_prod("val -> TRUE"); }
#line 2420 "y.tab.c"
    break;


#line 2424 "y.tab.c"

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
  return to_vector(id) + "&" + id + "{}" + "=" + "'&funcao'" + label + "[=]" + "^";
}

void atualiza_variaveis_declaradas(string var, string tipo) {
  // cout << "var global" << var << endl;
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    Simbolo novo;
    novo.tipo = tipo;
    novo.linha = yylloc.first_line;
    variaveis_declaradas[var] = novo;
  } else {
    if (tipo != "var") {
      cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas[var].linha << "." << endl;
      exit(1);
    }
  }
}

void atualiza_variaveis_declaradas_escopo(string var, string tipo) {
  // cout << "var func" << var << endl;
  auto it = variaveis_declaradas_escopo.find(var);

  if (it == variaveis_declaradas_escopo.end()) {
    Simbolo novo;
    novo.tipo = tipo;
    novo.linha = yylloc.first_line;
    variaveis_declaradas_escopo[var] = novo;
  } else {
    if(tipo != "var") {
      cout << "Erro: a variável '" << var << "' já foi declarada na linha " << variaveis_declaradas_escopo[var].linha << "." << endl;
      exit(1);
    }
  }
}

void verifica_variaveis_declaradas(string var) {
  auto it = variaveis_declaradas.find(var);

  if (it == variaveis_declaradas.end()) {
    cout << "Erro: a variável '" << var << "' não foi declarada." << endl;
    exit(1);
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
