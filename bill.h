#include<stdio.h>
#include<string.h>

typedef struct bill {
	char cname[30];
	char mediname[20];
	int qty;
	double mrp;
	double rate;
	double total;
	int date;
	int month;
	int year;

}bill;

typedef struct st {
	char mediname[20];
	int qty;
	double rate;
	double total;
}st;

//Prepare a bill
void bil();

//Check the total sale
void sale();

//check daily sales
int day();

//check daily profit
int profit();
