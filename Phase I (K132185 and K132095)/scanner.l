%{
 #include <stdio.h>
 int linecount = 0;
 void yyerror(char*, int);
 int comment(void);
%}

%option noyywrap yylineno

ArithmeticOperator		(+|-|*|/|%)
AssignmentOperator		(=|+=|-=|*=|/=|%=)
Break				(break)
Case				(case)
Character		        \'[^\n"]\'{1}
ClosingBraces 		        [\}]
ClosingRoundBracket 		[\)]
ClosingSquareBracket 		[\]]
Colon				(:)
Comma				(,)
Constant			({Integer}|{Float}|{String}|{Character})	
Continue			(continue)
Decrement			(--)
Default				(default)
Digit		                [0-9]
Do				(do)
EndOfStatement			(;)
Else				(else)
For				(for)
Identifier                      {Letter}({Letter}|{Digit}|_)*
If				(if)
Increment			(++)
Integer				[0-9][0-9]*
Letter         			[A-Za-z]
LogicalOperator			(<|<=|==|!=|=>|>)
MultiString                     \"(\\.|[^\\"])*\"
MultiChar			\'.{2,}\'
OpeningBraces 		        [\{]
OpeningRoundBracket 		[\(]
OpeningSquareBracket 		[\[]
Real				[0-9]+([\.][0-9]+)?
Return				(return)
String			        \"(\\.|[^\n\\"])*\"
Switch				(switch)
TypeSpecifier			(void|char|int|float)
While				(while)
WS		                [ \t]+


%%
{WS}            { /* skip whitespace, do nothing about it */ }

\n		{ /* same for newline */ linecount = yylineno; }

{ClosingBraces} {}
{ClosingRoundBracket} {}
{ClosingSquareBracket} {}
{Comma}         {}
{OpeningBraces} {}
{OpeningRoundBracket} {}
{OpeningSquareBracket} {}
{EndOfStatement} {}

"/*"		{ int c;
    		  while ((c = input()) != EOF)
	              if (c == '*')
		      {
		          while ((c = input()) == '*');
  	                  if (c == '/')
                 	    return 1;

	                  if (c == EOF) break;    
		
	              }
		  yyerror("Unterminated Comment Starting At Line", linecount);
	          linecount = yylineno;
	          return -1;
	        }


{String}        { fprintf(yyout, "<String, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

{MultiString}   { yyerror("String Constant Exceeds Line at Line", linecount); linecount = yylineno; return 1;}

{TypeSpecifier} { fprintf(yyout, "<TypeSpecifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

{Character}     { fprintf(yyout, "<Character, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

{MultiChar}     { yyerror("Char Constant Too Long", yylineno); linecount = yylineno; return -1; }

{Integer}       { fprintf(yyout, "<Integer, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

{Real}          { fprintf(yyout, "<Real, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

{Identifier}    { fprintf(yyout, "<Identifier, %s, %d>\n", yytext, yylineno); linecount = yylineno; return 1; }

.		{ yyerror("Undefined Symbol at Line", yylineno); linecount = yylineno;  return -1; }

%%

main(void)
{
    yyin = fopen("in.txt", "r");
    yyout = fopen("out.txt", "w+");
    int check;
    while ((check = yylex()) != 0)
        if (check == -1)
            while(input() != EOF && input() != '\n');
  
    return 0;
}



int yyinput() {}


void yyerror(char *s, int lineno)
{
    printf ("%s %d\n", s, lineno);
}


int comment(void)
{
    
}