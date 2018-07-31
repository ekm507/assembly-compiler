a.out: main.o compiler.o clean-code.o
	gcc main.o compiler.o clean-code.o -o a.out

main.o: main.c
	gcc -c main.c

compiler.o: compiler.c compiler.h
	gcc -c compiler.c

clean-code.o: clean-code.c clean-code.h
	gcc -c clean-code.c

clean:
	rm *.o a.out
