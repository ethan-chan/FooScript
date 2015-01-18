/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 34 "parser2.y"

#include <stdio.h>

extern int lineno;

static void yyerror(char *s);

/* Line 371 of yacc.c  */
#line 76 "parser2.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER = 259,
     FLOATING = 260,
     CHARACTER = 261,
     STRING = 262,
     TYPEDEF_NAME = 263,
     NAMESPACE_NAME = 264,
     CLASS_NAME = 265,
     ENUM_NAME = 266,
     TEMPLATE_NAME = 267,
     ELLIPSIS = 268,
     COLONCOLON = 269,
     DOTSTAR = 270,
     ADDEQ = 271,
     SUBEQ = 272,
     MULEQ = 273,
     DIVEQ = 274,
     MODEQ = 275,
     XOREQ = 276,
     ANDEQ = 277,
     OREQ = 278,
     SL = 279,
     SR = 280,
     SREQ = 281,
     SLEQ = 282,
     EQ = 283,
     NOTEQ = 284,
     LTEQ = 285,
     GTEQ = 286,
     ANDAND = 287,
     OROR = 288,
     PLUSPLUS = 289,
     MINUSMINUS = 290,
     ARROWSTAR = 291,
     ARROW = 292,
     ASM = 293,
     AUTO = 294,
     BOOL = 295,
     BREAK = 296,
     CASE = 297,
     CATCH = 298,
     CHAR = 299,
     CLASS = 300,
     CONST = 301,
     CONST_CAST = 302,
     CONTINUE = 303,
     DEFAULT = 304,
     DELETE = 305,
     DO = 306,
     DOUBLE = 307,
     DYNAMIC_CAST = 308,
     ELSE = 309,
     ENUM = 310,
     EXPLICIT = 311,
     EXPORT = 312,
     EXTERN = 313,
     FALSE = 314,
     FLOAT = 315,
     FOR = 316,
     FRIEND = 317,
     GOTO = 318,
     IF = 319,
     INLINE = 320,
     INT = 321,
     LONG = 322,
     MUTABLE = 323,
     NAMESPACE = 324,
     NEW = 325,
     OPERATOR = 326,
     PRIVATE = 327,
     PROTECTED = 328,
     PUBLIC = 329,
     REGISTER = 330,
     REINTERPRET_CAST = 331,
     RETURN = 332,
     SHORT = 333,
     SIGNED = 334,
     SIZEOF = 335,
     STATIC = 336,
     STATIC_CAST = 337,
     STRUCT = 338,
     SWITCH = 339,
     TEMPLATE = 340,
     THIS = 341,
     THROW = 342,
     TRUE = 343,
     TRY = 344,
     TYPEDEF = 345,
     TYPEID = 346,
     TYPENAME = 347,
     UNION = 348,
     UNSIGNED = 349,
     USING = 350,
     VIRTUAL = 351,
     VOID = 352,
     VOLATILE = 353,
     WCHAR_T = 354,
     WHILE = 355
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 239 "parser2.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3586

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  189
/* YYNRULES -- Number of rules.  */
#define YYNRULES  477
/* YYNRULES -- Number of states.  */
#define YYNSTATES  785

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,     2,     2,   116,   111,     2,
     101,   102,   110,   112,   109,   113,   106,   115,   125,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   122,
     107,   121,   108,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,   117,   126,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   123,   118,   124,   103,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    51,    54,    57,    60,
      64,    66,    68,    70,    72,    74,    76,    79,    81,    85,
      89,    91,    93,    95,   100,   105,   110,   116,   122,   126,
     130,   133,   136,   144,   152,   160,   168,   173,   178,   180,
     184,   191,   196,   198,   201,   204,   207,   210,   215,   217,
     219,   221,   223,   225,   227,   229,   231,   237,   245,   249,
     252,   255,   257,   261,   266,   270,   274,   280,   282,   287,
     289,   293,   297,   299,   303,   307,   311,   313,   317,   321,
     323,   327,   331,   333,   337,   341,   345,   349,   351,   355,
     359,   361,   365,   367,   371,   373,   377,   379,   383,   385,
     389,   391,   397,   399,   403,   405,   407,   409,   411,   413,
     415,   417,   419,   421,   423,   425,   427,   429,   433,   435,
     437,   439,   441,   443,   445,   447,   449,   451,   455,   460,
     464,   467,   471,   473,   476,   482,   490,   496,   498,   503,
     509,   517,   526,   528,   530,   533,   536,   540,   544,   546,
     548,   551,   553,   555,   557,   559,   561,   563,   565,   567,
     569,   571,   573,   575,   579,   581,   583,   585,   587,   589,
     592,   594,   596,   598,   600,   602,   604,   606,   608,   610,
     612,   614,   616,   618,   622,   624,   626,   628,   630,   632,
     634,   636,   638,   640,   642,   644,   646,   648,   650,   655,
     660,   665,   673,   679,   681,   685,   687,   691,   693,   695,
     697,   699,   701,   707,   713,   718,   720,   726,   730,   737,
     742,   749,   755,   761,   765,   767,   771,   774,   776,   779,
     781,   788,   793,   797,   800,   802,   807,   810,   812,   814,
     817,   821,   824,   827,   830,   832,   839,   844,   848,   851,
     855,   857,   861,   864,   869,   872,   877,   882,   886,   888,
     891,   895,   897,   902,   905,   907,   911,   916,   920,   925,
     927,   929,   931,   934,   938,   942,   945,   948,   950,   952,
     954,   958,   961,   964,   968,   971,   974,   977,   979,   983,
     987,   993,   999,  1001,  1003,  1005,  1008,  1011,  1014,  1017,
    1019,  1023,  1028,  1032,  1034,  1037,  1039,  1041,  1045,  1049,
    1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,
    1071,  1073,  1075,  1077,  1079,  1081,  1083,  1085,  1087,  1089,
    1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,  1109,
    1111,  1113,  1115,  1117,  1119,  1121,  1124,  1127,  1134,  1136,
    1140,  1142,  1144,  1147,  1152,  1155,  1160,  1167,  1176,  1181,
    1183,  1187,  1189,  1191,  1193,  1196,  1201,  1205,  1210,  1213,
    1219,  1222,  1225,  1227,  1229,  1232,  1237,  1239,  1243,  1244,
    1246,  1247,  1249,  1250,  1252,  1253,  1255,  1256,  1258,  1259,
    1261,  1262,  1264,  1265,  1267,  1268,  1270,  1271,  1273,  1274,
    1276,  1277,  1279,  1280,  1282,  1283,  1285,  1286,  1288,  1289,
    1291,  1292,  1294,  1295,  1297,  1298,  1300,  1301,  1303,  1304,
    1306,  1307,  1309,  1310,  1312,  1313,  1315,  1316,  1318,  1319,
    1321,  1322,  1324,  1325,  1327,  1328,  1330,  1331,  1333,  1334,
    1336,  1337,  1339,  1340,  1342,  1343,  1345,  1346,  1348,  1349,
    1351,  1352,  1354,  1355,  1357,  1358,  1360,  1361
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     142,     0,    -1,     8,    -1,   130,    -1,   131,    -1,     9,
      -1,     9,    -1,    10,    -1,   263,    -1,    11,    -1,    12,
      -1,     3,    -1,   137,    -1,   138,    -1,   139,    -1,   140,
      -1,   141,    -1,     4,    -1,     6,    -1,     5,    -1,     7,
      -1,    88,    -1,    59,    -1,   276,    -1,   136,    -1,    86,
      -1,    14,   135,    -1,    14,   257,    -1,    14,   146,    -1,
     101,   176,   102,    -1,   144,    -1,   145,    -1,   146,    -1,
     135,    -1,   257,    -1,   250,    -1,   103,   132,    -1,   263,
      -1,   147,   277,   145,    -1,   148,    14,   278,    -1,   132,
      -1,   129,    -1,   143,    -1,   149,   104,   176,   105,    -1,
     149,   101,   279,   102,    -1,   198,   101,   279,   102,    -1,
     149,   106,   277,   280,   144,    -1,   149,    37,   277,   280,
     144,    -1,   149,   106,   151,    -1,   149,    37,   151,    -1,
     149,    34,    -1,   149,    35,    -1,    53,   107,   225,   108,
     101,   176,   102,    -1,    82,   107,   225,   108,   101,   176,
     102,    -1,    76,   107,   225,   108,   101,   176,   102,    -1,
      47,   107,   225,   108,   101,   176,   102,    -1,    91,   101,
     176,   102,    -1,    91,   101,   225,   102,    -1,   174,    -1,
     150,   109,   174,    -1,   280,   278,   199,    14,   103,   199,
      -1,   280,   278,   103,   199,    -1,   149,    -1,    34,   161,
      -1,    35,   161,    -1,   153,   161,    -1,    80,   152,    -1,
      80,   101,   225,   102,    -1,   154,    -1,   160,    -1,   110,
      -1,   111,    -1,   112,    -1,   113,    -1,   114,    -1,   103,
      -1,   280,    70,   281,   156,   282,    -1,   280,    70,   281,
     101,   225,   102,   282,    -1,   101,   150,   102,    -1,   226,
     283,    -1,   221,   283,    -1,   158,    -1,   104,   176,   105,
      -1,   158,   104,   177,   105,    -1,   101,   279,   102,    -1,
     280,    50,   161,    -1,   280,    50,   104,   105,   161,    -1,
     152,    -1,   101,   225,   102,   161,    -1,   161,    -1,   162,
      15,   161,    -1,   162,    36,   161,    -1,   162,    -1,   163,
     110,   162,    -1,   163,   115,   162,    -1,   163,   116,   162,
      -1,   163,    -1,   164,   112,   163,    -1,   164,   113,   163,
      -1,   164,    -1,   165,    24,   164,    -1,   165,    25,   164,
      -1,   165,    -1,   166,   107,   165,    -1,   166,   108,   165,
      -1,   166,    30,   165,    -1,   166,    31,   165,    -1,   166,
      -1,   167,    28,   166,    -1,   167,    29,   166,    -1,   167,
      -1,   168,   111,   167,    -1,   168,    -1,   169,   117,   168,
      -1,   169,    -1,   170,   118,   169,    -1,   170,    -1,   171,
      32,   170,    -1,   171,    -1,   172,    33,   171,    -1,   172,
      -1,   172,   119,   176,   120,   174,    -1,   173,    -1,   172,
     175,   174,    -1,   273,    -1,   121,    -1,    18,    -1,    19,
      -1,    20,    -1,    16,    -1,    17,    -1,    26,    -1,    27,
      -1,    22,    -1,    21,    -1,    23,    -1,   174,    -1,   176,
     109,   174,    -1,   173,    -1,   179,    -1,   180,    -1,   181,
      -1,   183,    -1,   185,    -1,   187,    -1,   188,    -1,   268,
      -1,   135,   120,   178,    -1,    42,   177,   120,   178,    -1,
      49,   120,   178,    -1,   284,   122,    -1,   123,   285,   124,
      -1,   178,    -1,   182,   178,    -1,    64,   101,   184,   102,
     178,    -1,    64,   101,   184,   102,   178,    54,   178,    -1,
      84,   101,   184,   102,   178,    -1,   176,    -1,   226,   219,
     121,   174,    -1,   100,   101,   184,   102,   178,    -1,    51,
     178,   100,   101,   176,   102,   122,    -1,    61,   101,   186,
     286,   122,   284,   102,   178,    -1,   180,    -1,   192,    -1,
      41,   122,    -1,    48,   122,    -1,    77,   284,   122,    -1,
      63,   135,   122,    -1,   191,    -1,   190,    -1,   189,   190,
      -1,   191,    -1,   232,    -1,   259,    -1,   266,    -1,   267,
      -1,   216,    -1,   205,    -1,   192,    -1,   215,    -1,   211,
      -1,   213,    -1,   214,    -1,   287,   288,   122,    -1,   195,
      -1,   197,    -1,   196,    -1,    62,    -1,    90,    -1,   287,
     193,    -1,    39,    -1,    75,    -1,    81,    -1,    58,    -1,
      68,    -1,    65,    -1,    96,    -1,    56,    -1,   198,    -1,
     237,    -1,   201,    -1,   200,    -1,   223,    -1,   280,   278,
     199,    -1,    44,    -1,    99,    -1,    40,    -1,    78,    -1,
      66,    -1,    67,    -1,    79,    -1,    94,    -1,    60,    -1,
      52,    -1,    97,    -1,   132,    -1,   133,    -1,   128,    -1,
     239,   280,   278,   135,    -1,    55,   280,   278,   135,    -1,
      92,   280,   147,   135,    -1,    92,   280,   147,   135,   107,
     264,   108,    -1,    55,   289,   123,   290,   124,    -1,   203,
      -1,   202,   109,   203,    -1,   204,    -1,   204,   121,   177,
      -1,   135,    -1,   206,    -1,   209,    -1,   207,    -1,   208,
      -1,    69,   135,   123,   210,   124,    -1,    69,   130,   123,
     210,   124,    -1,    69,   123,   210,   124,    -1,   276,    -1,
      69,   135,   121,   212,   122,    -1,   280,   278,   129,    -1,
      95,   291,   280,   147,   145,   122,    -1,    95,    14,   145,
     122,    -1,    95,    69,   280,   278,   129,   122,    -1,    38,
     101,   140,   102,   122,    -1,    58,   140,   123,   276,   124,
      -1,    58,   140,   190,    -1,   218,    -1,   217,   109,   218,
      -1,   219,   292,    -1,   220,    -1,   221,   219,    -1,   224,
      -1,   220,   101,   229,   102,   293,   294,    -1,   220,   104,
     295,   105,    -1,   101,   219,   102,    -1,   110,   293,    -1,
     111,    -1,   280,   147,   110,   293,    -1,   223,   293,    -1,
      46,    -1,    98,    -1,   280,   144,    -1,   280,   278,   199,
      -1,   226,   296,    -1,   197,   297,    -1,   221,   296,    -1,
     228,    -1,   298,   101,   229,   102,   293,   294,    -1,   298,
     104,   295,   105,    -1,   101,   227,   102,    -1,   299,   300,
      -1,   230,   109,    13,    -1,   231,    -1,   230,   109,   231,
      -1,   194,   219,    -1,   194,   219,   121,   174,    -1,   194,
     296,    -1,   194,   296,   121,   174,    -1,   287,   219,   301,
     233,    -1,   287,   219,   269,    -1,   181,    -1,   121,   235,
      -1,   101,   150,   102,    -1,   174,    -1,   123,   236,   302,
     124,    -1,   123,   124,    -1,   235,    -1,   236,   109,   235,
      -1,   238,   123,   303,   124,    -1,   239,   289,   304,    -1,
     239,   147,   135,   304,    -1,    45,    -1,    83,    -1,    93,
      -1,   241,   303,    -1,   249,   120,   303,    -1,   287,   305,
     122,    -1,   232,   306,    -1,   146,   122,    -1,   213,    -1,
     259,    -1,   243,    -1,   242,   109,   243,    -1,   219,   307,
      -1,   219,   308,    -1,   289,   120,   177,    -1,   121,   125,
      -1,   121,   177,    -1,   120,   247,    -1,   248,    -1,   247,
     109,   248,    -1,   280,   278,   132,    -1,    96,   309,   280,
     278,   132,    -1,   249,   310,   280,   278,   132,    -1,    72,
      -1,    73,    -1,    74,    -1,    71,   251,    -1,   226,   311,
      -1,   221,   311,    -1,   120,   254,    -1,   255,    -1,   255,
     109,   254,    -1,   256,   101,   279,   102,    -1,   280,   278,
     132,    -1,   135,    -1,    71,   258,    -1,    70,    -1,    50,
      -1,    70,   104,   105,    -1,    50,   104,   105,    -1,   112,
      -1,   126,    -1,   110,    -1,   115,    -1,   116,    -1,   117,
      -1,   111,    -1,   118,    -1,   103,    -1,   114,    -1,   121,
      -1,   107,    -1,   108,    -1,    16,    -1,    17,    -1,    18,
      -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,   109,    -1,    36,    -1,    37,
      -1,   101,   102,    -1,   104,   105,    -1,   312,    85,   107,
     260,   108,   190,    -1,   261,    -1,   260,   109,   261,    -1,
     262,    -1,   231,    -1,    45,   289,    -1,    45,   289,   121,
     225,    -1,    92,   289,    -1,    92,   289,   121,   225,    -1,
      85,   107,   260,   108,    45,   289,    -1,    85,   107,   260,
     108,    45,   289,   121,   134,    -1,   134,   107,   264,   108,
      -1,   265,    -1,   264,   109,   265,    -1,   174,    -1,   225,
      -1,   134,    -1,    85,   190,    -1,    85,   107,   108,   190,
      -1,    89,   181,   270,    -1,    89,   301,   233,   270,    -1,
     271,   313,    -1,    43,   101,   272,   102,   181,    -1,   226,
     219,    -1,   226,   227,    -1,   226,    -1,    13,    -1,    87,
     314,    -1,    87,   101,   315,   102,    -1,   225,    -1,   275,
     109,   225,    -1,    -1,   189,    -1,    -1,    85,    -1,    -1,
     147,    -1,    -1,   150,    -1,    -1,    14,    -1,    -1,   155,
      -1,    -1,   159,    -1,    -1,   157,    -1,    -1,   176,    -1,
      -1,   182,    -1,    -1,   184,    -1,    -1,   194,    -1,    -1,
     217,    -1,    -1,   135,    -1,    -1,   202,    -1,    -1,    92,
      -1,    -1,   234,    -1,    -1,   222,    -1,    -1,   274,    -1,
      -1,   177,    -1,    -1,   227,    -1,    -1,   226,    -1,    -1,
     228,    -1,    -1,   230,    -1,    -1,    13,    -1,    -1,   253,
      -1,    -1,   109,    -1,    -1,   240,    -1,    -1,   246,    -1,
      -1,   242,    -1,    -1,   122,    -1,    -1,   244,    -1,    -1,
     245,    -1,    -1,   249,    -1,    -1,    96,    -1,    -1,   252,
      -1,    -1,    57,    -1,    -1,   270,    -1,    -1,   174,    -1,
      -1,   275,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    77,    82,    87,    88,    93,
      98,   106,   110,   111,   112,   113,   114,   118,   122,   126,
     130,   134,   135,   143,   151,   152,   153,   154,   155,   156,
     157,   161,   162,   166,   167,   168,   169,   170,   174,   178,
     182,   183,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   206,   207,
     211,   212,   216,   217,   218,   219,   220,   221,   222,   223,
     227,   228,   229,   230,   231,   232,   236,   237,   241,   245,
     249,   250,   254,   255,   259,   263,   264,   268,   269,   273,
     274,   275,   279,   280,   281,   282,   286,   287,   288,   292,
     293,   294,   298,   299,   300,   301,   302,   306,   307,   308,
     312,   313,   317,   318,   322,   323,   327,   328,   332,   333,
     337,   338,   342,   343,   344,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   362,   363,   367,   375,
     376,   377,   378,   379,   380,   381,   382,   386,   387,   388,
     392,   396,   400,   401,   405,   406,   407,   411,   412,   416,
     417,   418,   422,   423,   427,   428,   429,   430,   434,   442,
     443,   447,   448,   449,   450,   451,   452,   453,   457,   458,
     459,   460,   461,   465,   469,   470,   471,   472,   473,   477,
     481,   482,   483,   484,   485,   489,   490,   491,   501,   502,
     503,   504,   505,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   524,   525,   526,   530,   531,
     532,   533,   543,   547,   548,   552,   553,   557,   572,   573,
     577,   578,   582,   586,   590,   594,   604,   608,   612,   613,
     617,   621,   625,   626,   634,   635,   639,   643,   644,   648,
     649,   650,   651,   655,   656,   657,   661,   665,   666,   670,
     671,   675,   679,   683,   684,   688,   689,   690,   694,   695,
     699,   700,   704,   705,   706,   707,   711,   712,   716,   720,
     721,   725,   726,   727,   731,   732,   747,   751,   752,   756,
     757,   758,   762,   763,   767,   768,   769,   770,   771,   775,
     776,   780,   781,   782,   791,   795,   803,   807,   808,   812,
     813,   814,   818,   819,   820,   828,   832,   836,   840,   844,
     845,   849,   853,   854,   862,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   883,   884,   885,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   902,   903,   904,   905,   906,   907,   915,   919,   920,
     924,   925,   929,   930,   931,   932,   933,   934,   938,   948,
     949,   953,   954,   955,   959,   963,   971,   975,   979,   983,
     987,   988,   989,   990,   994,   998,  1002,  1003,  1010,  1012,
    1015,  1017,  1020,  1022,  1025,  1027,  1030,  1032,  1035,  1037,
    1040,  1042,  1045,  1047,  1050,  1052,  1055,  1057,  1060,  1062,
    1065,  1067,  1070,  1072,  1075,  1077,  1080,  1082,  1085,  1087,
    1090,  1092,  1095,  1097,  1100,  1102,  1105,  1107,  1110,  1112,
    1115,  1117,  1120,  1122,  1125,  1127,  1130,  1132,  1135,  1137,
    1140,  1142,  1145,  1147,  1150,  1152,  1155,  1157,  1160,  1162,
    1165,  1167,  1170,  1172,  1175,  1177,  1180,  1182,  1185,  1187,
    1190,  1192,  1195,  1197,  1200,  1202,  1205,  1207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "FLOATING",
  "CHARACTER", "STRING", "TYPEDEF_NAME", "NAMESPACE_NAME", "CLASS_NAME",
  "ENUM_NAME", "TEMPLATE_NAME", "ELLIPSIS", "COLONCOLON", "DOTSTAR",
  "ADDEQ", "SUBEQ", "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "ANDEQ", "OREQ",
  "SL", "SR", "SREQ", "SLEQ", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND",
  "OROR", "PLUSPLUS", "MINUSMINUS", "ARROWSTAR", "ARROW", "ASM", "AUTO",
  "BOOL", "BREAK", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONST_CAST",
  "CONTINUE", "DEFAULT", "DELETE", "DO", "DOUBLE", "DYNAMIC_CAST", "ELSE",
  "ENUM", "EXPLICIT", "EXPORT", "EXTERN", "FALSE", "FLOAT", "FOR",
  "FRIEND", "GOTO", "IF", "INLINE", "INT", "LONG", "MUTABLE", "NAMESPACE",
  "NEW", "OPERATOR", "PRIVATE", "PROTECTED", "PUBLIC", "REGISTER",
  "REINTERPRET_CAST", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STATIC_CAST", "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THROW", "TRUE",
  "TRY", "TYPEDEF", "TYPEID", "TYPENAME", "UNION", "UNSIGNED", "USING",
  "VIRTUAL", "VOID", "VOLATILE", "WCHAR_T", "WHILE", "'('", "')'", "'~'",
  "'['", "']'", "'.'", "'<'", "'>'", "','", "'*'", "'&'", "'+'", "'-'",
  "'!'", "'/'", "'%'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "'0'", "'_'", "$accept", "typedef_name", "namespace_name",
  "original_namespace_name", "namespace_alias", "class_name", "enum_name",
  "template_name", "identifier", "literal", "integer_literal",
  "character_literal", "floating_literal", "string_literal",
  "boolean_literal", "translation_unit", "primary_expression",
  "id_expression", "unqualified_id", "qualified_id",
  "nested_name_specifier", "class_or_namespace_name", "postfix_expression",
  "expression_list", "pseudo_destructor_name", "unary_expression",
  "unary_operator", "new_expression", "new_placement", "new_type_id",
  "new_declarator", "direct_new_declarator", "new_initializer",
  "delete_expression", "cast_expression", "pm_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_seq",
  "selection_statement", "condition", "iteration_statement",
  "for_init_statement", "jump_statement", "declaration_statement",
  "declaration_seq", "declaration", "block_declaration",
  "simple_declaration", "decl_specifier", "decl_specifier_seq",
  "storage_class_specifier", "function_specifier", "type_specifier",
  "simple_type_specifier", "type_name", "elaborated_type_specifier",
  "enum_specifier", "enumerator_list", "enumerator_definition",
  "enumerator", "namespace_definition", "named_namespace_definition",
  "original_namespace_definition", "extension_namespace_definition",
  "unnamed_namespace_definition", "namespace_body",
  "namespace_alias_definition", "qualified_namespace_specifier",
  "using_declaration", "using_directive", "asm_definition",
  "linkage_specification", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "ptr_operator", "cv_qualifier_seq",
  "cv_qualifier", "declarator_id", "type_id", "type_specifier_seq",
  "abstract_declarator", "direct_abstract_declarator",
  "parameter_declaration_clause", "parameter_declaration_list",
  "parameter_declaration", "function_definition", "function_body",
  "initializer", "initializer_clause", "initializer_list",
  "class_specifier", "class_head", "class_key", "member_specification",
  "member_declaration", "member_declarator_list", "member_declarator",
  "pure_specifier", "constant_initializer", "base_clause",
  "base_specifier_list", "base_specifier", "access_specifier",
  "conversion_function_id", "conversion_type_id", "conversion_declarator",
  "ctor_initializer", "mem_initializer_list", "mem_initializer",
  "mem_initializer_id", "operator_function_id", "operator",
  "template_declaration", "template_parameter_list", "template_parameter",
  "type_parameter", "template_id", "template_argument_list",
  "template_argument", "explicit_instantiation", "explicit_specialization",
  "try_block", "function_try_block", "handler_seq", "handler",
  "exception_declaration", "throw_expression", "exception_specification",
  "type_id_list", "declaration_seq_opt", "TEMPLATE_opt",
  "nested_name_specifier_opt", "expression_list_opt", "COLONCOLON_opt",
  "new_placement_opt", "new_initializer_opt", "new_declarator_opt",
  "expression_opt", "statement_seq_opt", "condition_opt",
  "decl_specifier_seq_opt", "init_declarator_list_opt", "identifier_opt",
  "enumerator_list_opt", "TYPENAME_opt", "initializer_opt",
  "cv_qualifier_seq_opt", "exception_specification_opt",
  "constant_expression_opt", "abstract_declarator_opt",
  "type_specifier_seq_opt", "direct_abstract_declarator_opt",
  "parameter_declaration_list_opt", "ELLIPSIS_opt", "ctor_initializer_opt",
  "COMMA_opt", "member_specification_opt", "base_clause_opt",
  "member_declarator_list_opt", "SEMICOLON_opt", "pure_specifier_opt",
  "constant_initializer_opt", "access_specifier_opt", "VIRTUAL_opt",
  "conversion_declarator_opt", "EXPORT_opt", "handler_seq_opt",
  "assignment_expression_opt", "type_id_list_opt", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,    40,    41,   126,    91,    93,    46,    60,    62,    44,
      42,    38,    43,    45,    33,    47,    37,    94,   124,    63,
      58,    61,    59,   123,   125,    48,    95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   127,   128,   129,   129,   130,   131,   132,   132,   133,
     134,   135,   136,   136,   136,   136,   136,   137,   138,   139,
     140,   141,   141,   142,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   145,   145,   145,   145,   145,   146,   147,
     148,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     153,   153,   153,   153,   153,   153,   154,   154,   155,   156,
     157,   157,   158,   158,   159,   160,   160,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   164,   164,   164,   165,
     165,   165,   166,   166,   166,   166,   166,   167,   167,   167,
     168,   168,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   174,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   176,   176,   177,   178,
     178,   178,   178,   178,   178,   178,   178,   179,   179,   179,
     180,   181,   182,   182,   183,   183,   183,   184,   184,   185,
     185,   185,   186,   186,   187,   187,   187,   187,   188,   189,
     189,   190,   190,   190,   190,   190,   190,   190,   191,   191,
     191,   191,   191,   192,   193,   193,   193,   193,   193,   194,
     195,   195,   195,   195,   195,   196,   196,   196,   197,   197,
     197,   197,   197,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   199,   199,   199,   200,   200,
     200,   200,   201,   202,   202,   203,   203,   204,   205,   205,
     206,   206,   207,   208,   209,   210,   211,   212,   213,   213,
     214,   215,   216,   216,   217,   217,   218,   219,   219,   220,
     220,   220,   220,   221,   221,   221,   222,   223,   223,   224,
     224,   225,   226,   227,   227,   228,   228,   228,   229,   229,
     230,   230,   231,   231,   231,   231,   232,   232,   233,   234,
     234,   235,   235,   235,   236,   236,   237,   238,   238,   239,
     239,   239,   240,   240,   241,   241,   241,   241,   241,   242,
     242,   243,   243,   243,   244,   245,   246,   247,   247,   248,
     248,   248,   249,   249,   249,   250,   251,   252,   253,   254,
     254,   255,   256,   256,   257,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   259,   260,   260,
     261,   261,   262,   262,   262,   262,   262,   262,   263,   264,
     264,   265,   265,   265,   266,   267,   268,   269,   270,   271,
     272,   272,   272,   272,   273,   274,   275,   275,   276,   276,
     277,   277,   278,   278,   279,   279,   280,   280,   281,   281,
     282,   282,   283,   283,   284,   284,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   295,   296,   296,
     297,   297,   298,   298,   299,   299,   300,   300,   301,   301,
     302,   302,   303,   303,   304,   304,   305,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   310,   311,   311,
     312,   312,   313,   313,   314,   314,   315,   315
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     1,     4,     4,     4,     5,     5,     3,     3,
       2,     2,     7,     7,     7,     7,     4,     4,     1,     3,
       6,     4,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     7,     3,     2,
       2,     1,     3,     4,     3,     3,     5,     1,     4,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     5,     7,     5,     1,     4,     5,
       7,     8,     1,     1,     2,     2,     3,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     7,     5,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     5,     5,     4,     1,     5,     3,     6,     4,
       6,     5,     5,     3,     1,     3,     2,     1,     2,     1,
       6,     4,     3,     2,     1,     4,     2,     1,     1,     2,
       3,     2,     2,     2,     1,     6,     4,     3,     2,     3,
       1,     3,     2,     4,     2,     4,     4,     3,     1,     2,
       3,     1,     4,     2,     1,     3,     4,     3,     4,     1,
       1,     1,     2,     3,     3,     2,     2,     1,     1,     1,
       3,     2,     2,     3,     2,     2,     2,     1,     3,     3,
       5,     5,     1,     1,     1,     2,     2,     2,     2,     1,
       3,     4,     3,     1,     2,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     6,     1,     3,
       1,     1,     2,     4,     2,     4,     6,     8,     4,     1,
       3,     1,     1,     1,     2,     4,     3,     4,     2,     5,
       2,     2,     1,     1,     2,     4,     1,     3,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     420,     0,   471,     0,     0,   420,   428,     0,   420,   169,
     171,   178,   421,   177,   228,   230,   231,   229,   180,   181,
     182,   179,   176,   172,   173,   174,   175,    23,   406,     0,
       0,    20,   420,    11,     5,   420,     0,     0,     0,   384,
       0,   406,   429,   406,     1,   170,   407,   190,   206,   204,
     289,   257,   213,   406,   197,   193,   212,   187,   195,   208,
     209,   194,   191,   207,   210,   192,   290,   188,   406,   291,
     211,   196,   214,   258,   205,   406,   432,   254,   189,   184,
     186,   185,   198,   201,   200,   423,   244,   430,   247,   406,
     202,   249,   199,     0,   424,   402,     0,     0,     0,   420,
     243,     0,   235,   420,   406,   420,   420,    10,   406,     0,
       0,    33,     0,    35,    34,    37,     0,     0,   425,   402,
       0,     0,     0,   402,   433,   432,   253,   406,   448,   406,
     406,   406,   431,   449,   277,   246,     0,   420,   406,   248,
     420,     5,     7,    41,     3,     4,    40,     0,     0,     8,
     402,   454,   259,    31,    32,   400,    37,     0,   183,   420,
       0,     0,   234,     0,     0,     0,     0,   385,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   363,   364,
     326,   325,     0,   337,     0,   340,   341,   362,   331,   335,
     329,   338,   332,   333,   334,   336,   339,   330,   440,   468,
     315,   324,   402,    36,   406,   239,   403,     0,     0,     0,
     426,     0,   252,     0,   256,   245,   430,     0,    17,    19,
      18,   407,   406,   406,     0,     0,    22,     0,   406,     0,
      25,   474,    21,     0,   406,    75,    70,    71,    72,    73,
      74,    24,    12,    13,    14,    15,    16,    42,    30,   400,
      62,     0,    87,   406,    68,    69,    89,    92,    96,    99,
     102,   107,   110,   112,   114,   116,   118,   120,   122,    58,
       0,   124,   402,   323,   318,   319,     0,     0,   406,   281,
     279,   420,   278,   276,   421,     0,   445,   270,   406,   446,
     120,   138,   437,     0,   312,   313,   314,   428,     0,   297,
     458,   453,   420,     0,   298,   406,     0,   454,   402,     0,
     406,   455,   287,   401,   432,     0,     2,     9,   217,   215,
     216,   203,   424,     0,   424,   371,     0,   368,   370,   241,
     242,   233,   236,     0,   232,     0,     0,   365,   366,   441,
     262,   468,   469,     0,   316,     0,   383,   381,   198,   382,
     406,     0,   379,     0,     0,   219,   227,   427,   223,   225,
       0,   220,   260,     0,     0,    26,    28,    27,    63,    64,
     406,   406,   406,   406,    66,   406,   475,   394,   406,   136,
       0,     0,    50,    51,   400,   406,   406,   400,   280,   406,
      65,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     129,   130,   126,   127,   128,   134,   133,   135,   131,   132,
     406,   406,   125,   406,   406,   406,   408,   406,   406,     0,
     283,   284,   450,     0,   406,     0,     0,   420,     0,     0,
       0,     0,   406,     0,     0,     0,    33,   415,   152,   139,
     140,   141,   420,   142,   143,   144,   145,   168,   146,     0,
       0,   406,   406,   272,   406,   439,   264,   274,     0,   432,
     420,   447,   268,   251,   296,   459,   295,   292,   420,   460,
     457,   299,     0,     0,   286,   288,    39,   218,   464,   306,
     307,   466,     0,   255,    38,   372,   420,   374,   420,   420,
     237,   328,   327,   317,     0,   203,   406,   406,   261,   378,
     406,   240,   238,     0,   406,   222,   406,     0,   387,   472,
       0,     0,     0,     0,     0,     0,     0,    29,   406,   406,
      49,   406,   402,   405,     0,     0,    48,   406,    59,    90,
      91,    93,    94,    95,    97,    98,   100,   101,   105,   106,
     103,   104,   108,   109,   111,   113,   115,   117,   119,     0,
     123,     0,     0,    85,   406,   409,   406,   320,     0,   322,
     406,     0,   164,     0,   165,   420,     0,   420,     0,   406,
       0,     0,   406,     0,   406,   420,   153,   150,   151,     0,
     406,   263,   406,   420,   406,   434,   269,   271,   293,   406,
     461,   463,   301,   302,   406,   406,   294,   465,   406,   406,
     467,   406,     0,   406,     0,   406,   367,   369,   380,   224,
     226,     0,   406,   473,   388,     0,     0,     0,    67,     0,
      56,    57,   137,    88,     0,     0,    44,    43,     0,   406,
      45,   406,     0,   406,   410,   412,   321,   285,   282,   420,
     149,     0,   162,   406,   163,   167,   157,     0,   406,   166,
       0,   386,     0,   147,   267,   273,   275,     0,     0,     0,
     435,   250,   304,   305,   460,   300,   303,     0,   308,     0,
     309,   373,     0,   375,   221,   393,   406,     0,   406,   406,
     406,   406,    47,     0,     0,    46,   121,    86,    78,     0,
     406,   411,    76,   406,   413,    81,   412,    79,   148,   406,
     419,     0,   420,     0,   420,   420,   432,   266,   406,     0,
       0,   424,   390,   391,     0,     0,     0,     0,     0,    61,
       0,   410,     0,     0,   406,    80,     0,   406,   154,   406,
     156,   159,   434,   396,   477,     0,   310,   311,   376,   389,
      55,    52,    54,    53,     0,    77,    84,    82,     0,     0,
       0,   420,   158,   265,   406,   395,     0,    60,    83,   160,
     420,   155,   397,   377,   161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   328,   143,   144,   145,   146,   330,   110,   111,   251,
     252,   253,   254,   255,   256,     7,   257,   258,   153,   154,
     259,   148,   260,   543,   540,   262,   263,   264,   575,   654,
     714,   715,   711,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   389,   433,   457,
     302,   458,   459,   460,   461,   462,   463,   667,   464,   663,
     465,   466,     8,     9,   467,    11,    78,    12,    79,    80,
     208,   280,   331,    83,    84,   367,   368,   369,    13,    14,
      15,    16,    17,   101,    18,   164,    19,    20,    21,    22,
      85,    86,   122,    88,    89,   124,    90,    91,   359,   360,
     475,   476,   295,   296,   335,    23,   293,   132,   290,   442,
      92,    93,    94,   311,   312,   490,   491,   610,   611,   321,
     499,   500,   313,   113,   210,   352,   133,   284,   285,   286,
     114,   211,    24,   336,   337,   338,   156,   361,   362,    25,
      26,   468,   134,   528,   529,   697,   281,   680,   754,   102,
     325,   355,   544,   282,   576,   712,   717,   469,   470,   721,
     471,    96,   492,   370,    43,   135,   126,   681,   303,   601,
     350,   478,   299,   482,   136,   581,   316,   322,   493,   486,
     612,   613,   618,   621,   354,    29,   634,   387,   755
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -504
static const yytype_int16 yypact[] =
{
     668,   -21,  -504,   110,    35,   981,    85,   132,   198,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  2051,    52,
     110,  -504,   742,  -504,  -504,   763,    33,   231,    42,  -504,
      69,   155,  -504,   155,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,    63,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,   155,  -504,
    -504,  -504,  -504,  -504,  -504,    81,    14,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,    75,  -504,   156,   137,    81,
    -504,  -504,  -504,   120,   533,   341,    71,   144,   166,   763,
    -504,   122,  -504,   763,   155,   763,   805,  -504,  2173,   311,
     165,  -504,   175,  -504,  -504,  -504,   289,   289,  -504,   289,
     187,   289,   254,   341,  -504,    14,  -504,    81,   215,  2745,
      91,  1536,  -504,  -504,  -504,  -504,   240,    27,  2857,  -504,
     617,  -504,  -504,  -504,  -504,  -504,  -504,   372,   367,  -504,
     289,   267,  -504,  -504,  -504,    51,   381,   514,  -504,   -10,
     277,   279,  -504,   285,   300,   289,   306,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
     338,   349,   358,  -504,   360,  -504,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  3371,   154,
    -504,  -504,   289,  -504,  2297,  -504,  -504,   458,    69,   372,
     372,   372,  -504,   514,  -504,  -504,   -58,   240,  -504,  -504,
    -504,   329,  3081,  3081,   377,   379,  -504,   387,  3193,   392,
    -504,  2409,  -504,   399,  2297,   311,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,   422,
     558,   -16,  -504,  3081,  -504,  -504,  -504,    70,   305,    32,
     184,   104,   193,   398,   386,   411,   484,   922,  -504,  -504,
     416,  -504,   428,  -504,  -504,   424,   437,   289,  1171,  -504,
    -504,   923,  -504,  -504,  2067,   438,   452,  -504,  3427,   550,
      38,  -504,  -504,   441,  -504,  -504,  -504,    73,   445,  -504,
     449,  -504,   617,   453,  -504,  1963,   450,   267,   289,   372,
     332,  -504,  -504,  -504,    14,    69,  -504,  -504,  -504,  -504,
    -504,   293,   372,   471,   372,  -504,   176,  -504,  -504,  -504,
    -504,  -504,  -504,   458,  -504,   474,   479,  -504,  -504,  -504,
    -504,   154,  -504,   289,  -504,   514,   165,  -504,   416,  -504,
     673,   355,  -504,   464,   466,  -504,  -504,   488,  -504,   486,
     476,   502,  -504,   571,  3292,  -504,  -504,  -504,  -504,  -504,
    3487,  3487,  3487,  2297,  -504,  3487,  -504,  -504,  2297,  -504,
      21,   513,  -504,  -504,    90,  2521,  2745,    90,  -504,  2745,
    -504,  3081,  3081,  3081,  3081,  3081,  3081,  3081,  3081,  3081,
    3081,  3081,  3081,  3081,  3081,  3081,  3081,  3081,  3081,  3081,
    -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,  -504,
    3081,  2745,  -504,  2745,  2521,  2969,   516,    91,  2521,   311,
    -504,  -504,   509,   506,  3081,   510,   503,  1415,   538,   372,
     539,   372,  1882,   541,   240,   543,   525,   537,  -504,  -504,
    -504,  -504,  1049,  -504,  -504,  -504,  -504,  -504,  -504,   527,
     529,  2051,   546,   542,   715,  -504,   159,   544,   263,    14,
     645,  -504,  -504,  -504,  -504,  -504,  -504,  -504,   617,   501,
     551,  -504,   553,   548,  -504,  -504,  -504,  -504,   362,   557,
    -504,   584,   289,  -504,  -504,   561,   -10,   563,   805,   -10,
    -504,  -504,  -504,  -504,   575,  -504,   647,   673,  -504,  -504,
    2297,  -504,  -504,   372,  3081,  -504,  2297,   585,  -504,   571,
     580,   586,   590,   591,   593,    92,   597,  -504,  2745,  3081,
    -504,   155,   289,   598,   607,   115,  -504,   155,  -504,  -504,
    -504,    70,    70,    70,   305,   305,    32,    32,   184,   184,
     184,   184,   104,   104,   193,   398,   386,   411,   484,    -1,
    -504,   608,   606,  -504,  2745,  -504,  1264,  -504,   611,  -504,
    1293,   599,  -504,   594,  -504,  1415,   615,  1768,   600,  2297,
     603,   609,  2297,   571,  2297,  1415,  -504,  -504,  -504,   628,
    2745,  -504,  2745,    27,  2857,   648,  -504,  -504,  -504,   800,
    -504,  -504,  -504,  -504,   139,  3081,  -504,  -504,   155,   332,
    -504,   155,   311,  3487,   366,  3487,  -504,  -504,  -504,  -504,
    -504,   374,  1507,  -504,  -504,   631,   638,   639,  -504,   641,
    -504,  -504,  -504,  -504,   341,   223,  -504,  -504,   341,  2745,
    -504,  3081,   105,  3487,   642,   282,  -504,  -504,  -504,  1415,
    -504,   643,  -504,  1648,  -504,  -504,   537,   644,    81,  -504,
     653,  -504,   654,  -504,  -504,  -504,  -504,   659,   640,   649,
    -504,  -504,  -504,  -504,   652,  -504,  -504,   289,  -504,   289,
    -504,  -504,   719,  -504,  -504,  -504,   447,   663,  2745,  2745,
    2745,  2745,  -504,   514,   752,  -504,  -504,  -504,  -504,   666,
    2521,  -504,  -504,  2745,  -504,   665,   282,  -504,  -504,  2745,
    -504,   656,  1415,   658,  1415,  1415,    14,  -504,  1142,   311,
     311,   372,  -504,  -504,   240,   135,   145,   200,   205,  -504,
     667,   642,   683,   157,  3081,  -504,   216,  2633,   732,  2745,
    -504,  -504,   648,  -504,   682,   690,  -504,  -504,   672,  -504,
    -504,  -504,  -504,  -504,   514,  -504,  -504,  -504,   691,   675,
     693,  1415,  -504,  -504,  3487,  -504,   786,  -504,  -504,  -504,
    1415,  -504,  -504,  -504,  -504
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -504,  -504,  -191,   809,  -504,   -26,  -504,  -207,    -4,  -504,
    -504,  -504,  -504,    62,  -504,  -504,  -504,   -78,    12,  -122,
     418,  -504,  -504,  -118,   425,   577,  -504,  -504,  -504,  -504,
    -504,  -504,  -504,  -504,  -196,   233,    64,   -18,   142,    76,
     412,   413,   415,   410,   401,  -136,  -128,   -15,  -504,    89,
    -386,  -314,  -504,   251,  -130,  -504,  -504,  -503,  -504,  -504,
    -504,  -504,  -504,     7,    68,   252,  -504,  -108,  -504,  -504,
      -9,   -12,  -214,  -504,  -504,  -504,   318,  -504,  -504,  -504,
    -504,  -504,  -504,   336,  -504,  -504,  -109,  -504,  -504,  -504,
    -504,   718,   -25,  -504,   -24,  -504,   -72,  -504,    44,   -88,
    -438,  -504,   239,  -504,  -123,   -99,   619,  -504,  -275,  -504,
    -504,  -504,  -504,  -504,  -504,  -504,   235,  -504,  -504,  -504,
    -504,   232,  -270,  -504,  -504,  -504,  -504,   417,  -504,  -504,
     624,  -504,   -94,   344,   347,  -504,    30,   331,   348,  -504,
    -504,  -504,  -504,  -482,  -504,  -504,  -504,  -504,  -504,    79,
    -279,    60,  -406,   -20,  -504,   123,   153,  -427,  -504,  -504,
      22,  -504,   -52,  -504,  -504,  -504,  -120,   109,   266,  -238,
    -504,  -504,  -504,  -504,   744,  -504,  -288,   556,  -504,  -504,
    -504,  -504,  -504,  -504,   524,  -504,  -504,  -504,  -504
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -477
static const yytype_int16 yytable[] =
{
      37,   120,   300,    87,   125,   224,   292,   356,    95,   372,
     301,   261,    39,   441,   297,    45,    82,   152,   308,    81,
     209,   116,    28,   117,   487,   591,   363,    28,   571,   294,
      28,   309,   578,   119,   599,   332,   378,   379,    33,   100,
    -444,   310,   151,   129,    34,   152,   314,   633,   121,   118,
     501,   294,   112,   125,    28,   123,   477,    28,   583,  -403,
      51,  -403,  -403,   131,   139,    32,    33,   400,    10,   123,
     115,   430,    33,    10,   150,   333,    10,    46,   599,    27,
      30,   107,   334,   213,   165,   401,   398,    40,   212,   670,
     118,   672,    98,   399,    33,    46,    82,   292,  -406,    40,
      10,  -406,   226,    10,    46,    46,   402,   123,   538,   376,
     287,   671,    73,   167,   279,   541,   289,    31,   547,   649,
     349,    28,   518,   537,   149,    28,   283,    28,    28,  -444,
     538,   329,    44,   586,   410,   411,   323,    97,   630,   149,
     108,   515,    33,   317,   406,   407,   149,   149,   596,   149,
     106,   149,   510,    46,    41,   157,   103,   431,    35,   298,
     720,   324,   315,  -406,  -406,    42,  -406,    10,    46,    46,
     149,    10,   109,    10,    10,   323,   217,    42,   161,   219,
     149,   298,    75,   223,   127,   351,  -424,   149,   212,   353,
     308,    76,    77,   158,   640,   149,    82,   329,  -399,   357,
     608,   538,   358,   309,   503,   549,   550,   708,   408,   409,
     319,   412,   413,   310,   399,   365,   366,   371,   314,   213,
     647,   414,   415,   683,   538,   343,   386,   375,   617,   686,
     364,   326,   358,   142,   327,   107,     1,   760,   137,   573,
      75,   138,   149,   140,   538,   128,   162,   761,   115,    76,
      77,   159,   125,   149,   538,     2,     3,   129,   733,  -424,
    -443,   149,   767,  -443,    76,    77,   538,     4,   160,   473,
     474,   660,   214,   289,   123,   149,   130,   131,   212,  -448,
     505,   673,   507,     5,   508,   509,    82,   456,   391,    81,
     489,  -406,  -406,     6,  -406,    95,    46,   215,   141,   142,
     502,   107,   762,    82,   742,   657,    81,   763,   300,   538,
     220,   118,   149,   356,   538,   497,   301,   149,   769,   356,
     770,   142,  -399,   107,   593,   538,   703,   351,   118,   329,
     118,   353,    33,   390,   315,   130,   517,   504,   141,   142,
     353,   107,   149,   643,    33,   718,    46,   439,   149,   501,
     141,   142,   104,   107,   105,   115,   222,   607,   768,   605,
     212,   212,   212,   291,   603,   212,   308,   604,    82,    82,
      82,   358,   294,    82,   542,    33,   358,   542,   496,   309,
     279,   318,  -260,   149,   548,   149,   713,   320,   300,   310,
     556,   557,    76,    77,   314,    -8,   301,  -260,   294,   339,
     374,   294,  -260,   340,   304,   305,   306,   125,   748,   341,
     750,   751,   108,   579,  -260,   403,  -260,   287,   570,   279,
     404,   405,   342,   279,   530,   531,   532,   533,   498,   534,
     344,   704,   536,   283,   304,   305,   306,   141,   142,   163,
     107,   166,   345,   456,   109,   588,   226,   590,   474,   139,
     474,    95,   123,   346,   123,   707,   652,   781,   456,    82,
     347,    46,    81,   519,   520,   348,   784,   141,   300,   149,
     554,   555,   390,   300,   692,   509,   301,   535,   435,   300,
     297,   301,   694,   520,   380,   545,   381,   301,   655,   739,
     562,   563,   517,   517,   382,   294,   353,   353,   436,   385,
     388,   668,   298,   417,   668,   357,   668,   323,   358,   416,
     315,   357,   147,   155,   358,   626,   419,   434,   149,   366,
     569,   644,   326,   642,   142,   327,   107,   648,   298,   418,
      28,   298,   149,   437,   216,   218,    33,   216,   438,   221,
     479,   155,   141,   142,   696,   107,   483,    46,   472,  -392,
     777,  -442,   558,   559,   560,   561,   212,    76,    77,   279,
      46,   480,   622,   481,    82,   289,   702,   484,   216,   783,
     705,   485,   149,   488,   494,   668,    10,   358,   506,   511,
     358,   456,   358,   216,   512,   675,   521,   676,   522,   684,
     128,   456,   392,   393,   123,   394,   690,   523,   687,   502,
     525,   689,   645,   212,   759,   212,   752,   524,   300,   526,
     118,    82,   212,    82,   527,   539,   301,   574,   580,   329,
      82,   130,   609,   585,  -448,   298,   141,   142,   582,   107,
     216,   716,   584,   212,   706,   353,   551,   552,   553,   587,
     589,    82,   592,   723,   594,   595,   538,   472,   123,   597,
    -442,   358,   149,   598,   125,   456,    76,    77,   606,   395,
     614,    46,   396,   600,   397,   602,   619,   691,  -398,   693,
     616,   732,   474,   615,     2,   149,   123,   329,   666,   758,
     620,   666,   623,   666,   625,   324,   632,    46,   635,   304,
     305,   306,   716,   638,   636,   279,   353,   709,   637,   641,
     216,   639,  -470,   756,   757,   216,     1,   399,   212,   646,
     650,   651,   307,   656,   659,   661,    82,   149,   456,   149,
     456,   456,   665,   658,   104,     2,     3,   118,  -438,    46,
     674,   669,   698,   149,   772,   679,   216,     4,   329,   699,
     700,  -452,   701,   710,   719,   727,   722,   729,   516,   730,
     728,  -442,   666,     5,   212,   724,   725,    76,    77,   149,
     149,   726,    82,     6,   731,   734,   740,   456,   741,   744,
     764,   514,   753,   609,   516,  -438,   456,  -442,   747,   749,
       1,  -438,  -438,    76,    77,   766,   771,   735,   736,   737,
     738,   774,   775,   776,   149,   780,   778,   779,   107,     2,
       3,     1,   743,    33,   228,   229,   230,    31,   746,   141,
     142,     4,   107,    36,   231,   384,   472,  -438,   782,  -442,
       2,     3,   546,  -438,  -438,    76,    77,     5,   564,   567,
     565,   568,     4,   566,   232,   233,  -438,     6,   662,   664,
      48,   629,   677,     1,    49,   225,   373,   234,     5,   685,
     624,   688,    52,   235,   577,   377,   627,   631,     6,   236,
      56,   773,     2,     3,   765,    99,    59,    60,   628,   745,
     678,   108,   227,   495,     4,   513,   237,     0,    63,    64,
     238,     0,   239,     0,     0,     0,   240,  -398,   242,     0,
       5,   243,     0,     0,    70,     0,     0,    72,     0,    74,
       6,   244,     0,   245,     0,     0,     0,     0,     0,     0,
     246,   247,   248,   249,   250,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,   682,    33,   228,   229,   230,
      31,  -406,   141,   142,  -406,   107,     0,   231,   420,   421,
     422,   423,   424,   425,   426,   427,     0,     0,   428,   429,
       0,     0,     0,     0,     0,   430,     0,   232,   233,     0,
     216,     1,     0,    48,   443,   444,     0,    49,     0,     0,
     234,   445,   446,  -406,   447,    52,   235,     0,     0,     0,
       0,     0,   236,    56,   448,     0,   449,   450,     0,    59,
      60,     0,   451,  -406,   108,     0,     0,     0,     0,   237,
     452,    63,    64,   238,     0,   239,     0,   453,     0,   240,
     241,   242,   454,     0,   243,     0,     0,    70,     6,     1,
      72,     0,    74,   455,   244,     0,   245,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,   250,     2,     3,
       0,   431,     0,   432,     0,  -414,   291,  -416,     0,     0,
       4,     0,    33,   228,   229,   230,    31,  -406,   141,   142,
    -406,   107,     0,   231,     0,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     0,     0,   232,   233,     0,     0,     1,    38,    48,
     443,   444,     0,    49,     0,     0,   234,   445,   446,  -406,
     447,    52,   235,     0,     0,   216,     0,   216,   236,    56,
     448,     0,   449,   450,     0,    59,    60,     0,   451,  -406,
     108,     0,     0,     0,     0,   237,   452,    63,    64,   238,
       0,   239,     0,   453,     0,   240,   241,   242,   454,     0,
     243,     0,     0,    70,     6,     0,    72,     0,    74,   455,
     244,     0,   245,     0,     0,     0,    46,     0,     0,   246,
     247,   248,   249,   250,     0,     0,     0,     0,     0,     0,
       0,  -414,   291,  -417,    33,   228,   229,   230,    31,     0,
     141,   142,    48,   107,     0,   231,    49,    50,    51,     0,
       0,     0,     0,     0,    52,     0,     0,    53,     0,     0,
       0,     0,    56,     0,     0,   232,   233,     0,    59,    60,
       0,    48,     0,     0,     0,    49,     0,     0,   234,     0,
      63,    64,     0,    52,   235,    66,     0,     0,     0,     0,
     236,    56,     0,     0,    68,    69,    70,    59,    60,    72,
      73,    74,   108,     0,  -476,     0,     0,   237,     0,    63,
      64,   238,     0,   239,     0,     0,     0,   240,   241,   242,
       0,     0,   243,     0,     0,    70,     0,     0,    72,     0,
      74,     0,   244,     0,   245,     0,     0,     0,    46,     0,
       0,   246,   247,   248,   249,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   288,   440,    33,   228,   229,   230,
      31,     0,   141,   142,    48,   107,     0,   231,    49,    50,
      51,     0,     0,     0,     0,     0,    52,     0,     0,    53,
       0,     0,     0,     0,    56,     0,     0,   232,   233,     0,
      59,    60,     0,    48,     0,     0,     0,    49,     0,     0,
     234,     0,    63,    64,     0,    52,   235,    66,     0,     0,
       0,     0,   236,    56,     0,     0,    68,    69,    70,    59,
      60,    72,    73,    74,   108,   653,     0,     0,     0,   237,
       0,    63,    64,   238,     0,   239,     0,     0,     0,   240,
     241,   242,     0,     0,   243,     0,     0,    70,     0,     0,
      72,     0,    74,     0,   244,     0,   245,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,     0,   288,  -451,    33,   228,
     229,   230,    31,  -406,   141,   142,  -406,   107,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,     0,     0,     1,     0,    48,   443,   444,     0,    49,
       0,     0,   234,   445,   446,  -406,   447,    52,   235,     0,
       0,     0,     0,     0,   236,    56,   448,     0,   449,   450,
       0,    59,    60,     0,   451,  -406,   108,     0,     0,     0,
       0,   237,   452,    63,    64,   238,     0,   239,     0,   453,
       0,   240,   241,   242,   454,     0,   243,     0,     0,    70,
       6,     0,    72,     0,    74,   455,   244,     0,   245,     0,
     695,    46,     0,     0,     0,   246,   247,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,  -414,   291,    33,
     228,   229,   230,    31,     0,   141,   142,    48,   107,     0,
     231,    49,    50,    51,     0,     0,     0,     0,     0,    52,
       0,     0,    53,     0,     0,     0,     0,    56,     0,     0,
     232,   233,     0,    59,    60,     0,    48,     0,     0,     0,
      49,     0,     0,   234,     0,    63,    64,     0,    52,   235,
      66,     0,     0,     0,     0,   236,    56,     0,     0,    68,
      69,    70,    59,    60,    72,    73,    74,   108,     0,     0,
       0,     0,   237,     0,    63,    64,   238,     0,   239,     0,
       0,     0,   240,   241,   242,     0,     0,   243,     0,     0,
      70,     0,     0,    72,     0,    74,     0,   244,     0,   245,
       0,     0,     0,     0,     0,     0,   246,   247,   248,   249,
     250,    33,   228,   229,   230,    31,     0,   141,   142,   288,
     107,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   233,     0,     0,     0,     0,    48,     0,
       0,     0,    49,    50,    51,   234,     0,     0,     0,     0,
      52,   235,     0,    53,     0,     0,     0,   236,    56,     0,
       0,     0,     0,     0,    59,    60,     0,     0,     0,   108,
       0,     0,     0,     0,   237,     0,    63,    64,   238,     0,
     239,    66,     0,     0,   240,   241,   242,     0,     0,   243,
      68,    69,    70,     0,     0,    72,    73,    74,     0,   244,
       0,   245,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,   250,     0,     0,     0,     0,     0,     0,     0,
    -418,    33,   228,   229,   230,    31,  -406,   141,   142,  -406,
     107,     0,   231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   233,     0,     0,     0,     0,    48,     0,
       0,     0,    49,     0,     0,   234,     0,     0,  -406,     0,
      52,   235,     0,     0,     0,     0,     0,   236,    56,     0,
       0,     0,     0,     0,    59,    60,     0,     0,  -406,   108,
       0,     0,     0,     0,   237,     0,    63,    64,   238,     0,
     239,     0,     0,     0,   240,   241,   242,     0,     0,   243,
       0,     0,    70,     0,     0,    72,     0,    74,     0,   244,
       0,   245,     0,     0,     0,     0,     0,     0,   246,   247,
     248,   249,   250,     0,     0,    33,   228,   229,   230,    31,
    -414,   141,   142,     0,   107,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   233,     0,     0,
       0,     0,    48,     0,     0,     0,    49,     0,     0,   234,
       0,     0,     0,     0,    52,   235,     0,     0,     0,     0,
       0,   236,    56,     0,     0,     0,     0,     0,    59,    60,
       0,     0,     0,   108,     0,     0,     0,     0,   237,     0,
      63,    64,   238,     0,   239,     0,    33,     0,   240,   241,
     242,     0,     0,   243,     0,     0,    70,    46,     0,    72,
       0,    74,     0,   244,     0,   245,     0,     0,     0,     0,
       0,     0,   246,   247,   248,   249,   250,     0,     0,     0,
       0,     0,    47,    48,  -414,     0,     0,    49,    50,    51,
       0,     0,     0,     0,     0,    52,     0,     0,    53,    54,
       0,    55,     0,    56,     0,    57,     0,     0,    58,    59,
      60,    61,     0,     0,     0,     0,     0,     0,    62,     0,
       0,    63,    64,     0,    65,     0,    66,     0,     0,     0,
       0,     0,     0,    67,     0,    68,    69,    70,     0,    71,
      72,    73,    74,     0,    75,    46,     0,     0,     0,     0,
    -406,     0,     0,    76,    77,  -406,  -406,  -406,  -406,  -406,
    -438,    46,     0,  -424,     0,  -456,     0,     0,     0,     0,
      47,    48,     0,     0,     0,    49,    50,    51,     0,     0,
       0,     0,     0,    52,     0,     0,    53,    54,     0,    55,
       0,    56,     0,    57,     0,     0,    58,    59,    60,    61,
       0,     0,     0,     0,     0,     0,    62,     0,     0,    63,
      64,     0,    65,     0,    66,     0,     0,     0,  -406,     0,
       0,    67,     0,    68,    69,    70,     0,    71,    72,    73,
      74,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,     0,     0,     0,     0,   472,  -438,
    -406,  -442,     0,  -422,     0,  -438,  -438,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,    46,  -438,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,     0,    48,     0,     0,     0,    49,    50,    51,
       0,     0,     0,   190,     0,    52,     0,     0,    53,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,    59,
      60,     0,     0,   191,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    69,    70,     0,     0,
      72,    73,    74,     0,   192,     0,   193,   194,     0,     0,
     195,   196,   197,   198,   199,   200,     0,   201,   202,   203,
     204,   205,     0,     0,   206,     0,     0,     0,     0,   207,
      33,   228,   229,   230,    31,     0,   141,   142,     0,   107,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,     0,     0,     0,     0,    48,     0,     0,
       0,    49,    50,    51,   234,     0,     0,     0,     0,    52,
     235,     0,    53,     0,     0,     0,   236,    56,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,   108,     0,
       0,     0,     0,   237,     0,    63,    64,   238,     0,   239,
      66,     0,     0,   240,   241,   242,     0,     0,   243,    68,
      69,    70,     0,     0,    72,    73,    74,     0,   244,     0,
     245,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,   250,    33,   228,   229,   230,    31,  -406,   141,   142,
    -406,   107,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,   233,     0,     0,     0,     0,    48,
       0,     0,     0,    49,     0,     0,   234,     0,     0,  -406,
       0,    52,   235,     0,     0,     0,     0,     0,   236,    56,
       0,     0,     0,     0,     0,    59,    60,     0,     0,  -406,
     108,     0,     0,     0,     0,   237,     0,    63,    64,   238,
       0,   239,     0,     0,     0,   240,   241,   242,     0,     0,
     243,     0,     0,    70,     0,     0,    72,     0,    74,     0,
     244,     0,   245,     0,     0,     0,     0,     0,     0,   246,
     247,   248,   249,   250,    33,   228,   229,   230,    31,     0,
     141,   142,     0,   107,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   233,     0,     0,     0,
       0,    48,     0,     0,     0,    49,     0,     0,   234,     0,
       0,     0,     0,    52,   235,     0,     0,     0,     0,     0,
     236,    56,     0,     0,     0,     0,     0,    59,    60,     0,
       0,     0,   108,     0,     0,     0,     0,   237,     0,    63,
      64,   238,     0,   239,     0,     0,     0,   240,   241,   242,
       0,     0,   243,     0,     0,    70,     0,     0,    72,     0,
      74,     0,   244,  -404,   245,     0,     0,     0,     0,     0,
       0,   246,   247,   248,   249,   250,    33,   228,   229,   230,
      31,     0,   141,   142,     0,   107,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,   233,     0,
       0,     0,     0,    48,     0,     0,     0,    49,     0,     0,
     234,     0,     0,     0,     0,    52,   235,     0,     0,     0,
       0,     0,   236,    56,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,   108,     0,     0,     0,     0,   237,
       0,    63,    64,   238,     0,   239,     0,     0,     0,   240,
     241,   242,     0,     0,   243,     0,     0,    70,     0,     0,
      72,     0,    74,     0,   244,  -414,   245,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,   250,    33,   228,
     229,   230,    31,     0,   141,   142,     0,   107,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
     233,     0,     0,     0,     0,    48,     0,     0,     0,    49,
       0,     0,   234,     0,     0,     0,     0,    52,   235,     0,
       0,     0,     0,     0,   236,    56,     0,     0,     0,     0,
       0,    59,    60,     0,     0,     0,   108,     0,     0,     0,
       0,   237,     0,    63,    64,   238,     0,   239,     0,     0,
       0,   240,   241,   242,     0,     0,   243,     0,     0,    70,
       0,     0,    72,     0,    74,     0,   244,     0,   245,     0,
       0,     0,     0,     0,     0,   246,   247,   248,   249,   250,
      33,   228,   229,   230,    31,     0,   141,   142,     0,   107,
       0,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,     0,     0,     0,     0,    48,     0,     0,
       0,    49,     0,     0,   234,     0,     0,     0,     0,    52,
     235,     0,     0,     0,     0,     0,   236,    56,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,   108,     0,
       0,     0,     0,   237,     0,    63,    64,   238,     0,   239,
       0,     0,     0,   240,     0,   242,     0,     0,   243,     0,
       0,    70,     0,     0,    72,     0,    74,     0,   244,     0,
     245,     0,  -436,     0,     0,     0,     0,   246,   247,   248,
     249,   250,    33,   228,   229,   230,    31,     0,   141,   142,
       0,   107,     0,   231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,   233,     0,     0,     0,     0,    48,
       0,     0,     0,    49,     0,     0,   234,     0,     0,     0,
       0,    52,   235,     0,     0,     0,     0,     0,   236,    56,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
     108,     0,     0,     0,     0,   237,     0,    63,    64,   238,
       0,   239,     0,     0,     0,   240,     0,   242,     0,     0,
     243,     0,     0,    70,     0,     0,    72,     0,    74,     0,
     244,     0,   245,   572,     0,     0,     0,     0,     0,   246,
     247,   248,   249,   250,    33,   228,   229,   230,    31,     0,
     141,   142,     0,   107,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   233,     0,     0,     0,
       0,    48,     0,     0,     0,    49,     0,     0,   234,     0,
       0,     0,     0,    52,   235,     0,     0,     0,     0,     0,
     236,    56,     0,     0,     0,     0,     0,    59,    60,     0,
       0,     0,   108,     0,     0,     0,     0,   237,     0,    63,
      64,   238,     0,   239,     0,     0,     0,   240,     0,   242,
       0,     0,   243,     0,     0,    70,     0,     0,    72,     0,
      74,     0,   244,     0,   245,     0,     0,     0,     0,     0,
       0,   246,   247,   248,   249,   250,    33,   228,   229,   230,
      31,     0,   141,   142,     0,   107,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,   233,     0,
       0,     0,     0,    48,     0,     0,     0,    49,     0,     0,
     234,     0,     0,     0,     0,    52,   235,     0,     0,     0,
       0,     0,   236,    56,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,   108,     0,     0,     0,     0,   237,
       0,    63,    64,   238,     0,   239,     0,     0,     0,   240,
       0,   242,     0,     0,   243,     0,     0,    70,     0,     0,
      72,     0,    74,     0,   383,     0,   245,     0,     0,     0,
       0,     0,     0,   246,   247,   248,   249,   250,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -406,
    -406,  -406,  -406,  -406,     0,    46,     0,     0,     0,     0,
       0,     0,     0,   192,     0,   193,   194,     0,     0,   195,
     196,   197,   198,   199,   200,     0,   201,   202,   203,   204,
     205,    48,     0,   206,     0,    49,    50,    51,   207,     0,
       0,     0,     0,    52,     0,     0,    53,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,    59,    60,     0,
       0,    46,     0,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    47,    48,    72,    73,
      74,    49,    50,    51,     0,     0,     0,     0,     0,    52,
       0,     0,    53,    54,     0,    55,     0,    56,     0,    57,
       0,     0,    58,    59,    60,    61,     0,     0,     0,     0,
       0,    46,    62,     0,     0,    63,    64,     0,    65,     0,
      66,     0,     0,     0,     0,     0,     0,    67,     0,    68,
      69,    70,     0,    71,    72,    73,    74,    48,     0,     0,
       0,    49,    50,    51,     0,     0,     0,     0,     0,    52,
       0,     0,    53,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,     0,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      69,    70,     0,     0,    72,    73,    74
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-504)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       4,    53,   138,    28,    76,   125,   136,   214,    28,   223,
     138,   129,     5,   288,   137,     8,    28,    95,   140,    28,
     108,    41,     0,    43,   312,   452,   217,     5,   434,   137,
       8,   140,   438,    53,   472,    45,   232,   233,     3,    32,
      13,   140,    94,   101,     9,   123,   140,   529,    68,    53,
     320,   159,    40,   125,    32,    75,   294,    35,   444,     8,
      46,    10,    11,   121,    89,     3,     3,   263,     0,    89,
      40,    33,     3,     5,    94,    85,     8,    14,   516,     0,
     101,    12,    92,   109,   104,    15,   102,    14,   108,   592,
      94,   594,    30,   109,     3,    14,   108,   227,     8,    14,
      32,    11,   127,    35,    14,    14,    36,   127,   109,   231,
     130,   593,    98,   106,   129,   394,   131,     7,   397,   120,
     208,    99,   360,   102,    94,   103,   130,   105,   106,   102,
     109,   157,     0,   447,    30,    31,    85,    85,   524,   109,
      71,   355,     3,   147,   112,   113,   116,   117,   462,   119,
     108,   121,   343,    14,    69,    95,   123,   119,   123,   137,
     663,   110,   140,     9,    10,    92,    12,    99,    14,    14,
     140,   103,   103,   105,   106,    85,   116,    92,    99,   119,
     150,   159,   101,   123,   109,   209,   123,   157,   208,   209,
     312,   110,   111,   122,   102,   165,   208,   223,     0,   214,
     488,   109,   214,   312,   324,   401,   402,   102,    24,    25,
     150,   107,   108,   312,   109,   219,   220,   221,   312,   245,
     105,    28,    29,   609,   109,   165,   241,   231,   498,   615,
     218,     8,   244,    10,    11,    12,    38,   102,   101,   435,
     101,   104,   212,   123,   109,    89,   124,   102,   218,   110,
     111,   107,   324,   223,   109,    57,    58,   101,   696,   120,
     101,   231,   105,   104,   110,   111,   109,    69,   102,   294,
     294,   585,   107,   288,   294,   245,   120,   121,   298,   123,
     332,   595,   334,    85,   108,   109,   298,   291,   244,   298,
     315,     9,    10,    95,    12,   315,    14,   122,     9,    10,
     320,    12,   102,   315,   710,   580,   315,   102,   444,   109,
     123,   315,   282,   520,   109,   319,   444,   287,   102,   526,
     747,    10,   124,    12,   454,   109,   103,   351,   332,   355,
     334,   351,     3,   244,   312,   120,   360,   325,     9,    10,
     360,    12,   312,   539,     3,   659,    14,   287,   318,   619,
       9,    10,   121,    12,   123,   325,   102,   480,   744,   479,
     380,   381,   382,   123,   101,   385,   488,   104,   380,   381,
     382,   383,   480,   385,   394,     3,   388,   397,   318,   488,
     395,    14,    89,   353,   399,   355,   104,   120,   524,   488,
     408,   409,   110,   111,   488,    14,   524,   104,   506,   122,
      71,   509,   109,   124,    72,    73,    74,   479,   722,   124,
     724,   725,    71,   439,   121,   110,   123,   437,   433,   434,
     115,   116,   122,   438,   380,   381,   382,   383,    96,   385,
     124,   645,   388,   437,    72,    73,    74,     9,    10,   103,
      12,   105,   104,   447,   103,   449,   471,   451,   472,   474,
     474,   471,   472,   104,   474,   651,   574,   771,   462,   471,
     102,    14,   471,   108,   109,   105,   780,     9,   604,   439,
     406,   407,   383,   609,   108,   109,   604,   388,    50,   615,
     603,   609,   108,   109,   107,   396,   107,   615,   576,   703,
     414,   415,   516,   517,   107,   603,   516,   517,    70,   107,
     101,   589,   480,   117,   592,   520,   594,    85,   520,   111,
     488,   526,    94,    95,   526,   508,    32,   101,   488,   523,
     431,   541,     8,   538,    10,    11,    12,   547,   506,   118,
     508,   509,   502,   109,   116,   117,     3,   119,   101,   121,
     102,   123,     9,    10,   632,    12,   105,    14,   101,   102,
     764,   104,   410,   411,   412,   413,   576,   110,   111,   574,
      14,   109,   502,    13,   576,   580,   644,   122,   150,   776,
     648,   122,   542,   120,   124,   663,   508,   589,   107,   105,
     592,   585,   594,   165,   105,   600,   122,   602,   122,   614,
      89,   595,    34,    35,   614,    37,   622,   109,   618,   619,
     124,   621,   542,   623,   734,   625,   726,   121,   744,   107,
     614,   623,   632,   625,    43,   102,   744,   101,   109,   645,
     632,   120,   121,   120,   123,   603,     9,    10,   122,    12,
     212,   655,   122,   653,   649,   655,   403,   404,   405,   101,
     101,   653,   101,   668,   101,   120,   109,   101,   668,   122,
     104,   663,   622,   124,   726,   659,   110,   111,    13,   101,
     109,    14,   104,   121,   106,   121,   109,   623,     0,   625,
     122,   696,   696,   120,    57,   645,   696,   703,   589,   731,
      96,   592,   121,   594,   121,   110,   101,    14,   108,    72,
      73,    74,   716,   102,   108,   710,   716,   653,   108,   102,
     282,   108,    85,   729,   730,   287,    38,   109,   728,   102,
     102,   105,    95,   102,   120,   100,   728,   687,   722,   689,
     724,   725,   122,   124,   121,    57,    58,   731,    13,    14,
     102,   122,   101,   703,   749,    87,   318,    69,   764,   101,
     101,   124,   101,   101,   101,   105,   102,   687,   101,   689,
     101,   104,   663,    85,   774,   102,   102,   110,   111,   729,
     730,   102,   774,    95,    45,   102,    14,   771,   102,   104,
     103,   353,   728,   121,   101,   102,   780,   104,   122,   121,
      38,   108,   109,   110,   111,   102,    54,   698,   699,   700,
     701,   109,   102,   121,   764,   102,   105,   122,    12,    57,
      58,    38,   713,     3,     4,     5,     6,     7,   719,     9,
      10,    69,    12,     4,    14,   238,   101,   102,   774,   104,
      57,    58,   397,   108,   109,   110,   111,    85,   416,   419,
     417,   430,    69,   418,    34,    35,   121,    95,   587,   587,
      40,   523,   603,    38,    44,   127,   227,    47,    85,   614,
     506,   619,    52,    53,   437,   231,   509,   526,    95,    59,
      60,   752,    57,    58,   741,   123,    66,    67,   520,   716,
     604,    71,   128,   317,    69,   351,    76,    -1,    78,    79,
      80,    -1,    82,    -1,    -1,    -1,    86,   124,    88,    -1,
      85,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,
      95,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
     502,    -1,    -1,    -1,    -1,   125,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    34,    35,    -1,
     542,    38,    -1,    40,    41,    42,    -1,    44,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    -1,    63,    64,    -1,    66,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    -1,    82,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    91,    -1,    -1,    94,    95,    38,
      97,    -1,    99,   100,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    57,    58,
      -1,   119,    -1,   121,    -1,   122,   123,   124,    -1,    -1,
      69,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    38,   107,    40,
      41,    42,    -1,    44,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,   687,    -1,   689,    59,    60,
      61,    -1,    63,    64,    -1,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      91,    -1,    -1,    94,    95,    -1,    97,    -1,    99,   100,
     101,    -1,   103,    -1,    -1,    -1,    14,    -1,    -1,   110,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,     3,     4,     5,     6,     7,    -1,
       9,    10,    40,    12,    -1,    14,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    34,    35,    -1,    66,    67,
      -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      78,    79,    -1,    52,    53,    83,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    92,    93,    94,    66,    67,    97,
      98,    99,    71,    -1,   102,    -1,    -1,    76,    -1,    78,
      79,    80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,    -1,   103,    -1,    -1,    -1,    14,    -1,
      -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,   124,     3,     4,     5,     6,
       7,    -1,     9,    10,    40,    12,    -1,    14,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    34,    35,    -1,
      66,    67,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    78,    79,    -1,    52,    53,    83,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    92,    93,    94,    66,
      67,    97,    98,    99,    71,   101,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    38,    -1,    40,    41,    42,    -1,    44,
      -1,    -1,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    61,    -1,    63,    64,
      -1,    66,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    91,    -1,    -1,    94,
      95,    -1,    97,    -1,    99,   100,   101,    -1,   103,    -1,
      13,    14,    -1,    -1,    -1,   110,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,     3,
       4,     5,     6,     7,    -1,     9,    10,    40,    12,    -1,
      14,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      34,    35,    -1,    66,    67,    -1,    40,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    78,    79,    -1,    52,    53,
      83,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    92,
      93,    94,    66,    67,    97,    98,    99,    71,    -1,    -1,
      -1,    -1,    76,    -1,    78,    79,    80,    -1,    82,    -1,
      -1,    -1,    86,    87,    88,    -1,    -1,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    99,    -1,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,     3,     4,     5,     6,     7,    -1,     9,    10,   123,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,
      92,    93,    94,    -1,    -1,    97,    98,    99,    -1,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    50,    -1,
      52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    70,    71,
      -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,
      82,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,   101,
      -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,
     112,   113,   114,    -1,    -1,     3,     4,     5,     6,     7,
     122,     9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,
      78,    79,    80,    -1,    82,    -1,     3,    -1,    86,    87,
      88,    -1,    -1,    91,    -1,    -1,    94,    14,    -1,    97,
      -1,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    39,    40,   122,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      -1,    58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,   101,    14,    -1,    -1,    -1,    -1,
       3,    -1,    -1,   110,   111,     8,     9,    10,    11,    12,
      13,    14,    -1,   120,    -1,   122,    -1,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,
      -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    81,    -1,    83,    -1,    -1,    -1,    71,    -1,
      -1,    90,    -1,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,   104,    -1,   122,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,   121,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    50,    -1,    52,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,    -1,
      97,    98,    99,    -1,   101,    -1,   103,   104,    -1,    -1,
     107,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,    82,
      83,    -1,    -1,    86,    87,    88,    -1,    -1,    91,    92,
      93,    94,    -1,    -1,    97,    98,    99,    -1,   101,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    50,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    70,
      71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,
      -1,    82,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    76,    -1,    78,    79,    80,    -1,    82,    -1,    -1,
      -1,    86,    87,    88,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    97,    -1,    99,    -1,   101,    -1,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    76,    -1,    78,    79,    80,    -1,    82,
      -1,    -1,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    99,    -1,   101,    -1,
     103,    -1,   105,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    76,    -1,    78,    79,    80,
      -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    99,    -1,
     101,    -1,   103,   104,    -1,    -1,    -1,    -1,    -1,   110,
     111,   112,   113,   114,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    76,    -1,    78,
      79,    80,    -1,    82,    -1,    -1,    -1,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      99,    -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    -1,    82,    -1,    -1,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      97,    -1,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,   103,   104,    -1,    -1,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    40,    -1,   121,    -1,    44,    45,    46,   126,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    39,    40,    97,    98,
      99,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    14,    75,    -1,    -1,    78,    79,    -1,    81,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      93,    94,    -1,    96,    97,    98,    99,    40,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    38,    57,    58,    69,    85,    95,   142,   189,   190,
     191,   192,   194,   205,   206,   207,   208,   209,   211,   213,
     214,   215,   216,   232,   259,   266,   267,   276,   287,   312,
     101,     7,   140,     3,     9,   123,   130,   135,   107,   190,
      14,    69,    92,   291,     0,   190,    14,    39,    40,    44,
      45,    46,    52,    55,    56,    58,    60,    62,    65,    66,
      67,    68,    75,    78,    79,    81,    83,    90,    92,    93,
      94,    96,    97,    98,    99,   101,   110,   111,   193,   195,
     196,   197,   198,   200,   201,   217,   218,   219,   220,   221,
     223,   224,   237,   238,   239,   280,   288,    85,   140,   123,
     190,   210,   276,   123,   121,   123,   108,    12,    71,   103,
     134,   135,   145,   250,   257,   263,   280,   280,   135,   280,
     289,   280,   219,   280,   222,   223,   293,   109,    89,   101,
     120,   121,   234,   253,   269,   292,   301,   101,   104,   219,
     123,     9,    10,   129,   130,   131,   132,   147,   148,   263,
     280,   289,   144,   145,   146,   147,   263,   278,   122,   107,
     102,   276,   124,   210,   212,   280,   210,   190,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      50,    70,   101,   103,   104,   107,   108,   109,   110,   111,
     112,   114,   115,   116,   117,   118,   121,   126,   197,   226,
     251,   258,   280,   132,   107,   122,   147,   278,   147,   278,
     123,   147,   102,   278,   293,   218,   219,   301,     4,     5,
       6,    14,    34,    35,    47,    53,    59,    76,    80,    82,
      86,    87,    88,    91,   101,   103,   110,   111,   112,   113,
     114,   136,   137,   138,   139,   140,   141,   143,   144,   147,
     149,   150,   152,   153,   154,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     198,   273,   280,   135,   254,   255,   256,   280,   123,   174,
     235,   123,   181,   233,   194,   229,   230,   231,   287,   299,
     172,   173,   177,   295,    72,    73,    74,    95,   146,   213,
     232,   240,   241,   249,   259,   287,   303,   135,    14,   278,
     120,   246,   304,    85,   110,   277,     8,    11,   128,   132,
     133,   199,    45,    85,    92,   231,   260,   261,   262,   122,
     124,   124,   122,   278,   124,   104,   104,   102,   105,   226,
     297,   221,   252,   280,   311,   278,   134,   174,   198,   225,
     226,   264,   265,   129,   145,   135,   135,   202,   203,   204,
     290,   135,   199,   233,    71,   135,   146,   257,   161,   161,
     107,   107,   107,   101,   152,   107,   174,   314,   101,   174,
     176,   225,    34,    35,    37,   101,   104,   106,   102,   109,
     161,    15,    36,   110,   115,   116,   112,   113,    24,    25,
      30,    31,   107,   108,    28,    29,   111,   117,   118,    32,
      16,    17,    18,    19,    20,    21,    22,    23,    26,    27,
      33,   119,   121,   175,   101,    50,    70,   109,   101,   278,
     124,   235,   236,    41,    42,    48,    49,    51,    61,    63,
      64,    69,    77,    84,    89,   100,   135,   176,   178,   179,
     180,   181,   182,   183,   185,   187,   188,   191,   268,   284,
     285,   287,   101,   219,   221,   227,   228,   296,   298,   102,
     109,    13,   300,   105,   122,   122,   306,   303,   120,   219,
     242,   243,   289,   305,   124,   304,   278,   135,    96,   247,
     248,   249,   280,   293,   145,   289,   107,   289,   108,   109,
     129,   105,   105,   311,   147,   199,   101,   221,   296,   108,
     109,   122,   122,   109,   121,   124,   107,    43,   270,   271,
     225,   225,   225,   225,   225,   176,   225,   102,   109,   102,
     151,   277,   280,   150,   279,   176,   151,   277,   174,   161,
     161,   162,   162,   162,   163,   163,   164,   164,   165,   165,
     165,   165,   166,   166,   167,   168,   169,   170,   171,   176,
     174,   279,   104,   161,   101,   155,   281,   254,   279,   132,
     109,   302,   122,   177,   122,   120,   178,   101,   135,   101,
     135,   284,   101,   181,   101,   120,   178,   122,   124,   227,
     121,   296,   121,   101,   104,   293,    13,   231,   303,   121,
     244,   245,   307,   308,   109,   120,   122,   249,   309,   109,
      96,   310,   278,   121,   260,   121,   190,   261,   265,   203,
     177,   264,   101,   270,   313,   108,   108,   108,   102,   108,
     102,   102,   174,   161,   280,   278,   102,   105,   280,   120,
     102,   105,   150,   101,   156,   226,   102,   235,   124,   120,
     178,   100,   180,   186,   192,   122,   176,   184,   226,   122,
     184,   270,   184,   178,   102,   174,   174,   229,   295,    87,
     274,   294,   125,   177,   219,   243,   177,   280,   248,   280,
     132,   225,   108,   225,   108,    13,   226,   272,   101,   101,
     101,   101,   144,   103,   199,   144,   174,   161,   102,   225,
     101,   159,   282,   104,   157,   158,   221,   283,   178,   101,
     184,   286,   102,   219,   102,   102,   102,   105,   101,   278,
     278,    45,   219,   227,   102,   176,   176,   176,   176,   199,
      14,   102,   279,   176,   104,   283,   176,   122,   178,   121,
     178,   178,   293,   225,   275,   315,   132,   132,   289,   181,
     102,   102,   102,   102,   103,   282,   102,   105,   177,   102,
     284,    54,   174,   294,   109,   102,   121,   199,   105,   122,
     102,   178,   225,   134,   178
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
	    /* Fall through.  */
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
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
  *yyssp = yystate;

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
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1792 of yacc.c  */
#line 2825 "parser2.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 1210 "parser2.y"


static void
yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
}

int
main(void)
{
	lineno = 1;
	yyparse();

	return 0;
}
