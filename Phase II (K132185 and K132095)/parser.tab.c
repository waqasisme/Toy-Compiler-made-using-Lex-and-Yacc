
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h> /* For I/O */
#include <stdlib.h> /* For malloc here and in symbol table */
#include <string.h> /* For strcmp in symbol table */
#include "SymbolTable.h" /* SymbolTable */
#define YYDEBUG 1
#define YYERROR_VERBOSE 1
int errors;
int linecount = 0;
int iarraysize = 0;
char* ctype = "";
int ifunction = 0;
int inumargs = 0;

void yyerror(char*);

install(char *clexeme)
{
	tEntry *s;
	s = getsym (clexeme, current_scope);
	if (s == 0)
		s = add(clexeme, ctype, current_scope, 0, 0, 0);
	else 
	{ 
		errors++;
		printf("ERROR: variable %s at Line %d is already defined\n", clexeme, yylineno);
	}
}



/* Line 189 of yacc.c  */
#line 105 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Integer = 258,
     Identifier = 259,
     VOID = 260,
     CHAR = 261,
     INT = 262,
     FLOAT = 263,
     Character = 264,
     Real = 265,
     String = 266,
     Subtract = 267,
     Add = 268,
     Multiply = 269,
     Divide = 270,
     Modulus = 271,
     Assign = 272,
     AddAndAssign = 273,
     MultiplyAndAssign = 274,
     DivideAndAssign = 275,
     SubtractAndAssign = 276,
     BREAK = 277,
     CASE = 278,
     CONTINUE = 279,
     DEFAULT = 280,
     DO = 281,
     ELSE = 282,
     IF = 283,
     FOR = 284,
     WHILE = 285,
     RETURN = 286,
     SWITCH = 287,
     Colon = 288,
     Comma = 289,
     EndOfStatement = 290,
     ConditionalOperator = 291,
     ClosingBraces = 292,
     ClosingRoundBracket = 293,
     ClosingSquareBracket = 294,
     OpeningBraces = 295,
     OpeningRoundBracket = 296,
     OpeningSquareBracket = 297,
     Increment = 298,
     Decrement = 299,
     LessThan = 300,
     GreaterThan = 301,
     LessThanEqualTo = 302,
     GreaterThanEqualTo = 303,
     IsEqualTo = 304,
     NotEqualTo = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 "parser.y"

	int intval; /* Integer values */
	float floatval;
	char charval;
	char *id; /* Identifiers */
	char *type;



/* Line 214 of yacc.c  */
#line 201 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "parser.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNRULES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    53,    52,     2,    51,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    55,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    12,    14,    18,    21,
      24,    26,    29,    31,    33,    35,    37,    39,    41,    44,
      45,    49,    50,    53,    56,    60,    61,    66,    69,    72,
      73,    78,    81,    82,    84,    87,    88,    91,    95,    96,
      98,   100,   104,   106,   110,   112,   116,   118,   119,   124,
     127,   128,   132,   133,   137,   138,   140,   143,   147,   151,
     156,   159,   160,   163,   165,   167,   169,   171,   173,   175,
     180,   184,   186,   189,   196,   197,   200,   206,   209,   212,
     215,   218,   224,   232,   239,   247,   250,   251,   256,   259,
     260,   264,   266,   270,   273,   274,   278,   281,   282,   286,
     290,   294,   298,   301,   302,   306,   310,   313,   314,   318,
     322,   326,   328,   330,   332,   334,   336,   338,   340,   342,
     344,   347,   350,   353,   354,   359,   362,   365,   368,   372,
     375,   377,   381,   383,   385,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    59,    58,    -1,    -1,    59,    58,    -1,
      60,    -1,    76,    -1,    63,    64,    61,    -1,    64,    62,
      -1,    74,    88,    -1,    88,    -1,    74,    88,    -1,    88,
      -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,    65,
      -1,    72,    65,    -1,    -1,     4,    66,    67,    -1,    -1,
      41,    68,    -1,    42,    70,    -1,    64,    38,    67,    -1,
      -1,    69,    83,    38,    67,    -1,    38,    67,    -1,    39,
      67,    -1,    -1,     3,    39,    71,    67,    -1,    14,    73,
      -1,    -1,    72,    -1,    76,    75,    -1,    -1,    76,    75,
      -1,    63,    77,    35,    -1,    -1,    78,    -1,    79,    -1,
      78,    34,    79,    -1,    64,    -1,    64,    17,    80,    -1,
     103,    -1,    40,    81,    37,    -1,    80,    -1,    -1,    81,
      34,    82,    80,    -1,    85,    84,    -1,    -1,    34,    85,
      84,    -1,    -1,    63,    86,    87,    -1,    -1,    64,    -1,
      40,    37,    -1,    40,    89,    37,    -1,    40,    74,    37,
      -1,    40,    74,    89,    37,    -1,    91,    90,    -1,    -1,
      91,    90,    -1,    92,    -1,    88,    -1,    93,    -1,    94,
      -1,    98,    -1,    96,    -1,    23,   113,    33,    91,    -1,
      25,    33,    91,    -1,    35,    -1,   101,    35,    -1,    28,
      41,   101,    38,    91,    95,    -1,    -1,    27,    91,    -1,
      32,    41,   101,    38,    91,    -1,    24,    35,    -1,    22,
      35,    -1,    31,    97,    -1,   101,    35,    -1,    30,    41,
     101,    38,    91,    -1,    26,    91,    30,    41,   101,    38,
      35,    -1,    29,    41,    93,    93,    38,    91,    -1,    29,
      41,    93,    93,   101,    38,    91,    -1,   104,   100,    -1,
      -1,    36,   101,    33,    99,    -1,   103,   102,    -1,    -1,
      34,   103,   102,    -1,    99,    -1,   114,   112,   103,    -1,
     106,   105,    -1,    -1,    49,   106,   105,    -1,   108,   107,
      -1,    -1,    45,   108,   107,    -1,    46,   108,   107,    -1,
      47,   108,   107,    -1,    48,   108,   107,    -1,   110,   109,
      -1,    -1,    13,   110,   109,    -1,    12,   110,   109,    -1,
     114,   111,    -1,    -1,    14,   114,   111,    -1,    15,   114,
     111,    -1,    16,   114,   111,    -1,    17,    -1,    18,    -1,
      21,    -1,    19,    -1,    20,    -1,     3,    -1,     9,    -1,
      10,    -1,   115,    -1,    43,   114,    -1,    44,   114,    -1,
     119,   116,    -1,    -1,    42,   101,    39,   116,    -1,    41,
     117,    -1,    43,   116,    -1,    44,   116,    -1,   118,    38,
     116,    -1,    38,   116,    -1,   103,    -1,   118,    34,   103,
      -1,     4,    -1,   113,    -1,    11,    -1,    41,   101,    38,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    73,    75,    79,    80,    84,    85,    89,
      90,    94,    95,    99,   100,   101,   102,   106,   107,   111,
     111,   114,   116,   117,   121,   122,   122,   123,   127,   128,
     128,   132,   135,   137,   141,   144,   146,   150,   153,   155,
     160,   161,   165,   166,   170,   171,   175,   176,   176,   180,
     183,   185,   189,   189,   192,   194,   198,   199,   200,   201,
     205,   208,   210,   214,   215,   216,   217,   218,   219,   223,
     224,   228,   229,   233,   236,   238,   242,   246,   247,   248,
     252,   256,   257,   258,   259,   263,   266,   268,   272,   275,
     277,   281,   282,   286,   289,   291,   295,   298,   300,   301,
     302,   303,   307,   310,   312,   313,   317,   320,   322,   323,
     324,   328,   329,   330,   331,   332,   336,   337,   338,   342,
     343,   344,   348,   351,   353,   354,   355,   356,   360,   361,
     365,   366,   370,   371,   372,   373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Integer", "Identifier", "VOID", "CHAR",
  "INT", "FLOAT", "Character", "Real", "String", "Subtract", "Add",
  "Multiply", "Divide", "Modulus", "Assign", "AddAndAssign",
  "MultiplyAndAssign", "DivideAndAssign", "SubtractAndAssign", "BREAK",
  "CASE", "CONTINUE", "DEFAULT", "DO", "ELSE", "IF", "FOR", "WHILE",
  "RETURN", "SWITCH", "Colon", "Comma", "EndOfStatement",
  "ConditionalOperator", "ClosingBraces", "ClosingRoundBracket",
  "ClosingSquareBracket", "OpeningBraces", "OpeningRoundBracket",
  "OpeningSquareBracket", "Increment", "Decrement", "LessThan",
  "GreaterThan", "LessThanEqualTo", "GreaterThanEqualTo", "IsEqualTo",
  "NotEqualTo", "'-'", "'+'", "'*'", "'/'", "'^'", "$accept",
  "TransitionUnit", "TransitionUnit_a", "ExternalDeclaration",
  "FunctionDefinition", "FunctionDefinition_a", "FunctionDefinition_b",
  "TypeSpecifier", "Declarator", "DirectDeclarator", "$@1",
  "DirectDeclarator_a", "DirectDeclarator_b", "$@2", "DirectDeclarator_c",
  "$@3", "Pointer", "Pointer_a", "DeclarationList", "DeclarationList_a",
  "Declaration", "Declaration_a", "InitDeclaratorList", "InitDeclarator",
  "Initializer", "InitializerList", "$@4", "ParameterList",
  "ParameterList_a", "ParameterDeclaration", "$@5",
  "ParameterDeclaration_a", "CompoundStatement", "StatementList",
  "StatementList_a", "Statement", "LabeledStatement",
  "ExpressionStatement", "SelectionStatement", "SelectionStatement_a",
  "JumpStatement", "JumpStatement_a", "IterationStatement",
  "ConditionalExpression", "ConditionalExpression_a", "Expression",
  "Expression_a", "AssignmentExpression", "EqualityExpression",
  "EqualityExpression_a", "RelationalExpression", "RelationalExpression_a",
  "AdditiveExpression", "AdditiveExpression_a", "MultiplicativeExpression",
  "MultiplicativeExpression_a", "AssignmentOperator", "Constant",
  "UnaryExpression", "PostFixExpression", "PostFixExpression_a",
  "PostFixExpression_b", "ArgumentExpressionList", "PrimaryExpression", 0
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
     305,    45,    43,    42,    47,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    64,    64,    66,
      65,    67,    67,    67,    68,    69,    68,    68,    70,    71,
      70,    72,    73,    73,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    81,    83,
      84,    84,    86,    85,    87,    87,    88,    88,    88,    88,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    95,    95,    94,    96,    96,    96,
      97,    98,    98,    98,    98,    99,   100,   100,   101,   102,
     102,   103,   103,   104,   105,   105,   106,   107,   107,   107,
     107,   107,   108,   109,   109,   109,   110,   111,   111,   111,
     111,   112,   112,   112,   112,   112,   113,   113,   113,   114,
     114,   114,   115,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   119,   119,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     3,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     2,     2,     3,     0,     4,     2,     2,     0,
       4,     2,     0,     1,     2,     0,     2,     3,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     0,     4,     2,
       0,     3,     0,     3,     0,     1,     2,     3,     3,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     4,
       3,     1,     2,     6,     0,     2,     5,     2,     2,     2,
       2,     5,     7,     6,     7,     2,     0,     4,     2,     0,
       3,     1,     3,     2,     0,     3,     2,     0,     3,     3,
       3,     3,     2,     0,     3,     3,     2,     0,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     0,     4,     2,     2,     2,     3,     2,
       1,     3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    13,    14,    15,    16,    32,     0,     3,     5,
      38,     0,    17,     0,     6,    21,    33,    31,     1,     2,
       3,    42,     0,    39,    40,     0,     8,    38,     0,    35,
      12,    18,    25,     0,    20,     4,     0,     7,     0,    10,
      37,     0,   116,   132,   117,   118,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,    56,     0,
       0,     0,     0,    64,     0,    61,    63,    65,    66,    68,
      67,    91,     0,    89,    86,    94,    97,   103,   133,   107,
     119,   123,    42,    11,    34,    35,    21,     0,    22,     0,
       0,    21,    23,     0,    43,    44,     9,    41,    78,     0,
      77,     0,     0,     0,     0,     0,    79,     0,     0,     0,
     120,   121,    58,     0,    57,    60,    61,    72,     0,    88,
       0,    85,     0,    93,     0,     0,     0,     0,    96,     0,
       0,   102,     0,     0,     0,   111,   112,   114,   115,   113,
     106,     0,     0,     0,   123,   123,   122,    36,    27,    21,
      52,     0,    50,    29,    28,    46,     0,     0,    70,     0,
       0,     0,     0,    80,     0,   135,    59,    62,    89,     0,
      94,   107,    97,    97,    97,    97,   103,   103,   107,   107,
     107,    92,   123,   130,   125,     0,     0,   126,   127,    24,
      54,    21,     0,    49,    21,    47,    45,    69,     0,     0,
       0,     0,     0,    90,     0,    95,    98,    99,   100,   101,
     105,   104,   108,   109,   110,   129,     0,   123,   123,    55,
      53,    26,    50,    30,     0,     0,    74,     0,     0,    81,
      76,    87,   131,   128,   124,    51,    48,     0,     0,    73,
      83,     0,    82,    75,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    19,    20,     9,    37,    26,    27,    11,    12,
      15,    34,    88,    89,    92,   194,    13,    17,    28,    84,
      14,    22,    23,    24,    94,   156,   224,   151,   193,   152,
     190,   220,    63,    64,   115,    65,    66,    67,    68,   239,
      69,   106,    70,    71,   121,    72,   119,    73,    74,   123,
      75,   128,    76,   131,    77,   140,   141,    78,    79,    80,
     146,   184,   185,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -124
static const yytype_int16 yypact[] =
{
     109,  -124,  -124,  -124,  -124,  -124,    -3,    23,   109,  -124,
      13,    48,  -124,    21,  -124,     8,  -124,  -124,  -124,  -124,
     109,    40,    58,     7,  -124,   135,  -124,    13,    25,    97,
    -124,  -124,    14,     3,  -124,  -124,    28,  -124,    25,  -124,
    -124,    13,  -124,  -124,  -124,  -124,  -124,    62,    26,   115,
      10,   228,    20,    42,    65,   287,   113,  -124,  -124,   287,
     287,   287,   186,  -124,   125,   228,  -124,  -124,  -124,  -124,
    -124,  -124,   133,   137,   138,   124,    74,    87,  -124,   110,
    -124,   157,   152,  -124,  -124,    97,     8,   142,  -124,    97,
     144,     8,  -124,    28,  -124,  -124,  -124,  -124,  -124,   148,
    -124,   228,   154,   287,   232,   287,  -124,   151,   287,   149,
    -124,  -124,  -124,   169,  -124,  -124,   228,  -124,   287,  -124,
     287,  -124,   287,  -124,   287,   287,   287,   287,  -124,   287,
     287,  -124,   287,   287,   287,  -124,  -124,  -124,  -124,  -124,
    -124,   287,   274,   287,   157,   157,  -124,  -124,  -124,     8,
    -124,   156,   173,  -124,  -124,  -124,    36,   228,  -124,   172,
     181,   232,   182,  -124,   184,  -124,  -124,  -124,   137,   191,
     124,   121,    74,    74,    74,    74,    87,    87,   121,   121,
     121,  -124,   157,  -124,  -124,     6,   189,  -124,  -124,  -124,
      13,     8,    97,  -124,     8,  -124,  -124,  -124,   287,   228,
     278,   228,   228,  -124,   287,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,   287,   157,   157,  -124,
    -124,  -124,   173,  -124,    28,   187,   206,   228,   196,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,   205,   228,  -124,
    -124,   228,  -124,  -124,  -124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,   229,   248,  -124,  -124,  -124,     0,    -8,   242,
    -124,   -82,  -124,  -124,  -124,  -124,   255,  -124,    71,   177,
       5,  -124,  -124,   233,   -90,  -124,  -124,  -124,    57,    78,
    -124,  -124,    80,   218,   170,   -50,  -124,   -97,  -124,  -124,
    -124,  -124,  -124,    88,  -124,   -45,   126,   -31,  -124,   123,
     178,    30,   120,   -44,    18,    86,  -124,   247,   -48,  -124,
    -123,  -124,  -124,  -124
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      10,   102,    21,   155,   148,    95,    90,   161,    10,   154,
     107,     6,   110,   111,   109,   116,    29,     1,     1,    82,
      10,   187,   188,    18,    87,     1,    29,     6,     6,    42,
      29,    42,    43,    82,    85,    44,    45,    44,    45,    46,
     216,    41,    91,   101,   217,     2,     3,     4,     5,    32,
      33,   158,    86,     2,     3,     4,     5,    36,   160,   215,
     162,   103,    95,   164,   200,    25,   116,   189,    93,    59,
     195,    60,    61,   196,   171,   169,   171,   171,   171,   171,
      25,   171,   171,   104,   178,   179,   180,   168,    25,   150,
      85,    30,    38,    40,   233,   234,    62,    98,   186,   129,
     130,    39,     2,     3,     4,     5,   105,   197,    83,   221,
     181,   183,   223,     1,     2,     3,     4,     5,    96,   124,
     125,   126,   127,     6,   132,   133,   134,   135,   136,   137,
     138,   139,   210,   211,   236,   132,   133,   134,    42,    43,
       2,     3,     4,     5,    44,    45,    46,   176,   177,   226,
     100,   229,   230,   225,   108,   228,   171,    47,    48,    49,
      50,    51,   114,    52,    53,    54,    55,    56,   117,    36,
      57,   118,    58,   122,   120,    25,    59,   240,    60,    61,
     149,   157,   219,   153,   159,   232,   163,   165,   243,    42,
      43,   244,   150,    95,   191,    44,    45,    46,   142,   143,
     144,   145,   206,   207,   208,   209,   166,   192,    47,    48,
      49,    50,    51,   198,    52,    53,    54,    55,    56,   199,
     201,    57,   202,   112,   204,   237,    25,    59,   218,    60,
      61,    42,    43,   238,   241,    42,    43,    44,    45,    46,
     242,    44,    45,    46,   172,   173,   174,   175,     8,    35,
      47,    48,    49,    50,    51,    31,    52,    53,    54,    55,
      56,    16,   147,    57,   212,   213,   214,    57,    25,    59,
     222,    60,    61,    59,    97,    60,    61,    42,    43,   235,
     113,    42,    43,    44,    45,    46,   167,    44,    45,    46,
      42,    43,   231,   205,   203,    99,    44,    45,    46,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,     0,     0,    59,   227,    60,    61,    59,
       0,    60,    61,     0,     0,     0,     0,     0,    59,     0,
      60,    61
};

static const yytype_int16 yycheck[] =
{
       0,    51,    10,    93,    86,    36,     3,   104,     8,    91,
      55,    14,    60,    61,    59,    65,    11,     4,     4,    27,
      20,   144,   145,     0,    32,     4,    21,    14,    14,     3,
      25,     3,     4,    41,    29,     9,    10,     9,    10,    11,
      34,    34,    39,    33,    38,     5,     6,     7,     8,    41,
      42,   101,    38,     5,     6,     7,     8,    17,   103,   182,
     105,    41,    93,   108,   161,    40,   116,   149,    40,    41,
      34,    43,    44,    37,   122,   120,   124,   125,   126,   127,
      40,   129,   130,    41,   132,   133,   134,   118,    40,    89,
      85,    11,    21,    35,   217,   218,    25,    35,   143,    12,
      13,    21,     5,     6,     7,     8,    41,   157,    28,   191,
     141,   142,   194,     4,     5,     6,     7,     8,    38,    45,
      46,    47,    48,    14,    14,    15,    16,    17,    18,    19,
      20,    21,   176,   177,   224,    14,    15,    16,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   129,   130,   199,
      35,   201,   202,   198,    41,   200,   204,    22,    23,    24,
      25,    26,    37,    28,    29,    30,    31,    32,    35,    17,
      35,    34,    37,    49,    36,    40,    41,   227,    43,    44,
      38,    33,   190,    39,    30,   216,    35,    38,   238,     3,
       4,   241,   192,   224,    38,     9,    10,    11,    41,    42,
      43,    44,   172,   173,   174,   175,    37,    34,    22,    23,
      24,    25,    26,    41,    28,    29,    30,    31,    32,    38,
      38,    35,    38,    37,    33,    38,    40,    41,    39,    43,
      44,     3,     4,    27,    38,     3,     4,     9,    10,    11,
      35,     9,    10,    11,   124,   125,   126,   127,     0,    20,
      22,    23,    24,    25,    26,    13,    28,    29,    30,    31,
      32,     6,    85,    35,   178,   179,   180,    35,    40,    41,
     192,    43,    44,    41,    41,    43,    44,     3,     4,   222,
      62,     3,     4,     9,    10,    11,   116,     9,    10,    11,
       3,     4,   204,   170,   168,    48,     9,    10,    11,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    41,    38,    43,    44,    41,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,    14,    57,    59,    60,
      63,    64,    65,    72,    76,    66,    72,    73,     0,    58,
      59,    64,    77,    78,    79,    40,    62,    63,    74,    76,
      88,    65,    41,    42,    67,    58,    17,    61,    74,    88,
      35,    34,     3,     4,     9,    10,    11,    22,    23,    24,
      25,    26,    28,    29,    30,    31,    32,    35,    37,    41,
      43,    44,    74,    88,    89,    91,    92,    93,    94,    96,
      98,    99,   101,   103,   104,   106,   108,   110,   113,   114,
     115,   119,    64,    88,    75,    76,    38,    64,    68,    69,
       3,    39,    70,    40,    80,   103,    88,    79,    35,   113,
      35,    33,    91,    41,    41,    41,    97,   101,    41,   101,
     114,   114,    37,    89,    37,    90,    91,    35,    34,   102,
      36,   100,    49,   105,    45,    46,    47,    48,   107,    12,
      13,   109,    14,    15,    16,    17,    18,    19,    20,    21,
     111,   112,    41,    42,    43,    44,   116,    75,    67,    38,
      63,    83,    85,    39,    67,    80,    81,    33,    91,    30,
     101,    93,   101,    35,   101,    38,    37,    90,   103,   101,
     106,   114,   108,   108,   108,   108,   110,   110,   114,   114,
     114,   103,    38,   103,   117,   118,   101,   116,   116,    67,
      86,    38,    34,    84,    71,    34,    37,    91,    41,    38,
      93,    38,    38,   102,    33,   105,   107,   107,   107,   107,
     109,   109,   111,   111,   111,   116,    34,    38,    39,    64,
      87,    67,    85,    67,    82,   101,    91,    38,   101,    91,
      91,    99,   103,   116,   116,    84,    80,    38,    27,    95,
      91,    38,    35,    91,    91
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
        case 7:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    { current_scope = "global";;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { current_scope = "global";;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { ctype = "void";  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    { ctype = "char";  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { ctype = "int";   ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { ctype = "float"; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    { strcat(last->type, "ptr"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { install((yyvsp[(1) - (1)].id)); last->scope = current_scope; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    { last->function = 1; current_scope = last->lexeme; ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    { last->arraysize = (yyvsp[(1) - (2)].intval); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { last->arraysize++; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { last->arraysize++; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    { if(getLastFunction() != (tEntry*) 0) getLastFunction()->numargs++; ;}
    break;



/* Line 1455 of yacc.c  */
#line 1760 "parser.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 375 "parser.y"


void yyerror(char *s)
{
    errors++;
    printf ("ERROR: %s at Line %d\n", s, yylineno);
}

int main(void)
{
    extern FILE *yyin;
    extern FILE *yyout;
    yyin = fopen("in.txt", "r");
    yyout = fopen("out.txt", "w+");
    
    
    yyparse();
    printf("Done Parsing. Total errors: %d\n\n", errors);
    
    printtable();


	

}
