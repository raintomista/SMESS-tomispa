//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//DELETE EMPLOYEE OPERATION FUNCTIONS


//SAVES THE APPOINTMENT DATA TO THE TEXT FILE
void saveApptData(appointmentNode ** head, int * appointmentcnt); //function prototype


//DELETE OPERATION
void emplDeleteAtHead(employeeNode ** del, employeeNode ** head, appointmentNode ** apphead, int input, int * appointmentcnt){
	appointmentNode * del2;
	del2 = *apphead;
	int cnt = 0;

	//UNASSIGNS EMPLOYEE FROM THE APPOINTMENT
	while(del2 !=NULL){
		if(input == del2->id){
			del2->id = 0;
			strcpy(del2->name, "\0");
		}
		del2 = del2->next;
	}

	//DELETES THE EMPLOYEE FROM THE EMPLOYEE LINKED LIST
	employeeNode * temp;
	//DELETE AT HEAD
	if(*del == *head){
		*head = (*del)->next;
		(*del)->prev = NULL;
		free(*del);
	}
	//DELETE AT TAIl
	else{
		temp = *head;
		while(temp->next != *del){
			temp = temp->next;
		}
		temp->next = (*del)->next;
		(*del)->prev = temp;
		free(*del);
	}
}

//DELETES ALL EMPLOYEE
void deleteAll(employeeNode ** head, appointmentNode ** apphead){
	employeeNode * temp;
	appointmentNode * temp2;

	temp = *head;
	//REPEATED DELETE AT HEAD
	while(temp != NULL){
		employeeNode * p1 = temp;

		*head = (*head)->next;
		temp = temp->next;
		free(p1);

	}
	//UNASSIGNS EMPLOYEE FROM ALL APPOINTMENTS
	*head = NULL;
	if(*apphead != NULL){
		temp2 = *apphead;
		while(temp2 != NULL){
			temp2->id = 0;
			strcpy(temp2->name, "\0");
			temp2 = temp2->next;
		}
	}
}


//DELETES AN EMPLOYEE
void deleteAnEmployee(employeeNode ** head, int * employeecnt, appointmentNode ** apphead, int * appointmentcnt){
	//VARIABLE INIT/DECLARAION
	char input[100], prompt[100];
	employeeNode * del; int promptvalid = 0;
	clear();
	deleteAnEmployeeLogo(0);	//displays proper heading for delete an employee
	validEmployeeID(&del, &input, 1); //checks if employee id is valid

	del = *head;
	while(del!=NULL && atoi(input) != del->id){ //traverse the linked list until the it similar empl no in the linked list
		del = del->next;
	}
	if(del == NULL) {
		clear();
		printf(" Employee No. E%04d not found\n", atoi(input));
	}
	else{ //if the empl no exists
		clear();
		deleteAnEmployeeLogo(0);	
		emplData(del);
		while(promptvalid != 1){
			promptvalid = 0;
			printf("\n Do you really want to delete Employee No. E%04d? (y/n): ",atoi(input)); //asks the user if he/she wants to delete it
			rfgets(prompt, 100);
			if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0) && strlen(prompt) == 1){
				printf(" Do you REALLY want to delete Employee No. E%04d? (y/n): ",atoi(input));
				rfgets(prompt, 100);
				if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0) && strlen(prompt) == 1){
					emplDeleteAtHead(&del, head, apphead, atoi(input), appointmentcnt); //delete employee operation
					clear();
					printf(" Employee No. E%04d has been successful deleted.\n",atoi(input));
					*employeecnt = *employeecnt-1; //decreases the total number of employees
					promptvalid = 1;
				}
				else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0) && strlen(prompt) == 1){
					clear();
					printf(" Employee No. E%04d has not been deleted. Operation cancelled.\n",atoi(input));
					promptvalid = 1;
				}
				else{
					clear();
					printf(" Invalid input. Try again.\n");
					deleteAnEmployeeLogo(1);
					emplData(del); //displays the entries of the node to be deleted
				}
			}
			else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0) && strlen(prompt) == 1){
				clear();
				printf(" Employee No. E%04d has not been deleted. Operation cancelled.\n",atoi(input));
				promptvalid = 1;
			}
			else{
				clear();
				printf(" Invalid input. Try again.\n");
				deleteAnEmployeeLogo(1);
				emplData(del); //displays the entries of the node to be deleted
			}
		}
	}
}


//DELETE ALL EMPLOYEE
void deleteAllEmployees(employeeNode ** head, appointmentNode ** apphead, int * employeecnt){
	// VAR INIT/DECLARATION
	char prompt[100];
	int promptvalid = 0;
	clear();
	deleteAllEmployeeLogo(0);	
	while(promptvalid != 1){
		promptvalid = 0;
		printf(" Do you really want to delete all employees? (y/n): ");
		rfgets(prompt, 100); //asks the user if he/she wants to delete all employees
		if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){
			printf(" Do you REALLY want to delete all employees? (y/n): ");
			rfgets(prompt, 100);
			if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){
				printf("\n Deleting all employees...\n");
				deleteAll(head, apphead); //deletes all employee operation
				clear();
				printf(" All employee have been successfully deleted.\n");
				promptvalid = 1;
				*employeecnt = 0; //sets the employee cnt to zero
			}
			else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0) && strlen(prompt) == 1){
				clear();
				printf(" Delete all employees failed. Operation cancelled.\n");
				promptvalid = 1;
			}
			else{
				clear();
				printf(" Invalid input. Try again.\n");
				deleteAllEmployeeLogo(1);	
			}
		}
		else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0)  && strlen(prompt) == 1){
				clear();
				printf(" Delete all employees failed. Operation cancelled.\n");
				promptvalid = 1;
		}
		else{
			clear();
			printf(" Invalid input. Try again.\n");
			deleteAllEmployeeLogo(1);	
		}
	}
}


//DELETE EMPLOYEE MENU
void deleteEmployee(employeeNode ** head, int * employeecnt, int * flag, appointmentNode ** apphead, int * appointmentcnt){
	int choice = 0, del_flag = 0; //VAR INIT/DECLARATION
	clear();
	while(choice != 3){
		deleteMenu(del_flag);
		getChoice(&choice);
		if(choice > 3){
			clear();
			printf(" Choice is out of range. Try again.\n");
			del_flag = 1;
		}
		switch(choice){
			case 1: //DELETE AN EMPLOYEE
				if(*head != NULL){
					deleteAnEmployee(head, employeecnt, apphead, appointmentcnt); //CALLS THE FUNCTION THAT WILL ASK THE USER IF HE OR SHE WANTS TO DELETE ALL APPT
					saveEmployeeData(head, employeecnt); //SAVES THE EMPL DATA TO TEXT FILE
					saveApptData(apphead, appointmentcnt); //SAVES THE APPT DATA TO TEXT FILE
					del_flag = 1;
				}
				else{
					clear();
					printf(" Cannot delete an employee. Employee Directory is empty.\n");
					del_flag = 1;
				}
				break;
			case 2: //DELETE ALL EMPLOYEE
				if(*head != NULL){
					deleteAllEmployees(head,apphead, employeecnt); //CALLS THE FUNCTION THAT WILL ASK THE USER IF HE OR SHE WANTS TO DELETE ALL APPT
					del_flag = 1;
					saveEmployeeData(head, employeecnt); //SAVES THE EMPL DATA TO TEXT FILE
					saveApptData(apphead, appointmentcnt); //SAVES THE APPT DATA TO TEXT FILE
				}
				else{
					clear();
					printf(" Cannot delete all employees. Employee Directory is empty.\n");
					del_flag = 1;
				}
				break;
			case 3: //EXIT
				clear();
				*flag = 0;
				break;
		}
	}

}