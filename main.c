/*****************************************************************************
 * Copyright (C) Nimish B Somani nimishsomani1@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "main.h"
void welcome() {
	move(45, 18);
	printf("******************");
	move(50, 20);
	printf("WELCOME");
	move(45, 22);
	printf("******************");
	move(0, 0);
	system("sleep 2");
	system("clear");
}
void mainmenu() {
	move(30, 10);
	printf("Make a choice");
	move(25, 12);
	printf("1. Enter new stock");
	move(25, 13);
	printf("2. Search for the stock of a particular medicine");
	move(25, 14);
	printf("3. Delete a record");
	move(25, 15);
	printf("4. Shortage stock");
	move(25, 16);
	printf("5. Modify a medicine");
	move(25, 17);
	printf("6. Make a BILL");
	move(25, 18);
	printf("7. Check the sale");
	move(25, 19);
	printf("8. EXIT!!");
	move(25, 20);
}
int main() {
	int choice, i = 0;
	if(i == 0) {
		system("clear");
		i++;
		welcome();
	}
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
			move(5, 5);
			printf("Enter the name of medicine whose record is to be removed\n\n");
			move(5, 6);
			scanf("%s", tmp.mediname);
			del(tmp);
			move(10, 11);
			system("sleep 2");
			system("clear");
			break;
		case 4: 
			stock();
			break;
		case 5: 
			modify();
			break;
		case 6:
			bil();
			break;
		case 7:
			sale();
			break;
		case 8:
			system("clear");
			move(45, 18);
			printf("******************");
			move(50, 20);
			printf("THANK YOU!!");
			move(45, 22);
			printf("******************");
			move(0, 0);
			system("sleep 2");
			system("clear");
			return;
		}	
	}
	return 0;
} 

	
