#include "headers.h"


int main( int argc, char* argv[]){

	FILE *fp;
	char symbolList[512][512];
	char directiveList[512][512];
	char directivesTwo[512][512];
        char justInstructions[512][512];
	int addressList[512];
	int fullAddressList[512];
	int i = 0;
	char line[1024];
	char* newsym;
	char* nextoken;
	int address = 0;
	int lineNumber = 0;
	int trueLineNumber = 0;
	int directiveNumber = 0;
	int pc = 0;
	int temp = 0;
	int count = 0;

	char fullline[1024];
	if ( argc != 2 ) {
	printf("ERROR: Usage: %s filename\n", argv[0]);
	return 0;
	}


	fp = fopen( argv[1], "r");

	if ( fp == NULL ) {
	printf("ERROR: %s could not be opened for reading,\n", argv[1] );
	return 0;
	}

	newsym = malloc(  1024 * sizeof(char)             );
	memset( newsym, '\0', 1024 * sizeof(char) );
	nextoken = malloc(  1024 * sizeof(char)             );
	memset( nextoken, '\0', 1024 * sizeof(char) );
	while(  fgets( line , 1024 , fp ) != NULL   ) {

		strcpy( fullline, line );
		if ( line[0] == 35) { //if line[0] == #;
		//	printf("COMMENT:%s", line );
			continue;
		}

		if (  (line[0] >= 65 ) && ( line[0] <= 90 )   )  {
			newsym = strtok( line, " \t\n");
//			printf("FULL LINE:%s\n", fullline );
			lineNumber++;
			fullAddressList[trueLineNumber-1] = 1;
//			trueLineNumber++;
			temp = 0;
			if(IsAValidSymbol(newsym)){
//				printf("Line %d\t", lineNumber);
                                strcpy(symbolList[lineNumber-1], newsym);
//				printf("%s\t",newsym);
				i++;
//				printf("Is a valid symbol is %d\n", IsAValidSymbol( newsym ) );


			nextoken = strtok( NULL, " \t\n"  );
			directiveNumber++;
                       	strcpy(directiveList[directiveNumber-1], nextoken);
//			printf("%s\n", nextoken);
                	if (IsADirective(nextoken)){
//		              	printf("DIRECTIVE: %s\n", nextoken);
				if (!strcmp(nextoken, "WORD")){
					fullAddressList[trueLineNumber-1] = address;
					address+=3;
				}
                        	if (!IsThreeBytes(nextoken)){
                                	nextoken = strtok(NULL, "\t");
					int tokenBaseTen = strtol(nextoken, NULL, 10);
//					printf("nextoken = %s\n", nextoken);
					if(strtol(nextoken, NULL, 10) < 3){
						fullAddressList[trueLineNumber-1] = address;
						address+=3;
					}else{
						while(tokenBaseTen > 2){
							tokenBaseTen /= 2;
//							printf("%d\n", tokenBaseTen);
						}
						if(tokenBaseTen == 1){
							fullAddressList[trueLineNumber-1] = address;
							address += strtol(nextoken, NULL, 16);
						}
						if(tokenBaseTen == 2){
							fullAddressList[trueLineNumber-1] = address;
							address+=3;
							pc = address +  strtol(nextoken, NULL, 10);
							temp = 1;
						}
					}
                        	}
			}
			if(pc != 0 && temp != 1){
				address = pc;
//				printf("Primary\n");
				addressList[lineNumber-1] = address;
				fullAddressList[trueLineNumber-1] = address;
			//	printf("%X\n", address);
				pc = 0;
				temp = 0;
			}else{
                                addressList[lineNumber-1] = address;
				fullAddressList[trueLineNumber-1] = address;
			//	printf("%X\n", address);
			}
//			printf("TEST ADDRESS: %X\n", pc);
                	if (IsAnInstruction(nextoken)){
//                        	printf("INSTRUCTION: %s\n", nextoken);
				fullAddressList[trueLineNumber-1] = address;
                        	address+=3;
                	}
			if ( IsAValidSymbol(newsym) == 0 ) {
				printf("ASSEMBLY ERROR:\n");
				printf("Line %d ", lineNumber);
				printf("INVALID SYMBOL\n");
				fclose(fp);
				return 0;
			}
			continue;
		}
}
		char *tempLine = line;
		char *hope = line;
		while(*tempLine == '\t' || *tempLine == '\n' || *tempLine == ' ' || *tempLine == '\0'){
			++tempLine;
		}
//		while(*tempLine != '\t'){//seg fault for some reason
//		}
		for(int j = 0; j < 6; j++){
			if(tempLine[j] == '\t'){
				hope[j] = '\0';
				break;
			}
			hope[j] = tempLine[j];
		}
		strcpy(justInstructions[count], line);
		count++;
//		printf("%s\n", line);
		directiveNumber++;
		strcpy(directiveList[directiveNumber-1], line);
		fullAddressList[trueLineNumber-1] = address;
		address+=3;


	}

	fclose( fp );
	printf("\n");
	int num = 1;
	int num2= 0;
/*	for(int i = 0; i < lineNumber; i++){
		printf("\033[0;3%dm", num);
		fputs(symbolList[i], stdout);
		printf("\t");
		printf("%X", addressList[i]);
		printf("\n");
		num++;
		//printf("%d", num);
		if(num > 6){
			num = 1;
		}
		printf("\033[0;37m");
	}*/
	num = 0;
	char directivesCopy[512][512];
	for(int i = 0; i < directiveNumber; i++){
		strcpy(directivesCopy[i], directiveList[i]);
		if(directiveList[i][0] != '\t'){
//			puts(directiveList[i]);
			strcpy(directiveList[num], directiveList[i]);
//			printf("%d\t", num+1);
			num++;
		}else{
			strcpy(directivesTwo[num2], directiveList[i]);
		}
		num2++;
	}
	trueLineNumber = num2;
	for(int i = 0; i < trueLineNumber; i++){
		printf("%X\n", fullAddressList[i]);
	}
/*	printf("justInstructions: \n");
	for(int i = 0; i < num2; i++){
		puts(justInstructions[i]);
	}
	printf("directiveList: \n");
	for(int i = 0; i < num; i++){
		puts(directiveList[i]);
	}*/
	char objectCode[512][512];
	FILE *fp2;
	fp2 = fopen("objFile.obj", "w");

	for(int i = 0; i < num2; i++){
		char* buffer;
		buffer = itoa(addressList[i], buffer, 16);
		if(!strcmp(findOpCode(directiveList[i]), "START")){
			continue;
		}else
			strcpy(objectCode[i], findOpCode(directiveList[i]));
		strcat(objectCode[i], buffer);
		fputs("00", fp2);
		fputs(objectCode[i], fp2);
		fputs("\n", fp2);
	}
	fclose(fp2);
}

