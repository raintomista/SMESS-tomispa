//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//EDIT EMPLOYEE OPERATION FUNCTIONS
void editEmployee(employeeNode ** head){
	//VARIABLE INITIALIZATION/DECLARATION
	int employeeExists = 0, clearflag = 0, promptvalid = 0;
	char prompt[100], input[100],strtemp[100];
	employeeNode * temp;

	clear();
	editEmployeeLogo(0); //displays proper heading for edit employee
	printf(" Enter employee name: ");
	rfgets(input,100); //asks for user input
	tostrlower(&input); //converts the string to lowercase (case insensitivity)

	clear();
	temp = *head;
	while(temp!=NULL){
		promptvalid = 0;
		strcpy(strtemp, temp->name); //stores the name in the node to the 
		tostrlower(&strtemp); //converts the string to lowercase (case insensitivity)
		if(strcmp(input, strtemp) == 0){ //if there is a match
			while(promptvalid != 1){
				promptvalid = 0;
				editEmployeeLogo(clearflag);
				printf("         Employee found!\n"); 
				emplData(temp);
				printf("\n Would you like to edit this? (y/n): "); //asks the user if he/she wants to edit
				rfgets(prompt, 100);
				if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){
					clear();
					printf("\n");
					getName(&temp, 1); //gets the employee name from the user
					getAge(&temp, 1); //gets employee age from the user
					getPosition(&temp, 1); //gets the employee position from the user
					editEmployeeLogo(1); //displays proper headings for edit employee
					printf("         Employee data have been edited: \n"); 
					emplData(temp); //displays edited entries
					printf("\n                                        Press ENTER to continue.");
					getchar();
					clear();
					clearflag = 1;
					printf(" Employee No. E%04d's data has been updated\n", temp->id);
					promptvalid = 1; 
				}
				else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0)  && strlen(prompt) == 1){
					clear();
					clearflag = 1;
					printf(" Employee No. E%04d's data has not been updated\n", temp->id);
					promptvalid = 1;
				}
				else{
					clearflag = 1;
					clear();
					printf(" Invalid input. Try again.\n");
				}
			}
			employeeExists++; //increases by one if the employee exists
		}
		temp = temp->next;
	}
	if(employeeExists == 0){
		printf(" Employee not found.\n");
	}
}

