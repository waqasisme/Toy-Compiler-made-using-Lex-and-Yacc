
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 33 "parser.y"

	int intval; /* Integer values */
	float floatval;
	char charval;
	char *id; /* Identifiers */
	char *type;



/* Line 1676 of yacc.c  */
#line 112 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


