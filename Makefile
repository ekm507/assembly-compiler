a.out: main.o compiler.o
	gcc main.o compiler.o read_write.o -o a.out

main.o: main.c
	gcc -c main.c

compiler.o: compiler.c compiler.h
	gcc -c compiler.c

read_write.o: read_write.c read_write.h
	gcc -c read_write.c

clean:
	rm *.o
