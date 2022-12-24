/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

    #include "tree.hpp"
    #include "lex.yy.c"
    #include <stdio.h>
    #include "stdlib.h"
    #include <string.h>
    #include "my_error.hpp"
    #include "symbol.hpp"
    #include "type.hpp"
    void yyerror(const char* s);
    int has_error=0;

#line 84 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ILLEGAL_TOKEN = 3,              /* ILLEGAL_TOKEN  */
  YYSYMBOL_LOWER_ELSE = 4,                 /* LOWER_ELSE  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_FLOAT = 9,                      /* FLOAT  */
  YYSYMBOL_STRUCT = 10,                    /* STRUCT  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_LP = 31,                        /* LP  */
  YYSYMBOL_RP = 32,                        /* RP  */
  YYSYMBOL_LB = 33,                        /* LB  */
  YYSYMBOL_RB = 34,                        /* RB  */
  YYSYMBOL_SEMI = 35,                      /* SEMI  */
  YYSYMBOL_LC = 36,                        /* LC  */
  YYSYMBOL_RC = 37,                        /* RC  */
  YYSYMBOL_INVALID_CHAR = 38,              /* INVALID_CHAR  */
  YYSYMBOL_WRONG_ID = 39,                  /* WRONG_ID  */
  YYSYMBOL_UNKNOWN_CHAR = 40,              /* UNKNOWN_CHAR  */
  YYSYMBOL_INVALID_NUMBER = 41,            /* INVALID_NUMBER  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_ExtDefList = 44,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 45,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 46,                /* ExtDecList  */
  YYSYMBOL_Specifier = 47,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 48,           /* StructSpecifier  */
  YYSYMBOL_VarDec = 49,                    /* VarDec  */
  YYSYMBOL_FunDec = 50,                    /* FunDec  */
  YYSYMBOL_VarList = 51,                   /* VarList  */
  YYSYMBOL_ParamDec = 52,                  /* ParamDec  */
  YYSYMBOL_CompSt = 53,                    /* CompSt  */
  YYSYMBOL_StmtList = 54,                  /* StmtList  */
  YYSYMBOL_Stmt = 55,                      /* Stmt  */
  YYSYMBOL_DefList = 56,                   /* DefList  */
  YYSYMBOL_Def = 57,                       /* Def  */
  YYSYMBOL_DecList = 58,                   /* DecList  */
  YYSYMBOL_Dec = 59,                       /* Dec  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Args = 61                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   449

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    59,    60,    61,    62,    63,
      66,    67,    71,    72,    75,    76,    77,    81,    82,    83,
      86,    87,    88,    89,    92,    93,    96,   100,   103,   104,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     120,   121,   124,   125,   126,   129,   130,   133,   134,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     172,   173
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ILLEGAL_TOKEN",
  "LOWER_ELSE", "ELSE", "TYPE", "INT", "CHAR", "FLOAT", "STRUCT", "ID",
  "IF", "WHILE", "RETURN", "COMMA", "ASSIGN", "OR", "AND", "LT", "LE",
  "GT", "GE", "NE", "EQ", "PLUS", "MINUS", "MUL", "DIV", "NOT", "DOT",
  "LP", "RP", "LB", "RB", "SEMI", "LC", "RC", "INVALID_CHAR", "WRONG_ID",
  "UNKNOWN_CHAR", "INVALID_NUMBER", "$accept", "Program", "ExtDefList",
  "ExtDef", "ExtDecList", "Specifier", "StructSpecifier", "VarDec",
  "FunDec", "VarList", "ParamDec", "CompSt", "StmtList", "Stmt", "DefList",
  "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,   -59,     3,    20,   -59,    76,     7,   -59,   -15,   -59,
     -59,   -59,     8,   -59,    10,    -9,   -14,    77,    91,   -59,
     -59,    30,    59,    48,   -59,    30,    30,     6,    48,   -59,
     -59,    30,    12,    33,   -59,   -59,    18,    95,    47,    65,
      53,    11,   -59,   -59,   -59,    43,   -59,   -59,    76,   -59,
     -59,   -59,   -59,   -59,   -59,    63,    68,    81,   108,   108,
     108,   108,   -59,   -59,    83,    95,   137,   108,   -59,    30,
     -59,   -59,   -59,    64,   108,   108,   165,   100,    58,   221,
     -59,   -59,   -59,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   102,   108,   -59,
     329,   -59,   -59,   -59,   303,    49,   249,   277,   -59,   -59,
     -59,   -59,   355,   373,   389,   404,   117,   117,   117,   117,
     117,   117,   100,   100,    58,    58,   -59,   193,   108,   -59,
     -59,    95,    95,    95,    95,   -59,   -59,   -59,   -59,   113,
     -59,   -59,    95,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    12,     0,     0,     2,     3,     0,    13,    15,     1,
       4,     9,    17,     6,     0,    10,     0,     0,     0,     8,
       5,     0,     0,     0,     7,     0,     0,     0,     0,    23,
      21,     0,     0,    25,    17,    11,     0,    28,    47,     0,
      45,     0,    16,    14,    41,    26,    22,    20,     0,    19,
      18,    73,    70,    72,    71,    69,     0,     0,     0,     0,
       0,     0,    74,    31,     0,    28,     0,     0,    44,     0,
      43,    42,    24,     0,     0,     0,     0,    63,    64,     0,
      27,    29,    36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
      48,    46,    78,    66,    81,     0,     0,     0,    37,    32,
      76,    62,    75,    49,    51,    50,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    68,     0,     0,    77,
      65,     0,     0,     0,     0,    79,    67,    80,    38,    33,
      39,    35,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   124,   -59,   101,     5,   -59,   104,   -59,    84,
     -59,   125,    86,   307,    41,   -59,   -22,   -59,   -58,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    14,    26,     7,    38,    16,    32,
      33,    63,    64,    65,    27,    28,    39,    40,    66,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,    77,    78,    79,    41,     6,    21,    42,    11,   100,
       6,    19,    70,    46,     8,   104,   106,   107,    12,    49,
       9,    17,    23,    31,    22,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    18,
     127,    34,    13,    43,    47,    20,    71,   101,    48,    25,
     129,   -40,    50,    31,     1,   -40,   -40,   -40,     2,   -40,
     -40,   -40,   -40,    67,    37,   102,    36,    51,    69,    44,
     104,    52,    53,    54,   -40,    55,    22,   -40,    25,   -40,
      22,   130,     1,     1,   -40,   -40,     2,     2,    97,   -40,
      59,    98,    29,    60,    73,    61,   103,     1,    51,    74,
      68,     2,    52,    53,    54,    62,    55,    56,    57,    58,
      15,    51,    75,   126,   -40,    52,    53,    54,   142,    55,
      80,    59,    35,    30,    60,    15,    61,    95,    96,    10,
      97,    23,    72,    98,    59,    45,    62,    60,    82,    61,
      83,    24,    93,    94,    95,    96,     0,    97,     0,    62,
      98,    81,   137,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   108,    97,    83,     0,
      98,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   135,    97,    83,     0,    98,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   110,    97,    83,     0,    98,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     131,    97,    83,   111,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   133,    97,
      83,   132,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    83,    97,     0,   134,
      98,     0,     0,     0,     0,     0,     0,     0,   128,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    83,    97,     0,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   -41,    97,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,     0,    97,     0,     0,    98,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,    97,     0,     0,    98,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,    97,
       0,     0,    98,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,    97,     0,     0,    98,   138,   139,
     140,   141,     0,     0,     0,     0,     0,     0,     0,   143
};

static const yytype_int16 yycheck[] =
{
      58,    59,    60,    61,    26,     0,    15,     1,     1,    67,
       5,     1,     1,     1,    11,    73,    74,    75,    11,     1,
       0,    36,    36,    18,    33,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    31,
      98,    11,    35,    37,    32,    35,    35,    69,    15,     1,
       1,     3,    34,    48,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    16,    23,     1,     7,     3,    15,    28,
     128,     7,     8,     9,    26,    11,    33,    29,     1,    31,
      33,    32,     6,     6,    36,    37,    10,    10,    30,    41,
      26,    33,     1,    29,    31,    31,    32,     6,     3,    31,
      35,    10,     7,     8,     9,    41,    11,    12,    13,    14,
       6,     3,    31,    11,    37,     7,     8,     9,     5,    11,
      37,    26,    21,    32,    29,    21,    31,    27,    28,     5,
      30,    36,    48,    33,    26,    31,    41,    29,     1,    31,
       3,    16,    25,    26,    27,    28,    -1,    30,    -1,    41,
      33,    65,   128,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    -1,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,     3,    30,    -1,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,     3,    30,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     3,    30,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    33,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    33,   131,   132,
     133,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    10,    43,    44,    45,    47,    48,    11,     0,
      44,     1,    11,    35,    46,    49,    50,    36,    31,     1,
      35,    15,    33,    36,    53,     1,    47,    56,    57,     1,
      32,    47,    51,    52,    11,    46,     7,    56,    49,    58,
      59,    58,     1,    37,    56,    49,     1,    32,    15,     1,
      34,     3,     7,     8,     9,    11,    12,    13,    14,    26,
      29,    31,    41,    53,    54,    55,    60,    16,    35,    15,
       1,    35,    51,    31,    31,    31,    60,    60,    60,    60,
      37,    54,     1,     3,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    30,    33,    35,
      60,    58,     1,    32,    60,    61,    60,    60,     1,    35,
       1,    32,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    11,    60,    15,     1,
      32,     1,    32,     1,    32,     1,    34,    61,    55,    55,
      55,    55,     5,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      46,    46,    47,    47,    48,    48,    48,    49,    49,    49,
      50,    50,    50,    50,    51,    51,    52,    53,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     3,     2,
       1,     3,     1,     1,     5,     2,     5,     1,     4,     4,
       4,     3,     4,     3,     3,     1,     2,     4,     0,     2,
       2,     1,     3,     5,     7,     5,     2,     3,     5,     5,
       0,     2,     3,     3,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     3,     4,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  case 2: /* Program: ExtDefList  */
#line 52 "syntax.y"
                     {(yyval.node_ptr) = new Node("Program", 1, (yyloc).first_line, (yyvsp[0].node_ptr)); if(has_error == 0) {parseProgram((yyval.node_ptr));}}
#line 1401 "syntax.tab.c"
    break;

  case 3: /* ExtDefList: %empty  */
#line 55 "syntax.y"
             {(yyval.node_ptr) = new Node("ExtDefList", 0, (yyloc).first_line);}
#line 1407 "syntax.tab.c"
    break;

  case 4: /* ExtDefList: ExtDef ExtDefList  */
#line 56 "syntax.y"
                    {(yyval.node_ptr) = new Node("ExtDefList", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1413 "syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 59 "syntax.y"
                                   {(yyval.node_ptr)=new Node("ExtDef", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1419 "syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 60 "syntax.y"
                 {(yyval.node_ptr)=new Node("ExtDef", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1425 "syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 61 "syntax.y"
                          {(yyval.node_ptr)=new Node("ExtDef", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1431 "syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier ExtDecList error  */
#line 62 "syntax.y"
                             {my_error(MISS_SEMI, (yyloc).first_line); has_error=1;}
#line 1437 "syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error  */
#line 63 "syntax.y"
                  {my_error(MISS_SEMI, (yyloc).first_line); has_error=1;}
#line 1443 "syntax.tab.c"
    break;

  case 10: /* ExtDecList: VarDec  */
#line 66 "syntax.y"
                   {(yyval.node_ptr)=new Node("ExtDecList", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1449 "syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 67 "syntax.y"
                          {(yyval.node_ptr)=new Node("ExtDecList", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1455 "syntax.tab.c"
    break;

  case 12: /* Specifier: TYPE  */
#line 71 "syntax.y"
                 {(yyval.node_ptr)=new Node("Specifier", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1461 "syntax.tab.c"
    break;

  case 13: /* Specifier: StructSpecifier  */
#line 72 "syntax.y"
                   {(yyval.node_ptr)=new Node("Specifier", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1467 "syntax.tab.c"
    break;

  case 14: /* StructSpecifier: STRUCT ID LC DefList RC  */
#line 75 "syntax.y"
                                         {(yyval.node_ptr)=new Node("StructSpecifier", 5, (yyloc).first_line, (yyvsp[-4].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1473 "syntax.tab.c"
    break;

  case 15: /* StructSpecifier: STRUCT ID  */
#line 76 "syntax.y"
            {(yyval.node_ptr)=new Node("StructSpecifier", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1479 "syntax.tab.c"
    break;

  case 16: /* StructSpecifier: STRUCT ID LC DefList error  */
#line 77 "syntax.y"
                             {my_error(MISS_RC, (yyloc).first_line); has_error=1;}
#line 1485 "syntax.tab.c"
    break;

  case 17: /* VarDec: ID  */
#line 81 "syntax.y"
           {(yyval.node_ptr)=new Node("VarDec", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1491 "syntax.tab.c"
    break;

  case 18: /* VarDec: VarDec LB INT RB  */
#line 82 "syntax.y"
                   {(yyval.node_ptr)=new Node("VarDec", 4, (yyloc).first_line, (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1497 "syntax.tab.c"
    break;

  case 19: /* VarDec: VarDec LB INT error  */
#line 83 "syntax.y"
                      {my_error(MISS_RB, (yyloc).first_line); has_error=1;}
#line 1503 "syntax.tab.c"
    break;

  case 20: /* FunDec: ID LP VarList RP  */
#line 86 "syntax.y"
                         {(yyval.node_ptr)=new Node("FunDec", 4, (yyloc).first_line, (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1509 "syntax.tab.c"
    break;

  case 21: /* FunDec: ID LP RP  */
#line 87 "syntax.y"
           {(yyval.node_ptr)=new Node("FunDec", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1515 "syntax.tab.c"
    break;

  case 22: /* FunDec: ID LP VarList error  */
#line 88 "syntax.y"
                      {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1521 "syntax.tab.c"
    break;

  case 23: /* FunDec: ID LP error  */
#line 89 "syntax.y"
              {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1527 "syntax.tab.c"
    break;

  case 24: /* VarList: ParamDec COMMA VarList  */
#line 92 "syntax.y"
                                {(yyval.node_ptr)=new Node("VarList", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1533 "syntax.tab.c"
    break;

  case 25: /* VarList: ParamDec  */
#line 93 "syntax.y"
           {(yyval.node_ptr)=new Node("VarList", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1539 "syntax.tab.c"
    break;

  case 26: /* ParamDec: Specifier VarDec  */
#line 96 "syntax.y"
                           {(yyval.node_ptr)=new Node("ParamDec", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1545 "syntax.tab.c"
    break;

  case 27: /* CompSt: LC DefList StmtList RC  */
#line 100 "syntax.y"
                               {(yyval.node_ptr)=new Node("CompSt", 4, (yyloc).first_line, (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1551 "syntax.tab.c"
    break;

  case 28: /* StmtList: %empty  */
#line 103 "syntax.y"
          {(yyval.node_ptr) = new Node("StmtList", 0, (yyloc).first_line);}
#line 1557 "syntax.tab.c"
    break;

  case 29: /* StmtList: Stmt StmtList  */
#line 104 "syntax.y"
               {(yyval.node_ptr)=new Node("StmtList", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1563 "syntax.tab.c"
    break;

  case 30: /* Stmt: Exp SEMI  */
#line 107 "syntax.y"
               {(yyval.node_ptr)=new Node("Stmt", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1569 "syntax.tab.c"
    break;

  case 31: /* Stmt: CompSt  */
#line 108 "syntax.y"
         {(yyval.node_ptr)=new Node("Stmt", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1575 "syntax.tab.c"
    break;

  case 32: /* Stmt: RETURN Exp SEMI  */
#line 109 "syntax.y"
                  {(yyval.node_ptr)=new Node("Stmt", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1581 "syntax.tab.c"
    break;

  case 33: /* Stmt: IF LP Exp RP Stmt  */
#line 110 "syntax.y"
                                     {(yyval.node_ptr)=new Node("Stmt", 5, (yyloc).first_line, (yyvsp[-4].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1587 "syntax.tab.c"
    break;

  case 34: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 111 "syntax.y"
                              {(yyval.node_ptr)=new Node("Stmt", 7, (yyloc).first_line, (yyvsp[-6].node_ptr), (yyvsp[-5].node_ptr), (yyvsp[-4].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1593 "syntax.tab.c"
    break;

  case 35: /* Stmt: WHILE LP Exp RP Stmt  */
#line 112 "syntax.y"
                       {(yyval.node_ptr)=new Node("Stmt", 5, (yyloc).first_line, (yyvsp[-4].node_ptr), (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1599 "syntax.tab.c"
    break;

  case 36: /* Stmt: Exp error  */
#line 113 "syntax.y"
            {my_error(MISS_SEMI, (yyloc).first_line); has_error=1;}
#line 1605 "syntax.tab.c"
    break;

  case 37: /* Stmt: RETURN Exp error  */
#line 114 "syntax.y"
                   {my_error(MISS_SEMI, (yyloc).first_line); has_error=1;}
#line 1611 "syntax.tab.c"
    break;

  case 38: /* Stmt: IF LP Exp error Stmt  */
#line 115 "syntax.y"
                       {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1617 "syntax.tab.c"
    break;

  case 39: /* Stmt: WHILE LP Exp error Stmt  */
#line 116 "syntax.y"
                          {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1623 "syntax.tab.c"
    break;

  case 40: /* DefList: %empty  */
#line 120 "syntax.y"
         {(yyval.node_ptr) = new Node("DefList", 0, (yyloc).first_line);}
#line 1629 "syntax.tab.c"
    break;

  case 41: /* DefList: Def DefList  */
#line 121 "syntax.y"
              {(yyval.node_ptr)=new Node("DefList", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1635 "syntax.tab.c"
    break;

  case 42: /* Def: Specifier DecList SEMI  */
#line 124 "syntax.y"
                            {(yyval.node_ptr)=new Node("Def", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1641 "syntax.tab.c"
    break;

  case 43: /* Def: Specifier DecList error  */
#line 125 "syntax.y"
                         {my_error(MISS_SEMI, (yyloc).first_line); has_error=1;}
#line 1647 "syntax.tab.c"
    break;

  case 44: /* Def: error DecList SEMI  */
#line 126 "syntax.y"
                     {my_error(MISS_SPEC, (yyloc).first_line +1); has_error=1;}
#line 1653 "syntax.tab.c"
    break;

  case 45: /* DecList: Dec  */
#line 129 "syntax.y"
             {(yyval.node_ptr)=new Node("DecList", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1659 "syntax.tab.c"
    break;

  case 46: /* DecList: Dec COMMA DecList  */
#line 130 "syntax.y"
                    {(yyval.node_ptr)=new Node("DecList", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1665 "syntax.tab.c"
    break;

  case 47: /* Dec: VarDec  */
#line 133 "syntax.y"
            {(yyval.node_ptr)=new Node("Dec", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1671 "syntax.tab.c"
    break;

  case 48: /* Dec: VarDec ASSIGN Exp  */
#line 134 "syntax.y"
                     {(yyval.node_ptr)=new Node("Dec", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1677 "syntax.tab.c"
    break;

  case 49: /* Exp: Exp ASSIGN Exp  */
#line 138 "syntax.y"
                    {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1683 "syntax.tab.c"
    break;

  case 50: /* Exp: Exp AND Exp  */
#line 139 "syntax.y"
              {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1689 "syntax.tab.c"
    break;

  case 51: /* Exp: Exp OR Exp  */
#line 140 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1695 "syntax.tab.c"
    break;

  case 52: /* Exp: Exp LT Exp  */
#line 141 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1701 "syntax.tab.c"
    break;

  case 53: /* Exp: Exp LE Exp  */
#line 142 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1707 "syntax.tab.c"
    break;

  case 54: /* Exp: Exp GT Exp  */
#line 143 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1713 "syntax.tab.c"
    break;

  case 55: /* Exp: Exp GE Exp  */
#line 144 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1719 "syntax.tab.c"
    break;

  case 56: /* Exp: Exp NE Exp  */
#line 145 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1725 "syntax.tab.c"
    break;

  case 57: /* Exp: Exp EQ Exp  */
#line 146 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1731 "syntax.tab.c"
    break;

  case 58: /* Exp: Exp PLUS Exp  */
#line 147 "syntax.y"
               {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1737 "syntax.tab.c"
    break;

  case 59: /* Exp: Exp MINUS Exp  */
#line 148 "syntax.y"
                {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1743 "syntax.tab.c"
    break;

  case 60: /* Exp: Exp MUL Exp  */
#line 149 "syntax.y"
              {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1749 "syntax.tab.c"
    break;

  case 61: /* Exp: Exp DIV Exp  */
#line 150 "syntax.y"
              {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1755 "syntax.tab.c"
    break;

  case 62: /* Exp: LP Exp RP  */
#line 151 "syntax.y"
            {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1761 "syntax.tab.c"
    break;

  case 63: /* Exp: MINUS Exp  */
#line 153 "syntax.y"
            {(yyval.node_ptr)=new Node("Exp", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1767 "syntax.tab.c"
    break;

  case 64: /* Exp: NOT Exp  */
#line 154 "syntax.y"
          {(yyval.node_ptr)=new Node("Exp", 2, (yyloc).first_line, (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1773 "syntax.tab.c"
    break;

  case 65: /* Exp: ID LP Args RP  */
#line 155 "syntax.y"
                {(yyval.node_ptr)=new Node("Exp", 4, (yyloc).first_line, (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1779 "syntax.tab.c"
    break;

  case 66: /* Exp: ID LP RP  */
#line 156 "syntax.y"
            {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1785 "syntax.tab.c"
    break;

  case 67: /* Exp: Exp LB Exp RB  */
#line 157 "syntax.y"
                {(yyval.node_ptr)=new Node("Exp", 4, (yyloc).first_line, (yyvsp[-3].node_ptr), (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1791 "syntax.tab.c"
    break;

  case 68: /* Exp: Exp DOT ID  */
#line 158 "syntax.y"
             {(yyval.node_ptr)=new Node("Exp", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1797 "syntax.tab.c"
    break;

  case 69: /* Exp: ID  */
#line 159 "syntax.y"
     {(yyval.node_ptr)=new Node("Exp", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1803 "syntax.tab.c"
    break;

  case 70: /* Exp: INT  */
#line 160 "syntax.y"
      {(yyval.node_ptr)=new Node("Exp", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1809 "syntax.tab.c"
    break;

  case 71: /* Exp: FLOAT  */
#line 161 "syntax.y"
        {(yyval.node_ptr)=new Node("Exp", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1815 "syntax.tab.c"
    break;

  case 72: /* Exp: CHAR  */
#line 162 "syntax.y"
       {(yyval.node_ptr)=new Node("Exp", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1821 "syntax.tab.c"
    break;

  case 73: /* Exp: ILLEGAL_TOKEN  */
#line 163 "syntax.y"
                {has_error = 1;}
#line 1827 "syntax.tab.c"
    break;

  case 74: /* Exp: INVALID_NUMBER  */
#line 164 "syntax.y"
                 {has_error=1;}
#line 1833 "syntax.tab.c"
    break;

  case 75: /* Exp: Exp ILLEGAL_TOKEN Exp  */
#line 165 "syntax.y"
                        {has_error = 1;}
#line 1839 "syntax.tab.c"
    break;

  case 76: /* Exp: LP Exp error  */
#line 166 "syntax.y"
               {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1845 "syntax.tab.c"
    break;

  case 77: /* Exp: ID LP Args error  */
#line 167 "syntax.y"
                   {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1851 "syntax.tab.c"
    break;

  case 78: /* Exp: ID LP error  */
#line 168 "syntax.y"
              {my_error(MISS_RP, (yyloc).first_line); has_error=1;}
#line 1857 "syntax.tab.c"
    break;

  case 79: /* Exp: Exp LB Exp error  */
#line 169 "syntax.y"
                   {my_error(MISS_RB, (yyloc).first_line); has_error=1;}
#line 1863 "syntax.tab.c"
    break;

  case 80: /* Args: Exp COMMA Args  */
#line 172 "syntax.y"
                      {(yyval.node_ptr)=new Node("Args", 3, (yyloc).first_line, (yyvsp[-2].node_ptr), (yyvsp[-1].node_ptr), (yyvsp[0].node_ptr));}
#line 1869 "syntax.tab.c"
    break;

  case 81: /* Args: Exp  */
#line 173 "syntax.y"
       {(yyval.node_ptr)=new Node("Args", 1, (yyloc).first_line, (yyvsp[0].node_ptr));}
#line 1875 "syntax.tab.c"
    break;


#line 1879 "syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 175 "syntax.y"


void yyerror(const char* s) {
}
int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
