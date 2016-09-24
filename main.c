//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//SMESS v0.6b for Escape from Acads Spa
#include <stdio.h>
#include<stdlib.h>
#include "struct.h" //contains the structure of nodes in the linked list
#include "core.h" //contains all the necessary function of the program


int main(){
	//Variable Initialization
	FILE * fp;
	int choice = 0, empl_cnt = 0, appt_cnt = 0;
	int flag = 0; // formatting fix: flag = 1 removes \n from the top and displays notification message
	employeeNode * empl_head = NULL; appointmentNode * appt_head = NULL;

	//Load program files
	loadEmployeeFile(&fp, &empl_head, &empl_cnt, "files/employees.txt");
	loadAppointmentFile(&fp, &appt_head, &appt_cnt, "files/appointments.txt");
	printf("%d\n", appt_cnt);
	printf("%d\n", empl_cnt);
	clear(); //clears the screen
	while(choice != 10){ //loops until the user enter the code for exit
		mainMenu(flag); //prints the main menu
		getChoice(&choice); //gets the user input
		if(choice > 10){ //checks if the choice exists
			clear(); //clears the screen
			printf(" Choice is out of range. Try again.\n");
			flag = 1; //removes the \n from the top to display the notification properly
		}
		switch(choice){
			case 1: //ADD AN EMPLOYEE
				addEmployee(&empl_head); //calls the function that adds employee data to the employee directory (linked list)
				empl_cnt++; //increases the employee number by 1
				flag = 1; //removes the \n from the top to display the notificiation properly
				saveEmployeeData(&empl_head, &empl_cnt); //saves the data from employee linked list to employees.txt
				saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				break;
			case 2: //EDIT AN EMPLOYEE
				if(empl_cnt != 0){ //proceeds with the edit operation if the employee directory is not empty
					editEmployee(&empl_head); //calls the function that edits the employee data
					saveEmployeeData(&empl_head, &empl_cnt); //saves the data from employee linked list to employees.txt
					saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				}
				else{ //if the employee directory is empty,
					clear(); //it will display a notification.
					printf(" Cannot edit an employee. Employee directory is empty.\n");
				}
				flag = 1; //this flag allows the notification to be displayed properly
				break;
			case 3: //DELETE EMPLOYEE MENU
				deleteEmployee(&empl_head, &empl_cnt, &flag, &appt_head, &appt_cnt); //calls the function that will display the "Delete An Employee" menu
				break;
			case 4: //VIEW EMPLOYEE MENU
				viewEmployee(empl_head, empl_cnt); //calls the function that will display the "View Employee" Menu
				flag = 0; //this flag adds a new line character (\n) at the top of the screen
				break;
			case 5: //ADD AN APPOINTMENT
				if(empl_head != NULL){
					addAppointment(&appt_head, empl_head); appt_cnt++; //calls the function that adds appointment data to the appointment directory (linked list)
					saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				}
				else{
					clear();
					printf(" Cannot add an appointment. Employee directory is empty.\n");
				}
				flag = 1; //this flag allows the notification to be displayed properly
				break;
			case 6: //EDIT AN APPOINTMENT
				if(appt_cnt != 0 && empl_head != NULL){ //proceeds with the edit operation if the appointment/employee directory is not empty
					editAppointment(&appt_head, empl_head); //calls the function that edits the appointment data
					saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				}
				else if(appt_cnt == 0 && empl_head != NULL){
					clear(); //clears the screen
					printf(" Cannot edit an appointment. Appointment directory is empty.\n"); //notification
				}
				else if(empl_head == NULL && appt_cnt != 0){ //if the employee directory is empty
					clear(); //clears the screen
					printf(" Cannot edit an appointment. Employee directory is empty.\n"); //notification
				}
				else if(empl_head == NULL && appt_cnt == 0){
					clear(); //clears the screen
					printf(" Cannot edit an appointment.  Appointment and Employee Directories are empty.\n"); //notification
				}
				flag = 1; //this flag allows the notification to be displayed properly
				break;
			case 7: //DELETE AN APPOINTMENT
				if(appt_cnt != 0 && empl_head != NULL){ //proceeds with the delete operation if the appointment directory is not empty
					deleteAppointment(&appt_head, empl_head, &appt_cnt); //calls the function that deletes the appointment data
					saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				}
				else if(appt_cnt == 0 && empl_head != NULL){
					clear(); //clears the screen
					printf(" Cannot delete an appointment. Appointment directory is empty.\n"); //notification
				}
				else if(empl_head == NULL && appt_cnt != 0){ //if the employee directory is empty
					clear(); //clears the screen
					printf(" Cannot delete an appointment. Employee directory is empty.\n"); //notification
				}
				else if(empl_head == NULL && appt_cnt == 0){
					clear(); //clears the screen
					printf(" Cannot delete an appointment.  Appointment and Employee Directories are empty.\n"); //notification
				}
				flag = 1; //this flag allows the notification to be displayed properly
				break;
			case 8: //VIEW ALL APPOINTMENT
				if(appt_cnt != 0){ //proceeds with the view operation if the appointment directory is not empty
					viewAllAppointment(appt_head, empl_head, appt_cnt); //calls the function that displays all the appointments
					flag = 0; //this flag adds a new line character (\n) at the top of the screen
				}
				else{
					clear(); //clears the screen
					printf(" Cannot view all appointments. Appointment directory is empty.\n"); //notification
					flag = 1;
				}
				break;
			case 9: //ABOUT THE PROGRAM
				aboutProgram(0);
				flag = 0;
				break;
			case 10: //EXIT
				saveApptData(&appt_head, &appt_cnt); //saves the data from the appointment linked list to appointments.txt
				saveEmployeeData(&empl_head, &empl_cnt); //saves the data from the employee linked list to employees.txt
				clear();
				exitMsg();
				break;
		}
	}
	return 0;
}