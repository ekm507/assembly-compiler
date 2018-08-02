a.out: main.o clean-code.o process.o check.o errors.o
	gcc main.o clean-code.o process.o check.o errors.o -o compile

main.o: main.c
	gcc -c main.c

process.o: process.c process.h
	gcc -c process.c

check.o: check.c check.h
	gcc -c check.c

clean-code.o: clean-code.c clean-code.h
	gcc -c clean-code.c

errors.o: errors.h errors.c
	gcc -c errors.c

clean:
	rm *.o compile
