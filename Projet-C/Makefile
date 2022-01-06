all : PROJET EXECUTION

avion.o : avion.c avion.h
		cc -c avion.c
main.o : main.c avion.h
	cc -c main.c
PROJET : avion.o main.o
	cc -o PROJET main.o avion.o

EXECUTION :
		./PROJET