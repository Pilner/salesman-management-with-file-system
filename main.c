#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define MAX_LINE 2048
#define NORMAL "\x1B[0m"
#define BOLD "\x1B[1m"
#define WHITE "\033[0;37m"
#define BLUE "\033[0;34m"
#define YELLOW "\033[0;33m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLACK "\033[0;30m"

FILE *fp, *temp;

struct Name {
	char fname[80], lname[80];
};

struct Sales {
	char salesman_num[80];
	struct Name salesman_name;
	double total_sales;
	float commission;
};

int checkExistID(char *salesman_number) {
	char buffer[MAX_LINE];
	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning
	while (!feof(fp)) {
		fscanf(fp, "%s", buffer);
		if (strcmp(buffer, salesman_number) == 0) {
			return 1;
		}
	}
	return 0;
}

void addSale() {
	char choice;
	char q1[13], q2[13], q3[13], q4[13];
	char *percent, salesmanNumber[80];
	int periodExist;

	system("cls");
	charlie:;
	struct Sales sale;
	printf("%sAdd New Salesman%s\n\n", BOLD, NORMAL);
	printf("(0 = Return)\n");
	printf("Salesman Number (e.g. AB-12345-C): ");
	scanf("%s", salesmanNumber);
	strcpy(salesmanNumber, strupr(salesmanNumber));
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	if (strcmp(salesmanNumber, "0") == 0) {	//Choice for the user to exit the delete function
		system("cls");
		return;
	}

	//Error Catching Invalid Salesman Number Inputs
	if (strlen(salesmanNumber) != 10 && strlen(salesmanNumber) != 8) {
		system("cls");
		printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
		goto charlie;
	} else if (strlen(salesmanNumber) == 10) {
		for (int i = 0; i < 10; i++) {
			if (i == 2 || i == 8) {
				if (salesmanNumber[i] != '-') {
					system("cls");
					printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
					goto charlie;
				}
			} else if (salesmanNumber[i] == '-') {
				system("cls");
				printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
				goto charlie;
			}
		}
		// Format: AB-12345-A
		for (int i = 0; i < 10; i++) {
			if (i != 2 || i != 8) {
				if (i < 2 || i == 9) {
					if (isalpha(salesmanNumber[i]) == 0) {
						system("cls");
						printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
						goto charlie;
					}
				}
				if (i >= 3 && i <= 7) {
					if (isdigit(salesmanNumber[i]) == 0) {
						system("cls");
						printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
						goto charlie;
					}
				}
			}
		}
		strcpy(sale.salesman_num, salesmanNumber);		
	}
	if (strlen(salesmanNumber) == 8) {
		for (int i = 0; i < 8; i++) {
			if (i < 2 || i == 7) {
				if (isalpha(salesmanNumber[i]) == 0) {
					system("cls");
					printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
					goto charlie;
				}
			} else if (i >= 2 && i <= 6) {
				if (isdigit(salesmanNumber[i]) == 0) {
					system("cls");
					printf("%sInvalid Salesman Number!%s\n", RED, WHITE);
					goto charlie;
				}
			}
		}
		sale.salesman_num[0] = salesmanNumber[0];
		sale.salesman_num[1] = salesmanNumber[1];
		sale.salesman_num[2] = '-';
		sale.salesman_num[3] = salesmanNumber[2];
		sale.salesman_num[4] = salesmanNumber[3];
		sale.salesman_num[5] = salesmanNumber[4];
		sale.salesman_num[6] = salesmanNumber[5];
		sale.salesman_num[7] = salesmanNumber[6];
		sale.salesman_num[8] = '-';
		sale.salesman_num[9] = salesmanNumber[7];
	}

	fp = fopen("database.txt", "r");
	if (checkExistID(sale.salesman_num) == 1) {
		system("cls");
		printf("%sThere is already a salesperson with that number!%s\n", RED, WHITE);
		goto charlie;
	}
	fclose(fp);

	system("cls");
	printf("%sAdd New Salesman%s\n\n", BOLD, NORMAL);
	printf("Salesman Number: %s\n", sale.salesman_num);
	printf("Salesman First Name: ");
	scanf("%s", sale.salesman_name.fname);
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	printf("Salesman Last Name: ");
	scanf("%s", sale.salesman_name.lname);
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q1_position:
	periodExist = 0;
	printf("\nFirst Quarter Sales: ");
	scanf("%s", q1);
	for (int i = 0; i < strlen(q1); i++) {
		if (q1[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q1[i]) == 0) {
			printf("%sInvalid Input!%s\n", RED, WHITE);
			goto q1_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q2_position:
	periodExist = 0;
	printf("Second Quarter Sales: ");
	scanf("%s", q2);
	for (int i = 0; i < strlen(q2); i++) {
		if (q2[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q2[i]) == 0) {
			printf("%sInvalid Input!%s\n", RED, WHITE);
			goto q2_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q3_position:
	periodExist = 0;
	printf("Third Quarter Sales: ");
	scanf("%s", q3);
	for (int i = 0; i < strlen(q3); i++) {
		if (q3[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q3[i]) == 0) {
			printf("%sInvalid Input!%s\n", RED, WHITE);
			goto q3_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q4_position:
	periodExist = 0;
	printf("Fourth Quarter Sales: ");
	scanf("%s", q4);
	for (int i = 0; i < strlen(q4); i++) {
		if (q4[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q4[i]) == 0) {
			printf("%sInvalid Input!%s\n", RED, WHITE);
			goto q4_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	sale.total_sales = (atof(q1) + atof(q2) + atof(q3) + atof(q4));
	if (sale.total_sales <= 5000) {
		sale.commission = sale.total_sales * 0.10;
		percent = "10%";
	} else if (sale.total_sales <= 10000) {
		sale.commission = sale.total_sales * 0.15;
		percent = "15%";
	} else if (sale.total_sales <= 15000) {
		sale.commission = sale.total_sales * 0.20;
		percent = "20%";
    } else if (sale.total_sales <= 20000) {
		sale.commission = sale.total_sales * 0.25;
		percent = "25%";
	} else if (sale.total_sales <= 25000) {
		sale.commission = sale.total_sales * 0.30;
		percent = "30%";
	} else if (sale.total_sales > 25000) {
		if (sale.total_sales <= 60000) {
			sale.commission = 30000;
			percent = "30000";
		} else {
			sale.commission = sale.total_sales * 0.5;
			percent = "50%";
		}
	}
	fp = fopen("database.txt", "a");
	fprintf(fp, "%s\t%s %s\t%.2lf\t%.2f\t%s\n", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, sale.total_sales, sale.commission, percent);
	fclose(fp);

	system("cls");
	printf("%s%s%s %s has been added!%s%s\n\n", GREEN, BOLD, sale.salesman_name.fname, sale
	.salesman_name.lname, NORMAL, WHITE);
}

void viewSale() {
	char ignore[MAX_LINE], buffer[MAX_LINE];
	int bg_number = 0;

	system("cls");
	charlie:;
	fp = fopen("database.txt", "r");
	if (fp == NULL) {
		fclose(fp);
		return;
	}
	if (fscanf(fp, "%s", buffer) == EOF) {
		printf("%sNo Data!%s\n", RED, WHITE);
		printf("Add a Record First!\n\n");
		printf("%sPress any key to return!%s\n\n", YELLOW, WHITE);
		getch();
		system("cls");
		fclose(fp);
		return;
	}

	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning

	struct Sales sale;
	printf("%sAll Sales:%s\n\n", BOLD, NORMAL);
	printf("%sSalesman Number\t\tSalesman Name\t\tTotal Sales\t\tSale Commission%s\n", GREEN, WHITE);
	while (fscanf(fp, "%s%s%s%lf%f", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, &sale.total_sales, &sale.commission) != EOF) {
		fgets(ignore, 21, fp);	//since "whichever is higher" is unstable for fscanf, we use fgets since also end of line
		if (bg_number % 2 == 0) {
			printf("\n%s\t\t%s %s\t\t%.2lf\t\t%.2f", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, sale.total_sales, sale.commission);
		} else {
			printf(BLACK);
			printf("\n%s\t\t%s %s\t\t%.2lf\t\t%.2f", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, sale.total_sales, sale.commission);
			printf(WHITE);
		}
		bg_number++;
	}
	fclose(fp);

	printf("\n\n%sPress any key to return!%s\n\n", YELLOW, WHITE);
	getch();
	system("cls");
}

void deleteSale() {
	char buffer[MAX_LINE], choice[MAX_LINE];
	char preDeleteSalesmanID[80], deleteSalesmanID[11];

	system("cls");

	fp = fopen("database.txt", "r");
	temp = fopen("TEMP_database.txt", "w");
	charlie:;
	fseek(fp, 0, SEEK_SET); //move cursor to the beginning

	struct Sales sale;
	int line_to_delete = 1;	//to keep track what line is the salesman number to be deleted
	int keep_reading = 1, current_line = 1;
	char percent[80];

	if (fp == NULL || temp == NULL) {	//if no file
		system("cls");
		fclose(fp);
		fclose(temp);
		return;
	}
	if (fscanf(fp, "%s", buffer) == EOF) {
		printf("%sNo Data!%s\n", RED, WHITE);
		printf("Add a Record First!\n\n");
		printf("%sPress any key to return!%s\n\n", YELLOW, WHITE);
		getch();
		system("cls");
		return;
	}

	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning
	//1. Input salesman number to be deleted (SMND)
	printf("%sDelete Record%s\n\n", BOLD, NORMAL);
	printf("(0 = Return)\n");
	printf("Enter Salesman Number: ");
	scanf("%s", preDeleteSalesmanID);
	strcpy(preDeleteSalesmanID, strupr(preDeleteSalesmanID)); // Capitalize the string
	if (strcmp(preDeleteSalesmanID, "0") == 0) {	//Choice for the user to exit the delete function
		fclose(fp);
		fclose(temp);
		remove("TEMP_database.txt");
		system("cls");
		return;
	}

	// Salesman Number Inputs Freedom
	// if Salesman Number is of length 8 (AB12345A)
	if (strlen(preDeleteSalesmanID) == 8) {
		//Adds dashes (AB-12345-A)
		deleteSalesmanID[0] = preDeleteSalesmanID[0];
		deleteSalesmanID[1] = preDeleteSalesmanID[1];
		deleteSalesmanID[2] = '-';
		deleteSalesmanID[3] = preDeleteSalesmanID[2];
		deleteSalesmanID[4] = preDeleteSalesmanID[3];
		deleteSalesmanID[5] = preDeleteSalesmanID[4];
		deleteSalesmanID[6] = preDeleteSalesmanID[5];
		deleteSalesmanID[7] = preDeleteSalesmanID[6];
		deleteSalesmanID[8] = '-';
		deleteSalesmanID[9] = preDeleteSalesmanID[7];
	} else {
		strcpy(deleteSalesmanID, preDeleteSalesmanID);
	}

	//2. Search for salesman in the file using the SMND
	if (checkExistID(deleteSalesmanID) == 0) { // if it doesn't exists, restart the whole function
		system("cls");
		printf("%sNo Salesman Found!%s\n", RED, WHITE);
		goto charlie;
	}
	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning

	// Here we start finding what line is the SMND
	while (!feof(fp)) { // While cursor is not the end of file
		// Insert data to struct (for every line)
		fscanf(fp, "%s\t%s %s\t%lf\t%f\n", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, &sale.total_sales, &sale.commission);

		// if SMND is the same as the line's salesman number
		if (strcmp(sale.salesman_num, deleteSalesmanID) == 0) {
			//break from the while loop
			break;
		}
		// fgets acts as to seek to the end of the line because of the "whichever is higher"
		fgets(percent, MAX_LINE, fp);

		// increments everytime it doesn't find SMND in the corresponding line
		line_to_delete++;
	}
	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning

	system("cls");
	delta:;
	printf("%sDelete Record%s\n\n", BOLD, NORMAL);
	printf("Salesman\n");
	printf("ID: %s\n", deleteSalesmanID);
	printf("Name: %s %s\n", sale.salesman_name.fname, sale.salesman_name.lname);
	printf("Total Sales: %.2lf\n", sale.total_sales);
	printf("Commission: %.2f\n\n", sale.commission);
	printf("Do you want to delete[yes/no]: ");
	scanf("%s", choice);
	strcpy(choice, strupr(choice));

	while (strcmp(choice, "NO") != 0 && strcmp(choice, "YES") != 0) {
		system("cls");
		printf("%sInvalid Input%s\n", RED, WHITE);
		goto delta;
	}

	if (strcmp(choice, "NO") == 0) {
		system("cls");
		goto charlie;
	}

	//3. Copy the contents of the original file to the temp file without the line where SMND;
	do {
		fgets(buffer, MAX_LINE, fp);	//use fgets to copy whole line to buffer

		if (feof(fp)) {
			keep_reading = 0;	//scanning will stop
		} else if (current_line != line_to_delete) {	//else if currentline doesn't include SMND
			fprintf(temp, buffer);	//copy to temp the line inside buffer
		}
		// increments after every line; also to know what line is currently being copied
		current_line++;
	} while (keep_reading == 1);
	fclose(temp);
	fclose(fp);

	system("cls");
	//4. Delete original file
	if (remove("database.txt") != 0) {
		printf("Error in removing file\n");
	};
	
	//5. Rename temp to original file
	if (rename("TEMP_database.txt", "database.txt") != 0) {
		printf("Error in renaming file!\n");
	};

	// Message of deletion
	printf("%s%s%s %s has been deleted%s%s\n", GREEN, BOLD, sale.salesman_name.fname, sale.salesman_name.lname, NORMAL, WHITE);
}

void editSale() {
	char buffer[MAX_LINE], choice[MAX_LINE], preEditSalesmanID[80], editSalesmanID[11];

	system("cls");

	fp = fopen("database.txt", "r");
	temp = fopen("TEMP_database.txt", "w");
	charlie:;
	fseek(fp, 0, SEEK_SET); //move cursor to the beginning

	struct Sales sale;
	char q1[13], q2[13], q3[13], q4[13];
	int line_to_edit = 1; //to keep track what line is the salesman number to be edited
	int keep_reading = 1, current_line = 1, periodExist;
	char *percent, percentBuffer[80];

	if (fp == NULL || temp == NULL) {	//if no file
		system("cls");
		fclose(fp);
		fclose(temp);
		return;
	}

	if (fscanf(fp, "%s", buffer) == EOF) {
		printf("%sNo Data!%s\n", RED, WHITE);
		printf("Add a Record First!\n\n");
		printf("%sPress any key to return!%s\n\n", YELLOW, WHITE);
		getch();
		system("cls");
		return;
	}

	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning

	//1. Input Salesman Number to be Edited (SMNE)
	printf("%sEdit Existing Record%s\n\n", BOLD, NORMAL);
	printf("(0 = Return)\n");
	printf("Enter Salesman Number: ");
	scanf("%s", preEditSalesmanID);
	strcpy(preEditSalesmanID, strupr(preEditSalesmanID)); // Capitalize the string
	if (strcmp(preEditSalesmanID, "0") == 0) {	//Choice for the user to exit the edit function
		fclose(fp);
		fclose(temp);
		remove("TEMP_database.txt");
		system("cls");
		return;
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	// Salesman Number Inputs Freedom
	if (strlen(preEditSalesmanID) == 8) {
		editSalesmanID[0] = preEditSalesmanID[0];
		editSalesmanID[1] = preEditSalesmanID[1];
		editSalesmanID[2] = '-';
		editSalesmanID[3] = preEditSalesmanID[2];
		editSalesmanID[4] = preEditSalesmanID[3];
		editSalesmanID[5] = preEditSalesmanID[4];
		editSalesmanID[6] = preEditSalesmanID[5];
		editSalesmanID[7] = preEditSalesmanID[6];
		editSalesmanID[8] = '-';
		editSalesmanID[9] = preEditSalesmanID[7];
	} else {
		strcpy(editSalesmanID, preEditSalesmanID);
	}

	//2. Search for salesman in the file using the SMNE
	if (checkExistID(editSalesmanID) == 0) { // if it doesn't exists, restart the whole function
		system("cls");
		printf("%sNo Salesman Found!%s\n", RED, WHITE);
		goto charlie;
	}
	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning
	// Here we start finding what line is the SMNE
	while (!feof(fp)) { // While cursor is not the end of file
		// Insert data to struct (for every line)
		fscanf(fp, "%s\t%s %s\t%lf\t%f\n", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, &sale.total_sales, &sale.commission);

		// if SMNE is the same as the line's salesman number
		if (strcmp(sale.salesman_num, editSalesmanID) == 0) {
			//break from the while loop
			break;
		}
		// fgets acts as to seek to the end of the line because of the "whichever is higher"
		fgets(percentBuffer, MAX_LINE, fp);

		// increments everytime it doesn't find SMNE in the corresponding line
		line_to_edit++;
	}
	fseek(fp, 0, SEEK_SET);	//move cursor to the beginning

	system("cls");
	printf("%sEdit Existing Record%s\n\n", BOLD, NORMAL);
	printf("Salesman\n");
	printf("ID: %s\n", editSalesmanID);
	printf("Name: %s %s\n", sale.salesman_name.fname, sale.salesman_name.lname);
	printf("Total Sales: %.2lf\n", sale.total_sales);
	printf("Commission: %.2f\n", sale.commission);
	printf("\n%sInput new contents of saleman:%s\n\n", BOLD, NORMAL);

	q1_position:
	periodExist = 0;
	printf("First Quarter Sales: ");
	scanf("%s", q1);
	for (int i = 0; i < strlen(q1); i++) {
		if (q1[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q1[i]) == 0) {
			printf("Invalid Input!\n");
			goto q1_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q2_position:
	periodExist = 0;
	printf("Second Quarter Sales: ");
	scanf("%s", q2);
	for (int i = 0; i < strlen(q2); i++) {
		if (q2[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q2[i]) == 0) {
			printf("Invalid Input!\n");
			goto q2_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q3_position:
	periodExist = 0;
	printf("Third Quarter Sales: ");
	scanf("%s", q3);
	for (int i = 0; i < strlen(q3); i++) {
		if (q3[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q3[i]) == 0) {
			printf("Invalid Input!\n");
			goto q3_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	q4_position:
	periodExist = 0;
	printf("Fourth Quarter Sales: ");
	scanf("%s", q4);
	for (int i = 0; i < strlen(q4); i++) {
		if (q4[i] == '.' && periodExist == 0) {
			periodExist = 1;
			continue;
		} else if (isdigit(q4[i]) == 0) {
			printf("Invalid Input!\n");
			goto q4_position;
		}
	}
	fflush(stdin); //Any remaining inputs(after whitespaces) will be flushed

	sale.total_sales = (atof(q1) + atof(q2) + atof(q3) + atof(q4));
	if (sale.total_sales <= 5000) {
		sale.commission = sale.total_sales * 0.10;
		percent = "10%";
	} else if (sale.total_sales <= 10000) {
		sale.commission = sale.total_sales * 0.15;
		percent = "15%";
	} else if (sale.total_sales <= 15000) {
		sale.commission = sale.total_sales * 0.20;
		percent = "20%";
    } else if (sale.total_sales <= 20000) {
		sale.commission = sale.total_sales * 0.25;
		percent = "25%";
	} else if (sale.total_sales <= 25000) {
		sale.commission = sale.total_sales * 0.30;
		percent = "30%";
	} else if (sale.total_sales > 25000) {
		if (sale.total_sales <= 60000) {
			sale.commission = 30000;
			percent = "30000";
		} else {
			sale.commission = sale.total_sales * 0.5;
			percent = "50%";
		}
	}

	//3. Copy the contents of the original file to the temp file without the line where SMNE;
	do {
		fgets(buffer, MAX_LINE, fp);	//use fgets to copy whole line to buffer

		if (feof(fp)) {
			keep_reading = 0;	//scanning will stop
		} else if (current_line != line_to_edit) {	//else if currentline doesn't include SMNE
			fprintf(temp, buffer);	//copy to temp the line inside buffer
		} else {
			//4. If the current line is the SMNE's line, then fprintf the new data
			fprintf(temp, "%s\t%s %s\t%.2lf\t%.2f\t%s\n", sale.salesman_num, sale.salesman_name.fname, sale.salesman_name.lname, sale.total_sales, sale.commission, percent);
			printf("4\n");
		}
		// increments after every line; also to know what line is currently being copied
		current_line++;
	} while (keep_reading == 1);
	fclose(temp);
	fclose(fp);

	system("cls");
	//5. Delete original file
	if (remove("database.txt") != 0) {
		printf("Error in removing file\n");
	};

	//6. Rename temp to original file
	if (rename("TEMP_database.txt", "database.txt") != 0) {
		printf("Error in renaming file!\n");
	};

	// Message of Edit
	printf("%s%s%s %s has been edited!%s%s\n", GREEN, BOLD, sale.salesman_name.fname, sale.salesman_name.lname, NORMAL, WHITE);
}

int main() {
	char choice;
	system("cls");
	printf("%sSalesman Program Management%s\n\n\n", BLUE, WHITE);
	printf("%sPress any key to proceed!%s\n\n", YELLOW, WHITE);
	getch();
	system("cls");
	alpha:;

	// Check first if we have data
	fp = fopen("database.txt", "r");
	if (fp == NULL) {	// if none, give user the choice to implicitly create the file or to locate the file first
		char choice2;

		printf("%sNo Data Found!%s\n", RED, WHITE);
		printf("Want to create the file?\n");
		printf("1. Yes\n");
		printf("2. No\n\n");
		printf("Enter Choice: ");
		scanf(" %c", &choice2);
		while (choice2-48 != 1 && choice2-48 != 2) {
			printf("Invalid Input\n");
			printf("Enter Choice: ");
			scanf(" %c", &choice2);
		}

		if (choice2-48 == 1) {
			fclose(fp);
			fp = fopen("database.txt", "w");
			system("cls");
		} else {
			printf("%sLocate the file or create the file before proceeding the program!%s\n", BOLD, NORMAL);
			getche();
			return 0;
		}
	}
	fclose(fp);

    //MENU
	printf("%sMain Menu:%s\n\n", BOLD, NORMAL);
    printf("[%sA%s]-Add New Salesman\n", YELLOW, WHITE);
	printf("[%sE%s]-Edit Existing Record\n", YELLOW, WHITE);
	printf("[%sD%s]-Delete a Record\n", YELLOW, WHITE);
	printf("[%sV%s]-View All Records\n", YELLOW, WHITE);
	printf("[%sX%s]-Exit the Program\n", YELLOW, WHITE);
    printf("\nPlease select: ");
    scanf(" %c", &choice);
	choice = toupper(choice);
	while (choice != 'A' && choice != 'E' && choice != 'D' && choice != 'V' && choice != 'A' && choice != 'X') {
		printf("Invalid Input\n");
		printf("Enter Choice: ");
		scanf(" %c", &choice);
		choice = toupper(choice);
	}
	switch (choice) {
		case 'A':
			addSale();
			goto alpha;
			break;
		case 'E':
			editSale();
			goto alpha;
			break;
		case 'D':
			deleteSale();
			goto alpha;
			break;
		case 'V':
			viewSale();
			goto alpha;
			break;
		case 'X':
			printf("Thank you and have a nice day!\n");
			break;
	}
	return 0;
}