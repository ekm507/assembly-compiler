a.out: main.o compiler.o clean-code.o process.o
	gcc main.o compiler.o clean-code.o process.o -o compile

main.o: main.c
	gcc -c main.c

process.o: process.c process.h
	gcc -c process.c

compiler.o: compiler.c compiler.h
	gcc -c compiler.c

clean-code.o: clean-code.c clean-code.h
	gcc -c clean-code.c

clean:
	rm *.o compile
