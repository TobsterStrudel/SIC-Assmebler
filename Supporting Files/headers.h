#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

struct symbols {
	int	DefinedOnSourceLine;
	int	Address; 
	char	Name[7]; };

typedef struct symbols	SYMBOL;

struct opcodes {
	char	OpCode;	
	char	Name[8];

};

typedef struct opcodes OPCODES;


OPCODES OpcodeTable[ 32 ];

int IsAValidSymbol( char *TestSymbol );
int IsADirective( char *Test );
int IsAnInstruction( char *Test );
int IsThreeBytes( char *Test );
int isaPowerOfTwo( int n);
void addSymbol(int addr, char *sname, SYMBOL *table[]);
char* findOpCode(char* sym);
void swap(char *x, char *y);
char* itoa(int value, char* buffer, int base);
