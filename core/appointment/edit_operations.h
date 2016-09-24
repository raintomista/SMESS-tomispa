//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//EDIT APPOINTMENT OPERATION FUNCTIONS

void editAppointment(appointmentNode ** apphead, employeeNode * head){
	int appointmentExists = 0, clearflag = 0, promptvalid = 0; //variable declaration/initialization
	char prompt[100], input[100],strtemp[100]; //variable declaration/initialization
	appointmentNode * temp; //temporary pointer declaration

	clear(); //clears the screen
	editAppointmentLogo(0); //displays the proper heading for edit appointment screem
	validAppointmentID(&temp, &input, head,1); //checks if the appointment number is valid

	clear(); //clears the screen
	temp = *apphead;
	while(temp!=NULL){
		promptvalid = 0; //ensures that there is no loop hole in the checker
		if(atoi(input) == temp->appId){ //if the appointment number exists
			while(promptvalid != 1){
				promptvalid = 0; //ensures that there is no loop hole in the checker
				editAppointmentLogo(clearflag);
				printf("                  Appointment found!\n"); 
				apptData(temp, head); //it will print the exisiting entries
				printf("\n Would you like to edit this? (y/n): "); //and ask the user if he/she wants to edit it
				rfgets(prompt, 100);
				if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){ //if yes
					clear();
					getAssignedEmployeeID(&temp, apphead, head, 1); //it will get assigned employee id
					getRsvnDate(&temp, head, 1); //get reservation date
					getRsvnTime(&temp, *apphead, head,1); //get reservation time
					editAppointmentLogo(1); //displays proper headings for edit an appointment
					printf("                  Appointment data have been filled out: \n"); 
					apptData(temp, head); //displays the edited entries
					printf("\n                                        Press ENTER to continue.");
					getchar();
					clear();
					printf(" Appointment No. A%04d has been successfully updated. \n", temp->appId); //notification
					promptvalid = 1; //input is valid
				}
				else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0)  && strlen(prompt) == 1){
					clear();
					clearflag = 1;
					printf("Appointment No. A%04d's data has not been updated\n", temp->appId); //notification
					promptvalid = 1; //input is valid
				}
				else{
					clearflag = 1;
					clear();
					printf(" Invalid input. Try again.\n");
				}
			}
			appointmentExists++; //increases by one if the appointment exists
		}
		temp = temp->next; //traverses the linked list
	}
	if(appointmentExists == 0){
		printf(" Appointment not found.\n"); //notification
	}
}