project : main.o functions.o
	cc main.o functions.o -o project
main.o : main.c main.h
	cc main.c -c 
functions.o : functions.c main.h
	cc functions.c -c 

