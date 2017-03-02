
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

#include <stdio.h>  	  /* For I/O */
#include <stdlib.h> 	  /* For malloc here and in symbol table */
#include <string.h> 	  /* For strcmp in symbol table */
#include "SymbolTable.h"  /* SymbolTable */

#define YYDEBUG 1
#define YYERROR_VERBOSE 1

int errors = 0;		// counter for errors
int linecount = 0;	// pass linecount through yylineno
int isArray = 0;	// flag to see if we are at array
int isPtr = 0;		// flag to see if we are at ptr
int didReturn = 0;
char* ctype = "";	// string to store types of identifiers
char* varName = "";	// to store variables under error

static int input YY_PROTO(( void ));
void yyerror(char*);

install(char *clexeme)
{
	tEntry *s;
	s  = getsym (clexeme, current_scope);	// see if its been defined
	
	if (s == (tEntry*)0)
		s = add(clexeme, ctype, current_scope, 0, 0, 0);
	else
	{ 
		errors++;
		if(s->function == 0)
			printf("ERROR: Variable %s at Line %d is already defined\n", clexeme, yylineno);
		else  printf("ERROR: Function %s at Line %d is already defined\n", clexeme, yylineno);
	}
}

struct set {
	char* name;
	char* type;
	int ival;
	float fval;
	char cval;
	char* sval;
};

typedef struct set set;





/* Line 189 of yacc.c  */
#line 125 "parser.tab.c"

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
     Identifier = 258,
     Integer = 259,
     Character = 260,
     Real = 261,
     String = 262,
     INT = 263,
     VOID = 264,
     CHAR = 265,
     FLOAT = 266,
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
#line 54 "parser.y"

	set F;



/* Line 214 of yacc.c  */
#line 217 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 229 "parser.tab.c"

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
#define YYLAST   326

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  259

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
       0,     0,     3,     4,     7,     8,    11,    13,    15,    19,
      22,    25,    27,    30,    32,    34,    36,    38,    40,    42,
      43,    47,    48,    52,    53,    54,    58,    61,    65,    69,
      72,    75,    76,    81,    84,    85,    87,    90,    91,    94,
      98,    99,   101,   103,   107,   109,   113,   115,   119,   121,
     122,   127,   130,   131,   135,   136,   140,   141,   143,   146,
     150,   154,   159,   162,   163,   166,   168,   170,   172,   174,
     176,   178,   183,   188,   192,   194,   197,   204,   205,   208,
     209,   216,   219,   222,   225,   228,   234,   242,   249,   257,
     260,   261,   262,   268,   271,   272,   276,   278,   279,   280,
     286,   289,   290,   294,   298,   301,   302,   306,   310,   314,
     318,   321,   322,   326,   330,   333,   334,   338,   342,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,   367,
     370,   373,   374,   375,   376,   377,   385,   388,   391,   394,
     398,   401,   403,   407,   409,   411,   413
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    -1,    59,    58,    -1,    -1,    59,    58,
      -1,    60,    -1,    77,    -1,    63,    64,    61,    -1,    64,
      62,    -1,    75,    89,    -1,    89,    -1,    75,    89,    -1,
      89,    -1,     9,    -1,    10,    -1,     8,    -1,    11,    -1,
      66,    -1,    -1,    73,    65,    66,    -1,    -1,     3,    67,
      68,    -1,    -1,    -1,    69,    41,    70,    -1,    42,    71,
      -1,    64,    38,    68,    -1,    84,    38,    68,    -1,    38,
      68,    -1,    39,    68,    -1,    -1,     4,    39,    72,    68,
      -1,    14,    74,    -1,    -1,    73,    -1,    77,    76,    -1,
      -1,    77,    76,    -1,    63,    78,    35,    -1,    -1,    79,
      -1,    80,    -1,    79,    34,    80,    -1,    64,    -1,    64,
      17,    81,    -1,   106,    -1,    40,    82,    37,    -1,    81,
      -1,    -1,    82,    34,    83,    81,    -1,    86,    85,    -1,
      -1,    34,    86,    85,    -1,    -1,    63,    87,    88,    -1,
      -1,    64,    -1,    40,    37,    -1,    40,    90,    37,    -1,
      40,    75,    37,    -1,    40,    75,    90,    37,    -1,    92,
      91,    -1,    -1,    92,    91,    -1,    93,    -1,    89,    -1,
      94,    -1,    95,    -1,   100,    -1,    98,    -1,    23,     4,
      33,    92,    -1,    23,     5,    33,    92,    -1,    25,    33,
      92,    -1,    35,    -1,   104,    35,    -1,    28,    41,   104,
      38,    92,    96,    -1,    -1,    27,    92,    -1,    -1,    32,
      41,   104,    97,    38,    92,    -1,    24,    35,    -1,    22,
      35,    -1,    31,    99,    -1,   104,    35,    -1,    30,    41,
     104,    38,    92,    -1,    26,    92,    30,    41,   104,    38,
      35,    -1,    29,    41,    94,    94,    38,    92,    -1,    29,
      41,    94,    94,   104,    38,    92,    -1,   109,   102,    -1,
      -1,    -1,    36,   104,   103,    33,   101,    -1,   106,   105,
      -1,    -1,    34,   106,   105,    -1,   101,    -1,    -1,    -1,
     119,   107,   117,   108,   106,    -1,   111,   110,    -1,    -1,
      49,   111,   110,    -1,    50,   111,   110,    -1,   113,   112,
      -1,    -1,    45,   113,   112,    -1,    46,   113,   112,    -1,
      47,   113,   112,    -1,    48,   113,   112,    -1,   115,   114,
      -1,    -1,    13,   115,   114,    -1,    12,   115,   114,    -1,
     119,   116,    -1,    -1,    14,   119,   116,    -1,    15,   119,
     116,    -1,    16,   119,   116,    -1,    17,    -1,    18,    -1,
      21,    -1,    19,    -1,    20,    -1,     4,    -1,     5,    -1,
       6,    -1,   120,    -1,    43,   119,    -1,    44,   119,    -1,
     127,   121,    -1,    -1,    -1,    -1,    -1,   122,    42,   104,
     123,    39,   124,   121,    -1,    41,   125,    -1,    43,   121,
      -1,    44,   121,    -1,   126,    38,   121,    -1,    38,   121,
      -1,   106,    -1,   126,    34,   106,    -1,     3,    -1,   118,
      -1,     7,    -1,    41,   104,    38,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   112,   112,   114,   117,   119,   123,   124,   128,   130,
     134,   135,   139,   140,   144,   145,   146,   147,   151,   152,
     152,   157,   156,   166,   168,   168,   171,   175,   176,   177,
     181,   183,   182,   188,   191,   193,   197,   200,   202,   206,
     209,   211,   216,   217,   221,   222,   247,   264,   268,   269,
     269,   273,   276,   278,   282,   282,   285,   287,   291,   297,
     303,   309,   317,   320,   322,   326,   327,   328,   329,   330,
     331,   335,   336,   337,   341,   342,   346,   349,   351,   356,
     355,   364,   365,   366,   410,   417,   418,   419,   420,   424,
     428,   430,   429,   438,   442,   443,   447,   449,   459,   448,
     506,   518,   519,   521,   526,   550,   551,   553,   555,   557,
     562,   598,   599,   601,   606,   650,   651,   653,   655,   660,
     661,   662,   663,   664,   668,   669,   670,   674,   675,   682,
     693,   697,   698,   703,   714,   698,   716,   717,   724,   734,
     735,   739,   740,   744,   768,   780,   781
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Identifier", "Integer", "Character",
  "Real", "String", "INT", "VOID", "CHAR", "FLOAT", "Subtract", "Add",
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
  "TypeSpecifier", "Declarator", "$@1", "DirectDeclarator", "$@2",
  "DirectDeclarator_a", "$@3", "DirectDeclarator_b", "DirectDeclarator_c",
  "$@4", "Pointer", "Pointer_a", "DeclarationList", "DeclarationList_a",
  "Declaration", "Declaration_a", "InitDeclaratorList", "InitDeclarator",
  "Initializer", "InitializerList", "$@5", "ParameterList",
  "ParameterList_a", "ParameterDeclaration", "$@6",
  "ParameterDeclaration_a", "CompoundStatement", "StatementList",
  "StatementList_a", "Statement", "LabeledStatement",
  "ExpressionStatement", "SelectionStatement", "SelectionStatement_a",
  "$@7", "JumpStatement", "JumpStatement_a", "IterationStatement",
  "ConditionalExpression", "ConditionalExpression_a", "$@8", "Expression",
  "Expression_a", "AssignmentExpression", "$@9", "$@10",
  "EqualityExpression", "EqualityExpression_a", "RelationalExpression",
  "RelationalExpression_a", "AdditiveExpression", "AdditiveExpression_a",
  "MultiplicativeExpression", "MultiplicativeExpression_a",
  "AssignmentOperator", "Constant", "UnaryExpression", "PostFixExpression",
  "PostFixExpression_a", "$@11", "$@12", "$@13", "PostFixExpression_b",
  "ArgumentExpressionList", "PrimaryExpression", 0
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
       0,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    65,
      64,    67,    66,    68,    69,    68,    68,    70,    70,    70,
      71,    72,    71,    73,    74,    74,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    83,
      82,    84,    85,    85,    87,    86,    88,    88,    89,    89,
      89,    89,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    94,    94,    95,    96,    96,    97,
      95,    98,    98,    98,    99,   100,   100,   100,   100,   101,
     102,   103,   102,   104,   105,   105,   106,   107,   108,   106,
     109,   110,   110,   110,   111,   112,   112,   112,   112,   112,
     113,   114,   114,   114,   115,   116,   116,   116,   116,   117,
     117,   117,   117,   117,   118,   118,   118,   119,   119,   119,
     120,   121,   122,   123,   124,   121,   121,   121,   121,   125,
     125,   126,   126,   127,   127,   127,   127
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     3,     2,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     3,     0,     0,     3,     2,     3,     3,     2,
       2,     0,     4,     2,     0,     1,     2,     0,     2,     3,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     0,
       4,     2,     0,     3,     0,     3,     0,     1,     2,     3,
       3,     4,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     1,     2,     6,     0,     2,     0,
       6,     2,     2,     2,     2,     5,     7,     6,     7,     2,
       0,     0,     5,     2,     0,     3,     1,     0,     0,     5,
       2,     0,     3,     3,     2,     0,     3,     3,     3,     3,
       2,     0,     3,     3,     2,     0,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     0,     0,     0,     0,     7,     2,     2,     2,     3,
       2,     1,     3,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    21,    16,    14,    15,    17,    34,     0,     4,     6,
      40,     0,    18,    19,     7,    23,    35,    33,     1,     3,
       4,    44,     0,    41,    42,     0,     9,    40,     0,    37,
      13,     0,     0,    22,     0,     5,     0,     8,     0,    11,
      39,     0,   143,   124,   125,   126,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    58,     0,
       0,     0,     0,    66,     0,    63,    65,    67,    68,    70,
      69,    96,     0,    94,    90,   101,   105,   111,   144,   115,
     127,   131,    44,    12,    36,    37,    20,     0,    23,    26,
       0,     0,    45,    46,    10,    43,    82,     0,     0,    81,
       0,     0,     0,     0,     0,    83,     0,     0,     0,   128,
     129,    60,     0,    59,    62,    63,    75,     0,    93,     0,
      89,     0,     0,   100,     0,     0,     0,     0,   104,     0,
       0,   110,     0,     0,     0,     0,   114,     0,   131,   131,
     130,     0,    38,    31,    30,    23,    54,     0,    25,     0,
      52,    48,     0,     0,     0,    73,     0,     0,     0,     0,
      84,    79,   146,    61,    64,    94,    91,   101,   115,   101,
     105,   105,   105,   105,   111,   111,   115,   115,   115,   119,
     120,   122,   123,   121,    98,   131,   141,   136,     0,   137,
     138,     0,    23,    29,    56,    23,    23,     0,    51,    49,
      47,    71,    72,     0,     0,     0,     0,     0,    95,     0,
     102,   103,   106,   107,   108,   109,   113,   112,   116,   117,
     118,     0,   140,     0,   131,   133,    32,    57,    55,    27,
      28,    52,     0,     0,    77,     0,     0,    85,     0,     0,
      99,   142,   139,     0,    53,    50,     0,     0,    76,    87,
       0,    80,    92,   134,    86,    78,    88,   131,   135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    19,    20,     9,    37,    26,    27,    11,    31,
      12,    15,    33,    34,   148,    89,   192,    13,    17,    28,
      84,    14,    22,    23,    24,    92,   152,   232,   149,   198,
     150,   194,   228,    63,    64,   114,    65,    66,    67,    68,
     248,   207,    69,   105,    70,    71,   120,   209,    72,   118,
      73,   135,   221,    74,   123,    75,   128,    76,   131,    77,
     136,   184,    78,    79,    80,   140,   141,   243,   257,   187,
     188,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -129
static const yytype_int16 yypact[] =
{
     245,  -129,  -129,  -129,  -129,  -129,    -9,    20,   245,  -129,
      15,    14,  -129,  -129,  -129,    -1,  -129,  -129,  -129,  -129,
     245,    78,     0,    -7,  -129,   198,  -129,    15,    18,   132,
    -129,    48,    11,  -129,    33,  -129,    94,  -129,    18,  -129,
    -129,    15,  -129,  -129,  -129,  -129,  -129,    26,   108,    71,
      22,   282,    89,    95,   105,    40,   113,  -129,  -129,    40,
      40,    40,   240,  -129,   123,   282,  -129,  -129,  -129,  -129,
    -129,  -129,   139,   124,   154,    73,   135,   120,  -129,   152,
    -129,   151,   180,  -129,  -129,   132,  -129,   149,    -1,  -129,
      28,    94,  -129,  -129,  -129,  -129,  -129,   181,   186,  -129,
     282,   195,    40,   104,    40,  -129,   196,    40,   194,  -129,
    -129,  -129,   197,  -129,  -129,   282,  -129,    40,  -129,    40,
    -129,    40,    40,  -129,    40,    40,    40,    40,  -129,    40,
      40,  -129,    40,    40,    40,   273,  -129,   121,   151,   151,
    -129,   215,  -129,  -129,  -129,    -1,  -129,   199,  -129,   202,
     224,  -129,    19,   282,   282,  -129,   219,   223,   104,   229,
    -129,  -129,  -129,  -129,  -129,   124,  -129,    73,   136,    73,
     135,   135,   135,   135,   120,   120,   136,   136,   136,  -129,
    -129,  -129,  -129,  -129,  -129,   151,  -129,  -129,    -6,  -129,
    -129,    40,    -1,  -129,    15,    -1,    -1,   132,  -129,  -129,
    -129,  -129,  -129,    40,   282,   172,   282,   235,  -129,   203,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,    40,  -129,    40,   151,  -129,  -129,  -129,  -129,  -129,
    -129,   224,    94,   236,   249,   282,   241,  -129,   282,    40,
    -129,  -129,  -129,   239,  -129,  -129,   247,   282,  -129,  -129,
     282,  -129,  -129,  -129,  -129,  -129,  -129,   151,  -129
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,   279,   300,  -129,  -129,  -129,     1,    -8,  -129,
     270,  -129,   -76,  -129,  -129,  -129,  -129,   296,  -129,    27,
     218,     5,  -129,  -129,   268,   -88,  -129,  -129,  -129,    84,
     119,  -129,  -129,    93,   256,   204,   -51,  -129,   -95,  -129,
    -129,  -129,  -129,  -129,  -129,    81,  -129,  -129,   -42,   156,
     -32,  -129,  -129,  -129,   -52,    35,    79,   171,    37,    88,
     -84,  -129,  -129,   -54,  -129,  -128,  -129,  -129,  -129,  -129,
    -129,  -129
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -133
static const yytype_int16 yytable[] =
{
     101,    10,    21,   151,    93,     6,   109,   110,   158,    10,
     189,   190,   144,   106,   115,    87,    29,   108,     1,    82,
      18,    10,     2,     3,     4,     5,    29,    41,   223,     6,
      29,     1,   224,    82,    85,    40,     2,     3,     4,     5,
     -24,    32,     6,    42,    43,    44,    45,    46,    38,   155,
      88,     1,    62,   199,    25,   100,   200,   222,    25,    93,
     157,    96,   159,   205,   115,   161,   145,   168,   168,   193,
     168,   168,   168,   168,    90,   168,   168,   166,   176,   177,
     178,    59,   147,    60,    61,   165,     2,     3,     4,     5,
      85,   146,   218,   219,   220,    36,   242,    42,    43,    44,
      45,    46,   201,   202,    30,   186,    99,    42,    43,    44,
      45,    46,    97,    98,    39,   210,   226,   211,    25,   229,
     230,    83,   121,   122,    42,    43,    44,    45,    46,   258,
     102,    94,   129,   130,    91,    59,   103,    60,    61,    57,
       2,     3,     4,     5,   245,    59,   104,    60,    61,   225,
     132,   133,   134,   234,   107,   237,   167,   169,   117,   185,
     113,   233,    59,   236,    60,    61,   132,   133,   134,   -97,
     -97,   -97,   -97,   -97,   116,    42,    43,    44,    45,    46,
     124,   125,   126,   127,   249,   168,   227,   251,   143,   240,
     119,   241,   137,  -132,   138,   139,   255,    36,   146,   256,
      93,    42,    43,    44,    45,    46,     2,     3,     4,     5,
     235,   216,   217,    59,   153,    60,    61,   174,   175,   154,
      47,    48,    49,    50,    51,   156,    52,    53,    54,    55,
      56,   160,   162,    57,   163,    58,   239,   195,    25,    59,
     196,    60,    61,    42,    43,    44,    45,    46,     1,   212,
     213,   214,   215,     2,     3,     4,     5,   191,   197,     6,
     203,   204,    47,    48,    49,    50,    51,   206,    52,    53,
      54,    55,    56,   238,   246,    57,   247,   111,   253,   250,
      25,    59,   254,    60,    61,    42,    43,    44,    45,    46,
     179,   180,   181,   182,   183,   170,   171,   172,   173,    35,
       8,    86,    16,   142,    47,    48,    49,    50,    51,    95,
      52,    53,    54,    55,    56,   244,   231,    57,   112,   164,
     252,   208,    25,    59,     0,    60,    61
};

static const yytype_int16 yycheck[] =
{
      51,     0,    10,    91,    36,    14,    60,    61,   103,     8,
     138,   139,    88,    55,    65,     4,    11,    59,     3,    27,
       0,    20,     8,     9,    10,    11,    21,    34,    34,    14,
      25,     3,    38,    41,    29,    35,     8,     9,    10,    11,
      41,    42,    14,     3,     4,     5,     6,     7,    21,   100,
      39,     3,    25,    34,    40,    33,    37,   185,    40,    91,
     102,    35,   104,   158,   115,   107,    38,   121,   122,   145,
     124,   125,   126,   127,    41,   129,   130,   119,   132,   133,
     134,    41,    90,    43,    44,   117,     8,     9,    10,    11,
      85,    90,   176,   177,   178,    17,   224,     3,     4,     5,
       6,     7,   153,   154,    11,   137,    35,     3,     4,     5,
       6,     7,     4,     5,    21,   167,   192,   169,    40,   195,
     196,    28,    49,    50,     3,     4,     5,     6,     7,   257,
      41,    38,    12,    13,    40,    41,    41,    43,    44,    35,
       8,     9,    10,    11,   232,    41,    41,    43,    44,   191,
      14,    15,    16,   204,    41,   206,   121,   122,    34,    38,
      37,   203,    41,   205,    43,    44,    14,    15,    16,    17,
      18,    19,    20,    21,    35,     3,     4,     5,     6,     7,
      45,    46,    47,    48,   235,   239,   194,   238,    39,   221,
      36,   223,    41,    42,    43,    44,   247,    17,   197,   250,
     232,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      38,   174,   175,    41,    33,    43,    44,   129,   130,    33,
      22,    23,    24,    25,    26,    30,    28,    29,    30,    31,
      32,    35,    38,    35,    37,    37,    33,    38,    40,    41,
      38,    43,    44,     3,     4,     5,     6,     7,     3,   170,
     171,   172,   173,     8,     9,    10,    11,    42,    34,    14,
      41,    38,    22,    23,    24,    25,    26,    38,    28,    29,
      30,    31,    32,    38,    38,    35,    27,    37,    39,    38,
      40,    41,    35,    43,    44,     3,     4,     5,     6,     7,
      17,    18,    19,    20,    21,   124,   125,   126,   127,    20,
       0,    31,     6,    85,    22,    23,    24,    25,    26,    41,
      28,    29,    30,    31,    32,   231,   197,    35,    62,   115,
     239,   165,    40,    41,    -1,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,     9,    10,    11,    14,    57,    59,    60,
      63,    64,    66,    73,    77,    67,    73,    74,     0,    58,
      59,    64,    78,    79,    80,    40,    62,    63,    75,    77,
      89,    65,    42,    68,    69,    58,    17,    61,    75,    89,
      35,    34,     3,     4,     5,     6,     7,    22,    23,    24,
      25,    26,    28,    29,    30,    31,    32,    35,    37,    41,
      43,    44,    75,    89,    90,    92,    93,    94,    95,    98,
     100,   101,   104,   106,   109,   111,   113,   115,   118,   119,
     120,   127,    64,    89,    76,    77,    66,     4,    39,    71,
      41,    40,    81,   106,    89,    80,    35,     4,     5,    35,
      33,    92,    41,    41,    41,    99,   104,    41,   104,   119,
     119,    37,    90,    37,    91,    92,    35,    34,   105,    36,
     102,    49,    50,   110,    45,    46,    47,    48,   112,    12,
      13,   114,    14,    15,    16,   107,   116,    41,    43,    44,
     121,   122,    76,    39,    68,    38,    63,    64,    70,    84,
      86,    81,    82,    33,    33,    92,    30,   104,    94,   104,
      35,   104,    38,    37,    91,   106,   104,   111,   119,   111,
     113,   113,   113,   113,   115,   115,   119,   119,   119,    17,
      18,    19,    20,    21,   117,    38,   106,   125,   126,   121,
     121,    42,    72,    68,    87,    38,    38,    34,    85,    34,
      37,    92,    92,    41,    38,    94,    38,    97,   105,   103,
     110,   110,   112,   112,   112,   112,   114,   114,   116,   116,
     116,   108,   121,    34,    38,   104,    68,    64,    88,    68,
      68,    86,    83,   104,    92,    38,   104,    92,    38,    33,
     106,   106,   121,   123,    85,    81,    38,    27,    96,    92,
      38,    92,   101,    39,    35,    92,    92,   124,   121
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
        case 6:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { yyerrok; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    { (yyval.F).name = (yyvsp[(2) - (3)].F).name; (yyval.F).type = (yyvsp[(1) - (3)].F.type); current_scope = "global"; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    { current_scope = "global"; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    { ctype = "void";  (yyval.F.type) = "void" ;    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    { ctype = "char";  (yyval.F.type) = "char" ;    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { ctype = "int";   (yyval.F.type) = "int"  ;    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { ctype = "float"; (yyval.F.type) = "float";    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    { (yyval.F).name = (yyvsp[(1) - (1)].F).name; (yyval.F).type = (yyvsp[(1) - (1)].F).type; ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { isPtr = 1; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { (yyval.F).type = strcat((yyvsp[(3) - (3)].F).type, "ptr"); (yyval.F).name = (yyvsp[(3) - (3)].F).name; (yyval.F).type = (yyvsp[(3) - (3)].F).type; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    { 
			install((yyvsp[(1) - (1)].F).name); // create entry in symbol table
			last->scope = current_scope;
			if(isPtr) 
				{ strcat(last->type, "ptr"); isPtr = 0; } // add ptr to type if pointer
		;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval.F).name = (yyvsp[(1) - (3)].F).name; (yyval.F).type = (yyvsp[(1) - (3)].F).type; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {
		last->function = 1; current_scope = last->lexeme; 
	  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { last->arraysize = (yyvsp[(1) - (2)].F.ival); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (3)].F.type); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {
			if(strcmp((yyvsp[(1) - (3)].F).type, (yyvsp[(3) - (3)].F).type) != 0 && !((strcmp((yyvsp[(1) - (3)].F).type, "float") == 0) && strcmp((yyvsp[(3) - (3)].F).type, "int") == 0))
		  { errors++; printf("ERROR: Type Mismatch, cannot initialize %s with %s value at Line %d\n", (yyvsp[(1) - (3)].F).type, (yyvsp[(3) - (3)].F).type, yylineno); }
		  else {
			  (yyval.F).type = (yyvsp[(1) - (3)].F).type;
			  int t = 4;
			  if(strcmp((yyval.F).type, "int") == 0) t = 0;
			  else if(strcmp((yyval.F).type, "char") == 0) t = 1;
			  else if(strcmp((yyval.F).type, "float") == 0) t = 2;
			  else if(strcmp((yyval.F).type, "string") == 0) t = 3;
			  	switch(t)
				{
					case 0: (yyvsp[(1) - (3)].F).ival = (yyvsp[(3) - (3)].F).ival; break; 
					case 1: (yyvsp[(1) - (3)].F).cval = (yyvsp[(3) - (3)].F).cval; break; 
					case 2: (yyvsp[(1) - (3)].F).fval = (yyvsp[(3) - (3)].F).fval; break; 
					case 3: (yyvsp[(1) - (3)].F).sval = (yyvsp[(3) - (3)].F).sval; break;
					default: break;
				}
		  }
			 
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {
			(yyval.F).type = (yyvsp[(1) - (1)].F).type; 
			int t = 4;
			if(strcmp((yyval.F).type, "int") == 0) t = 0;
			else if(strcmp((yyval.F).type, "char") == 0) t = 1;
			else if(strcmp((yyval.F).type, "float") == 0) t = 2;
			else if(strcmp((yyval.F).type, "string") == 0) t = 3;
			switch(t)
			{
				case 0: (yyval.F).ival = (yyvsp[(1) - (1)].F).ival; break; 
				case 1: (yyval.F).cval = (yyvsp[(1) - (1)].F).cval; break; 
				case 2: (yyval.F).fval = (yyvsp[(1) - (1)].F).fval; break; 
				case 3: (yyval.F).sval = (yyvsp[(1) - (1)].F).sval; break;
				default: break;
			}
		;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    { last->arraysize++; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { last->arraysize++; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    { if(getLastFunction() != (tEntry*) 0) getLastFunction()->numargs++; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    { 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    { 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 310 "parser.y"
    { 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    { (yyval.F).type = "none"; (yyval.F).name = "none";;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).name = (yyvsp[(1) - (2)].F).name;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {
			if(strcmp((yyvsp[(3) - (3)].F).type, "int") != 0 && strcmp((yyvsp[(3) - (3)].F).type, "char")) 
			{  errors++; printf("ERROR: Switch statement must have Integer or Character in header at Line %d\n", yylineno); }
		;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {
			didReturn = 1;
			tEntry* lastFunction = getLastFunction();
			if(strcmp((yyvsp[(2) - (2)].F).type, lastFunction->type) != 0 && !(strcmp(lastFunction->type, "float")== 0 && strcmp((yyvsp[(2) - (2)].F).type, "int")== 0))
			{ errors++; printf("ERROR: Function %s() is returning ", lastFunction->lexeme);
				int t = 4;
				if(strcmp((yyvsp[(2) - (2)].F).type, "int") == 0) t = 0;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "char") == 0) t = 1;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "float") == 0) t = 2;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "string") == 0) t = 3;
				
				switch(t)
				{
					case 0: printf(    "%d, ", (yyvsp[(2) - (2)].F).ival); break; 
					case 1: printf("\'%c\', ", (yyvsp[(2) - (2)].F).cval); break; 
					case 2: printf(    "%f, ", (yyvsp[(2) - (2)].F).fval); break; 
					case 3: printf("\"%s\", ", (yyvsp[(2) - (2)].F).sval); break; 
					default: printf("nothing"); break;
				}
				printf(" Return type is: %s (is returning %s) at Line %d\n", lastFunction->type, (yyvsp[(2) - (2)].F).type, yylineno);
			}
			else { 
				(yyval.F).type = lastFunction->type; 
				int t = 4;
				if(strcmp((yyvsp[(2) - (2)].F).type, "int") == 0) t = 0;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "char") == 0) t = 1;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "float") == 0) t = 2;
				else if(strcmp((yyvsp[(2) - (2)].F).type, "string") == 0) t = 3;
				if((strcmp(lastFunction->type, "float") == 0 && strcmp((yyvsp[(2) - (2)].F).type, "int") == 0)) t = 4;
				switch(t)
				{
					case 0: (yyval.F).ival = (yyvsp[(2) - (2)].F).ival; break; 
					case 1: (yyval.F).cval = (yyvsp[(2) - (2)].F).cval; break; 
					case 2: (yyval.F).fval = (yyvsp[(2) - (2)].F).fval; break; 
					case 3: (yyval.F).sval = (yyvsp[(2) - (2)].F).sval; break; 
					case 4: (yyval.F).fval = (yyvsp[(2) - (2)].F).ival; break; 
					default:  break;
				}
			}
		;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    { 	(yyval.F).type = (yyvsp[(1) - (2)].F).type;
		if(strcmp((yyval.F).type,"none") == 0) (yyval.F).type = "void";
	  (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 424 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (2)].F).type;  (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval;  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 428 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    {
			if(strcmp((yyvsp[(2) - (2)].F).type, "int") != 0)
			{ errors++; printf("ERROR: Expression in Conditional Statement is non boolean at Line %d\n", yylineno); }
		;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 443 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 447 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (1)].F).type; (yyval.F).ival = (yyvsp[(1) - (1)].F).ival; (yyval.F).cval = (yyvsp[(1) - (1)].F).cval; (yyval.F).fval = (yyvsp[(1) - (1)].F).fval; (yyval.F).sval = (yyvsp[(1) - (1)].F).sval; ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 449 "parser.y"
    {
		if(isArray == 1) 
		{ errors++; printf("ERROR: Array Variable %s being accessed without Index[] at Line %d\n", varName, yylineno); } 
		isArray = 0; 
		tEntry* s = getsym((yyvsp[(1) - (1)].F).name, getScope((yyvsp[(1) - (1)].F).name));
		
		if(s != (tEntry *)0 && s->function) 
		{	errors++; printf("ERROR: Function being assigned value at Line%d\n", (yyvsp[(1) - (1)].F).name, yylineno); }
		
	   ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 459 "parser.y"
    {;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 460 "parser.y"
    {	
	  
		  if(strcmp((yyvsp[(1) - (5)].F).type, (yyvsp[(5) - (5)].F).type) != 0 && !(strcmp((yyvsp[(1) - (5)].F).type, "float")==0 && strcmp((yyvsp[(5) - (5)].F).type, "int")==0))
		  { errors++; printf("ERROR: Type Mismatch, cannot assign %s to %s at Line %d\n", (yyvsp[(5) - (5)].F).type, (yyvsp[(1) - (5)].F).type, yylineno); }
		  else {
			  (yyval.F).type = (yyvsp[(1) - (5)].F).type;
			  int t;
			  if(strcmp((yyval.F).type, "int") == 0) t = 0;
			  else if(strcmp((yyval.F).type, "char") == 0) t = 1;
			  else if(strcmp((yyval.F).type, "float") == 0) t = 2;
			  else if(strcmp((yyval.F).type, "string") == 0) t = 3;
			  
			  char c = (yyvsp[(3) - (5)].F.cval);
			  
			  switch(c)
			  {
				  case '=': 
					switch(t)
					{	case 0: (yyvsp[(1) - (5)].F).ival = (yyvsp[(5) - (5)].F).ival; break; case 1: (yyvsp[(1) - (5)].F).cval = (yyvsp[(5) - (5)].F).cval; break; case 2: (yyvsp[(1) - (5)].F).fval = (yyvsp[(5) - (5)].F).fval; break; case 3: (yyvsp[(1) - (5)].F).sval = (yyvsp[(5) - (5)].F).sval; break; }	
				  break;

				  case '+': 
					switch(t)
					{	case 0: (yyvsp[(1) - (5)].F).ival += (yyvsp[(5) - (5)].F).ival; break; case 1: (yyvsp[(1) - (5)].F).cval += (yyvsp[(5) - (5)].F).cval; break; case 2: (yyvsp[(1) - (5)].F).fval += (yyvsp[(5) - (5)].F).fval; break; case 3: strcat((yyvsp[(1) - (5)].F).sval, (yyvsp[(5) - (5)].F).sval); break; }	
				  break;
				  case '-': 
					switch(t)
					{	case 0: (yyvsp[(1) - (5)].F).ival -= (yyvsp[(5) - (5)].F).ival; break; case 1: (yyvsp[(1) - (5)].F).cval -= (yyvsp[(5) - (5)].F).cval; break; case 2: (yyvsp[(1) - (5)].F).fval -= (yyvsp[(5) - (5)].F).fval; break; default: break; }	
				  break;
				  case '*': 
					switch(t)
					{	case 0: (yyvsp[(1) - (5)].F).ival *= (yyvsp[(5) - (5)].F).ival; break; case 2: (yyvsp[(1) - (5)].F).fval *= (yyvsp[(5) - (5)].F).fval; break; default: break; }	
				  break;
				  case '/': 
					switch(t)
					{	case 0: (yyvsp[(1) - (5)].F).ival /= (yyvsp[(5) - (5)].F).ival; break; case 2: (yyvsp[(1) - (5)].F).fval /= (yyvsp[(5) - (5)].F).fval; break; default: break; }	
				  break;
				  default: break;
			  }
			 
		  }
		  
	  ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 507 "parser.y"
    {
			(yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval;
			if(strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) != 0 && strcmp((yyvsp[(2) - (2)].F).type, "none") != 0)
			{	errors++; printf("ERROR: Type Mismatch, cannot compare expression of type %s with %s at Line %d\n", (yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type, yylineno); }
			else if(strcmp((yyvsp[(2) - (2)].F).type, "none") != 0){
				
				}
		;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 518 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 520 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "==";;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 522 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "!=";;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 527 "parser.y"
    {
			
			(yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval; 
			if(strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) != 0 && strcmp((yyvsp[(2) - (2)].F).type, "none") != 0)
			{	errors++; printf("ERROR: Type Mismatch, cannot compare expression of type %s with %s at Line %d\n", (yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type, yylineno); }
			else if(strcmp((yyvsp[(2) - (2)].F).type, "none") != 0) {
				if(strcmp((yyvsp[(2) - (2)].F).name, "==") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0;
				else if(strcmp((yyvsp[(2) - (2)].F).name, "!=") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0;
				else if(strcmp((yyvsp[(2) - (2)].F).name, "<") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0;
				else if(strcmp((yyvsp[(2) - (2)].F).name, "<=") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0;
				else if(strcmp((yyvsp[(2) - (2)].F).name, ">") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0;
				else if(strcmp((yyvsp[(2) - (2)].F).name, ">=") == 0)
					(yyval.F).ival = ((strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) == 0))?1:0; 
				}		
	;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 550 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 552 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "<";;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 554 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = ">";;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 556 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "<=";;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 558 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = ">=";;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 563 "parser.y"
    {
	
		(yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval;   
		
			if(strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) != 0 && strcmp((yyvsp[(2) - (2)].F).type, "none")!=0 && !((strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int") == 0) || (strcmp((yyvsp[(2) - (2)].F).type, "float")==0 && strcmp((yyvsp[(1) - (2)].F).type, "int") == 0)))
			{	errors++; printf("ERROR: Type Mismatch, cannot add expression of type %s with %s at Line %d\n", (yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type, yylineno); }
			else if(strcmp((yyvsp[(2) - (2)].F).type, "none") != 0) {
				(yyval.F).type = (strcmp((yyvsp[(1) - (2)].F).type, "float") == 0 || strcmp((yyvsp[(2) - (2)].F).type, "float") == 0)? "float": (yyvsp[(1) - (2)].F).type; 
				if(strcmp((yyvsp[(2) - (2)].F).name, "+") == 0)
				{
					if(strcmp((yyval.F).type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform addition on strings at Line %d\n", yylineno); }
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).ival = (yyvsp[(1) - (2)].F).ival + (yyvsp[(2) - (2)].F).ival;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "char")==0 && strcmp((yyvsp[(2) - (2)].F).type, "char")==0) (yyval.F).cval = (yyvsp[(1) - (2)].F).cval + (yyvsp[(2) - (2)].F).cval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval + (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).ival + (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval + (yyvsp[(2) - (2)].F).ival;
				
				}
				if(strcmp((yyvsp[(2) - (2)].F).name, "-") == 0)
				{
					if(strcmp((yyval.F).type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform subtraction on strings at Line %d\n", yylineno); }
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).ival = (yyvsp[(1) - (2)].F).ival - (yyvsp[(2) - (2)].F).ival;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "char")==0 && strcmp((yyvsp[(2) - (2)].F).type, "char")==0) (yyval.F).cval = (yyvsp[(1) - (2)].F).cval - (yyvsp[(2) - (2)].F).cval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval - (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).ival - (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval - (yyvsp[(2) - (2)].F).ival;
				
				}
			}
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 598 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 600 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "+";;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 602 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "-";;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 607 "parser.y"
    {
		(yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval; 
				
			if(strcmp((yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type) != 0 && strcmp((yyvsp[(2) - (2)].F).type, "none")!=0 && !((strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int") == 0) || (strcmp((yyvsp[(2) - (2)].F).type, "float")==0 && strcmp((yyvsp[(1) - (2)].F).type, "int") == 0)))
			{	errors++; printf("ERROR: Type Mismatch, cannot multiply expression of type %s with %s at Line %d\n", (yyvsp[(1) - (2)].F).type, (yyvsp[(2) - (2)].F).type, yylineno); }
			else {
			
				(yyval.F).type = (strcmp((yyvsp[(1) - (2)].F).type, "float") == 0 || strcmp((yyvsp[(2) - (2)].F).type, "float") == 0)? "float": (yyvsp[(1) - (2)].F).type; 
				if(strcmp((yyvsp[(2) - (2)].F).name, "*") == 0)
				{
					if(strcmp((yyval.F).type, "char") == 0 || strcmp((yyval.F).type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform multiplications on character/string types at Line %d\n", yylineno); }
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).ival = (yyvsp[(1) - (2)].F).ival * (yyvsp[(2) - (2)].F).ival;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval * (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).ival * (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval * (yyvsp[(2) - (2)].F).ival;
				
				}
				else if(strcmp((yyvsp[(2) - (2)].F).name, "/") == 0)
				{
					if(strcmp((yyval.F).type, "char") == 0 || strcmp((yyval.F).type, "string") == 0)
					    { errors++; printf("ERROR: Type Mismatch, cannot perform division on character/string types at Line %d\n", yylineno); }
					else if((strcmp((yyvsp[(2) - (2)].F).type, "int")== 0 && (yyvsp[(2) - (2)].F).ival == 0) || ((yyvsp[(2) - (2)].F).fval == 0 && strcmp((yyvsp[(2) - (2)].F).type, "float")== 0)) 
					    { errors++; printf("ERROR: Division by ZERO at Line %d\n", yylineno); }
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).ival = (yyvsp[(1) - (2)].F).ival / (yyvsp[(2) - (2)].F).ival;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval / (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "float")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).ival / (yyvsp[(2) - (2)].F).fval;
					else if(strcmp((yyvsp[(1) - (2)].F).type, "float")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).fval = (yyvsp[(1) - (2)].F).fval / (yyvsp[(2) - (2)].F).ival;
				
				}
				else if(strcmp((yyvsp[(2) - (2)].F).name, "%") == 0)
				{
					if(strcmp((yyval.F).type, "char") == 0 || strcmp((yyval.F).type, "string") == 0  || strcmp((yyval.F).type, "float") == 0)
					{	errors++; printf("ERROR: Type Mismatch, cannot perform modulus on character/string/float types at Line %d\n", yylineno); }
					else if(strcmp((yyvsp[(1) - (2)].F).type, "int")==0 && strcmp((yyvsp[(2) - (2)].F).type, "int")==0) (yyval.F).ival = (yyvsp[(1) - (2)].F).ival % (yyvsp[(2) - (2)].F).ival;
				
				}
				
			}
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 650 "parser.y"
    { (yyval.F).type = "none"; (yyval.F).name = "none"; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 652 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "*";;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 654 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "/";;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 656 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; (yyval.F).sval = (yyvsp[(2) - (3)].F).sval; (yyval.F).name = "%";;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 660 "parser.y"
    { (yyval.F.cval) = '=';;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 661 "parser.y"
    { (yyval.F.cval) = '+';;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 662 "parser.y"
    { (yyval.F.cval) = '-';;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 663 "parser.y"
    { (yyval.F.cval) = '*';;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 664 "parser.y"
    { (yyval.F.cval) = '/';;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 668 "parser.y"
    { (yyval.F).name = "none"; (yyval.F).ival = (yyvsp[(1) - (1)].F.ival); (yyval.F).type = "int";  ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 669 "parser.y"
    { (yyval.F).name = "none"; (yyval.F).cval = (yyvsp[(1) - (1)].F.cval); (yyval.F).type = "char"; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 670 "parser.y"
    { (yyval.F).name = "none"; (yyval.F).fval = (yyvsp[(1) - (1)].F.fval); (yyval.F).type = "float"; ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 674 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (1)].F).type; (yyval.F).name = (yyvsp[(1) - (1)].F).name; (yyval.F).ival = (yyvsp[(1) - (1)].F).ival; (yyval.F).cval = (yyvsp[(1) - (1)].F).cval; (yyval.F).fval = (yyvsp[(1) - (1)].F).fval; (yyval.F).sval = (yyvsp[(1) - (1)].F).sval;;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 676 "parser.y"
    {
		if(strcmp((yyvsp[(2) - (2)].F).type, "int") != 0 && strcmp((yyvsp[(2) - (2)].F).type, "float") != 0)
		{ errors++; printf("ERROR: Increment Operator with non-matching type at Line %d\n", yylineno); }

		(yyval.F).type = (yyvsp[(2) - (2)].F).type; (yyval.F).name = (yyvsp[(2) - (2)].F).name; (yyval.F).ival = (yyval.F).ival + 1; (yyval.F).fval = (yyval.F).fval + 1;  
	  ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 683 "parser.y"
    {
		if(strcmp((yyvsp[(2) - (2)].F).type, "int") != 0 && strcmp((yyvsp[(2) - (2)].F).type, "float") != 0)
		{ errors++; printf("ERROR: Decrement Operator with non-matching type at Line %d\n", yylineno); }

		(yyval.F).type = (yyvsp[(2) - (2)].F).type; (yyval.F).name = (yyvsp[(2) - (2)].F).name; (yyval.F).ival = (yyval.F).ival - 1; (yyval.F).fval = (yyval.F).fval - 1;  
	  ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 693 "parser.y"
    { (yyval.F).type = (yyvsp[(1) - (2)].F).type; (yyval.F).name = (yyvsp[(1) - (2)].F).name; (yyval.F).ival = (yyvsp[(1) - (2)].F).ival; (yyval.F).cval = (yyvsp[(1) - (2)].F).cval; (yyval.F).fval = (yyvsp[(1) - (2)].F).fval; (yyval.F).sval = (yyvsp[(1) - (2)].F).sval;;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 697 "parser.y"
    { (yyval.F).type = "none"; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 698 "parser.y"
    { 
		if(isArray == 0) 
		{ errors++; printf("ERROR: Non-Array Variable %s being accessed with Index[] at Line %d\n", varName, yylineno); } 
	  ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 703 "parser.y"
    {	
		if(strcmp((yyvsp[(3) - (3)].F).type, "int") != 0) 
		{ errors++; printf("ERROR: Array Index is of non-integer type at Line %d\n", yylineno); }
		else {
			tEntry* s =  getsym(varName, getScope(varName));
			
			if(s != (tEntry*)0 && (yyvsp[(3) - (3)].F).ival >= s->arraysize)
			{ errors++; printf("ERROR: Array Index is out of bounds at Line %d\n", yylineno); }
		}
		
	  ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 714 "parser.y"
    { isArray = 0; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 714 "parser.y"
    { (yyval.F).name = (yyvsp[(3) - (7)].F).name; (yyval.F).type; (yyval.F).type; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 718 "parser.y"
    {
		if(strcmp(getType(varName), "int") != 0 && strcmp(getType(varName), "float") != 0)
		{ errors++; printf("ERROR: Increment Operator with non-matching type at Line %d\n", yylineno); }

		(yyval.F).type = (yyvsp[(2) - (2)].F).type; (yyval.F).name = (yyvsp[(2) - (2)].F).name; (yyval.F).ival = (yyval.F).ival + 1; (yyval.F).fval = (yyval.F).fval + 1;  
	  ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 725 "parser.y"
    {
		if(strcmp(getType(varName), "int") != 0 && strcmp(getType(varName), "float") != 0)
		{ errors++; printf("ERROR: Decrement Operator with non-matching type at Line %d\n", yylineno); }

		(yyval.F).type = (yyvsp[(2) - (2)].F).type; (yyval.F).name = (yyvsp[(2) - (2)].F).name; (yyval.F).ival = (yyval.F).ival - 1; (yyval.F).fval = (yyval.F).fval - 1;  
	  ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 745 "parser.y"
    { 
			(yyval.F).name = (yyvsp[(1) - (1)].F).name;
			tEntry *s = getsym ((yyvsp[(1) - (1)].F).name, current_scope);
			tEntry *s2 = getsym ((yyvsp[(1) - (1)].F).name, "global");
			if(s == (tEntry*) 0 && s2 != (tEntry*) 0) s = s2;
			if (s == (tEntry*) 0) 
			{	
				errors++;
				printf("ERROR: Undeclared Identifier %s at Line %d\n", (yyvsp[(1) - (1)].F).name, yylineno);
				
			}
			else { 
				if(s->arraysize > 0) { isArray = 1; } 
				varName = s->lexeme;
				(yyval.F).type = s->type;  
				(yyval.F).name = s->lexeme;
				if(strcmp(s->type, "int") == 0) (yyval.F).ival = (yyvsp[(1) - (1)].F).ival;
					else if(strcmp(s->type, "char") == 0) (yyval.F).cval = (yyvsp[(1) - (1)].F).cval;
					else if(strcmp(s->type, "float") == 0) (yyval.F).fval = (yyvsp[(1) - (1)].F).fval;
					else if(strcmp(s->type, "string") == 0) (yyval.F).sval = (yyvsp[(1) - (1)].F).sval;
			}
			
		;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 769 "parser.y"
    { 
			(yyval.F).name = "Constant";
			(yyval.F).type = (yyvsp[(1) - (1)].F).type;
			
			{
				if(strcmp((yyvsp[(1) - (1)].F).type, "int") == 0) (yyval.F).ival = (yyvsp[(1) - (1)].F).ival;
				else if(strcmp((yyvsp[(1) - (1)].F).type, "char") == 0) (yyval.F).cval = (yyvsp[(1) - (1)].F).cval;
				else if(strcmp((yyvsp[(1) - (1)].F).type, "float") == 0) (yyval.F).fval = (yyvsp[(1) - (1)].F).fval;
			}
			
		;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 780 "parser.y"
    { (yyval.F).type = "string"; (yyval.F).sval = (yyvsp[(1) - (1)].F.sval); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 781 "parser.y"
    { (yyval.F).type = (yyvsp[(2) - (3)].F).type; (yyval.F).ival = (yyvsp[(2) - (3)].F).ival; (yyval.F).cval = (yyvsp[(2) - (3)].F).cval; (yyval.F).fval = (yyvsp[(2) - (3)].F).fval; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2586 "parser.tab.c"
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
#line 783 "parser.y"


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
    
    int check;
    while((check = yyparse()) != 0 && check != EOF && check != '\n')
    {
    }

    printtable();

    printf("\nDone Parsing. Total errors: %d. Total lines: %d.", errors, yylineno);
    	

	

}
