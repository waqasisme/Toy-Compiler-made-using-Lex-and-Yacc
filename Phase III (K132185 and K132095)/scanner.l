%{
 #include "parser.tab.c"
 #include <stdio.h>

%}

%option noyywrap yylineno

Add				(\+)
Assign				(\=)
AddAndAssign    		(\+\=)
SubtractAndAssign 		(\-\=)
MultiplyAndAssign   		(\*\=)
DivideAndAssign     		(\/\=)
BREAK				(break)
CASE				(case)
Character		    	\'[^\n"]\'
ClosingBraces 		 	[\}]
ClosingRoundBracket  		[\)]
ClosingSquareBracket 		[\]]
Colon				(\:)
Comma				(\,)
ConditionalOperator	 	(\?)
CONTINUE			(continue)
Decrement			(\-\-)
DEFAULT				(default)
Digit		         	[0-9]
Divide				(\/)
DO				(do)
DoubleQuote			(\")
EndOfStatement		 	(\;)
ELSE				(else)
FOR				(for)
Identifier           		{Letter}({Letter}|{Digit}|_)*
IF	                 	(if)
Increment			(\+\+)
Integer				[0-9][0-9]*
Letter         		 	[A-Za-z]
LessThan			(\<)
LessThanEqualTo 	 	(\<\=)
GreaterThan			(\>)
GreaterThanEqualTo 	 	(\>\=)
IsEqualTo			(\=\=)
NotEqualTo 			(\!\=)
Modulus				(\%)
Multiply			(\*)
MultiString          		\"(\\.|[^\\"])*\"
MultiChar			\'[^\n"]{2,}\'
OpeningBraces 		 	[\{]
OpeningRoundBracket  		[\(]
OpeningSquareBracket 		[\[]
Real				[0-9]+([\.][0-9]+)?
RETURN				(return)
Subtract			(\-)
String			     	\"(\\.|[^\n\\"])*\"
SingleQuote			(\')	
SWITCH				(switch)
VOID				(void)
CHAR				(char)
INT				(int)
FLOAT				(float)
WHILE				(while)
Comment				\/\*(\*(?!\/)|[^*\n])*\*\/

%%

{Add} 			{ fprintf(yyout, "<Add, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Add); }

{Assign} 		{ fprintf(yyout, "<Assign, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Assign); }

{AddAndAssign} 		{ fprintf(yyout, "<AddAndAssign, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (AddAndAssign); }

{SubtractAndAssign} 	{ fprintf(yyout, "<SubtractAndAssign, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (SubtractAndAssign); }

{DivideAndAssign} 	{ fprintf(yyout, "<DivideAndAssign, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (DivideAndAssign); }

{MultiplyAndAssign} 	{ fprintf(yyout, "<MultiplyAndAssign, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (MultiplyAndAssign); }

{Subtract} 		{ fprintf(yyout, "<Subtract, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Subtract); }

{Multiply} 		{ fprintf(yyout, "<Multiply, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Multiply); }

{Divide} 		{ fprintf(yyout, "<Divide, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Divide); }

{BREAK} 		{ fprintf(yyout, "<Break, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (BREAK); }

{CASE}	 		{ fprintf(yyout, "<Case, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (CASE); }

{Colon} 		{ fprintf(yyout, "<Colon, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Colon); }

{ConditionalOperator} 	{ fprintf(yyout, "<ConditionalOperator, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (ConditionalOperator); }

{CONTINUE} 		{ fprintf(yyout, "<Continue, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (CONTINUE); }

{Decrement} 		{ fprintf(yyout, "<Decrement, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Decrement); }

{DEFAULT} 		{ fprintf(yyout, "<Default, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (DEFAULT); }

{DO} 			{ fprintf(yyout, "<Do, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (DO); }

{ELSE}			{ fprintf(yyout, "<Else, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (ELSE); }

{FOR} 			{ fprintf(yyout, "<For, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (FOR); }

{IF} 			{ fprintf(yyout, "<If, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (IF); }

{Increment} 		{ fprintf(yyout, "<Increment, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Increment); }

{LessThan} 		{ fprintf(yyout, "<LessThan, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (LessThan); }

{LessThanEqualTo} 	{ fprintf(yyout, "<LessThanEqualTo, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (LessThanEqualTo); }

{GreaterThan} 		{ fprintf(yyout, "<GreaterThan, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (GreaterThan); }

{GreaterThanEqualTo} 	{ fprintf(yyout, "<GreaterThanEqualTo, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (GreaterThanEqualTo); }

{IsEqualTo} 		{ fprintf(yyout, "<EqualTo, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (IsEqualTo); }

{NotEqualTo} 		{ fprintf(yyout, "<NotEqualTo, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (NotEqualTo); }

{Modulus} 		{ fprintf(yyout, "<Modulus, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Modulus); }

{RETURN} 		{ fprintf(yyout, "<Return, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (RETURN); }

{SWITCH} 		{ fprintf(yyout, "<Switch, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (SWITCH); }

{WHILE} 		{ fprintf(yyout, "<While, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (WHILE); }

{ClosingBraces} 	{ fprintf(yyout, "<ClosingBraces, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (ClosingBraces); }

{ClosingRoundBracket}  	{ fprintf(yyout, "<ClosingRoundBracket, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (ClosingRoundBracket); }

{ClosingSquareBracket}  { fprintf(yyout, "<ClosingSquareBracket, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (ClosingSquareBracket); }

{Comma}        	 	{ fprintf(yyout, "<Comma, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (Comma); }

{OpeningBraces} 	{ fprintf(yyout, "<OpeningBraces, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (OpeningBraces); }

{OpeningRoundBracket}   { fprintf(yyout, "<OpeningRoundBracket, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (OpeningRoundBracket); }

{OpeningSquareBracket} 	{ fprintf(yyout, "<OpeningSqaureBracket, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (OpeningSquareBracket); }

{EndOfStatement} 	{ fprintf(yyout, "<EndOfStatement, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (EndOfStatement); }
\/\/[^\n]* 			{/*Single Line Comment*/}
\/\*(.|\n)*\*\/ 	{ /*Multi Line Comment */}

\/\*([^*]|\n)*[^\/]	{ printf("ERROR: Unterminated Comment at Line %d\n", linecount+1); errors++; linecount = yylineno;}	
\/\*([^*]|\n)*\/	{ printf("ERROR: Unterminated Comment at Line %d\n", linecount+1); errors++; linecount = yylineno;}


{String}        	{ fprintf(yyout, "<String, %s, %d>\n", yytext, yylineno); linecount = yylineno; return (String); }

{MultiString}   	{ printf("ERROR: String Constant Exceeds Line at Line %d\n", linecount+1); errors++; linecount = yylineno;}

{VOID}			{ fprintf(yyout, "<TypeSpecifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.type = (char *) strdup(yytext); return (VOID); }

{CHAR}			{ fprintf(yyout, "<TypeSpecifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.type = (char *) strdup(yytext); return (CHAR); }

{INT}			{ fprintf(yyout, "<TypeSpecifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.type = (char *) strdup(yytext);return (INT); }

{FLOAT} 		{ fprintf(yyout, "<TypeSpecifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.type = (char *) strdup(yytext);return (FLOAT); }

{MultiChar}     	{ printf("ERROR: Char Constant Too Long At Line %d\n", linecount+1); errors++; linecount = yylineno;}

{Integer}       	{ fprintf(yyout, "<Integer, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.ival = atoi(yytext); return (Integer); }

{Real}          	{ fprintf(yyout, "<Real, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.fval = atol(yytext); return (Real); }

{Character}     	{ fprintf(yyout, "<Character, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.cval = yytext[1]; return (Character); }

{Identifier}    	{ fprintf(yyout, "<Identifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; yylval.F.name = (char *) strdup(yytext); return (Identifier); }


{SingleQuote}		{ printf("ERROR: Out of Place ' At Line %d\n", linecount+1); errors++; linecount = yylineno; }
{DoubleQuote}		{ printf("ERROR: Out of Place \" At Line %d\n", linecount+1); errors++; linecount = yylineno;}

[ \t\n]+ 		/* eat up whitespace */

.			{ return yytext[0]; }



%%