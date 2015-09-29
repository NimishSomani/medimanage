#include <stdio.h>
#include <string.h>
#include "main.h"
void mainmenu() {
	printf("Make a choice\n");
	printf("1. Enter new stock\n");
	printf("2. Search for the stock of a particular medicine\n");
	printf("3. Show remainder for shortage\n");
	printf("4. Prepare a bill\n");
}
int main() {
	int choice;
	while(1) {
		mainmenu();
		scanf("%d", &choice);
		switch(choice) {
		case 1: 
			break;
		case 2: 
			break;
		case 3: 
			break;
		case 4: 
			break;
		}	
	}
	return 0;
} 

	
