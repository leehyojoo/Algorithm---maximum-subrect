CC=gcc
CFLAGS=-g -Wall
TARGET=mp1_20200901
OBJS=main.o subrect_algorithm.o

$(TARGET) : $(OBJS)
	gcc -o mp1_20200901 main.o subrect_algorithm.o

main.o : main.c
	gcc -c -o main.o main.c

subrect_algorithm.o : subrect_algorithm.c
	gcc -c -o subrect_algorithm.o subrect_algorithm.c

clean:
	rm *.o mp1_20200901
