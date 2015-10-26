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
	char suppname[30];
}medical;
typedef struct bill {
	char billno[6];
	char cname[30];
	char mediname[30];
	int qty;
	double mrp;
	double total;
	int day;
	int month;
	int year;

}bill;

//function for main menu
void mainmenu();

//function for bill slip
void makebill();

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
