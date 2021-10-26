project1:	main.o symbols.o  directives.o instructions.o notThreeBytes.o headers.h
	gcc -o project1 -Wall  -O0 main.o symbols.o directives.o instructions.o notThreeBytes.o

main.o:	main.c headers.h
	gcc -c -Wall  -O0 main.c

symbols.o:	symbols.c headers.h
	gcc -c -Wall  -O0 symbols.c

directives.o:	directives.c headers.h
	gcc -c -Wall  -O0 directives.c

instructions.o: instructions.c headers.h
	gcc -c -Wall -O0 instructions.c

notThreeBytes.o: notThreeBytes.c headers.h
	gcc -c -Wall -O0 notThreeBytes.c

clean:
	rm *.o -f
	touch *.c
	rm project1 -f
