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
#include <stdlib.h>
#include "main.h"

void medientry(){
	medical tmp, add;
	FILE *fp = fopen("medi.dat", "a+");
	system("clear");
	move(5, 5);
	printf("Enter Name of Medicine : ");
	move(30, 5);
	scanf("%s",add.mediname);

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {
		if(strcmp(add.mediname, tmp.mediname) == 0){
			move(10, 10);
			printf("Records already exists");
			move(10, 11);
			system("sleep 2");
			system("clear");
			return;
		}
	}
	move(5, 6);
	printf("Batch No. :");
	move(5, 7);
	printf("Manufacuturing date :");
	move(5, 8);
	printf("Expiry date :");
	move(5, 9);
	printf("Purchase date :");
	move(5, 10);
	printf("Rate :");
	move(5, 11);
	printf("MRP :");
	move(5, 12);
	printf("Quantity :");
	move(30, 6);
	scanf("%s", add.batch);
	move(30, 7);
	scanf("%s", add.manudate);
	move(30, 8);
	scanf("%s", add.expdate);
	move(30, 9);
	scanf("%s", add.purdate);
	move(30, 10);
	scanf("%lf", &add.rate);
	move(30, 11);
	scanf("%lf", &add.mrp);
	move(30, 12);
	scanf("%d", &add.qty);

	fprintf(fp, "%s %s %s %s %s %lf %lf %d \n", add.mediname,add.batch,add.manudate,add.expdate,add.purdate,add.rate,add.mrp,add.qty);

	fclose(fp);
	move(10, 15);
	printf("Record created successfully!");
	move(10, 16);
	system("sleep 2");
	system("clear");
}

void medisearch() {
	FILE *fp = fopen("medi.dat", "r+");
	medical tmp, search;
	int count = 0, choice, i;
	system("clear");
	move(5, 5);
	printf("Enter the name of medicine :");
	move(40, 5);
	scanf("%s", search.mediname);

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

		if(strcmp(search.mediname, tmp.mediname) == 0){
			move(20, 10);
			printf("DETAILS");
			move(5, 13);
			printf("Name of Medicine : %s ", tmp.mediname);
			move(5, 14);
			printf("Batch No. : %s ", tmp.batch);
			move(5, 15);
			printf("Manufacuturing date : %s ", tmp.manudate);
			move(5, 16);
			printf("Expiry date : %s ", tmp.expdate);
			move(5, 17);
			printf("Purchase date : %s ", tmp.purdate);
			move(5, 18);
			printf("Rate : %lf ", tmp.rate);
			move(5, 19);
			printf("MRP : %lf ", tmp.mrp);
			move(5, 20);
			printf("Quantity : %d ", tmp.qty);
			count = 1;
			move(1, 24);
			printf("Press any number to return");
			move(30, 24);
			scanf("%d", &i);
			switch(i){
				default:
					system("clear");
					break;
			}
		}
	}
	if(count == 0){
		move(5, 10);
		printf("No such Records exists");
		while(1){
			move(10, 15);
			printf("Press 1 to retry");
			move(10, 16);
			printf("Press 0 to return");
			move(10, 17);
			scanf("%d", &choice);
			switch(choice){
				default:
					system("clear");
					return;
					break;
				case 1:
					medisearch();
					break;
			}
		}
	}
	fclose(fp);
}

void del(medical rm) {
	medical tmp;
	int count = 0, choice;
	FILE *old, *new;
	old = fopen("medi.dat", "r");
	new = fopen("new.dat", "w");

	while(fscanf(old, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

		if(strcmp(rm.mediname, tmp.mediname) != 0){
			fprintf(new, "%s %s %s %s %s %lf %lf %d \n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,tmp.rate,tmp.mrp,tmp.qty);
		}

		else {
			count++;
		}
	}
	fclose(old);
	fclose(new);
	system("cp new.dat medi.dat");
	system("rm new.dat");
	if(count == 0){
		move(5, 10);
		printf("No such Records exists");
		move(5, 11);
	}
}		

void modify() {
	FILE *fp = fopen("medi.dat", "a+");
	medical tmp, edit;
	int choice, p = 0, a, count = 0;
	system("clear");
	move(5, 5);
	printf("Enter the name of medicine to be modified");
	move(5, 6);
	scanf("%s", edit.mediname);
	
	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {
		
		if(strcmp(edit.mediname, tmp.mediname) == 0){
			count = 1;
			move(15, 10);
			printf("AVAILABLE INFO");
			move(30, 12);
			printf("Old Data");
			move(10, 14);
			printf("1. Name of Medicine ");
			move(30, 14);
			printf(": %s ", tmp.mediname);
			move(10, 15);
			printf("2. Batch No. ");
			move(30, 15);
			printf(": %s ", tmp.batch);
			move(10, 16);
			printf("3. Manufacuturing date ");
			move(30, 16);
			printf(": %s ", tmp.manudate);
			move(10, 17);
			printf("4. Expiry date ");
			move(30, 17);
			printf(": %s ", tmp.expdate);
			move(10, 18);
			printf("5. Purchase date ");
			move(30, 18);
			printf(": %s ", tmp.purdate);
			move(10, 19);
			printf("6. Rate ");
			move(30, 19);
			printf(": %lf ", tmp.rate);
			move(10, 20);
			printf("7. MRP ");
			move(30, 20);
			printf(": %lf ", tmp.mrp);
			move(10, 21);
			printf("8. Quantity ");
			move(30, 21);
			printf(": %d ", tmp.qty);

			while(1) {
				move(10, 24);
				printf("Want to make changes? ");
				move(10, 25);
				printf("Press 1 for YES");
				move(10, 26);
				printf("Press 0 for NO");
				move(10, 27);
				scanf("%d", &choice);
				switch(choice){
					case 0:
						system("clear");
						return;
						break;
					case 1:
						p = 1;
						move(45, 12);
						printf("New Info");
						break;
					default:
						move(10, 29);
						printf("WRONG CHOICE");
						continue;
				}
				break;
			}
			if(p == 1) {
				strcpy(edit.mediname, tmp.mediname);
				strcpy(edit.batch,tmp.batch);
				strcpy(edit.manudate,tmp.manudate);
				strcpy(edit.expdate,tmp.expdate);
				strcpy(edit.purdate,tmp.purdate);
				edit.rate = tmp.rate;
				edit.mrp = tmp.mrp;
				edit.qty = tmp.qty;
				while(1) {
					move(10, 29);
					printf("Press the number where you want to make changes?");
					move(10, 22);
					printf("0. EXIT");
					move(10, 30);
					scanf("%d", &a);
					switch(a) {
						case 1:
//							"Name"
							move(45, 14);
							scanf("%s", edit.mediname);
							continue;
						case 2:
//							"Batch no.:"
							move(45, 15);
							scanf("%s", edit.batch);
							continue;
						case 3:
//							"Manu. Date:"
							move(45, 16);
							scanf("%s", edit.manudate);
							continue;
						case 5:
//							"Purchase Date:"
							move(45, 17);
							scanf("%s", edit.purdate);
							continue;
						case 4:
//							"Expiry Date:"
							move(45, 18);
							scanf("%s", edit.expdate);
							continue;
						case 6:
//							"Rate:"
							move(45, 19);
							scanf("%lf", &edit.rate);
							continue;
						case 7:
//							"MRP:"
							move(45, 20);
							scanf("%lf", &edit.mrp);
							continue;

						case 8:
//							"Quantity:"
							move(45, 21);
							scanf("%d", &edit.qty);
							continue;
						case 0:
							break;
						default:
							break;
					}
					break;
				}
			}
		system("clear");
		move(30, 20);
		printf("Changes Saved");
		del(tmp);
		move(30, 21);
		system("sleep 2");
		system("clear");

		fprintf(fp, "%s %s %s %s %s %lf %lf %d \n", edit.mediname,edit.batch,edit.manudate,edit.expdate,edit.purdate,edit.rate,edit.mrp,edit.qty);

		fclose(fp);
		}
	}
	if(count == 0){
		system("clear");
		move(30, 20);
		printf("No such records exist!!");
		move(30, 21);
		system("sleep 2");
		move(30, 21);
		system("clear");
	}
}

void stock() {
	FILE *fp = fopen("medi.dat", "a+");
	medical tmp;
	int count = 0, x, y;
	system("clear");
	move(5, 5);
	printf("What is the minimum expected number of medicine");
	move(5, 6);
	scanf("%d", &x);
	move(5, 12);
	printf("Name of medicine");
	move(30, 12);
	printf("Batch no.");
	move(45, 12);
	printf("Qty");
	move(52, 12);
	printf("Expiry Date");

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

		if(tmp.qty <= x)
		{
			move(5, 14 + count);
			printf("%s", tmp.mediname);
			move(30, 14 + count);
			printf("%s", tmp.batch);
			move(45, 14 + count);
			printf("%d", tmp.qty);
			move(52, 14 + count);
			printf("%s", tmp.expdate);
			count++;
		}
	}
	if(count == 0){
		move(0, 0);
		system("clear");
		move(40, 20);
		printf("All products have sufficient Quantity\n\n");
		move(40, 21);
		system("sleep 2");
		system("clear");
	}
	else {
		loop:		
		move(5, 20 + count);
		printf("Press 1 to return");
		move(5, 21 + count);
		scanf("%d", &y);
		if(y) {
			system("clear");
			return;
		}
		else {
			goto loop;
		}
	}			
}


