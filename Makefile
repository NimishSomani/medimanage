project : main.o functions.o move.o bill.o
	cc main.o functions.o move.o bill.o -o project
main.o : main.c main.h
	cc main.c -c 
functions.o : functions.c main.h
	cc functions.c -c 
move.o : move.c main.h
	cc move.c -c
bill.o : bill.c bill.h
	cc bill.c -c
clean:
	rm -rf *o project
