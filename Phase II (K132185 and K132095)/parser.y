%{
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

%}

%union 
{
	int intval; /* Integer values */
	float floatval;
	char charval;
	char *id; /* Identifiers */
	char *type;
}


%start TransitionUnit

%token <intval>Integer
%token <id> Identifier
%token <type> VOID
%token <type> CHAR
%token <type> INT
%token <type> FLOAT
%token <charval> Character
%token <floatval> Real
%token String
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

%%

TransitionUnit
	: ExternalDeclaration TransitionUnit_a
	;

TransitionUnit_a
	: 
	| ExternalDeclaration TransitionUnit_a
	;

ExternalDeclaration
	: FunctionDefinition
	| Declaration
	;

FunctionDefinition
	: TypeSpecifier Declarator FunctionDefinition_a	 	{ current_scope = "global";}
	| Declarator FunctionDefinition_b       		{ current_scope = "global";}
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
	: VOID	{ ctype = "void";  }	
	| CHAR	{ ctype = "char";  }
	| INT	{ ctype = "int";   }
	| FLOAT { ctype = "float"; }
	;

Declarator
	: DirectDeclarator
	| Pointer DirectDeclarator { strcat(last->type, "ptr"); }
	;

DirectDeclarator
	: Identifier { install($1); last->scope = current_scope; } DirectDeclarator_a 
	;

DirectDeclarator_a
	:
	| OpeningRoundBracket DirectDeclarator_b
	| OpeningSquareBracket DirectDeclarator_c 	
	;

DirectDeclarator_b
	: Declarator ClosingRoundBracket DirectDeclarator_a
	| { last->function = 1; current_scope = last->lexeme; } ParameterList ClosingRoundBracket DirectDeclarator_a
	| ClosingRoundBracket DirectDeclarator_a
	;

DirectDeclarator_c
	: ClosingSquareBracket DirectDeclarator_a
	| Integer ClosingSquareBracket { last->arraysize = $1; } DirectDeclarator_a 
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
	: TypeSpecifier Declaration_a EndOfStatement
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
	;

Initializer
	: AssignmentExpression
	| OpeningBraces InitializerList ClosingBraces  { last->arraysize++; }
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
	| OpeningBraces StatementList ClosingBraces
	| OpeningBraces DeclarationList ClosingBraces
	| OpeningBraces DeclarationList StatementList ClosingBraces
	;

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
	: CASE Constant Colon Statement
	| DEFAULT Colon Statement
	;

ExpressionStatement
	: EndOfStatement
	| Expression EndOfStatement
	;

SelectionStatement
	: IF OpeningRoundBracket Expression ClosingRoundBracket Statement SelectionStatement_a
	;

SelectionStatement_a
	:
	| ELSE Statement
	;

SelectionStatement
	: SWITCH OpeningRoundBracket Expression ClosingRoundBracket Statement
	;

JumpStatement
	: CONTINUE EndOfStatement
	| BREAK EndOfStatement
	| RETURN JumpStatement_a
	;

JumpStatement_a
	: Expression EndOfStatement
	;

IterationStatement
	: WHILE OpeningRoundBracket Expression ClosingRoundBracket Statement
	| DO Statement WHILE OpeningRoundBracket Expression ClosingRoundBracket EndOfStatement
	| FOR OpeningRoundBracket ExpressionStatement ExpressionStatement ClosingRoundBracket Statement
	| FOR OpeningRoundBracket ExpressionStatement ExpressionStatement Expression ClosingRoundBracket Statement
	;

ConditionalExpression
	: EqualityExpression ConditionalExpression_a
	;

ConditionalExpression_a
	:
	| ConditionalOperator Expression Colon ConditionalExpression
	;

Expression
	: AssignmentExpression Expression_a
	;

Expression_a
	: 
	| Comma AssignmentExpression Expression_a
	;

AssignmentExpression
	: ConditionalExpression
	| UnaryExpression AssignmentOperator AssignmentExpression
	;

EqualityExpression
	: RelationalExpression EqualityExpression_a
	;

EqualityExpression_a
	:
	| IsEqualTo RelationalExpression EqualityExpression_a
	;

RelationalExpression
	: AdditiveExpression RelationalExpression_a
	;

RelationalExpression_a
	:
	| LessThan AdditiveExpression RelationalExpression_a
	| GreaterThan AdditiveExpression RelationalExpression_a
	| LessThanEqualTo AdditiveExpression RelationalExpression_a
	| GreaterThanEqualTo AdditiveExpression RelationalExpression_a
	;

AdditiveExpression
	: MultiplicativeExpression AdditiveExpression_a
	;

AdditiveExpression_a
	:
	| Add MultiplicativeExpression AdditiveExpression_a
	| Subtract MultiplicativeExpression AdditiveExpression_a
	;
	
MultiplicativeExpression
	: UnaryExpression MultiplicativeExpression_a
	;

MultiplicativeExpression_a
	:
	| Multiply UnaryExpression MultiplicativeExpression_a
	| Divide UnaryExpression MultiplicativeExpression_a
	| Modulus UnaryExpression MultiplicativeExpression_a
	;

AssignmentOperator
	: Assign
	| AddAndAssign
	| SubtractAndAssign
	| MultiplyAndAssign
	| DivideAndAssign
	;

Constant
	: Integer
	| Character
	| Real
	;

UnaryExpression
	: PostFixExpression
	| Increment UnaryExpression
	| Decrement UnaryExpression
	;

PostFixExpression
	: PrimaryExpression PostFixExpression_a
	;

PostFixExpression_a
	: 
	| OpeningSquareBracket Expression ClosingSquareBracket PostFixExpression_a
	| OpeningRoundBracket PostFixExpression_b
	| Increment PostFixExpression_a
	| Decrement PostFixExpression_a
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
	| Constant
	| String
	| OpeningRoundBracket Expression ClosingRoundBracket
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
    
    
    yyparse();
    printf("Done Parsing. Total errors: %d\n\n", errors);
    
    printtable();


	

}