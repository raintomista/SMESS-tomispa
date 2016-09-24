//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//GRAPHICAL MANIPULATION FUNCTIONS
#include <time.h>
#include<string.h>

//clears the scren
void clear(){
	system("clear");
}

//prints the current date and time
void timestamp(){
	time_t timer;
    char buffer[100];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);
    //printf("                                    Friday, 4 December 2015  10:45:01\n\n");
    strftime(buffer, 100, "                                    %A,%e %B %Y  %H:%M:%S\n", tm_info);
    puts(buffer);
}

//prints the spa logo
void spaLogo(int flag){

	if(flag == 0){
		printf("\n");
	}
	printf("  ______                             __                                             _        _____             \n");
	printf(" |  ____|    by TomiSpa, Inc.       / _|                         /\\                | |      / ____|           \n");
	printf(" | |__   ___  ___ __ _ _ __   ___  | |_ _ __ ___  _ __ ___      /  \\   ___ __ _  __| |___  | (___  _ __   __ _ \n");
	printf(" |  __| / __|/ __/ _` | '_ \\ / _ \\ |  _| '__/ _ \\| '_ ` _ \\    / /\\ \\ / __/ _` |/ _` / __|  \\___ \\| '_ \\ / _` |\n");	
	printf(" | |____\\__ \\ (_| (_| | |_) |  __/ | | | | | (_) | | | | | |  / ____ \\ (_| (_| | (_| \\__ \\  ____) | |_) | (_| |\n");
	printf(" |______|___/\\___\\__,_| .__/ \\___| |_| |_|  \\___/|_| |_| |_| /_/    \\_\\___\\__,_|\\__,_|___/ |_____/| .__/ \\__,_|\n");
	printf("                      | |                                                                         | |        \n");
	printf("                      |_|     1 Singko St, Lopez Avenue, Brgy Batong Malake, Los Baños, Laguna    |_|    \n");
}

//prints the main menu
void mainMenu(int flag){
	spaLogo(flag);
	printf("\n\n                            Spa and Massage Employee and Scheduling System v0.6b\n");
	timestamp();
	printf("                                       PRESS 1 | Add Employee\n");
	printf("                                       PRESS 2 | Edit Employee\n");
	printf("                                       PRESS 3 | Delete Employee\n");
	printf("                                       PRESS 4 | View Employee\n");
	printf("                                       PRESS 5 | Add Appointment\n");
	printf("                                       PRESS 6 | Edit Appointment\n");
	printf("                                       PRESS 7 | Delete Appointment\n");
	printf("                                       PRESS 8 | View All Appointments\n");
	printf("                                       PRESS 9 | About Program \n");
	printf("                                       PRESS 10 | Exit \n\n");
	//printf("\n\n                                     Copyright 2015 Rain Tomista. All Rights Reserved.\n");
}


void addEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                  Add an Employee Feature (SMESS v0.6b)\n");
    timestamp();
}

void editEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                  Edit an Employee Feature (SMESS v0.6b)\n");
    timestamp();
}

void viewEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                   View Employee Feature (SMESS v0.6b)\n");
    timestamp();
}
void viewAnEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                               View Specific Employee Feature (SMESS v0.6b)\n");
    timestamp();
}
void viewAllEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                 View All Employee Feature (SMESS v0.6b)\n");
    timestamp();
}
void viewByPositionLogo(int flag){
	spaLogo(flag);
	printf("\n\n                             View Employee by Position Feature (SMESS v0.6b)\n");
    timestamp();
}

//prints the view meny
void viewMenu(int flag){
	viewEmployeeLogo(flag);
	printf("                                       PRESS 1 | Specific Employee\n");
	printf("                                       PRESS 2 | All Employees\n");
	printf("                                       PRESS 3 | By Position\n");
	printf("                                       PRESS 4 | Return to Main Menu\n");
}

void deleteEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                  Delete Employee Feature (SMESS v0.6b)\n");
    timestamp();
}

//prints the delete menu
void deleteMenu(int flag){
	deleteEmployeeLogo(flag);
	printf("                                       PRESS 1 | Delete an Employee\n");
	printf("                                       PRESS 2 | Delete All\n");
	printf("                                       PRESS 3 | Return to Main Menu\n");
}

void deleteAnEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                 Delete An Employee Feature (SMESS v0.6b)\n");
    timestamp();
}
void deleteAllEmployeeLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                 Delete All Employee Feature (SMESS v0.6b)\n");
    timestamp();
}

void addAppointmentLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                 Add an Appointment Feature (SMESS v0.6b)\n");
    timestamp();
}

void editAppointmentLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                  Edit Appointment Feature (SMESS v0.6b)\n");
    timestamp();
}

void viewAllAppointmentLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                View All Appointments Feature (SMESS v0.6b)\n");
    timestamp();
}

void deleteAppointmentLogo(int flag){
	spaLogo(flag);
	printf("\n\n                                 Delete Appointment Feature (SMESS v0.6b)\n");
    timestamp();
}
void enterToContinue();
void aboutProgram(int flag){
	clear();
	spaLogo(flag);
	printf("\n\n                                        About Program (SMESS v0.6b)\n");
	timestamp();
	printf("                         ____  __  __ _____ ____ ____           ___   __   _     \n");
	printf("                        / ___||  \\/  | ____/ ___/ ___|  __   __/ _ \\ / /_ | |__  \n");
	printf("                        \\___ \\| |\\/| |  _| \\___ \\___ \\  \\ \\ / / | | | '_ \\| '_ \\ \n");
	printf("                         ___) | |  | | |___ ___) |__) |  \\ V /| |_| | (_) | |_) |\n");
	printf("                        |____/|_|  |_|_____|____/____/    \\_(_)\\___(_)___/|_.__/ \n");
	printf("\n                            Spa And Massage Employee and Scheduling System\n");
	printf("                             Version 0.6 Beta. Developed by Rain Tomista\n");
	printf("                               Twitter: @raintomista | FB: /raintomista\n");
	enterToContinue();
	clear();


}

void exitMsg(){
	printf(" Saving current data...\n");
	printf(" Thank you for using SMESS v0.6b! :D\n");
	printf(" All ASCII Arts were generated by patorjk.com and bigtext.org\n");
	printf(" ___         ___                           ___        \n");
	printf("  |   |   | |   | |\\  | |  /         \\ /  |   | |   | \n");
	printf("  +   |-+-| |-+-| | + | |-+           +   |   | |   | \n");
	printf("  |   |   | |   | |  \\| |  \\          |   |   | |   | \n");
	printf("                                           ---   ---  \n\n\n\n\n");




}

void emplTableBorder(){
	printf("        ╠═══════╬════════════════════════════════╬═════╬═══════════════════════════╬════════════╣\n");
}
void emplTableHeader(){ //prints the table header of employee table
	printf("        ╔═══════╦════════════════════════════════╦═════╦═══════════════════════════╦════════════╗\n");
	printf("        ║ %-5s ║ %-30s ║ %-3s ║ %-25s ║ %-10s ║\n", "EMPL#", "EMPLOYEE NAME", "AGE", "POSITION", "DATE HIRED");
	emplTableBorder();
}

void emplTableBottom(){ //prints the end of the employee table
	printf("        ╚═══════╩════════════════════════════════╩═════╩═══════════════════════════╩════════════╝\n");
}

//limits the string to be displayed
void limitString(char (*dest)[], employeeNode * source, int maxsize, int flag){
	int i, length;
	//CONVERTS EMPLOYEE POSITION TO *MAXSIZE* CHARS ONLY IF ITS STRING LENGTH EXCEEDS THE MAX LENGTH OF THE COLUMN
	if(flag == 0){
		length = strlen(source->position); //gets the no. of characters of the employee position inputted by the user
	}
	else if(flag == 1){
		length = strlen(source->name);
	}
	//the snippet below removes extra characters by replacing it with ellipsis if the string exceeds the max length of the column 
	if(length <= maxsize){ //if the length of the string (employee name) is less than or equal to the max size of the column (which is 25 characters)
		if(flag == 0) {
			strcpy(*dest, source->position); //the string will be printed normally
		}
		else if(flag == 1) {
			strcpy(*dest, source->name);
		}
	}
	else{ //however, if the length of the string (employee name) exceeds the max size
		for(i=0;i<length;i++){ //the maxsize-3 characters of the string printed normally
			if(i < maxsize-3 && flag == 0) { //0 is for limiting of empl position
				(*dest)[i] = source->position[i];
			}
			else if(i < maxsize-3 && flag == 1){  //1 is for limiting of empl position
				(*dest)[i] = source->name[i];
			}
		}
		(*dest)[maxsize-3] = '.'; //while the remaining characters will be printed as an ellipsis
		(*dest)[maxsize-2] = '.'; 
		(*dest)[maxsize-1] = '.';
		(*dest)[maxsize] = '\0';

	}
}
void emplData(employeeNode * temp){ //prints the empl data in a complex table
	int i, length;
	char name[100] = {'\0'}, position[100] = {'\0'};

	limitString(&name, temp, 30, 1); //limits name string
	limitString(&position, temp, 25, 0); //limit position stirng

	
	emplTableHeader(); //prints the table header of the employee table
	//Case 1: Empty employee entries
	if(temp->id == 0 && temp->name[0] == 0 && temp->age == 0 && temp->position[0] == 0 && temp->dateHired.month == 0 && temp->dateHired.day == 0 && temp->dateHired.year == 0){
		printf("        ║ E%4s ║ %-30s ║ %-3s ║ %-25s ║ %s/%s/%s ║\n", "xxxx", " ", " ", 	" ", "MM","DD","YYYY"); 
	}
	//Case 2: Employee Entries are empty except for Employee No.
	else if(temp->id != 0 && temp->name[0] == 0 && temp->age == 0 && temp->position[0] == 0 && temp->dateHired.month == 0 && temp->dateHired.day == 0 && temp->dateHired.year == 0){
		printf("        ║ E%04d ║ %-30s ║ %-3s ║ %-25s ║ %s/%s/%s ║\n", temp->id, " ", " ", 	" ", "MM","DD","YYYY");
	}
	//Case 3: Employee Entries are empty except for Employee No & Name
	else if(temp->id != 0 && temp->name[0] != 0 && temp->age == 0 && temp->position[0] == 0 && temp->dateHired.month == 0 && temp->dateHired.day == 0 && temp->dateHired.year == 0){
		printf("        ║ E%04d ║ %-30s ║ %-3s ║ %-25s ║ %s/%s/%s ║\n", temp->id, name, " ", 	" ", "MM","DD","YYYY");
	}
	//Case 4: Employee Entries are empty except for Employee No, Name and Age
	else if(temp->id != 0 && temp->name[0] != 0 && temp->age != 0 && temp->position[0] == 0 && temp->dateHired.month == 0 && temp->dateHired.day == 0 && temp->dateHired.year == 0){
		printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %s/%s/%s ║\n", temp->id, name, temp->age, 	" ", "MM","DD","YYYY");
	}
	//Case 5: Employee Entries are filled out excecpt for date of employement
	else if(temp->id != 0 && temp->name[0] != 0 && temp->age != 0 && temp->position[0] != 0 && temp->dateHired.month == 0 && temp->dateHired.day == 0 && temp->dateHired.year == 0){
		printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %s/%s/%s ║\n", temp->id, name, temp->age, 	position, "MM","DD","YYYY");
	}
	//Case 6: All entries are filled out
	else{
		printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %02d/%02d/%04d ║\n", temp->id, name, temp->age, 	position, temp->dateHired.month,temp->dateHired.day,temp->dateHired.year);
	}
	emplTableBottom(); //prints the end of the employee table
}

void emplDataSimple(employeeNode * head){ //prints all employee in a simple table
	employeeNode * temp = head;
	char name[30] = {'\0'}, position[25] = {'\0'};
	int cnt = 0;
	emplTableHeader();
	while(temp != NULL){
		limitString(&name, temp, 30, 1); //limits name stirng
		limitString(&position, temp, 25, 0); //limits position stirng
		printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %02d/%02d/%04d ║\n", temp->id, name, temp->age, 	position, temp->dateHired.month,temp->dateHired.day,temp->dateHired.year);
		cnt ++;
		temp = temp->next;
	}
	emplTableBottom();
}

void availablePosition(){
	printf("                    The available positions are the follwing: \n"); 
	printf("                   ╔══════╦═══════════════════════════╦══════╦═══════════════════════════╗	\n");
	printf("                   ║ %-4s ║ %-25s ║ %-4s ║ %-25s ║\n", "CODE", "​POSITION NAME            ","CODE", "POSITION NAME");
	printf("                   ╠══════╬═══════════════════════════╬══════╬═══════════════════════════╣\n");
	printf("                   ║ %-4s ║ %-25s ║ %-4s ║ %-25s ║\n", "0001", "​Aesthetician             ","0005", "Salon Services Attendant");
	printf("                   ╠══════╬═══════════════════════════╬══════╬═══════════════════════════╣\n");
	printf("                   ║ %-4s ║ %-25s ║ %-4s ║ %-25s ║\n", "0002", "​Hair Stylist             ","0006", "Spa Attendant");
	printf("                   ╠══════╬═══════════════════════════╬══════╬═══════════════════════════╣\n");
	printf("                   ║ %-4s ║ %-25s ║ %-4s ║ %-25s ║\n", "0003", "​Massage Therapist        ","0007", "Spa Management");
	printf("                   ╠══════╬═══════════════════════════╬══════╬═══════════════════════════╣\n");
	printf("                   ║ %-4s ║ %-25s ║ %-4s ║ %-25s ║\n", "0004", "​Nail Technician          ","0008", "Spa Receptionist");
	printf("                   ╚══════╩═══════════════════════════╩══════╩═══════════════════════════╝\n");
}

erefresh(employeeNode * newNode, int flag){ //refresh for invalid employee input
	if(flag == 0){ 
		addEmployeeLogo(1);
		printf("         Fill out the following: \n"); 
	}
	else if(flag == 1){ 
		editEmployeeLogo(1);
		printf("         Currently editing: Employee No. E%04d's data\n", newNode->id);
	}
}

arefresh(appointmentNode * newNode, int flag){ //refresh for invalid appointment input
	if(flag == 0){ 
		addAppointmentLogo(1);	
		printf("                  Fill out the following: \n");	
	}
	else if(flag == 1){ 
		editAppointmentLogo(1);
		printf("                  Currently editing: Appointment No. A%04d's data\n", newNode->id);
	}
}


void apptTableBorder(){
	printf("                 ╠═══════╬════════════╬═══════╬════════════════════════════════╬═══════╣\n");
}
void apptTableHeader(){
	printf("                 ╔═══════╦════════════╦═══════╦════════════════════════════════╦═══════╗\n");
	printf("                 ║ %-5s ║ %-10s ║ %5s ║ %-30s ║ %-5s ║\n", "APPT#", "RSVN DATE", "TI:ME", "NAME OF ASSIGNED EMPLOYEE", "EMPL#");
	apptTableBorder();
}

void apptTableBottom(){
	printf("                 ╚═══════╩════════════╩═══════╩════════════════════════════════╩═══════╝\n");
}

//finds the name of the assigned employee
void findEmplNo(appointmentNode ** temp, employeeNode ** findID){
	
	while((*findID)->next != NULL){
		if((*temp)->id != 0 && (*temp)->id == (*findID)->id){
			strcpy((*temp)->name, (*findID)->name);
			break;
		}
		*findID = (*findID)->next;
	}
}

//prints the appointment data in a complex table
void apptData(appointmentNode * temp, employeeNode * head){
	char name[30] = {'\0'}, position[25] = {'\0'};
	char emptyname[30], emptyposition[25];
	int i, length;
	employeeNode * findID = head;
	findEmplNo(&temp, &findID);
	limitString(&name, findID,30,1);
	apptTableHeader();
	//CASE 1: IF EVERY ENTRY IS EMPTY
	if(temp->appId == 0 && temp->reservationDate.month == 0 && temp->reservationDate.day == 0 && temp->reservationDate.year == 0 && temp->reservationTime.hours == 0 && temp->reservationTime.minutes == 0 && temp->name[0] == 0 && temp->id == 0){
		printf("                 ║ A%4s ║ %s/%s/%s ║ %5s ║ %-30s ║ E%4s ║\n", "xxxx", "MM","DD","YYYY", "xx:xx", " ", "xxxx");
	}
	//CASE 2: IF APPTNO IS ALREADY FILLED OUT
	else if(temp->appId != 0 && temp->reservationDate.month == 0 && temp->reservationDate.day == 0 && temp->reservationDate.year == 0 && temp->reservationTime.hours == 0 && temp->reservationTime.minutes == 0 && temp->name[0] == 0 && temp->id == 0){
		printf("                 ║ A%04d ║ %s/%s/%s ║ %5s ║ %-30s ║ E%4s ║\n", temp->appId, "MM","DD","YYYY", "xx:xx", " ", "xxxx");
	}
	//CASE 3: IF APPTNO && EMPLNO ARE ALREADY FILLED OUT
	else if(temp->appId != 0 && temp->reservationDate.month == 0 && temp->reservationDate.day == 0 && temp->reservationDate.year == 0 && temp->reservationTime.hours == 0 && temp->reservationTime.minutes == 0 && temp->name[0] == 0 && temp->id != 0){
		printf("                 ║ A%04d ║ %s/%s/%s ║ %5s ║ %-30s ║ E%04d ║\n", temp->appId, "MM","DD","YYYY", "xx:xx", " ", temp->id);
	}
	//CASE 4: IF APPT NO, && EMPL NO W/ NAME ARE NOT EMPTY
	else if(temp->appId != 0 && temp->reservationDate.month == 0 && temp->reservationDate.day == 0 && temp->reservationDate.year == 0 && temp->reservationTime.hours == 0 && temp->reservationTime.minutes == 0 && temp->name[0] != 0 && temp->id != 0){
		printf("                 ║ A%04d ║ %s/%s/%s ║ %5s ║ %-30s ║ E%04d ║\n", temp->appId, "MM","DD","YYYY", "xx:xx", name, temp->id);
	}
	//CASE 5: IF ALL ARE FILLED OUT EXCEPT FOR THE TIME
	else if(temp->appId != 0 && temp->reservationDate.month != 0 && temp->reservationDate.day != 0 && temp->reservationDate.year != 0 && temp->reservationTime.hours == 0 && temp->reservationTime.minutes == 0 && temp->name[0] != 0 && temp->id != 0){
		printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %5s ║ %-30s ║ E%04d ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year, "xx:xx", name, temp->id);
	}
	//CASE 6: ALL ARE FILLED OUT
	else if(temp->appId != 0 && temp->reservationDate.month != 0 && temp->reservationDate.day != 0 && temp->reservationDate.year != 0 && temp->reservationTime.hours != 0 && temp->reservationTime.minutes != 0 && temp->name[0] != 0 && temp->id != 0){
		printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%04d ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , name, temp->id);
	}
	//CASE 7: IF MINUTES IS EQUAL TO ZERO
	else if(temp->appId != 0 && temp->reservationDate.month != 0 && temp->reservationDate.day != 0 && temp->reservationDate.year != 0 && temp->reservationTime.hours != 0 && temp->reservationTime.minutes == 0 && temp->name[0] != 0 && temp->id != 0){
		printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%04d ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , name, temp->id);
	}
	//CASE 8: IF MINUTES IS EQUAL TO ZERO AND NO EMPLOYEE ASSIGNED
	else if(temp->appId != 0 && temp->reservationDate.month != 0 && temp->reservationDate.day != 0 && temp->reservationDate.year != 0 && temp->reservationTime.hours != 0 && temp->reservationTime.minutes == 0 && temp->name[0] == 0 && temp->id == 0){
		printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%s ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , "NO ASSIGNED EMPLOYEE", "xxxx");
	}
	//CASE 8: NO EMPLOYEE ASSIGNED
	else if(temp->appId != 0 && temp->reservationDate.month != 0 && temp->reservationDate.day != 0 && temp->reservationDate.year != 0 && temp->reservationTime.hours != 0 && temp->reservationTime.minutes != 0 && temp->name[0] == 0 && temp->id == 0){
		printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%s ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , "NO ASSIGNED EMPLOYEE", "xxxx");
	}

	apptTableBottom();
}

void viewAllAppointment(appointmentNode * apphead, employeeNode * head, int appt_cnt){
	appointmentNode * temp = apphead;
	char name[30] = {'\0'}, position[25] = {'\0'};
	char emptyname[30], emptyposition[25];
	int i, length;
		int cnt = 0;

	clear();
	viewAllAppointmentLogo(0);

	employeeNode * findID;

	//TABLE HEADER
	printf("                 ╔═══════╦════════════╦═══════╦════════════════════════════════╦═══════╗\n");
	printf("                 ║ %-5s ║ %-10s ║ %5s ║ %-30s ║ %-5s ║\n", "APPT#", "RSVN DATE", "TI:ME", "NAME OF ASSIGNED EMPLOYEE", "EMPL#");
	printf("                 ╠═══════╬════════════╬═══════╬════════════════════════════════╬═══════╣\n");

	while(temp != NULL){
		if(temp->id != 0){

			//FINDS THE NAME OF THE EMPLOYEE
			findID = head;
			while(findID->next != NULL){
				if(temp->id != 0 && temp->id == findID->id){
					strcpy(temp->name, findID->name);
					break;
				}
				findID = findID->next;
			}


			//LIMITS THE STRING
			length = strlen(temp->name);
			strcpy(name, emptyname);

			if(length <= 30){
				strcpy(name, temp->name);
			}
			else{
				for(i=0;i<length;i++){
					if(i < 26) name[i] = temp->name[i];
				}
				name[26] = '.';
				name[27] = '.';
				name[28] = '.';
			}
		}
		//CASE 1: HAS ASSIGNED EMPLOYEE
		if(temp->id != 0){
			printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%04d ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , name, temp->id);
		}
		//CASE 2: NO ASSIGNED EMPL
		else{
			printf("                 ║ A%04d ║ %02d/%02d/%04d ║ %02d:%02d ║ %-30s ║ E%4s ║\n", temp->appId, temp->reservationDate.month,temp->reservationDate.day,temp->reservationDate.year,temp->reservationTime.hours, temp->reservationTime.minutes , "NO ASSIGNED EMPLOYEE", "xxxx");
		}
		cnt ++;
		temp = temp->next;

		//kapag hindi pa lima yung row, magprprint ng middle border
		if(cnt < 5 && temp != NULL) printf("                 ╠═══════╬════════════╬═══════╬════════════════════════════════╬═══════╣\n");

		//pero kapag limit na yung row, magprprint ng bottom border
		if(cnt == 5 || temp == NULL){
			printf("                 ╚═══════╩════════════╩═══════╩════════════════════════════════╩═══════╝\n");
			printf("\n                                        Press ENTER to continue.");
			getchar();
			cnt = 0; //tapos babalik sa zero
			clear();
			viewAllAppointmentLogo(0);
			if(temp!=NULL){ //kapag hindi pa naabot yung dulo ng linked list, pagprprint parin yung mga susunod na rows
				printf("                 ╔═══════╦════════════╦═══════╦════════════════════════════════╦═══════╗\n");
				printf("                 ║ %-5s ║ %-10s ║ %5s ║ %-30s ║ %-5s ║\n", "APPT#", "RSVN DATE", "TI:ME", "NAME OF ASSIGNED EMPLOYEE", "EMPL#");
				printf("                 ╠═══════╬════════════╬═══════╬════════════════════════════════╬═══════╣\n");
			}
		}
	}
	clear();
}