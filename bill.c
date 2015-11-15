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
#include "bill.h"

void bil() {
	FILE *fp = fopen("medi.dat", "a+");
	FILE *bi = fopen("bill.dat", "a+");
	medical tmp, edit;
	bill new[10];
	char b[20], p[20];
	int q;
	double r;
	int i, x, j = 0, count = 0, choice, loop = 0,k;
	double total, gtotal = 0;
	system("clear");
	printf("\n\t\t\t BILL\n\n");
	printf("\tCustomer's Name : ");
	scanf("%s", new[0].cname);
	printf("\n\tDate(dd-mm-yyyy) : ");
	scanf("%d-%d-%d", &new[0].date, &new[0].month, &new[0].year);
	while(count == 0 && j < 10) {
		loop = 0;
		printf("\n\nName of medicine :");
		scanf("%s", b);
		printf("\n\nQuantity :");
		scanf("%d", &i);
		
		while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

			if(strcmp(b, tmp.mediname) == 0) {
				if(tmp.qty < i) {
					printf("%s is not available in required quantity\n\n", tmp.mediname);
				}
				else {
					strcpy(new[j].mediname, tmp.mediname);
					new[j].mrp = tmp.mrp;
					new[j].qty = i;
					tmp.qty = tmp.qty - i;
					x = tmp.mrp;
					total = x * i;
					new[j].total = total;
					j++;
					loop = 1;


					fprintf(bi, "%s %d-%d-%d %s %d %.2lf %.2lf \n", new[0].cname, new[0].date, new[0].month, new[0].year, tmp.mediname, i, total, tmp.rate);

				}
			}
			while(loop) {			
				printf("\n\nYou want to continue??\n");
				printf("1. Yes\n");
				printf("0. No\n");
				scanf("%d", &choice);
				switch(choice){
					case 0:
						count = 1;
						break;
					case 1:
						count = 0;
						break;
					default:
						printf("WRONG CHOICE\n");
						continue;
				}
				break;
			}
			if(loop == 1) {

				strcpy(edit.mediname, tmp.mediname);
				strcpy(edit.batch,tmp.batch);
				strcpy(edit.manudate,tmp.manudate);
				strcpy(edit.expdate,tmp.expdate);
				strcpy(edit.purdate,tmp.purdate);
				edit.rate = tmp.rate;
				edit.mrp = tmp.mrp;
				edit.qty = tmp.qty;

				del(tmp);

				fprintf(fp, "%s %s %s %s %s %lf %lf %d \n", edit.mediname,edit.batch,edit.manudate,edit.expdate,edit.purdate,edit.rate,edit.mrp,edit.qty);

				break;
			}
		}
		rewind(fp);
		if(loop == 0){
			printf("\n\nNo such records exist\nTRY AGAIN\n\n");
		}
	}

	if(j != 0) {
		system("clear");
		printf("\n\n\t\tCustomer Copy\n\n");
		printf("\tDate : %d-%d-%d \n\n", new[0].date, new[0].month, new[0].year);
		printf("\n\tName of customer : %s\n\n", new[0].cname);
		printf("\n");
		printf("Sr. no.\tMedicine name\tQuantity\tMRP\tTotal\n\n");

		for(k = 0; k < j ; k++) {
			printf("%d\t%s\t\t\t%d\t%0.2lf\t%0.2lf\n", k + 1, new[k].mediname, new[k].qty, new[k].mrp, new[k].total);
		}
		for(k = 0; k < j ; k++) {
			gtotal = gtotal + new[k].total;
		}
		printf("\n\n\nGrand Total\t: %lf", gtotal);

		while(loop) {			
			printf("\n\n\n\nPress 1 to exit");
			scanf("%d", &choice);
			switch(choice){
				case 1:
					system("clear");
					break;
				default:
					printf("WRONG CHOICE\n");
					continue;
			}
			break;
		}		
	}

	fclose(fp);
	fclose(bi);
}

int day() {
	FILE *bi = fopen("bill.dat", "a+");
	bill new;
	st tmp[128];
	int d, m, y, i = 0, j, choice;
	double sum = 0, x;
	printf("\nDate(dd-mm-yyyy) : ");
	scanf("%d-%d-%d", &d, &m, &y);

	while(fscanf(bi, "%s%d-%d-%d%s%d%lf%lf\n", new.cname, &new.date, &new.month, &new.year, new.mediname, &new.qty, &new.total, &new.rate) != EOF) {

		if(new.date == d && new.month == m && new.year == y) {
			strcpy(tmp[i].mediname, new.mediname);
			tmp[i].qty = new.qty;
			tmp[i].total = new.total;
			tmp[i].rate = new.rate;
			x = new.total;
			sum = sum + x;
			i++;
		}
	}
	if(i == 0) {
		printf("\n\n\n\nNo Sales \n\n\n");
	}
	else {
		printf("\n\n\nThe total sale on the day is \t: %lf\n\n", sum);
		while(1) {
			printf("Press 1 for details\n");
			printf("Press 0 to return\n\n\n");
			scanf("%d", &choice);
			switch(choice){
				case 0:
					break;
				case 1:
					printf("\n\nMedicine\tQuantity\tMRP\n");
					for(j = 0; j < i; j++){
						printf("\n %s\t \t%d\t%lf", tmp[j].mediname, tmp[j].qty, tmp[j].total);
					}
					printf("\n\n\nTOTAL\t: %lf",sum);	
					printf("\n\n");
					break;
				default:
					printf("WRONG CHOICE\n");
					continue;
			}
			break;
		}
	}
	fclose(bi);
	return sum;
}

int profit() {
	FILE *bi = fopen("bill.dat", "a+");
	bill new;
	st tmp[128];
	int d, m, y, i = 0, j, choice;
	double sum = 0, x, profit = 0;
	printf("\nDate(dd-mm-yyyy) : ");
	scanf("%d-%d-%d", &d, &m, &y);

	while(fscanf(bi, "%s%d-%d-%d%s%d%lf%lf\n", new.cname, &new.date, &new.month, &new.year, new.mediname, &new.qty, &new.total, &new.rate) != EOF) {

		if(new.date == d && new.month == m && new.year == y) {
			strcpy(tmp[i].mediname, new.mediname);
			tmp[i].qty = new.qty;
			tmp[i].total = new.total;
			tmp[i].rate = new.rate;
			sum = sum + new.total;
			x = new.total - (new.rate * new.qty);
			profit = profit + x;
			i++;
		}
	}
	if(i == 0) {
		printf("\n\n\n\nNo Profit \n\n\n");
	}
	else {
		printf("\n\n\nThe total profit of the day is \t: %lf\n\n", profit);
		while(1) {
			printf("Press 1 for details\n");
			printf("Press 0 to return\n\n\n");
			scanf("%d", &choice);
			switch(choice){
				case 0:
					break;
				case 1:
					printf("\n\nMedicine\tQuantity\tRate\tMRP\tPROFIT\n");
					for(j = 0; j < i; j++){
						printf("\n %s\t \t%d\t\t%.2lf\t%.2lf\t%.2lf", tmp[j].mediname, tmp[j].qty, tmp[j].rate, (tmp[j].total/tmp[j].qty), tmp[j].total - (tmp[j].rate * tmp[j].qty));
					}
					printf("\n\n\nTOTAL\t: %lf",profit);	
					printf("\n\n");
					break;
				default:
					printf("WRONG CHOICE\n");
					continue;
			}
			break;
		}
	}
	fclose(bi);
	return profit;
}
		
void sale() {
	int choice;
	system("clear");
	while(1) {
		move(5, 7);
		printf("Press 0 to check Daily Sale\n");
		move(5, 8);
		printf("Press 1 to check Daily Profit\n");
		move(5, 9);
		scanf("%d", &choice);
		switch(choice){
			case 0:
				system("clear");
				day();
				break;
			case 1:
				system("clear");
				profit();
				break;
			default:
				system("clear");
				move(50, 20);
				printf("WRONG CHOICE\n");
				system("sleep 2");				
				system("clear");
				continue;
		}
		break;
	}
	while(1) {			
		printf("\n\n\n\nPress 1 to exit");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				system("clear");
				break;
			default:
				printf("WRONG CHOICE\n");
				continue;
		}
		break;
	}		
}
