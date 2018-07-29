a.out: main.o compiler.o
	gcc main.o compiler.o -o a.out

main.o: main.c
	gcc -c main.c

compiler.o: compiler.c compiler.h
	gcc -c compiler.c

clean:
	rm *.o a.out
