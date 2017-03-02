%{
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



%}


%union 
{
	set F;
}

%start TransitionUnit

%token <F> Identifier
%token <F.ival>Integer
%token <F.cval> Character
%token <F.fval> Real
%token <F.sval>String
%token INT VOID CHAR FLOAT
%token Subtract Add Multiply Divide Modulus
%token Assign AddAndAssign MultiplyAndAssign DivideAndAssign SubtractAndAssign 
%token BREAK CASE CONTINUE DEFAULT DO ELSE IF FOR WHILE RETURN SWITCH
%token Colon Comma EndOfStatement ConditionalOperator
%token ClosingBraces ClosingRoundBracket ClosingSquareBracket
%token OpeningBraces OpeningRoundBracket OpeningSquareBracket
%token Increment Decrement
%token LessThan GreaterThan LessThanEqualTo GreaterThanEqualTo IsEqualTo NotEqualTo

%expect 1
%left '-' '+'
%left '*' '/'
%right '^'

%type<F.type> TypeSpecifier
%type<F.cval> AssignmentOperator
%type<F> FunctionDefinition
%type<F> Declarator
%type<F> DirectDeclarator
%type<F> InitDeclarator
%type<F> Initializer
%type<F> Declaration
%type<F> Expression
%type<F> Expression_a
%type<F> AssignmentExpression
%type<F> ConditionalExpression
%type<F> ConditionalExpression_a
%type<F> EqualityExpression
%type<F> EqualityExpression_a
%type<F> AdditiveExpression
%type<F> AdditiveExpression_a
%type<F> MultiplicativeExpression
%type<F> MultiplicativeExpression_a
%type<F> RelationalExpression
%type<F> RelationalExpression_a
%type<F> UnaryExpression
%type<F> PrimaryExpression
%type<F> PostFixExpression
%type<F> PostFixExpression_a
%type<F> ExpressionStatement
%type<F> JumpStatement
%type<F> JumpStatement_a
%type<F> Constant

%%

TransitionUnit 
	: 
	| ExternalDeclaration TransitionUnit_a
	;

TransitionUnit_a
	: 
	| ExternalDeclaration TransitionUnit_a
	;

ExternalDeclaration
	: FunctionDefinition { yyerrok; }
	| Declaration { yyerrok; }
	;

FunctionDefinition
	: TypeSpecifier Declarator FunctionDefinition_a	 	
			{ $$.name = $2.name; $$.type = $1; current_scope = "global"; }
	| Declarator FunctionDefinition_b        { current_scope = "global"; }
	;

FunctionDefinition_a
	: DeclarationList CompoundStatement
	| CompoundStatement
	;

FunctionDefinition_b
	: DeclarationList CompoundStatement
	| CompoundStatement
	;

TypeSpecifier
	: VOID	{ ctype = "void";  $$ = "void" ;    }	
	| CHAR	{ ctype = "char";  $$ = "char" ;    }
	| INT	{ ctype = "int";   $$ = "int"  ;    }
	| FLOAT { ctype = "float"; $$ = "float";    }
	;

Declarator
	: DirectDeclarator	{ $$.name = $1.name; $$.type = $1.type; }
	| Pointer { isPtr = 1; } DirectDeclarator { $$.type = strcat($3.type, "ptr"); $$.name = $3.name; $$.type = $3.type; }
	;

DirectDeclarator
	: Identifier 
		{ 
			install($1.name); // create entry in symbol table
			last->scope = current_scope;
			if(isPtr) 
				{ strcat(last->type, "ptr"); isPtr = 0; } // add ptr to type if pointer
		} 
	  DirectDeclarator_a { $$.name = $1.name; $$.type = $1.type; }
	;

DirectDeclarator_a
	: 
	| {
		last->function = 1; current_scope = last->lexeme; 
	  } OpeningRoundBracket DirectDeclarator_b
	| OpeningSquareBracket DirectDeclarator_c 	
	;

DirectDeclarator_b
	: Declarator ClosingRoundBracket DirectDeclarator_a
	| ParameterList ClosingRoundBracket DirectDeclarator_a
	| ClosingRoundBracket DirectDeclarator_a
	;

DirectDeclarator_c
	: ClosingSquareBracket DirectDeclarator_a
	| Integer ClosingSquareBracket 
		{ last->arraysize = $1; } 
	  DirectDeclarator_a 
	;

Pointer
	: Multiply Pointer_a 
	;

Pointer_a
	: 
	| Pointer
	;

DeclarationList
	: Declaration DeclarationList_a
	;

DeclarationList_a
	:
	| Declaration DeclarationList_a
	;
 
Declaration
	: TypeSpecifier Declaration_a EndOfStatement { $$.type = $1; }
	;

Declaration_a
	:
	| InitDeclaratorList
	;


InitDeclaratorList	
	: InitDeclarator
	| InitDeclaratorList Comma InitDeclarator
	;

InitDeclarator
	: Declarator
	| Declarator Assign Initializer 
		{
			if(strcmp($1.type, $3.type) != 0 && !((strcmp($1.type, "float") == 0) && strcmp($3.type, "int") == 0))
		  { errors++; printf("ERROR: Type Mismatch, cannot initialize %s with %s value at Line %d\n", $1.type, $3.type, yylineno); }
		  else {
			  $$.type = $1.type;
			  int t = 4;
			  if(strcmp($$.type, "int") == 0) t = 0;
			  else if(strcmp($$.type, "char") == 0) t = 1;
			  else if(strcmp($$.type, "float") == 0) t = 2;
			  else if(strcmp($$.type, "string") == 0) t = 3;
			  	switch(t)
				{
					case 0: $1.ival = $3.ival; break; 
					case 1: $1.cval = $3.cval; break; 
					case 2: $1.fval = $3.fval; break; 
					case 3: $1.sval = $3.sval; break;
					default: break;
				}
		  }
			 
		}
	;

Initializer
	: AssignmentExpression
		{
			$$.type = $1.type; 
			int t = 4;
			if(strcmp($$.type, "int") == 0) t = 0;
			else if(strcmp($$.type, "char") == 0) t = 1;
			else if(strcmp($$.type, "float") == 0) t = 2;
			else if(strcmp($$.type, "string") == 0) t = 3;
			switch(t)
			{
				case 0: $$.ival = $1.ival; break; 
				case 1: $$.cval = $1.cval; break; 
				case 2: $$.fval = $1.fval; break; 
				case 3: $$.sval = $1.sval; break;
				default: break;
			}
		}
	| OpeningBraces InitializerList ClosingBraces { last->arraysize++; }
	;

InitializerList
	: Initializer
	| InitializerList Comma { last->arraysize++; } Initializer
	;

ParameterList
	: ParameterDeclaration ParameterList_a
	;

ParameterList_a
	:
	| Comma ParameterDeclaration ParameterList_a 
	;

ParameterDeclaration
	: TypeSpecifier { if(getLastFunction() != (tEntry*) 0) getLastFunction()->numargs++; } ParameterDeclaration_a
	;

ParameterDeclaration_a
	: 
	| Declarator 
	;

CompoundStatement
	: OpeningBraces ClosingBraces			
	{ 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	}
	| OpeningBraces StatementList ClosingBraces
	{ 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	}
	| OpeningBraces DeclarationList ClosingBraces
	{ 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	}
	| OpeningBraces DeclarationList StatementList ClosingBraces
	{ 
	  if(getLastFunction() != NULL && strcmp(getLastFunction()->type, "void") != 0 && !didReturn)
		printf("ERROR: Non-void Function missing Return Statement at Line %d\n", yylineno); 
	  else didReturn = 1;
	};

StatementList
	: Statement StatementList_a
	;

StatementList_a
	:
	| Statement StatementList_a
	;

Statement
	: LabeledStatement
	| CompoundStatement
	| ExpressionStatement
	| SelectionStatement
	| IterationStatement
	| JumpStatement
	;

LabeledStatement
	: CASE Integer Colon Statement
	| CASE Character Colon Statement
	| DEFAULT Colon Statement
	;

ExpressionStatement
	: EndOfStatement { $$.type = "none"; $$.name = "none";}
	| Expression EndOfStatement { $$.type = $1.type; $$.name = $1.name;}
	;

SelectionStatement
	: IF OpeningRoundBracket Expression ClosingRoundBracket Statement SelectionStatement_a 
	;

SelectionStatement_a
	:
	| ELSE Statement
	;

SelectionStatement
	: SWITCH OpeningRoundBracket Expression 
		{
			if(strcmp($3.type, "int") != 0 && strcmp($3.type, "char")) 
			{  errors++; printf("ERROR: Switch statement must have Integer or Character in header at Line %d\n", yylineno); }
		}
		ClosingRoundBracket Statement
	;

JumpStatement
	: CONTINUE EndOfStatement
	| BREAK EndOfStatement
	| RETURN JumpStatement_a
		{
			didReturn = 1;
			tEntry* lastFunction = getLastFunction();
			if(strcmp($2.type, lastFunction->type) != 0 && !(strcmp(lastFunction->type, "float")== 0 && strcmp($2.type, "int")== 0))
			{ errors++; printf("ERROR: Function %s() is returning ", lastFunction->lexeme);
				int t = 4;
				if(strcmp($2.type, "int") == 0) t = 0;
				else if(strcmp($2.type, "char") == 0) t = 1;
				else if(strcmp($2.type, "float") == 0) t = 2;
				else if(strcmp($2.type, "string") == 0) t = 3;
				
				switch(t)
				{
					case 0: printf(    "%d, ", $2.ival); break; 
					case 1: printf("\'%c\', ", $2.cval); break; 
					case 2: printf(    "%f, ", $2.fval); break; 
					case 3: printf("\"%s\", ", $2.sval); break; 
					default: printf("nothing"); break;
				}
				printf(" Return type is: %s (is returning %s) at Line %d\n", lastFunction->type, $2.type, yylineno);
			}
			else { 
				$$.type = lastFunction->type; 
				int t = 4;
				if(strcmp($2.type, "int") == 0) t = 0;
				else if(strcmp($2.type, "char") == 0) t = 1;
				else if(strcmp($2.type, "float") == 0) t = 2;
				else if(strcmp($2.type, "string") == 0) t = 3;
				if((strcmp(lastFunction->type, "float") == 0 && strcmp($2.type, "int") == 0)) t = 4;
				switch(t)
				{
					case 0: $$.ival = $2.ival; break; 
					case 1: $$.cval = $2.cval; break; 
					case 2: $$.fval = $2.fval; break; 
					case 3: $$.sval = $2.sval; break; 
					case 4: $$.fval = $2.ival; break; 
					default:  break;
				}
			}
		}
	;

JumpStatement_a
	: Expression EndOfStatement 
	{ 	$$.type = $1.type;
		if(strcmp($$.type,"none") == 0) $$.type = "void";
	  $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval; }
	;

IterationStatement
	: WHILE OpeningRoundBracket Expression ClosingRoundBracket Statement 
	| DO Statement WHILE OpeningRoundBracket Expression ClosingRoundBracket EndOfStatement
	| FOR OpeningRoundBracket ExpressionStatement ExpressionStatement ClosingRoundBracket Statement
	| FOR OpeningRoundBracket ExpressionStatement ExpressionStatement Expression ClosingRoundBracket Statement
	;

ConditionalExpression
	: EqualityExpression ConditionalExpression_a { $$.type = $1.type;  $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval;  }
	;

ConditionalExpression_a
	: { $$.type = "none"; }
	| ConditionalOperator Expression
		{
			if(strcmp($2.type, "int") != 0)
			{ errors++; printf("ERROR: Expression in Conditional Statement is non boolean at Line %d\n", yylineno); }
		}
		Colon ConditionalExpression
	;

Expression
	: AssignmentExpression Expression_a { $$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval; }
	;

Expression_a
	: { $$.type = "none"; }
	| Comma AssignmentExpression Expression_a { $$.type = $2.type; }
	;

AssignmentExpression
	: ConditionalExpression { $$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval; } 
	| UnaryExpression 
	   {
		if(isArray == 1) 
		{ errors++; printf("ERROR: Array Variable %s being accessed without Index[] at Line %d\n", varName, yylineno); } 
		isArray = 0; 
		tEntry* s = getsym($1.name, getScope($1.name));
		
		if(s != (tEntry *)0 && s->function) 
		{	errors++; printf("ERROR: Function being assigned value at Line%d\n", $1.name, yylineno); }
		
	   } 
	  AssignmentOperator {} AssignmentExpression
	  {	
	  
		  if(strcmp($1.type, $5.type) != 0 && !(strcmp($1.type, "float")==0 && strcmp($5.type, "int")==0))
		  { errors++; printf("ERROR: Type Mismatch, cannot assign %s to %s at Line %d\n", $5.type, $1.type, yylineno); }
		  else {
			  $$.type = $1.type;
			  int t;
			  if(strcmp($$.type, "int") == 0) t = 0;
			  else if(strcmp($$.type, "char") == 0) t = 1;
			  else if(strcmp($$.type, "float") == 0) t = 2;
			  else if(strcmp($$.type, "string") == 0) t = 3;
			  
			  char c = $3;
			  
			  switch(c)
			  {
				  case '=': 
					switch(t)
					{	case 0: $1.ival = $5.ival; break; case 1: $1.cval = $5.cval; break; case 2: $1.fval = $5.fval; break; case 3: $1.sval = $5.sval; break; }	
				  break;

				  case '+': 
					switch(t)
					{	case 0: $1.ival += $5.ival; break; case 1: $1.cval += $5.cval; break; case 2: $1.fval += $5.fval; break; case 3: strcat($1.sval, $5.sval); break; }	
				  break;
				  case '-': 
					switch(t)
					{	case 0: $1.ival -= $5.ival; break; case 1: $1.cval -= $5.cval; break; case 2: $1.fval -= $5.fval; break; default: break; }	
				  break;
				  case '*': 
					switch(t)
					{	case 0: $1.ival *= $5.ival; break; case 2: $1.fval *= $5.fval; break; default: break; }	
				  break;
				  case '/': 
					switch(t)
					{	case 0: $1.ival /= $5.ival; break; case 2: $1.fval /= $5.fval; break; default: break; }	
				  break;
				  default: break;
			  }
			 
		  }
		  
	  }
	;

EqualityExpression
	: RelationalExpression EqualityExpression_a 
		{
			$$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval;
			if(strcmp($1.type, $2.type) != 0 && strcmp($2.type, "none") != 0)
			{	errors++; printf("ERROR: Type Mismatch, cannot compare expression of type %s with %s at Line %d\n", $1.type, $2.type, yylineno); }
			else if(strcmp($2.type, "none") != 0){
				
				}
		}
	;

EqualityExpression_a
	: { $$.type = "none"; }
	| IsEqualTo RelationalExpression EqualityExpression_a
		{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "==";}
	| NotEqualTo RelationalExpression EqualityExpression_a
	    { $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "!=";}
	;

RelationalExpression
	: AdditiveExpression RelationalExpression_a
	{
			
			$$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval; 
			if(strcmp($1.type, $2.type) != 0 && strcmp($2.type, "none") != 0)
			{	errors++; printf("ERROR: Type Mismatch, cannot compare expression of type %s with %s at Line %d\n", $1.type, $2.type, yylineno); }
			else if(strcmp($2.type, "none") != 0) {
				if(strcmp($2.name, "==") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0;
				else if(strcmp($2.name, "!=") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0;
				else if(strcmp($2.name, "<") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0;
				else if(strcmp($2.name, "<=") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0;
				else if(strcmp($2.name, ">") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0;
				else if(strcmp($2.name, ">=") == 0)
					$$.ival = ((strcmp($1.type, $2.type) == 0))?1:0; 
				}		
	}
	;

RelationalExpression_a
	: { $$.type = "none"; }
	| LessThan AdditiveExpression RelationalExpression_a
		{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "<";}
	| GreaterThan AdditiveExpression RelationalExpression_a
		{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = ">";}
	| LessThanEqualTo AdditiveExpression RelationalExpression_a
		{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "<=";}
	| GreaterThanEqualTo AdditiveExpression RelationalExpression_a
		{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = ">=";}
	;

AdditiveExpression
	: MultiplicativeExpression AdditiveExpression_a
	{
	
		$$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval;   
		
			if(strcmp($1.type, $2.type) != 0 && strcmp($2.type, "none")!=0 && !((strcmp($1.type, "float")==0 && strcmp($2.type, "int") == 0) || (strcmp($2.type, "float")==0 && strcmp($1.type, "int") == 0)))
			{	errors++; printf("ERROR: Type Mismatch, cannot add expression of type %s with %s at Line %d\n", $1.type, $2.type, yylineno); }
			else if(strcmp($2.type, "none") != 0) {
				$$.type = (strcmp($1.type, "float") == 0 || strcmp($2.type, "float") == 0)? "float": $1.type; 
				if(strcmp($2.name, "+") == 0)
				{
					if(strcmp($$.type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform addition on strings at Line %d\n", yylineno); }
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "int")==0) $$.ival = $1.ival + $2.ival;
					else if(strcmp($1.type, "char")==0 && strcmp($2.type, "char")==0) $$.cval = $1.cval + $2.cval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "float")==0) $$.fval = $1.fval + $2.fval;
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "float")==0) $$.fval = $1.ival + $2.fval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "int")==0) $$.fval = $1.fval + $2.ival;
				
				}
				if(strcmp($2.name, "-") == 0)
				{
					if(strcmp($$.type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform subtraction on strings at Line %d\n", yylineno); }
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "int")==0) $$.ival = $1.ival - $2.ival;
					else if(strcmp($1.type, "char")==0 && strcmp($2.type, "char")==0) $$.cval = $1.cval - $2.cval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "float")==0) $$.fval = $1.fval - $2.fval;
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "float")==0) $$.fval = $1.ival - $2.fval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "int")==0) $$.fval = $1.fval - $2.ival;
				
				}
			}
	}
	;

AdditiveExpression_a
	: { $$.type = "none"; }
	| Add MultiplicativeExpression AdditiveExpression_a
	{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "+";}
	| Subtract MultiplicativeExpression AdditiveExpression_a
	{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "-";}
	;
	
MultiplicativeExpression
	: UnaryExpression MultiplicativeExpression_a
	{
		$$.type = $1.type; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval; 
				
			if(strcmp($1.type, $2.type) != 0 && strcmp($2.type, "none")!=0 && !((strcmp($1.type, "float")==0 && strcmp($2.type, "int") == 0) || (strcmp($2.type, "float")==0 && strcmp($1.type, "int") == 0)))
			{	errors++; printf("ERROR: Type Mismatch, cannot multiply expression of type %s with %s at Line %d\n", $1.type, $2.type, yylineno); }
			else {
			
				$$.type = (strcmp($1.type, "float") == 0 || strcmp($2.type, "float") == 0)? "float": $1.type; 
				if(strcmp($2.name, "*") == 0)
				{
					if(strcmp($$.type, "char") == 0 || strcmp($$.type, "string") == 0 )
					{	errors++; printf("ERROR: Type Mismatch, cannot perform multiplications on character/string types at Line %d\n", yylineno); }
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "int")==0) $$.ival = $1.ival * $2.ival;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "float")==0) $$.fval = $1.fval * $2.fval;
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "float")==0) $$.fval = $1.ival * $2.fval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "int")==0) $$.fval = $1.fval * $2.ival;
				
				}
				else if(strcmp($2.name, "/") == 0)
				{
					if(strcmp($$.type, "char") == 0 || strcmp($$.type, "string") == 0)
					    { errors++; printf("ERROR: Type Mismatch, cannot perform division on character/string types at Line %d\n", yylineno); }
					else if((strcmp($2.type, "int")== 0 && $2.ival == 0) || ($2.fval == 0 && strcmp($2.type, "float")== 0)) 
					    { errors++; printf("ERROR: Division by ZERO at Line %d\n", yylineno); }
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "int")==0) $$.ival = $1.ival / $2.ival;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "float")==0) $$.fval = $1.fval / $2.fval;
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "float")==0) $$.fval = $1.ival / $2.fval;
					else if(strcmp($1.type, "float")==0 && strcmp($2.type, "int")==0) $$.fval = $1.fval / $2.ival;
				
				}
				else if(strcmp($2.name, "%") == 0)
				{
					if(strcmp($$.type, "char") == 0 || strcmp($$.type, "string") == 0  || strcmp($$.type, "float") == 0)
					{	errors++; printf("ERROR: Type Mismatch, cannot perform modulus on character/string/float types at Line %d\n", yylineno); }
					else if(strcmp($1.type, "int")==0 && strcmp($2.type, "int")==0) $$.ival = $1.ival % $2.ival;
				
				}
				
			}
	}
	;

MultiplicativeExpression_a
	: { $$.type = "none"; $$.name = "none"; }
	| Multiply UnaryExpression MultiplicativeExpression_a
	{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "*";}
	| Divide UnaryExpression MultiplicativeExpression_a
	{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "/";}
	| Modulus UnaryExpression MultiplicativeExpression_a
	{ $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; $$.sval = $2.sval; $$.name = "%";}
	;

AssignmentOperator
	: Assign 		{ $$ = '=';}
	| AddAndAssign		{ $$ = '+';}
	| SubtractAndAssign 	{ $$ = '-';}
	| MultiplyAndAssign 	{ $$ = '*';}
	| DivideAndAssign	{ $$ = '/';}
	;

Constant
	: Integer   { $$.name = "none"; $$.ival = $1; $$.type = "int";  }  
	| Character { $$.name = "none"; $$.cval = $1; $$.type = "char"; }  
	| Real	    { $$.name = "none"; $$.fval = $1; $$.type = "float"; }  
	;

UnaryExpression
	: PostFixExpression { $$.type = $1.type; $$.name = $1.name; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval;}
	| Increment UnaryExpression 
	  {
		if(strcmp($2.type, "int") != 0 && strcmp($2.type, "float") != 0)
		{ errors++; printf("ERROR: Increment Operator with non-matching type at Line %d\n", yylineno); }

		$$.type = $2.type; $$.name = $2.name; $$.ival = $$.ival + 1; $$.fval = $$.fval + 1;  
	  }
	| Decrement UnaryExpression
           {
		if(strcmp($2.type, "int") != 0 && strcmp($2.type, "float") != 0)
		{ errors++; printf("ERROR: Decrement Operator with non-matching type at Line %d\n", yylineno); }

		$$.type = $2.type; $$.name = $2.name; $$.ival = $$.ival - 1; $$.fval = $$.fval - 1;  
	  }

	;

PostFixExpression
	: PrimaryExpression PostFixExpression_a { $$.type = $1.type; $$.name = $1.name; $$.ival = $1.ival; $$.cval = $1.cval; $$.fval = $1.fval; $$.sval = $1.sval;}
	;

PostFixExpression_a
	: { $$.type = "none"; }
	| { 
		if(isArray == 0) 
		{ errors++; printf("ERROR: Non-Array Variable %s being accessed with Index[] at Line %d\n", varName, yylineno); } 
	  }
	  OpeningSquareBracket Expression
	  {	
		if(strcmp($3.type, "int") != 0) 
		{ errors++; printf("ERROR: Array Index is of non-integer type at Line %d\n", yylineno); }
		else {
			tEntry* s =  getsym(varName, getScope(varName));
			
			if(s != (tEntry*)0 && $3.ival >= s->arraysize)
			{ errors++; printf("ERROR: Array Index is out of bounds at Line %d\n", yylineno); }
		}
		
	  }
	  ClosingSquareBracket { isArray = 0; } PostFixExpression_a { $$.name = $3.name; $$.type; $$.type; }
	  
	| OpeningRoundBracket PostFixExpression_b
	| Increment PostFixExpression_a 
	  {
		if(strcmp(getType(varName), "int") != 0 && strcmp(getType(varName), "float") != 0)
		{ errors++; printf("ERROR: Increment Operator with non-matching type at Line %d\n", yylineno); }

		$$.type = $2.type; $$.name = $2.name; $$.ival = $$.ival + 1; $$.fval = $$.fval + 1;  
	  }
	| Decrement PostFixExpression_a 
	  {
		if(strcmp(getType(varName), "int") != 0 && strcmp(getType(varName), "float") != 0)
		{ errors++; printf("ERROR: Decrement Operator with non-matching type at Line %d\n", yylineno); }

		$$.type = $2.type; $$.name = $2.name; $$.ival = $$.ival - 1; $$.fval = $$.fval - 1;  
	  }
	;

PostFixExpression_b
	: ArgumentExpressionList ClosingRoundBracket PostFixExpression_a
	| ClosingRoundBracket PostFixExpression_a	
	;

ArgumentExpressionList
	: AssignmentExpression
	| ArgumentExpressionList Comma AssignmentExpression
	;

PrimaryExpression
	: Identifier 
		{ 
			$$.name = $1.name;
			tEntry *s = getsym ($1.name, current_scope);
			tEntry *s2 = getsym ($1.name, "global");
			if(s == (tEntry*) 0 && s2 != (tEntry*) 0) s = s2;
			if (s == (tEntry*) 0) 
			{	
				errors++;
				printf("ERROR: Undeclared Identifier %s at Line %d\n", $1.name, yylineno);
				
			}
			else { 
				if(s->arraysize > 0) { isArray = 1; } 
				varName = s->lexeme;
				$$.type = s->type;  
				$$.name = s->lexeme;
				if(strcmp(s->type, "int") == 0) $$.ival = $1.ival;
					else if(strcmp(s->type, "char") == 0) $$.cval = $1.cval;
					else if(strcmp(s->type, "float") == 0) $$.fval = $1.fval;
					else if(strcmp(s->type, "string") == 0) $$.sval = $1.sval;
			}
			
		}
	| Constant
		{ 
			$$.name = "Constant";
			$$.type = $1.type;
			
			{
				if(strcmp($1.type, "int") == 0) $$.ival = $1.ival;
				else if(strcmp($1.type, "char") == 0) $$.cval = $1.cval;
				else if(strcmp($1.type, "float") == 0) $$.fval = $1.fval;
			}
			
		}
	| String     { $$.type = "string"; $$.sval = $1; }		
	| OpeningRoundBracket Expression ClosingRoundBracket { $$.type = $2.type; $$.ival = $2.ival; $$.cval = $2.cval; $$.fval = $2.fval; }
	;
%%

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