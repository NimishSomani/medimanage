#include<stdio.h>
#include<string.h>

typedef struct medical {
	char batch[10];
	char mediname[20];
	int qty;
	double rate;
	double total;
	double mrp;
	char purdate[15];
	char expdate[15];
	char manudate[15];
}medical;

//function for main menu
void mainmenu();

//check for products with qty less than 10
void stock();

//Enter a new record
void medientry();

//Search for a particular record
void medisearch();

//Edit the available info
void modify();

//Delete a record
void del(medical rm);

//to move to a particular point on the screen
void move(int x, int y);
