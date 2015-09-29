#include<stdio.h>
#include<string.h>

typedef struct medical {
	char batch[10];
	char medi-name[20];
	int qty;
	float rate;
	float total;
	float mrp;
	char pur-date[15];
	char exp-date[15];
	char manu-date[15];
	char consu-name[20];
	char supp-name[30];
}medical;
typedef struct bill {
	char billno[6];
	char cname[30];
	char medi-name[30];
	int qty;
	float rate;
	float total;
	int day;
	int month;
	int year;

}bill;
typedef struct list {
	medical *head, *tail;
}list;

//function for main menu
void mainmenu();

//function for bill slip
void bill();

//functions for medicine menu
void stock();
void medi-entry();
void medi-search();
void remainder();


