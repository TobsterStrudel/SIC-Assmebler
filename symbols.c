#include "headers.h"



int IsAValidSymbol( char *TestSymbol ){

	int Result = 1;
	int index =0;
	int maxlength = 6;
	int done;
	done = 0 ;

	while( !done ) {
		if ( TestSymbol[index] == '\0' ) {
			break;
			}

		if ( index == maxlength ) {
			done = 1;
			Result = 0;
		}
		index++;

	}


	return Result;
}
void addSymbol(int addr, char *sname, SYMBOL *table[]){
	int index = 0;
	SYMBOL *newsym;
	newsym = malloc(sizeof(SYMBOL));
	newsym -> Address = addr;
	strcpy(newsym -> Name, sname);

	while(table[index] != NULL)
		index++;
	table[index] = newsym;
}
char* findOpCode(char* sym){
		if(!strcmp(sym, "START")){
		   return "START";
		}
	        if(!strcmp(sym, "ADD")){
                    return "18";
                }
                if(!strcmp(sym, "ADDF")){
                    return "58";
                }
                if(!strcmp(sym, "ADDR")){
                    return "90";
                }
                if(!strcmp(sym, "AND")){
                    return "40";
                }
                if(!strcmp(sym, "CLEAR")){
                    return "B4";
                }
                if(!strcmp(sym, "COMP")){
                    return "28";
                }
                if(!strcmp(sym, "COMPF")){
                    return "88";
                }
                if(!strcmp(sym, "COMPR")){
                    return "A0";
                }
                if(!strcmp(sym, "DIV")){
                    return "24";
                }
                if(!strcmp(sym, "DIVF")){
                    return "64";
                }
                if(!strcmp(sym, "DIVR")){
                    return "9C";
                }
                if(!strcmp(sym, "FIX")){
                    return "C4";
                }
                if(!strcmp(sym, "FLOAT")){
                    return "C0";
                }
                if(!strcmp(sym, "HIO")){
                    return "F4";
                }
                if(!strcmp(sym, "J")){
                    return "3C";
                }
                if(!strcmp(sym, "JEQ")){
                    return "30";
                }
                if(!strcmp(sym, "JGT")){
                    return "34";
                }
                if(!strcmp(sym, "JLT")){
                    return "38";
                }
                if(!strcmp(sym, "JSUB")){
                    return "48";
                }
                if(!strcmp(sym, "LDA")){
                    return "00";
                }
                if(!strcmp(sym, "LDB")){
                    return "68";
                }
                if(!strcmp(sym, "LDCH")){
                    return "50";
                }
                if(!strcmp(sym, "LDF")){
                    return "70";
                }
                if(!strcmp(sym, "LDL")){
                    return "08";
                }
                if(!strcmp(sym, "LDS")){
                    return "6C";
                }
                if(!strcmp(sym, "LDX")){
                    return "74";
                }
                if(!strcmp(sym, "LPS")){
                    return "04";
                }
                if(!strcmp(sym, "MUL")){
                    return "D0";
                }
                if(!strcmp(sym, "MULF")){
                    return "20";
                }
                if(!strcmp(sym, "MULR")){
                    return "60";
                }
                if(!strcmp(sym, "NORM")){
                    return "98";
                }
                if(!strcmp(sym, "OR")){
                    return "C8";
                }
                if(!strcmp(sym, "RD")){
                    return "44";
                }
                if(!strcmp(sym, "RMO")){
                    return "D8";
                }
                if(!strcmp(sym, "RSUB")){
                    return "AC";
                }
                if(!strcmp(sym, "SHIFTL")){
                    return "4C";
                }
                if(!strcmp(sym, "SHIFTR")){
                    return "A4";
                }
                if(!strcmp(sym, "SIO")){
                    return "A8";
                }
                if(!strcmp(sym, "SSK")){
                    return "EC";
                }
                if(!strcmp(sym, "STA")){
                    return "OC";
                }
                if(!strcmp(sym, "STB")){
                    return "78";
                }
                if(!strcmp(sym, "STCH")){
                    return "54";
                }
                if(!strcmp(sym, "STF")){
                    return "80";
                }
                if(!strcmp(sym, "STI")){
                    return "D4";
                }
                if(!strcmp(sym, "STL")){
                    return "14";
                }
                if(!strcmp(sym, "STS")){
                    return "7C";
                }
                if(!strcmp(sym, "STSW")){
                    return "E8";
                }
                if(!strcmp(sym, "STT")){
                    return "84";
                }
                if(!strcmp(sym, "STX")){
                    return "10";
                }
                if(!strcmp(sym, "SUB")){
                    return "1C";
                }
                if(!strcmp(sym, "SUBF")){
                    return "5C";
                }
                if(!strcmp(sym, "SUBR")){
                    return "94";
                }
                if(!strcmp(sym, "SVC")){
                    return "B0";
                }
                if(!strcmp(sym, "TD")){
                    return "E0";
                }
                if(!strcmp(sym, "TIO")){
                    return "F8";
                }
                if(!strcmp(sym, "TIX")){
                    return "2C";
                }
                if(!strcmp(sym, "TIXR")){
                    return "B8";
                }
                if(!strcmp(sym, "WD")){
                    return "DC";
            	}
		return "NONE FOUND";
}
void swap(char *x, char *y) {
    char t = *x; *x = *y; *y = t;
}

// Function to reverse `buffer[i…j]`
char* reverse(char *buffer, int i, int j)
{
    while (i < j) {
        swap(&buffer[i++], &buffer[j--]);
    }

    return buffer;
}

// Iterative function to implement `itoa()` function in C
char* itoa(int value, char* buffer, int base)
{
    // invalid input
    if (base < 2 || base > 32) {
        return buffer;
    }

    // consider the absolute value of the number
    int n = abs(value);

    int i = 0;
    while (n)
    {
        int r = n % base;

        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        }
        else {
            buffer[i++] = 48 + r;
        }

        n = n / base;
    }

    // if the number is 0
    if (i == 0) {
        buffer[i++] = '0';
    }

    // If the base is 10 and the value is negative, the resulting string
    // is preceded with a minus sign (-)
    // With any other base, value is always considered unsigned
    if (value < 0 && base == 10) {
        buffer[i++] = '-';
    }

    buffer[i] = '\0'; // null terminate string

    // reverse the string and return it
    return reverse(buffer, 0, i - 1);
}
