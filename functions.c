#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

void medientry(){
	medical tmp, add;

	FILE *fp = fopen("medi.dat", "a+");
	system("clear");
	printf("\nEnter Name of Medicine : ");
	scanf("%s",add.mediname);

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {
		if(strcmp(add.mediname, tmp.mediname) == 0){
			printf("Records already exists\n\n");
			return;
		}
	}
	printf("\nBatch No. :");
	scanf("%s", add.batch);
	printf("\nManufacuturing date :");
	scanf("%s", add.manudate);
	printf("\nExpiry date :");
	scanf("%s", add.expdate);
	printf("\nPurchase date :");
	scanf("%s", add.purdate);
	printf("\nRate :");
	scanf("%lf", &add.rate);
	printf("\nMRP :");
	scanf("%lf", &add.mrp);
	printf("\nQuantity :");
	scanf("%d", &add.qty);

	fprintf(fp, "%s %s %s %s %s %lf %lf %d \n", add.mediname,add.batch,add.manudate,add.expdate,add.purdate,add.rate,add.mrp,add.qty);

	fclose(fp);
	printf("\n\tRecord created successfully!\n\n");
}

void medisearch() {
	FILE *fp = fopen("medi.dat", "r+");
	medical tmp, search;
	int count = 0, choice;
	system("clear");
	printf("\nEnter the name of medicine :");
	scanf("%s", search.mediname);

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

		if(strcmp(search.mediname, tmp.mediname) == 0){
			printf("\nName of Medicine :\t %s ", tmp.mediname);
			printf("\nBatch No. :\t %s ", tmp.batch);
			printf("\nManufacuturing date :\t %s ", tmp.manudate);
			printf("\nExpiry date :\t %s ", tmp.expdate);
			printf("\nPurchase date :\t %s ", tmp.purdate);
			printf("\nRate :\t %lf ", tmp.rate);
			printf("\nMRP :\t %lf ", tmp.mrp);
			printf("\nQuantity :\t %d \n\n\n", tmp.qty);
			count = 1;
		}
	}
	if(count == 0){
		printf("\n\tNo such Records exists\n");
		while(1){
			printf("\tPress 1 to retry\n");
			printf("\tPress 0 to return\n");
			scanf("%d", &choice);
			switch(choice){
				case 0:
					return;
					break;
				case 1:
					medisearch();
					break;
				default:
					printf("WRONG CHOICE\n");
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
			fprintf(new, "%s %s %s %s %s %lf %lf %d ", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,tmp.rate,tmp.mrp,tmp.qty);
		}

		else {
			count++;
			printf("\n\n\n\tDone sucessfully\n\n");
		}
	}
	fclose(old);
	fclose(new);
	system("cp new.dat medi.dat");
	system("rm new.dat");
	if(count == 0){
		printf("\n\tNo such Records exists\n\n\n\n\n");
//		system("clear");
	}
}		




void modify() {
	FILE *fp = fopen("medi.dat", "a+");
	medical tmp, edit;
	int choice, p = 0, a;
	system("clear");
	printf("Enter the name of medicine to be modified\n");
	scanf("%s", edit.mediname);
	
	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {
		
		if(strcmp(edit.mediname, tmp.mediname) == 0){
			printf("\nAVAILABLE INFO\n\n\n");
			printf("\nName of Medicine :\t %s ", tmp.mediname);
			printf("\nBatch No. :\t %s ", tmp.batch);
			printf("\nManufacuturing date :\t %s ", tmp.manudate);
			printf("\nExpiry date :\t %s ", tmp.expdate);
			printf("\nPurchase date :\t %s ", tmp.purdate);
			printf("\nRate :\t %lf ", tmp.rate);
			printf("\nMRP :\t %lf ", tmp.mrp);
			printf("\nQuantity :\t %d \n\n\n", tmp.qty);

			while(1) {
				printf("Want to make changes? \n");
				printf("Press 1 for YES\n");
				printf("Press 0 for NO\n\n\n");
				scanf("%d", &choice);
				switch(choice){
					case 0:
						return;
						break;
					case 1:
						p = 1;
						break;
					default:
						printf("WRONG CHOICE\n");
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
					printf("\n\nWhere do you want to make changes?\n\n");
					printf("1.Name\n");
					printf("2.Batch no.\n");
					printf("3.Manufacturing Date\n");
					printf("4.Expiry Date\n");
					printf("5.Purchase Date\n");
					printf("6.Rate\n");
					printf("7.MRP\n");
					printf("8.Quantity\n");
					printf("0.EXIT\n\n\n");
					scanf("%d", &a);
					switch(a) {
						case 1:
							printf("Name\t:");
							scanf("%s", edit.mediname);
							continue;
						case 2:
							printf("Batch no.\t:");
							scanf("%s", edit.batch);
							continue;
						case 3:
							printf("Manu. Date\t:");
							scanf("%s", edit.manudate);
							continue;
						case 5:
							printf("Purchase Date\t:");
							scanf("%s", edit.purdate);
							continue;
						case 4:
							printf("Expiry Date\t:");
							scanf("%s", edit.expdate);
							continue;
						case 6:
							printf("Rate\t:");
							scanf("%lf", &edit.rate);
							continue;
						case 7:
							printf("MRP\t:");
							scanf("%lf", &edit.mrp);
							continue;

						case 8:
							printf("Quantity\t:");
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
	del(tmp);

	fprintf(fp, "%s %s %s %s %s %lf %lf %d ", edit.mediname,edit.batch,edit.manudate,edit.expdate,edit.purdate,edit.rate,edit.mrp,edit.qty);

	fclose(fp);
		}
	}	
}

void stock() {
	FILE *fp = fopen("medi.dat", "a+");
	medical tmp;
	int count = 0;
	system("clear");
	printf("Name of medicine\tBatch no.\tQUANTITY\n\n");

	while(fscanf(fp, "%s%s%s%s%s%lf%lf%d\n", tmp.mediname,tmp.batch,tmp.manudate,tmp.expdate,tmp.purdate,&tmp.rate,&tmp.mrp,&tmp.qty) != EOF) {

		if(tmp.qty <= 10)
		{
			printf("%s\t\t%s\t\t%d\n", tmp.mediname,tmp.batch,tmp.qty);
			count++;
		}
	}
	printf("\n\n");
	if(count == 0){
		printf("All products have sufficient Quantity\n\n");
	}
}

