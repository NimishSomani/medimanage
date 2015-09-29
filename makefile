project : main.o
	cc main.o -o project
main.o : main.c main.h
	cc main.c -c 
