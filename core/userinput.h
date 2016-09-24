//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//SYSTEM-WIDE USER INPUT FUNCTIONS

//GET MENU CHOICE
void getChoice(int * choice){ //gets the choice of the user
	char input[100]; //defines the variable that will hold the choice
	int isValid = 0; //valid choice flag

	while(isValid != 1){ //loops until the choice is valid
		printf(" Enter choice: ");
		rfgets(input, 100); //gets the user input and removes the new line character at the end of the string
		if(isstrdigit(input) == 1){ //checks if the string is a digit
			*choice = atoi(input); //converts the string into an integer
			isValid = 1; //flag which tells the program that the choice is valid
		}
		else{
			printf(" Invalid input. Choice must not contain alphabet characters or must not be empty.\n\n"); //notification
			isValid = 0; //flag which tells the program that the choice is not valid. Asks the user for a choice (again)
		}
			
	}
}

//UNUSED PROMPT FUNCTION
void promptMsg(char * prompt, char action[100]){ //this function makes it easier for the programmer to assign verb to the prompt message
	char input[100]; ///defines the variable that will hold the choice
	int isValid = 0; //valid choice flag

	while(isValid != 1){ //loops until the choice is valid
		printf("\n Would you like to %s this? (y/n): ", action); //ask the user if they want to *insert verb here*
		rfgets(input, 100); //gets the user input and removes the new line character at the end of the string
		if(strlen(input) == 1 && isstralpha(input) == 1){ //checks if the length is of the string is one and it is an alphabet
			isValid = 1; //flag which tells the program that the choice is valid
		}
		else{
			printf(" Invalid input. Try again.\n\n");
			isValid = 0; //flag which tells the program that the choice is not valid. Asks the user for a choice (again)
		}

	}

}


//EMPLOYEE USER INPUT FUNCTIONS START HERE 
//EMPLOYEE ID INPUT CHECKER
void validEmployeeID(employeeNode ** newNode, char (*input)[100], int flag){ //checks if the employee number inputted by the user is valid
	int isValid = 0; //valid choice flag
	while(isValid!=1){ //the program will continuously get input from the user if the input is not valid
		isValid = 0; //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter 4-digit employee number (e.g. E0045): E");
		rfgets(*input, 100); //gets the user input and removes the new line character at the end of the string
		if(isstrdigit(*input) == 1 && strlen(*input) <= 4 && atoi(*input) > 0){
			//if all characters of the string are digits, the length of the code is at most 4 and the value of the code is greater than zero
			isValid = 1; //then it is a valid employee no. Moreover, the loop will stop.
		}
		else{
			clear(); //clears the screen 
			//ADD AN EMPLOYEE
			if(flag == 0){ 	//IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN EMPLOYEE SCREEN 
				printf(" Invalid employee number. Please try again.\n");
				addEmployeeLogo(1); //the parameter is 1 so that the action message will display properly
				printf("         Fill out the following: \n");
				emplData(*newNode); //displays the entries to be filled out
			}
			//EDIT AN EMPLOYEE
			else if(flag == 1){ //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE DELETE AN EMPLOYEE SCREEN 
				printf(" Invalid employee number. Please try again.\n");
				deleteAnEmployeeLogo(1); //the parameter is 1 so that the action message will display properly
			}
			
		}
	}
}

//GETS THE EMPLOYEE ID FROM THE USER
void getEmployeeID(employeeNode ** newNode, employeeNode ** head){
	int isUnique = 0, duplicatecnt = 0; //variable initialization/declaration
	employeeNode * temp; char input[100]; //variable initialization/declaration

	printf("         Fill out the following: \n"); 
	emplData(*newNode); //displays the entries to be filled out
	while(isUnique != 1){ //the program will continuously get input from the user if the valid employee number is not unique
		isUnique = 0; //and the loop wouldn't magically stop even if the input is not unique
		duplicatecnt = 0; //this makes sure that the counter would not overcount 
		if(*head == NULL){ //if the linked list of the employee directory is empty, it will not scan the existing employee number
			validEmployeeID(newNode, &input, 0); //however, it will check first if the employee no. inputted by the user if valid
			(*newNode)->id = atoi(input); //if the employee number is valid, then it will be stored in the new node
			clear(); //clears the screen
			printf(" Employee no. E%04d is valid.\n", atoi(input)); //displays notification
			isUnique = 1; //the loops will stop. 
		}
		else if(*head != NULL){ //however, if the linked list of the employee directory is not empty, it will scan the existing employee number
			validEmployeeID(newNode,&input, 0); //however, it will check if the employee no. inputted by the user if valid
			isUnique = 0; //this makes sure that the counter would not overcount
			temp = *head; //points the temporary pointer to the node being pointed by the head pointer
			while(temp != NULL){ //checks if there is a duplicate employee number
				if(atoi(input) == temp->id){ //if there is a duplicate
					duplicatecnt++; //the duplicate counter will increase
					isUnique = 0; //tells the program that the employee number is not unique
				}
				temp = temp->next;
			}
			if(duplicatecnt == 0){ //if there is no duplicate
				(*newNode)->id = atoi(input); //it will store the employee number to the node
				clear(); //clears the screen
				printf(" Employee no. E%04d is valid.\n", atoi(input)); //notificationn
				isUnique = 1; //tells the program that the employee number is not unique
			}
			else if(duplicatecnt != 0){
				clear();//clears the screen
				printf(" Employee no. E%04d already exists. Try again.\n", atoi(input)); //notification
				addEmployeeLogo(1); //displays the header for add an employee 
				printf("         Fill out the following: \n"); 
				emplData(*newNode); //displays the entries to be filled out
				isUnique = 0; //tells the program that the employee number is not unique
			}
		}
	}
}

//GETS THE EMPLOYEE ID FROM THE USER
void getName(employeeNode ** newNode, int flag){
	int isValid = 0; char input[100]; //variable initialization/declaration
	erefresh(*newNode, flag); //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
	emplData(*newNode); //displays the entries to be filled out
	while(isValid != 1){ //looops until the employee name is valid 
		isValid = 0; //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter employee name: " );
		rfgets(input, 100);  //gets the user input and removes the new line character at the end of the string
		if(isstralpha(input) == 1){ //checks if the string is alphabet
			capitalize(&input); //capitalizes the first letter of every word
			strcpy((*newNode)->name, input); //if the employee name is valid, then it will be stored in the new node
			clear(); //clears the screen
			printf(" Employee Name \"%s\" is valid.\n", input); //notification
			isValid = 1; //tells the program that the employee number is valid
		}
		else{
			clear(); //clears the screen
			printf(" Invalid name. Must not contain number or special characters.\n"); //notification
			erefresh(*newNode, flag); //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
			emplData(*newNode); //displays the entries to be filled out
			isValid = 0; //tells the program that the employee number is not valid
		}
	}
}

//GETS THE EMPLOYEE AGE FROM THE USER
void getAge(employeeNode ** newNode, int flag){
	int isValid = 0; char input[10]; //variable initialization/declaration
	erefresh(*newNode, flag); //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
	emplData(*newNode); //displays the entries to be filled out
	while(isValid != 1){  //looops until the employee name is valid 
		isValid = 0; //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter employee's age: ");
		rfgets(input, 100); //gets the user input and removes the new line character at the end of the string
		if(strlen(input) <=3 && isstrdigit(input) == 1 && atoi(input) >= 18 && atoi(input) <=60){ //checks if the length of the string is at most 3 and the string is a digit. also, if the age is legal (18) and not beyond the retirement age(60)
			(*newNode)->age = atoi(input); //stores the age to the node
			clear(); //clears the screen
			printf(" Employee age \"%d\" is valid.\n", atoi(input)); //notifcation
			isValid = 1; //tells the program that the employee age is valid
		}
		else if(isstrdigit(input) == 1 && atoi(input) < 18){ //if the age is under the legal age
			clear(); //clears the screen
			printf(" Employee is underage. Try again.\n"); //notification
			erefresh(*newNode, flag);  //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
			emplData(*newNode); //displays the entries to be filled out
		}
		else if(isstrdigit(input) == 1 && atoi(input) > 60){ //if the age is beyond the retirement
			clear(); //clears the screen
			printf(" Employee is too old. Try again.\n"); //notification
			erefresh(*newNode, flag);   //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
			emplData(*newNode); //displays the entries to be filled out
		}
		else{
			clear(); //clears the screen
			printf(" Invalid age. Try again.\n");
			erefresh(*newNode, flag); //displays the proper heading for add/edit an employee. if flag == 0 (add), flag == 1 (edit)
			emplData(*newNode); //displays the entries to be filled out
			isValid = 0; //tells the program that the employee age is not valid
		}
	}
}

//GETS THE EMPLOYEE POSITION FROM THE USER
void getPosition(employeeNode ** newNode, int flag){
	int isValid = 0; char input[10]; //variable declaration/initialization

	//ADD AN EMPLOYEE
	if(flag == 0){  //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN EMPLOYEE SCREEN 
		addEmployeeLogo(1);
	}
	//EDIT AN EMPLOYEE
	else if(flag == 1){  //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN EMPLOYEE SCREEN 
		editEmployeeLogo(1);
	}
	availablePosition(); //displays the available position
	while(isValid != 1){ //loops until the employee name is valid 
		isValid = 0;  //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter the code of employee's position: ");
		rfgets(input,100); //gets the user input and removes the new line character at the end of the string
		if(strlen(input) <=4 && isstrdigit(input) == 1 && atoi(input) > 0 && atoi(input) <=	 8){ //checks if the code is valid
			switch(atoi(input)){
				case 1:
					strcpy((*newNode)->position, "Aesthetician");
					break;
				case 2:
					strcpy((*newNode)->position, "Hair Stylist");
					break;
				case 3:
					strcpy((*newNode)->position, "Massage Therapist");
					break;
				case 4:
					strcpy((*newNode)->position, "Nail Technician");
					break;
				case 5:
					strcpy((*newNode)->position, "Salon Services Attendant");
					break;
				case 6:
					strcpy((*newNode)->position, "Spa Attendant");
					break;
				case 7:
					strcpy((*newNode)->position, "Spa Management");
					break;
				case 8:
					strcpy((*newNode)->position, "Spa Receptionist");
					break;
			}
			clear(); //clears the screen
			printf(" Position code \"%04d\" is valid.\n", atoi(input)); //notification
			isValid = 1; //tells the program that the code is valid
		}
		else{
			clear(); //clears the screen
			printf(" Invalid position code. Try again.\n"); //notification
			//ADD AN EMPLOYEE
			if(flag == 0){  //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN EMPLOYEE SCREEN 
				addEmployeeLogo(1);
			}
			//EDIT AN EMPLOYEE
			else if(flag == 1){  //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN EMPLOYEE SCREEN 
				editEmployeeLogo(1);
			}
			availablePosition(); //displays the available position
			isValid = 0; //tells the program that the code is not valid
		}
	}
}

//STORES THE VALID DATE TO THE NODE
void saveValidDate(employeeNode ** newNode, int month, int day, int year){
	(*newNode)->dateHired.month = month; //stores the month to the node
	(*newNode)->dateHired.day = day; //stores the day to the node
	(*newNode)->dateHired.year = year;	//stores the year to the node
}

//GETS THE DATE OF EMPLOYMENT FROM THE USER
void getDateHired(employeeNode ** newNode){
	int month, day, isValid = 0; //variable initialization/declaration
	int birthYear = 2015 - (*newNode)->age; //gets the birthyear
	int legalYear = birthYear + 18; //gets the legalyaer
	char year[10]; //variable initialization/declaration
	char date[100]; //variable initialization/declaration
	addEmployeeLogo(1); //displays the proper heading for the add an employee
	printf("         Fill out the following: \n"); 
	emplData	(*newNode); //displays the entries to be filled out
	while(isValid != 1){ //loops until the input is valid
		printf("\n Enter date of employment (MM/DD/YYYY): "); 
		rfgets(date,100); //gets the user input and removes the new line character at the end of the string
		sscanf(date, "%d/%d/%s", &month, &day, year);	//splits and stores the date into month, day, year as an integer
		//CHECKS IF THE FORMAT OF INPUT IS VALID AND THERE ARE NO ALPHA OR SPECIAL CHARACTERS (except for slash)
		if( (date[2] == '/' && (date[4] == '/' || date[5] == '/') && strlen(year) > 0 && strlen(year) <= 4 && isstrdigit(year) == 1) || 
			(date[1] == '/' && (date[3] == '/' || date[4] == '/') && strlen(year) > 0 && strlen(year) <= 4 && isstrdigit(year) == 1) ){
			if(atoi(year) >= legalYear ){ //checks if the employment date is within/beyond the legalyear
				if(month >= 1 && month <= 12){ //checks if the month is within january and december
					if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
						if(day >= 1 && day <=31){
							saveValidDate(newNode, month, day, atoi(year)); //stores the valid date to the node 
							clear(); //clears the screen
							addEmployeeLogo(0); //displays the proper heading for the add an employee
							printf("         Employee data have been filled out: \n"); 
							emplData(*newNode);  //displays the filled out entries
							printf("\n                                        Press ENTER to continue.");
							getchar();
							isValid = 1;
						}
						else if(day > 31){
							clear();
							//ERROR NOTIFICATIONS
							if(month == 1) printf(" There is no Day %d in January %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 3) printf(" There is no Day %d in March %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 5) printf(" There is no Day %d in May %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 7) printf(" There is no Day %d in July %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 8) printf(" There is no Day %d in August %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 10) printf(" There is no Day %d in October %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 12) printf(" There is no Day %d in December %04d. It must be within 1-31.\n", day, atoi(year));
							addEmployeeLogo(1); //displays the proper heading for the add an employee
							printf("         Fill out the following: \n");  
							emplData(*newNode); //displays the entries to be filled out
						}
					}
					else if(month == 4 || month == 6 || month == 9 || month == 11){
						if(day >= 1 && day <=30){
							saveValidDate(newNode, month, day, atoi(year)); //stores the valid date to the node 
							clear(); //clears the screen
							addEmployeeLogo(0); //displays the proper heading for the add an employee
							printf("         Employee data have been filled out: \n"); 
							emplData(*newNode);  //displays the filled out entries
							printf("\n                                        Press ENTER to continue.");
							getchar();
							isValid = 1;
						}
						else if(day > 30){
							clear();
							//ERROR NOTIFICATIONS
							if(month == 4) printf(" There is no Day %d in April %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 6) printf(" There is no Day %d in June %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 9) printf(" There is no Day %d in September %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 11) printf(" There is no Day %d in November %04d. It must be within 1-30.\n", day, atoi(year));
							addEmployeeLogo(1); //displays the proper heading for the add an employee
							printf("         Fill out the following: \n");  
							emplData(*newNode); //displays the entries to be filled out
						}
					}
					else if(month == 2){
						if((atoi(year) % 4 == 0 && atoi(year) % 100 != 0) || (atoi(year) % 4 == 0 && atoi(year) % 100 == 0 && atoi(year) % 400 == 0)){ 
							if(day >= 1 && day <=29){
								saveValidDate(newNode, month, day, atoi(year)); //stores the valid date to the node 
								clear(); //clears the screen
								addEmployeeLogo(0); //displays the proper heading for the add an employee
								printf("         Employee data have been filled out: \n"); 
								emplData(*newNode); //displays the filled out entries
								printf("\n                                        Press ENTER to continue.");
								getchar();
								isValid = 1;
							}
							else if(day > 29){
								clear();
								//ERROR NOTIFICATION
								printf(" There is no Day %d in February %04d. It must be within 1-29.\n", day, atoi(year));
								addEmployeeLogo(1); //displays the proper heading for the add an employee
								printf("         Fill out the following: \n"); 
								emplData(*newNode); //displays the entries to be filled out
							}
						}
						else if((atoi(year) % 4 != 0) || (atoi(year) % 4 == 0 && atoi(year) % 100 == 0 && atoi(year) % 400 != 0)){ 
							if(day >= 1 && day <=28){
								saveValidDate(newNode, month, day, atoi(year)); //stores the valid date to the node 
								clear(); //clears the screen
								addEmployeeLogo(0); //displays the proper heading for the add an employee
								printf("         Employee data have been filled out: \n"); 
								emplData(*newNode); //displays the filled out entries
								printf("\n                                        Press ENTER to continue.");
								getchar();
								isValid = 1;
							}
							else if(day > 28){
								clear();
								//ERROR NOTIFICATION
								printf(" There is no Day %d in February %04d. It must be within 1-28.\n", day, atoi(year));
								addEmployeeLogo(1);
								printf("         Fill out the following: \n"); 
								emplData(*newNode);  //displays the entries to be filled out
							}
						}
					}
				}
				else{
					clear();
					//ERROR NOTIFICATION
					printf(" Month is %d, should be 1-12\n",month);
					addEmployeeLogo(1); //displays the proper heading for the add an employee
					printf("         Fill out the following: \n"); 
					emplData(*newNode); //displays the entries to be filled out
				}
			}
			else{
				clear();
				//ERROR NOTIFICATION
				printf("Employee is not at the legal age at that time. Try again.\n");
				addEmployeeLogo(1); //displays the proper heading for the add an employee
				printf("         Fill out the following: \n"); 
				emplData(*newNode); //displays the entries to be filled out
			} 
		}
		else{
			clear();
			//ERROR NOTIFICATION
			printf(" Invalid date format. Try again.\n");
			addEmployeeLogo(1);  //displays the proper heading for the add an employee
			printf("         Fill out the following: \n"); 
			emplData(*newNode); //displays the entries to be filled out
		}
	}
}

//EMPLOYEE USER INPUT FUNCTIONS END HERE 

//ENTER TO CONTINUE FUNCTION
void enterToContinue(){
	printf("\n                                        Press ENTER to continue.");
	getchar();
}

//APPOINTMENT USER INPUT FUNCTIONS START HERE

//APPOINTMENT ID INPUT CHECKER
void validAppointmentID(appointmentNode ** newNode, char (*input)[100], employeeNode * head, int flag){
	int isValid = 0; //variable initialization/declaration
	while(isValid!=1){ //the program will continuously get input from the user if the input is not valid
		isValid = 0; //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter 4-digit appointment number (e.g. A0045): A");
		rfgets(*input, 100); //gets the user input and removes the new line character at the end of the string
		if(isstrdigit(*input) == 1 && strlen(*input) <= 4 && atoi(*input) > 0){
			//if all characters of the string are digits, the length of the code is at most 4 and the value of the code is greater than zero
			isValid = 1; //then it is a valid employee no. Moreover, the loop will stop.
		}
		else{
			clear(); //clears the screen 

			//ADD AN APPOINTMENT
			if(flag == 0){ //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN APPOINTMENT SCREEN 
				printf(" Invalid appointment number. Please try again.\n");
				addAppointmentLogo(1); //the parameter is 1 so that the action message will display properly
				printf("                  Fill out the following: \n"); 
				apptData(*newNode, head); //displays the entries to be filled out
			}
			//EDIT AN APPOINTMENT
			else if(flag == 1){ //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN APPOINTMENT SCREEN 
				printf(" Invalid appointment number. Please try again.\n");
				editAppointmentLogo(1);
			}
			//DELETE AN APPOINTMENT
			else if(flag == 2){ //IF FLAG IS 2, IT WILL DISPLAY THE PROPER HEADINGS FOR THE DELETE AN APPOINTMENT SCREEN 
				printf(" Invalid appointment number. Please try again.\n");
				deleteAppointmentLogo(1);
			}
			
		}
	}
}

//GETS THE APPOINTMENT ID FROM THE USER
void getAppointmentID(appointmentNode ** newNode, appointmentNode ** apphead, employeeNode * head){
	int isUnique = 0, duplicatecnt = 0; //variable initialization/declaration
	appointmentNode * temp; char input[100]; //variable initialization/declaration

	printf("                  Fill out the following: \n"); ; 
	apptData(*newNode, head); //displays the entries to be filled out
	while(isUnique != 1){ //the program will continuously get input from the user if the valid appointment number is not unique
		isUnique = 0; //makes sure that the loop wouldn't magically stop even if the input is not unique
		duplicatecnt = 0; //this makes sure that the counter would not overcount  
		if(*apphead == NULL){ //if the linked list of the appointment directory is empty, it will not scan the existing employee number
			validAppointmentID(newNode, &input, head, 0); //however, it will check first if the appointment no. inputted by the user if valid
			(*newNode)->appId = atoi(input); //if the appointment number is valid, then it will be stored in the new node
			clear(); //clears the screen
			printf(" Appointment no. A%04d is valid.\n", atoi(input)); //displays notification
			isUnique = 1; //the loops will stop. 
		}
		else if(*apphead != NULL){ //however, if the linked list of the appointment directory is not empty, it will scan the existing appointment number
			validAppointmentID(newNode,&input, head, 0); //however, it will check if the appointment no. inputted by the user if valid
			isUnique = 0; //makes sure that the loop wouldn't magically stop even if the input is not unique
			temp = *apphead;  //points the temporary pointer to the node being pointed by the head pointer
			while(temp != NULL){ //checks if there is a duplicate appointment number
				if(atoi(input) == temp->appId){  //if there is a duplicate
					duplicatecnt++; //the counter will increase by one
					isUnique = 0; //tells the program that the appointment number is not unique
				}
				temp = temp->next; //traverses the entire linked list
			}
			if(duplicatecnt == 0){ //if there are no duplicate appointment number
				(*newNode)->appId = atoi(input); //the input will be stored to the node
				clear(); //clears the screen
				printf(" Appointment no. A%04d is valid.\n", atoi(input)); //displays notification
				isUnique = 1; //tells the program that the appointment number is unique
			}
			else if(duplicatecnt != 0){
				clear(); //clears the screen
				printf(" Appointment no. A%04d already exists. Try again.\n", atoi(input)); //displays notification
				addAppointmentLogo(1); //displays the proper heading for the add an employee
				printf("                  Fill out the following: \n"); 
				apptData(*newNode, head);  //displays the entries to be filled out
				isUnique = 0; //tells the program that the appointment number is not unique
			}
		}
	}
}



void validAssignedEmployeeID(appointmentNode ** newNode, char (*input)[100], employeeNode * head, int flag){
	int isValid = 0;
	while(isValid!=1){ //the program will continuously get input from the user if the input is not valid
		isValid = 0; //this makes sure that the loop wouldn't magically stop even if the input is not valid
		printf("\n Enter 4-digit employee number of assigned employee (e.g. E0045): E");
		rfgets(*input, 100);  //gets the user input and removes the new line character at the end of the string
		if(isstrdigit(*input) == 1 && strlen(*input) <= 4 && atoi(*input) > 0){
			//if all characters of the string are digits, the length of the code is at most 4 and the value of the code is greater than zero
			isValid = 1; //then it is a valid employee no. Moreover, the loop will stop.
		}
		else{
			clear(); //clears the screen 
			printf(" Invalid employee number. Please try again.\n"); //displays notification
			//ADD AN APPOINTMENT
			if(flag == 0){  //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN APPOINTMENT SCREEN 
				addAppointmentLogo(1);		
			}
			//EDIT AN APPOINTMENT
			else if(flag == 1){  //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN APPOINTMENT SCREEN 
				editAppointmentLogo(1);
			}
			emplDataSimple(head); //displays all the employee in a simple table

		}
	}
}

//GETS THE ASSIGNED EMPLOYEE's ID FROM THE USER
void getAssignedEmployeeID(appointmentNode ** newNode, appointmentNode ** apphead, employeeNode * head, int flag){
	int isUnique = 0, existcnt = 0, isValid = 0; //variable initialization/declaration
	employeeNode * temp; char input[100]; //variable initialization/declaration
	//ADD AN APPOINTMENT
	if(flag == 0){ //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN APPOINTMENT SCREEN
		addAppointmentLogo(1);		
	}
	//EDIT AN APPOINTMENT
	else if(flag == 1){ //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN APPOINTMENT SCREEN 
		editAppointmentLogo(0);
	}
	emplDataSimple(head); //displays all the employee in a simple table
	while(isValid != 1){ //the program will continuously get input from the user if the input is not valid
		validAssignedEmployeeID(newNode, &input, head, flag); //however, it will check first if the employment no. inputted by the user if valid
		temp = head; //points the temporary pointer to the node being pointed by the head pointer
		while(temp!=NULL){ //checks if the appointment number exists
			if(atoi(input) == temp->id){  //if the employee exists
				existcnt++; //the cnt will increase by 1
				break;
			}
			temp = temp->next; //traverse the linked list
		}
		if(existcnt != 0){ //if the employee exists
			(*newNode)->id = atoi(input); //the employee number will be stored
			strcpy((*newNode)->name,temp->name); //and the employee name will be also stored
			clear(); //clears the screen
			printf(" Employee no. E%04d exists.\n", atoi(input)); //displays notification
			isValid = 1;
		}
		else if(existcnt == 0){ //if the employee does not exists
			clear(); //clears the screen
			printf(" Employee no. E%04d does not exist. Try again.\n", atoi(input));
			//ADD AN APPOINTMENT
			if(flag == 0){  //IF FLAG IS 0, IT WILL DISPLAY THE PROPER HEADINGS FOR THE ADD AN APPOINTMENT SCREEN
				addAppointmentLogo(1);		
			}
			//EDIT AN APPOINTMENT
			else if(flag == 1){  //IF FLAG IS 1, IT WILL DISPLAY THE PROPER HEADINGS FOR THE EDIT AN APPOINTMENT SCREEN
				editAppointmentLogo(1);
			}
			emplDataSimple(head); //displays the all the employee in a simple table
			isValid = 0;
		}

	}
}

//STORES THE VALID DATE TO THE NODE
void saveValidRsvnDate(appointmentNode ** newNode, int month, int day, int year, char date[100]){
	(*newNode)->reservationDate.month = month; //stores the month to the node 
	(*newNode)->reservationDate.day = day; //stores the day to the node 
	(*newNode)->reservationDate.year = year; //stores the year to the node
	sprintf((*newNode)->reservationDate.strdate, "%02d/%02d/%04d", (*newNode)->reservationDate.month, (*newNode)->reservationDate.day,(*newNode)->reservationDate.year); 
	//^stores month, day and year as a string for easy comparison purposes
}

//GETS THE RESERVATION DATE FROM THE USER
void getRsvnDate(appointmentNode ** newNode, employeeNode * head, int flag){
	int month, day, isValid = 0; //variable declaration/initialization
	char year[10];  //variable declaration/initialization
	char date[100];  //variable declaration/initialization
	arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
	apptData(*newNode, head); //displays the entries to be filled out
	while(isValid != 1){  //loops until the input is valid
		printf("\n NOTE: Appointment date must be from 2015 onwards. (e.g. 12/25/2015)\n");
		printf(" Enter appointment date (MM/DD/YYYY): "); 
		rfgets(date,100); //gets the user input and removes the new line character at the end of the string
		sscanf(date, "%d/%d/%s", &month, &day, year);	//splits and stores the date into month, day, year as an integer
		//CHECKS IF THE FORMAT OF INPUT IS VALID AND THERE ARE NO ALPHA OR SPECIAL CHARACTERS (except for slash)
		if( (date[2] == '/' && (date[4] == '/' || date[5] == '/') && strlen(year) > 0 && strlen(year) <= 4 && isstrdigit(year) == 1) || 
			(date[1] == '/' && (date[3] == '/' || date[4] == '/') && strlen(year) > 0 && strlen(year) <= 4 && isstrdigit(year) == 1) ){
			if(atoi(year) >= 2015) //checks if the appointment date is within/beyond the present year
				if(month >= 1 && month <= 12){ //checks if the month is within january and december
					if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
						if(day >= 1 && day <=31){
							saveValidRsvnDate(newNode, month, day, atoi(year), date); //stores the valid date to the node 
							clear(); //clears the screen
							printf(" %02d/%02d/%04d is a valid date\n", month, day, atoi(year)); //notification	
							isValid = 1;
						}
						else if(day > 31){
							clear();
							//ERROR NOTIFICATION
							if(month == 1) printf(" There is no Day %d in January %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 3) printf(" There is no Day %d in March %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 5) printf(" There is no Day %d in May %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 7) printf(" There is no Day %d in July %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 8) printf(" There is no Day %d in August %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 10) printf(" There is no Day %d in October %04d. It must be within 1-31.\n", day, atoi(year));
							else if(month == 12) printf(" There is no Day %d in December %04d. It must be within 1-31.\n", day, atoi(year));
							arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
							apptData(*newNode, head); //displays the entries to be filled out
						}
					}
					else if(month == 4 || month == 6 || month == 9 || month == 11){
						if(day >= 1 && day <=30){
							saveValidRsvnDate(newNode, month, day, atoi(year), date); //stores the valid date to the node 
							clear(); //clears the screen
							printf(" %02d/%02d/%04d is a valid date\n", month, day, atoi(year)); //notification	
							isValid = 1;
						}
						else if(day > 30){
							clear();
							//ERROR NOTIFICATION
							if(month == 4) printf(" There is no Day %d in April %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 6) printf(" There is no Day %d in June %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 9) printf(" There is no Day %d in September %04d. It must be within 1-30.\n", day, atoi(year));
							else if(month == 11) printf(" There is no Day %d in November %04d. It must be within 1-30.\n", day, atoi(year));
							arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
							apptData(*newNode, head);  //displays the entries to be filled out
						}
					}
					else if(month == 2){
						if((atoi(year) % 4 == 0 && atoi(year) % 100 != 0) || (atoi(year) % 4 == 0 && atoi(year) % 100 == 0 && atoi(year) % 400 == 0)){ 
							if(day >= 1 && day <=29){
								saveValidRsvnDate(newNode, month, day, atoi(year), date); //stores the valid date to the node 
								clear();
								printf(" %02d/%02d/%04d is a valid date\n", month, day, atoi(year));	//notification	
								isValid = 1;
							}
							else if(day > 29){
								clear();
								//ERROR NOTIFICATION
								printf(" There is no Day %d in February %04d. It must be within 1-29.\n", day, atoi(year));
								arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
								apptData(*newNode, head); //displays the entries to be filled out
							}
						}
						else if((atoi(year) % 4 != 0) || (atoi(year) % 4 == 0 && atoi(year) % 100 == 0 && atoi(year) % 400 != 0)){ 
							if(day >= 1 && day <=28){
								saveValidRsvnDate(newNode, month, day, atoi(year), date);  //stores the valid date to the node 
								clear();
								printf(" %02d/%02d/%04d is a valid date\n", month, day, atoi(year));	//notification
								isValid = 1;
							}
							else if(day > 28){
								clear();
								printf(" There is no Day %d in February %04d. It must be within 1-28.\n", day, atoi(year));
								arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
								apptData(*newNode, head); //displays the entries to be filled out
							}
						}
					}
				}
				else{
					clear();
					printf(" Month is %d, should be 1-12\n",month);
					arefresh(*newNode, flag);  //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
					apptData(*newNode, head);  //displays the entries to be filled out
				}
			else{
				clear();
				printf(" Invalid year. Must be from 2015-future.	\n");
				arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
				apptData(*newNode, head); //displays the entries to be filled out
			}
		}
		else{
			clear();
			printf(" Invalid date format. Try again.\n");
			arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
			apptData(*newNode, head); //displays the entries to be filled out
		}
	}
}

//STORES THE VALID TME TO THE NODE
void saveValidTime(appointmentNode ** newNode, int hour, int minutes, char rsvntime[]){
	(*newNode)->reservationTime.hours = hour; //stores the hour to the node
	(*newNode)->reservationTime.minutes = minutes; //stores the minutes to the node 
	strcpy((*newNode)->reservationTime.strtime, rsvntime); //stores the time as a string

}
//CHECKS IF THERE IS A CONFLICT
int checkConflict(appointmentNode * newNode, appointmentNode * apphead, int hour, int minutes, char rsvntime[]){
	appointmentNode * temp; int conflictcnt = 0; //variable declaration/initialization 
	temp = apphead; //points the temporary pointer to the node being pointed by the head
	while(temp != NULL){ //counts the number of conflicts
		if(strcmp(temp->reservationDate.strdate, newNode->reservationDate.strdate) == 0 && temp->id == newNode->id){	
			if(strcmp(temp->reservationTime.strtime, rsvntime) == 0){
				conflictcnt++; //increases the counter by one
				return 1; //returns 1 if there is a conflict 
			}
			
		}
		temp = temp->next; //traverses the linked list
	}
	if(conflictcnt == 0){ //if there is no confict
		saveValidTime(&newNode, hour, minutes, rsvntime); //it will save the time 
		return 0; //returns 0 if there is no conflict
	}
}

//GETS THE RESERVATION TIME FROM THE USER
void getRsvnTime(appointmentNode ** newNode, appointmentNode * apphead, employeeNode * head, int flag){
	int hour, minutes, isValid = 0, index = 0, hasConflict = 0; //variable initialization/declaration
	char rsvntime[10], input[100]; //variable initialization/declaration
	arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
	apptData(*newNode, head); //displays the entries to be filled out
	while(isValid != 1){
		printf("\n NOTE: Escape from Acads Spa | Opening Hours: 9:00 | Closing Hours: 21:00.\n");
		printf(" Enter appointment time (HH:MM): ");
		rfgets(input,100); //gets the user input and removes the new line character at the end of the string
		sscanf(input, "%d:%d", &hour, &minutes);  //splits and stores the date into hour and minute as an integer
		sprintf(rsvntime, "%02d:%02d", hour, minutes); //stores the date as a string (proper format)
		//CHECKS IF THE TIME FORMAT IS CORRECT
		if((rsvntime[2] == ':' && (strlen(rsvntime) == 5 || strlen(rsvntime) == 4)) || 
			(rsvntime[1] == ':' &&  (strlen(rsvntime) == 3 || (strlen(rsvntime) == 4)))
			){
			if(isstrtimedigit(&index, rsvntime) == 1){ //checks if the time does not contain alpha/special chars
				if(hour >= 9 && hour < 21){ //checks if hour is within the open and closing hours
					if(minutes >= 0 && minutes <=59){ //checks if minute is valid
						hasConflict = checkConflict(*newNode, apphead, hour, minutes, rsvntime); //checks if there is a conflict
						if(hasConflict == 1){
							clear();
							printf(" Appointment has conflict. Try again.\n");
							arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
							apptData(*newNode, head); //displays the entries to be filled out
						}
						else if(hasConflict == 0){
							saveValidTime(newNode, hour, minutes, rsvntime); //saves the time to the node if there are no conflicts
							clear(); //clears the screen
							printf(" Time is valid. \n"); //notification
							isValid = 1;
						}
					}
					else{
						clear();//clears the screen
						printf(" Minute is %02d:%02d. Must be within %02d:00-%02d:59 only\n", hour, minutes, hour, hour);  //notification
						arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
						apptData(*newNode, head); //displays the entries to be filled out
					}
				}
				else{
					clear(); //clears the screen
					printf(" Hour is %02d:00. Must be within 09:00-20:59 only.\n", hour);
					arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
					apptData(*newNode, head); //displays the entries to be filled out
				}
			}
			else{
				clear(); //clears the screen
				printf(" Time must not contain letter or special character. Try again.\n");
				arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
				apptData(*newNode, head); //displays the entries to be filled out
			}

		}
		else{
			clear(); //clears the screen
			printf(" Invalid time format. Try again.\n");
			arefresh(*newNode, flag); //displays the proper heading for add/edit an appointment. if flag == 0 (add), flag == 1 (edit)
			apptData(*newNode, head); //displays the entries to be filled out
		}

	}
}

//APPOINTMENT USER INPUT FUNCTIONS ENDS HERE