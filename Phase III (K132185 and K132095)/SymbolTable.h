#ifndef __SYMBOLTABLE_H__
#define __SYMBOLTABLE_H__

struct tEntry
{
char *lexeme; 
char *type;
char *scope;
int  arraysize;
int  function;
int  numargs;

struct tEntry *next;
};


typedef struct tEntry tEntry;



char *current_scope = "global";

tEntry *symbol_table = (tEntry *)0; 
tEntry *last = (tEntry*) 0;


tEntry * add(char *clexeme, char*ctype, char*cscope, int iarraysize, int ifunction, int inumargs)
{
    tEntry *ptr;
    ptr = (tEntry *) malloc (sizeof(tEntry));
    ptr->lexeme = (char *) malloc (strlen(clexeme)+1);
    strcpy(ptr->lexeme, clexeme);    
    ptr->type = (char *) malloc (strlen(ctype)+1);
    strcpy (ptr->type, ctype);    
    ptr->scope = (char *) malloc (strlen(cscope)+1);
    strcpy (ptr->scope, cscope);    
    ptr->arraysize = iarraysize;
    ptr->function = ifunction;
	if(ptr->function != 0) current_scope = ptr->lexeme;
    ptr->numargs = inumargs;
    
    ptr->next = (tEntry*) 0;
    if(symbol_table == (tEntry*) 0)
    {
   	symbol_table = ptr;
   	last = symbol_table;
    }
    else
    {
   	last->next = ptr;
    }

    last = ptr;	
    return last;
}


tEntry * getsym (char *clexeme, char* cscope)
{
   tEntry *ptr;
   for ( ptr = symbol_table; ptr != (tEntry *) 0; ptr = (tEntry *)ptr->next )
	if (strcmp (ptr->lexeme,clexeme) == 0 && strcmp(ptr->scope, cscope) == 0)
		return ptr;
   return 0;
}

tEntry *getsymbol_table()
{
   return (struct tEntry *)symbol_table;
}


tEntry* getLastFunction()
{
   tEntry* itr;
   tEntry* lastfunction = (tEntry*) 0;
   
   for(itr = symbol_table; itr != (tEntry *) 0; itr = (tEntry*) itr->next)
   {
	if(itr->function == 1) lastfunction = itr;
   }

   return lastfunction;
}


char* getType(char * a)
{
	tEntry *ptr = getsym(a, current_scope);
	
	if(ptr == 0)
		ptr = getsym(a, "global");	

	if (ptr != 0)
	   return ptr->type;
	
	return "none";	
}


char* getScope(char* clexeme)
{
	tEntry *ptr = symbol_table;

	if(ptr == (tEntry *) 0)
		return "undefined";

	for(ptr = symbol_table; ptr != (tEntry *) 0; ptr = (tEntry *)ptr->next )
	if (strcmp (ptr->lexeme, clexeme) == 0)
		return ptr->scope;

}

int isFunction(char *clexeme)
{
	tEntry *ptr = symbol_table;
	if(ptr == (tEntry *) 0)
		return 0;
	
	for ( ptr = symbol_table; ptr != (tEntry *) 0; ptr = (tEntry *)ptr->next )
	if (strcmp (ptr->lexeme, clexeme) == 0)
		return ptr->function;
	
	return 0;
}


int isArr(char* clexeme)
{
	tEntry * ptr = symbol_table;
	
	for ( ptr = symbol_table; ptr != (tEntry *) 0; ptr = (tEntry *)ptr->next )
	if (strcmp (ptr->lexeme, clexeme) && ptr->arraysize > 0)
		return 1;
	
	return 0;
}


void printtable()
{
    printf("LEXEME\t\tTYPE\tSCOPE\t\tARRAYSIZE\tFUNCTION\tNUMARGS\n");
    tEntry *ptr;
    
    for ( ptr = getsymbol_table(); ptr != (tEntry *) 0; ptr = (tEntry *)ptr->next )
    {
	  printf("%s\t\t%s\t%s\t\t%d\t\t%d\t%d\n", ptr->lexeme, ptr->type, ptr->scope, ptr->arraysize, ptr->function, ptr->numargs);
    }
}

#endif
//end symboltable.h

