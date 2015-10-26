#include <stdio.h>
#include <string.h>
#include "main.h"
void mainmenu() {
	printf("\t\t\t");
	printf("Make a choice\n");
	printf("\t1. Enter new stock\n");
	printf("\t2. Search for the stock of a particular medicine\n");
	printf("\t3. Delete a record\n");
	printf("\t4. Shortage stock\n");
	printf("\t5. Modify a medicine\n");
	printf("\t6. EXIT!!\n\n");
}
int main() {
	int choice;
	medical tmp;
	while(1) {
		mainmenu();
		scanf("%d", &choice);
		switch(choice) {
		case 1: 
			medientry();
			break;
		case 2: 
			medisearch();
			break;
		case 3: 
			system("clear");
			printf("Enter the name of medicine whose record is to be removed\n\n");
			scanf("%s", tmp.mediname);
			del(tmp);
			break;
		case 4: 
			stock();
			break;
		case 5: 
			modify();
			break;
		case 6:
			return;
		continue;
		}	
	}
	return 0;
} 

	
