/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         swqparse
#define yylex           swqlex
#define yyerror         swqerror
#define yydebug         swqdebug
#define yynerrs         swqnerrs


/* Copy the first part of user declarations.  */
#line 1 "swq_parser.y" /* yacc.c:339  */

/******************************************************************************
 *
 * Component: OGR SQL Engine
 * Purpose: expression and select parser grammar.
 *          Requires Bison 2.4.0 or newer to process.  Use "make parser" target.
 * Author: Frank Warmerdam <warmerdam@pobox.com>
 *
 ******************************************************************************
 * Copyright (C) 2010 Frank Warmerdam <warmerdam@pobox.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ****************************************************************************/

#include "cpl_port.h"
#include "swq.h"

#include <cstdlib>
#include <cstring>
#include <limits>

#include "cpl_conv.h"
#include "cpl_error.h"
#include "cpl_string.h"
#include "ogr_core.h"
#include "ogr_geometry.h"

CPL_CVSID("$Id$")

#define YYSTYPE swq_expr_node *

/* Defining YYSTYPE_IS_TRIVIAL is needed because the parser is generated as a C++ file. */
/* See http://www.gnu.org/s/bison/manual/html_node/Memory-Management.html that suggests */
/* increase YYINITDEPTH instead, but this will consume memory. */
/* Setting YYSTYPE_IS_TRIVIAL overcomes this limitation, but might be fragile because */
/* it appears to be a non documented feature of Bison */
#define YYSTYPE_IS_TRIVIAL 1

#line 127 "swq_parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "swq_parser.hpp".  */
#ifndef YY_SWQ_SWQ_PARSER_HPP_INCLUDED
# define YY_SWQ_SWQ_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int swqdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    SWQT_INTEGER_NUMBER = 258,
    SWQT_FLOAT_NUMBER = 259,
    SWQT_STRING = 260,
    SWQT_IDENTIFIER = 261,
    SWQT_IN = 262,
    SWQT_LIKE = 263,
    SWQT_ESCAPE = 264,
    SWQT_BETWEEN = 265,
    SWQT_NULL = 266,
    SWQT_IS = 267,
    SWQT_SELECT = 268,
    SWQT_LEFT = 269,
    SWQT_JOIN = 270,
    SWQT_WHERE = 271,
    SWQT_ON = 272,
    SWQT_ORDER = 273,
    SWQT_BY = 274,
    SWQT_FROM = 275,
    SWQT_AS = 276,
    SWQT_ASC = 277,
    SWQT_DESC = 278,
    SWQT_DISTINCT = 279,
    SWQT_CAST = 280,
    SWQT_UNION = 281,
    SWQT_ALL = 282,
    SWQT_LIMIT = 283,
    SWQT_OFFSET = 284,
    SWQT_VALUE_START = 285,
    SWQT_SELECT_START = 286,
    SWQT_NOT = 287,
    SWQT_OR = 288,
    SWQT_AND = 289,
    SWQT_UMINUS = 290,
    SWQT_RESERVED_KEYWORD = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int swqparse (swq_parse_context *context);

#endif /* !YY_SWQ_SWQ_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 215 "swq_parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM static_cast<YYSIZE_T>(-1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   400

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  (static_cast<unsigned int>(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,    43,     2,     2,
      46,    47,    41,    39,    48,    40,    49,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    35,    37,     2,     2,     2,     2,     2,     2,     2,
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
      44,    45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   122,   122,   123,   128,   134,   139,   147,   155,   162,
     170,   178,   186,   194,   202,   210,   218,   226,   234,   242,
     254,   263,   276,   285,   298,   307,   320,   327,   339,   345,
     352,   360,   373,   378,   383,   387,   392,   397,   402,   437,
     444,   451,   458,   465,   472,   508,   516,   522,   529,   538,
     556,   576,   577,   580,   585,   591,   592,   594,   602,   603,
     606,   615,   626,   641,   662,   693,   728,   753,   782,   788,
     790,   791,   796,   797,   803,   810,   811,   814,   815,   818,
     824,   830,   837,   838,   845,   846,   854,   864,   875,   886,
     899,   910
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of string\"", "error", "$undefined", "\"integer number\"",
  "\"floating point number\"", "\"string\"", "\"identifier\"", "\"IN\"",
  "\"LIKE\"", "\"ESCAPE\"", "\"BETWEEN\"", "\"NULL\"", "\"IS\"",
  "\"SELECT\"", "\"LEFT\"", "\"JOIN\"", "\"WHERE\"", "\"ON\"", "\"ORDER\"",
  "\"BY\"", "\"FROM\"", "\"AS\"", "\"ASC\"", "\"DESC\"", "\"DISTINCT\"",
  "\"CAST\"", "\"UNION\"", "\"ALL\"", "\"LIMIT\"", "\"OFFSET\"",
  "SWQT_VALUE_START", "SWQT_SELECT_START", "\"NOT\"", "\"OR\"", "\"AND\"",
  "'='", "'<'", "'>'", "'!'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "SWQT_UMINUS", "\"reserved keyword\"", "'('", "')'", "','", "'.'",
  "$accept", "input", "value_expr", "value_expr_list", "field_value",
  "value_expr_non_logical", "type_def", "select_statement", "select_core",
  "opt_union_all", "union_all", "select_field_list", "column_spec",
  "as_clause", "opt_where", "opt_joins", "opt_order_by", "sort_spec_list",
  "sort_spec", "opt_limit", "opt_offset", "table_def", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    61,    60,    62,    33,    43,
      45,    42,    47,    37,   290,   291,    40,    41,    44,    46
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   181,    -9,    12,  -126,  -126,  -126,   -29,  -126,   -27,
     181,   204,   181,   314,  -126,   183,    53,     8,  -126,    28,
    -126,   181,    59,   181,   352,  -126,   230,    30,   181,   204,
      -8,     6,   181,   181,    86,   104,   158,    63,   204,   204,
     204,   204,   204,    20,   171,  -126,   266,    94,    58,    69,
      92,  -126,    -9,   223,    70,  -126,   299,  -126,   181,   111,
      61,  -126,   110,    78,   181,   204,   331,   346,   181,   181,
    -126,   181,   181,  -126,   181,  -126,   181,   -13,   -13,  -126,
    -126,  -126,   148,     1,   107,  -126,   122,  -126,    55,   171,
      28,  -126,  -126,   181,  -126,   124,    84,   181,   204,  -126,
     181,   126,   357,  -126,  -126,  -126,  -126,  -126,  -126,   127,
      91,  -126,    55,  -126,    88,     4,    65,  -126,  -126,  -126,
      96,    93,  -126,  -126,   183,    98,   181,   204,    97,   100,
       2,    65,   137,   142,  -126,   140,    55,   141,    49,  -126,
    -126,  -126,   183,     2,  -126,   141,     2,     2,    55,   143,
     181,   138,    36,    39,  -126,   138,  -126,  -126,   149,   181,
     314,   146,   150,  -126,   165,  -126,   167,   150,   181,   281,
     127,   168,   152,   132,   144,   152,   281,  -126,    90,  -126,
     147,  -126,   194,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
     127,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,    32,    33,    34,    30,    37,     0,
       0,     0,     0,     3,    35,     5,     0,     0,     4,    55,
       1,     0,     0,     0,     8,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    62,    60,     0,    58,     0,
       0,    51,     0,    29,     0,    31,     0,    36,     0,    18,
       0,    26,     0,     0,     0,     0,     7,     6,     0,     0,
       9,     0,     0,    12,     0,    13,     0,    39,    40,    41,
      42,    43,     0,     0,     0,    69,     0,    61,     0,     0,
      55,    57,    56,     0,    44,     0,     0,     0,     0,    27,
       0,    19,     0,    15,    16,    14,    10,    17,    11,     0,
       0,    63,     0,    68,     0,    86,    72,    59,    52,    28,
      46,     0,    22,    20,    24,     0,     0,     0,    30,     0,
      64,    72,     0,     0,    87,     0,     0,    70,     0,    45,
      23,    21,    25,    66,    65,    70,    88,    90,     0,     0,
       0,    75,     0,     0,    67,    75,    89,    91,     0,     0,
      71,     0,    82,    47,     0,    49,     0,    82,     0,    72,
       0,     0,    84,     0,     0,    84,    72,    73,    79,    76,
      78,    83,     0,    53,    48,    50,    54,    74,    80,    81,
       0,    85,    77
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,    -1,   -19,  -108,     7,  -126,   153,   182,   112,
    -126,   -39,  -126,   139,    56,  -125,    45,    24,  -126,    51,
      41,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    53,    54,    14,    15,   121,    18,    19,    51,
      52,    47,    48,    87,   151,   137,   162,   179,   180,   172,
     183,   116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,   129,   131,    61,    16,    84,   145,    55,    85,    24,
      85,    26,    20,    63,    64,    46,    65,    21,    25,    23,
      22,    16,    56,    86,    62,    86,   149,    59,    40,    41,
      42,    66,    67,    70,    73,    75,    60,    17,   158,    96,
       1,     2,   111,    46,   177,    77,    78,    79,    80,    81,
     117,   187,   152,   133,    50,   153,     4,     5,     6,    43,
     114,   115,   178,   101,     8,    55,    82,   103,   104,    83,
     105,   106,   102,   107,   119,   108,    58,    44,     9,   135,
     136,   125,   178,   163,   164,    10,   165,   166,    46,     4,
       5,     6,     7,    11,    45,    98,   123,     8,    76,    12,
      38,    39,    40,    41,    42,   124,    89,     4,     5,     6,
       7,     9,   188,   189,    88,     8,    90,    94,    10,    91,
      97,    99,    68,    69,   100,   141,    11,   112,   113,     9,
     120,   122,    12,   128,   142,   126,    10,   132,   130,    71,
     139,    72,   138,   146,    11,   140,    22,   143,   147,   160,
      12,     4,     5,     6,     7,   148,   161,   150,   169,     8,
     159,     4,     5,     6,     7,   170,   168,   176,   173,     8,
     174,   181,   109,     9,     4,     5,     6,    43,   171,   184,
      10,   182,     8,     9,     4,     5,     6,     7,    11,   110,
      10,   185,     8,    74,    12,   190,     9,   191,    11,    49,
     167,   155,   118,    10,    12,    92,     9,     4,     5,     6,
       7,    11,    45,    10,   192,     8,   186,    12,   175,     0,
       0,    11,    38,    39,    40,    41,    42,    12,     0,     9,
      27,    28,     0,    29,     0,    30,     0,    27,    28,     0,
      29,     0,    30,     0,    11,     0,     0,     0,     0,     0,
      12,     0,     0,     0,   134,    31,    32,    33,    34,    35,
      36,    37,    31,    32,    33,    34,    35,    36,    37,   144,
       0,    93,    85,    27,    28,     0,    29,    57,    30,     0,
       0,     0,   154,     0,     0,   156,   157,    86,    27,    28,
       0,    29,     0,    30,     0,   135,   136,     0,    31,    32,
      33,    34,    35,    36,    37,     0,    27,    28,     0,    29,
       0,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      95,    27,    28,     0,    29,     0,    30,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,    37,    27,    28,
       0,    29,     0,    30,     0,     0,    31,    32,    33,    34,
      35,    36,    37,    27,    28,     0,    29,     0,    30,    27,
      28,     0,    29,    31,    30,    33,    34,    35,    36,    37,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,    34,    35,    36,    37,     0,     0,    34,    35,    36,
      37,   127,     0,     0,     0,     0,    38,    39,    40,    41,
      42
};

static const yytype_int16 yycheck[] =
{
       1,   109,   112,    11,    13,    44,   131,     6,     6,    10,
       6,    12,     0,     7,     8,    16,    10,    46,    11,    46,
      49,    13,    23,    21,    32,    21,   136,    28,    41,    42,
      43,    32,    33,    34,    35,    36,    29,    46,   148,    58,
      30,    31,    41,    44,   169,    38,    39,    40,    41,    42,
      89,   176,     3,    49,    26,     6,     3,     4,     5,     6,
       5,     6,   170,    64,    11,     6,    46,    68,    69,    49,
      71,    72,    65,    74,    93,    76,    46,    24,    25,    14,
      15,   100,   190,    47,    48,    32,    47,    48,    89,     3,
       4,     5,     6,    40,    41,    34,    97,    11,    35,    46,
      39,    40,    41,    42,    43,    98,    48,     3,     4,     5,
       6,    25,    22,    23,    20,    11,    47,    47,    32,    27,
       9,    11,    36,    37,    46,   126,    40,    20,     6,    25,
       6,    47,    46,     6,   127,     9,    32,    49,    47,    35,
      47,    37,    46,     6,    40,    47,    49,    47,     6,   150,
      46,     3,     4,     5,     6,    15,    18,    16,   159,    11,
      17,     3,     4,     5,     6,    19,    17,   168,     3,    11,
       3,     3,    24,    25,     3,     4,     5,     6,    28,    47,
      32,    29,    11,    25,     3,     4,     5,     6,    40,    41,
      32,    47,    11,    35,    46,    48,    25,     3,    40,    17,
     155,   145,    90,    32,    46,    52,    25,     3,     4,     5,
       6,    40,    41,    32,   190,    11,   175,    46,   167,    -1,
      -1,    40,    39,    40,    41,    42,    43,    46,    -1,    25,
       7,     8,    -1,    10,    -1,    12,    -1,     7,     8,    -1,
      10,    -1,    12,    -1,    40,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,   115,    32,    33,    34,    35,    36,
      37,    38,    32,    33,    34,    35,    36,    37,    38,   130,
      -1,    48,     6,     7,     8,    -1,    10,    47,    12,    -1,
      -1,    -1,   143,    -1,    -1,   146,   147,    21,     7,     8,
      -1,    10,    -1,    12,    -1,    14,    15,    -1,    32,    33,
      34,    35,    36,    37,    38,    -1,     7,     8,    -1,    10,
      -1,    12,    -1,    32,    33,    34,    35,    36,    37,    38,
      21,     7,     8,    -1,    10,    -1,    12,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,     7,     8,
      -1,    10,    -1,    12,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,     7,     8,    -1,    10,    -1,    12,     7,
       8,    -1,    10,    32,    12,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    35,    36,    37,
      38,    34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    31,    51,     3,     4,     5,     6,    11,    25,
      32,    40,    46,    52,    54,    55,    13,    46,    57,    58,
       0,    46,    49,    46,    52,    55,    52,     7,     8,    10,
      12,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     6,    24,    41,    52,    61,    62,    58,
      26,    59,    60,    52,    53,     6,    52,    47,    46,    52,
      55,    11,    32,     7,     8,    10,    52,    52,    36,    37,
      52,    35,    37,    52,    35,    52,    35,    55,    55,    55,
      55,    55,    46,    49,    61,     6,    21,    63,    20,    48,
      47,    27,    57,    48,    47,    21,    53,     9,    34,    11,
      46,    52,    55,    52,    52,    52,    52,    52,    52,    24,
      41,    41,    20,     6,     5,     6,    71,    61,    59,    53,
       6,    56,    47,    52,    55,    53,     9,    34,     6,    54,
      47,    71,    49,    49,    63,    14,    15,    65,    46,    47,
      47,    52,    55,    47,    63,    65,     6,     6,    15,    71,
      16,    64,     3,     6,    63,    64,    63,    63,    71,    17,
      52,    18,    66,    47,    48,    47,    48,    66,    17,    52,
      19,    28,    69,     3,     3,    69,    52,    65,    54,    67,
      68,     3,    29,    70,    47,    47,    70,    65,    22,    23,
      48,     3,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      64,    64,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    71,    71,
      71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     3,     3,     2,     3,
       4,     4,     3,     3,     4,     4,     4,     4,     3,     4,
       5,     6,     5,     6,     5,     6,     3,     4,     3,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     2,     3,
       3,     3,     3,     3,     4,     6,     1,     4,     6,     4,
       6,     2,     4,     9,    10,     0,     2,     2,     1,     3,
       1,     2,     1,     3,     4,     5,     5,     6,     2,     1,
       0,     2,     0,     5,     6,     0,     3,     3,     1,     1,
       2,     2,     0,     2,     0,     2,     1,     2,     3,     4,
       3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (context, YY_("syntax error: cannot back up")); \
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
                  Type, Value, context); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, swq_parse_context *context)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (context);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, swq_parse_context *context)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, context);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, swq_parse_context *context)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , context);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, context); \
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            CPL_FALLTHROUGH
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, swq_parse_context *context)
{
  YYUSE (yyvaluep);
  YYUSE (context);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* "integer number"  */
#line 117 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1217 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* "floating point number"  */
#line 117 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1223 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* "string"  */
#line 117 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1229 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* "identifier"  */
#line 117 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1235 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 52: /* value_expr  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1241 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 53: /* value_expr_list  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1247 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 54: /* field_value  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1253 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 55: /* value_expr_non_logical  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1259 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 56: /* type_def  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1265 "swq_parser.cpp" /* yacc.c:1257  */
        break;

    case 71: /* table_def  */
#line 118 "swq_parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep)); }
#line 1271 "swq_parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (swq_parse_context *context)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH]; /* workaround bug with gcc 4.1 -O2 */ memset(yyssa, 0, sizeof(yyssa));
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = static_cast<yytype_int16>(yystate);

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          static_cast<union yyalloc *>(YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize)));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = yylex (&yylval, context);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 124 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poRoot = (yyvsp[0]);
        }
#line 1541 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poRoot = (yyvsp[0]);
        }
#line 1549 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1557 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_AND );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1568 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 148 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_OR );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1579 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1589 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_EQ );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1600 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 171 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_NE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1611 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 179 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_NE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1622 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1633 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 195 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_GT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1644 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 203 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1655 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 211 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1666 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1677 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 227 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_GE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1688 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 235 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LIKE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1699 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 243 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *like = new swq_expr_node( SWQ_LIKE );
            like->field_type = SWQ_BOOLEAN;
            like->PushSubExpression( (yyvsp[-3]) );
            like->PushSubExpression( (yyvsp[0]) );

            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( like );
        }
#line 1714 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 255 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_LIKE );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-4]) );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1726 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 264 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *like = new swq_expr_node( SWQ_LIKE );
            like->field_type = SWQ_BOOLEAN;
            like->PushSubExpression( (yyvsp[-5]) );
            like->PushSubExpression( (yyvsp[-2]) );
            like->PushSubExpression( (yyvsp[0]) );

            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( like );
        }
#line 1742 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 277 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->nOperation = SWQ_IN;
            (yyval)->PushSubExpression( (yyvsp[-4]) );
            (yyval)->ReverseSubExpressions();
        }
#line 1754 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 286 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *in = (yyvsp[-1]);
            in->field_type = SWQ_BOOLEAN;
            in->nOperation = SWQ_IN;
            in->PushSubExpression( (yyvsp[-5]) );
            in->ReverseSubExpressions();

            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( in );
        }
#line 1770 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 299 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_BETWEEN );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-4]) );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1782 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 308 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *between = new swq_expr_node( SWQ_BETWEEN );
            between->field_type = SWQ_BOOLEAN;
            between->PushSubExpression( (yyvsp[-5]) );
            between->PushSubExpression( (yyvsp[-2]) );
            between->PushSubExpression( (yyvsp[0]) );

            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( between );
        }
#line 1798 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 321 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_ISNULL );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( (yyvsp[-2]) );
        }
#line 1808 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 328 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *isnull = new swq_expr_node( SWQ_ISNULL );
            isnull->field_type = SWQ_BOOLEAN;
            isnull->PushSubExpression( (yyvsp[-3]) );

            (yyval) = new swq_expr_node( SWQ_NOT );
            (yyval)->field_type = SWQ_BOOLEAN;
            (yyval)->PushSubExpression( isnull );
        }
#line 1822 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 340 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
            (yyvsp[0])->PushSubExpression( (yyvsp[-2]) );
        }
#line 1831 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 346 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_ARGUMENT_LIST ); /* temporary value */
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1840 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 353 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);  // validation deferred.
            (yyval)->eNodeType = SNT_COLUMN;
            (yyval)->field_index = -1;
            (yyval)->table_index = -1;
        }
#line 1851 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 361 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-2]);  // validation deferred.
            (yyval)->eNodeType = SNT_COLUMN;
            (yyval)->field_index = -1;
            (yyval)->table_index = -1;
            (yyval)->table_name = (yyval)->string_value;
            (yyval)->string_value = CPLStrdup((yyvsp[0])->string_value);
            delete (yyvsp[0]);
            (yyvsp[0]) = nullptr;
        }
#line 1866 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 374 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1874 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 379 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1882 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 384 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1890 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 388 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[0]);
        }
#line 1898 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 393 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
        }
#line 1906 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 398 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node(static_cast<const char*>(nullptr));
        }
#line 1914 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 403 "swq_parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0])->eNodeType == SNT_CONSTANT)
            {
                if( (yyvsp[0])->field_type == SWQ_FLOAT &&
                    (yyvsp[0])->string_value &&
                    strcmp((yyvsp[0])->string_value, "9223372036854775808") == 0 )
                {
                    (yyval) = (yyvsp[0]);
                    (yyval)->field_type = SWQ_INTEGER64;
                    (yyval)->int_value = std::numeric_limits<GIntBig>::min();
                    (yyval)->float_value = static_cast<double>(std::numeric_limits<GIntBig>::min());
                }
                // - (-9223372036854775808) cannot be represented on int64
                // the classic overflow is that its negation is itself.
                else if( (yyvsp[0])->field_type == SWQ_INTEGER64 &&
                         (yyvsp[0])->int_value == std::numeric_limits<GIntBig>::min() )
                {
                    (yyval) = (yyvsp[0]);
                }
                else
                {
                    (yyval) = (yyvsp[0]);
                    (yyval)->int_value *= -1;
                    (yyval)->float_value *= -1;
                }
            }
            else
            {
                (yyval) = new swq_expr_node( SWQ_MULTIPLY );
                (yyval)->PushSubExpression( new swq_expr_node(-1) );
                (yyval)->PushSubExpression( (yyvsp[0]) );
            }
        }
#line 1952 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 438 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_ADD );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1962 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 445 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_SUBTRACT );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1972 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 452 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_MULTIPLY );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1982 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 459 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_DIVIDE );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 1992 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 466 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = new swq_expr_node( SWQ_MODULUS );
            (yyval)->PushSubExpression( (yyvsp[-2]) );
            (yyval)->PushSubExpression( (yyvsp[0]) );
        }
#line 2002 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 473 "swq_parser.y" /* yacc.c:1646  */
    {
            const swq_operation *poOp =
                    swq_op_registrar::GetOperator( (yyvsp[-3])->string_value );

            if( poOp == nullptr )
            {
                if( context->bAcceptCustomFuncs )
                {
                    (yyval) = (yyvsp[-1]);
                    (yyval)->eNodeType = SNT_OPERATION;
                    (yyval)->nOperation = SWQ_CUSTOM_FUNC;
                    (yyval)->string_value = CPLStrdup((yyvsp[-3])->string_value);
                    (yyval)->ReverseSubExpressions();
                    delete (yyvsp[-3]);
                }
                else
                {
                    CPLError( CE_Failure, CPLE_AppDefined,
                                    "Undefined function '%s' used.",
                                    (yyvsp[-3])->string_value );
                    delete (yyvsp[-3]);
                    delete (yyvsp[-1]);
                    YYERROR;
                }
            }
            else
            {
                (yyval) = (yyvsp[-1]);
                (yyval)->eNodeType = SNT_OPERATION;
                (yyval)->nOperation = poOp->eOperation;
                (yyval)->ReverseSubExpressions();
                delete (yyvsp[-3]);
            }
        }
#line 2041 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 509 "swq_parser.y" /* yacc.c:1646  */
    {
            (yyval) = (yyvsp[-1]);
            (yyval)->PushSubExpression( (yyvsp[-3]) );
            (yyval)->ReverseSubExpressions();
        }
#line 2051 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 517 "swq_parser.y" /* yacc.c:1646  */
    {
        (yyval) = new swq_expr_node( SWQ_CAST );
        (yyval)->PushSubExpression( (yyvsp[0]) );
    }
#line 2060 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 523 "swq_parser.y" /* yacc.c:1646  */
    {
        (yyval) = new swq_expr_node( SWQ_CAST );
        (yyval)->PushSubExpression( (yyvsp[-1]) );
        (yyval)->PushSubExpression( (yyvsp[-3]) );
    }
#line 2070 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 530 "swq_parser.y" /* yacc.c:1646  */
    {
        (yyval) = new swq_expr_node( SWQ_CAST );
        (yyval)->PushSubExpression( (yyvsp[-1]) );
        (yyval)->PushSubExpression( (yyvsp[-3]) );
        (yyval)->PushSubExpression( (yyvsp[-5]) );
    }
#line 2081 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 539 "swq_parser.y" /* yacc.c:1646  */
    {
        OGRwkbGeometryType eType = OGRFromOGCGeomType((yyvsp[-1])->string_value);
        if( !EQUAL((yyvsp[-3])->string_value, "GEOMETRY") ||
            (wkbFlatten(eType) == wkbUnknown &&
            !STARTS_WITH_CI((yyvsp[-1])->string_value, "GEOMETRY")) )
        {
            yyerror (context, "syntax error");
            delete (yyvsp[-3]);
            delete (yyvsp[-1]);
            YYERROR;
        }
        (yyval) = new swq_expr_node( SWQ_CAST );
        (yyval)->PushSubExpression( (yyvsp[-1]) );
        (yyval)->PushSubExpression( (yyvsp[-3]) );
    }
#line 2101 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "swq_parser.y" /* yacc.c:1646  */
    {
        OGRwkbGeometryType eType = OGRFromOGCGeomType((yyvsp[-3])->string_value);
        if( !EQUAL((yyvsp[-5])->string_value, "GEOMETRY") ||
            (wkbFlatten(eType) == wkbUnknown &&
            !STARTS_WITH_CI((yyvsp[-3])->string_value, "GEOMETRY")) )
        {
            yyerror (context, "syntax error");
            delete (yyvsp[-5]);
            delete (yyvsp[-3]);
            delete (yyvsp[-1]);
            YYERROR;
        }
        (yyval) = new swq_expr_node( SWQ_CAST );
        (yyval)->PushSubExpression( (yyvsp[-1]) );
        (yyval)->PushSubExpression( (yyvsp[-3]) );
        (yyval)->PushSubExpression( (yyvsp[-5]) );
    }
#line 2123 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 581 "swq_parser.y" /* yacc.c:1646  */
    {
        delete (yyvsp[-5]);
    }
#line 2131 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 586 "swq_parser.y" /* yacc.c:1646  */
    {
        context->poCurSelect->query_mode = SWQM_DISTINCT_LIST;
        delete (yyvsp[-5]);
    }
#line 2140 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 595 "swq_parser.y" /* yacc.c:1646  */
    {
        swq_select* poNewSelect = new swq_select();
        context->poCurSelect->PushUnionAll(poNewSelect);
        context->poCurSelect = poNewSelect;
    }
#line 2150 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 607 "swq_parser.y" /* yacc.c:1646  */
    {
            if( !context->poCurSelect->PushField( (yyvsp[0]) ) )
            {
                delete (yyvsp[0]);
                YYERROR;
            }
        }
#line 2162 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 616 "swq_parser.y" /* yacc.c:1646  */
    {
            if( !context->poCurSelect->PushField( (yyvsp[-1]), (yyvsp[0])->string_value ) )
            {
                delete (yyvsp[-1]);
                delete (yyvsp[0]);
                YYERROR;
            }
            delete (yyvsp[0]);
        }
#line 2176 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 627 "swq_parser.y" /* yacc.c:1646  */
    {
            swq_expr_node *poNode = new swq_expr_node();
            poNode->eNodeType = SNT_COLUMN;
            poNode->string_value = CPLStrdup( "*" );
            poNode->table_index = -1;
            poNode->field_index = -1;

            if( !context->poCurSelect->PushField( poNode ) )
            {
                delete poNode;
                YYERROR;
            }
        }
#line 2194 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 642 "swq_parser.y" /* yacc.c:1646  */
    {
            CPLString osTableName = (yyvsp[-2])->string_value;

            delete (yyvsp[-2]);
            (yyvsp[-2]) = nullptr;

            swq_expr_node *poNode = new swq_expr_node();
            poNode->eNodeType = SNT_COLUMN;
            poNode->table_name = CPLStrdup(osTableName );
            poNode->string_value = CPLStrdup( "*" );
            poNode->table_index = -1;
            poNode->field_index = -1;

            if( !context->poCurSelect->PushField( poNode ) )
            {
                delete poNode;
                YYERROR;
            }
        }
#line 2218 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 663 "swq_parser.y" /* yacc.c:1646  */
    {
                // special case for COUNT(*), confirm it.
            if( !EQUAL((yyvsp[-3])->string_value, "COUNT") )
            {
                CPLError( CE_Failure, CPLE_AppDefined,
                        "Syntax Error with %s(*).",
                        (yyvsp[-3])->string_value );
                delete (yyvsp[-3]);
                YYERROR;
            }

            delete (yyvsp[-3]);
            (yyvsp[-3]) = nullptr;

            swq_expr_node *poNode = new swq_expr_node();
            poNode->eNodeType = SNT_COLUMN;
            poNode->string_value = CPLStrdup( "*" );
            poNode->table_index = -1;
            poNode->field_index = -1;

            swq_expr_node *count = new swq_expr_node( SWQ_COUNT );
            count->PushSubExpression( poNode );

            if( !context->poCurSelect->PushField( count ) )
            {
                delete count;
                YYERROR;
            }
        }
#line 2252 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 694 "swq_parser.y" /* yacc.c:1646  */
    {
                // special case for COUNT(*), confirm it.
            if( !EQUAL((yyvsp[-4])->string_value, "COUNT") )
            {
                CPLError( CE_Failure, CPLE_AppDefined,
                        "Syntax Error with %s(*).",
                        (yyvsp[-4])->string_value );
                delete (yyvsp[-4]);
                delete (yyvsp[0]);
                YYERROR;
            }

            delete (yyvsp[-4]);
            (yyvsp[-4]) = nullptr;

            swq_expr_node *poNode = new swq_expr_node();
            poNode->eNodeType = SNT_COLUMN;
            poNode->string_value = CPLStrdup( "*" );
            poNode->table_index = -1;
            poNode->field_index = -1;

            swq_expr_node *count = new swq_expr_node( SWQ_COUNT );
            count->PushSubExpression( poNode );

            if( !context->poCurSelect->PushField( count, (yyvsp[0])->string_value ) )
            {
                delete count;
                delete (yyvsp[0]);
                YYERROR;
            }

            delete (yyvsp[0]);
        }
#line 2290 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 729 "swq_parser.y" /* yacc.c:1646  */
    {
                // special case for COUNT(DISTINCT x), confirm it.
            if( !EQUAL((yyvsp[-4])->string_value, "COUNT") )
            {
                CPLError(
                    CE_Failure, CPLE_AppDefined,
                    "DISTINCT keyword can only be used in COUNT() operator." );
                delete (yyvsp[-4]);
                delete (yyvsp[-1]);
                    YYERROR;
            }

            delete (yyvsp[-4]);

            swq_expr_node *count = new swq_expr_node( SWQ_COUNT );
            count->PushSubExpression( (yyvsp[-1]) );

            if( !context->poCurSelect->PushField( count, nullptr, TRUE ) )
            {
                delete count;
                YYERROR;
            }
        }
#line 2318 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 754 "swq_parser.y" /* yacc.c:1646  */
    {
            // special case for COUNT(DISTINCT x), confirm it.
            if( !EQUAL((yyvsp[-5])->string_value, "COUNT") )
            {
                CPLError( CE_Failure, CPLE_AppDefined,
                        "DISTINCT keyword can only be used in COUNT() operator." );
                delete (yyvsp[-5]);
                delete (yyvsp[-2]);
                delete (yyvsp[0]);
                YYERROR;
            }

            swq_expr_node *count = new swq_expr_node( SWQ_COUNT );
            count->PushSubExpression( (yyvsp[-2]) );

            if( !context->poCurSelect->PushField( count, (yyvsp[0])->string_value, TRUE ) )
            {
                delete (yyvsp[-5]);
                delete count;
                delete (yyvsp[0]);
                YYERROR;
            }

            delete (yyvsp[-5]);
            delete (yyvsp[0]);
        }
#line 2349 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 783 "swq_parser.y" /* yacc.c:1646  */
    {
            delete (yyvsp[-1]);
            (yyval) = (yyvsp[0]);
        }
#line 2358 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 792 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->where_expr = (yyvsp[0]);
        }
#line 2366 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 798 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->PushJoin( static_cast<int>((yyvsp[-3])->int_value),
                                            (yyvsp[-1]) );
            delete (yyvsp[-3]);
        }
#line 2376 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 804 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->PushJoin( static_cast<int>((yyvsp[-3])->int_value),
                                            (yyvsp[-1]) );
            delete (yyvsp[-3]);
        }
#line 2386 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 819 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->PushOrderBy( (yyvsp[0])->table_name, (yyvsp[0])->string_value, TRUE );
            delete (yyvsp[0]);
            (yyvsp[0]) = nullptr;
        }
#line 2396 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 825 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->PushOrderBy( (yyvsp[-1])->table_name, (yyvsp[-1])->string_value, TRUE );
            delete (yyvsp[-1]);
            (yyvsp[-1]) = nullptr;
        }
#line 2406 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 831 "swq_parser.y" /* yacc.c:1646  */
    {
            context->poCurSelect->PushOrderBy( (yyvsp[-1])->table_name, (yyvsp[-1])->string_value, FALSE );
            delete (yyvsp[-1]);
            (yyvsp[-1]) = nullptr;
        }
#line 2416 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 839 "swq_parser.y" /* yacc.c:1646  */
    {
        context->poCurSelect->SetLimit( (yyvsp[0])->int_value );
        delete (yyvsp[0]);
        (yyvsp[0]) = nullptr;
    }
#line 2426 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 847 "swq_parser.y" /* yacc.c:1646  */
    {
        context->poCurSelect->SetOffset( (yyvsp[0])->int_value );
        delete (yyvsp[0]);
        (yyvsp[0]) = nullptr;
    }
#line 2436 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 855 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( nullptr, (yyvsp[0])->string_value,
                                                nullptr );
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2449 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 865 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( nullptr, (yyvsp[-1])->string_value,
                                                (yyvsp[0])->string_value );
        delete (yyvsp[-1]);
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2463 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 876 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( (yyvsp[-2])->string_value,
                                                (yyvsp[0])->string_value, nullptr );
        delete (yyvsp[-2]);
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2477 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 887 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( (yyvsp[-3])->string_value,
                                                (yyvsp[-1])->string_value,
                                                (yyvsp[0])->string_value );
        delete (yyvsp[-3]);
        delete (yyvsp[-1]);
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2493 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 900 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( (yyvsp[-2])->string_value,
                                                (yyvsp[0])->string_value, nullptr );
        delete (yyvsp[-2]);
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2507 "swq_parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 911 "swq_parser.y" /* yacc.c:1646  */
    {
        const int iTable =
            context->poCurSelect->PushTableDef( (yyvsp[-3])->string_value,
                                                (yyvsp[-1])->string_value,
                                                (yyvsp[0])->string_value );
        delete (yyvsp[-3]);
        delete (yyvsp[-1]);
        delete (yyvsp[0]);

        (yyval) = new swq_expr_node( iTable );
    }
#line 2523 "swq_parser.cpp" /* yacc.c:1646  */
    break;


#line 2527 "swq_parser.cpp" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
      yyerror (context, YY_("syntax error"));
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
            yymsg = static_cast<char *>(YYSTACK_ALLOC (yymsg_alloc));
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
        yyerror (context, yymsgp);
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
                      yytoken, &yylval, context);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[yystate], yyvsp, context);
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
  yyerror (context, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, context);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, context);
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
