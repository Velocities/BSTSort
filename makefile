sort: BSTSort.o main.o
	gcc -o sort BSTSort.o main.o

main.o: main.c
	gcc -c main.c

BSTSort.o: BSTSort.c BSTSort.h
	gcc -c BSTSort.c

clean:
	rm sort BSTSort.o main.o
