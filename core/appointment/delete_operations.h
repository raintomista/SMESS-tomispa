//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//EDIT APPOINTMENT OPERATION FUNCTIONS

//DELETE AN APPOINTMENT OPERATIN
void deleteAppt(appointmentNode ** del, appointmentNode ** head){
	appointmentNode * temp;
	//DELETE AT HEAD
	if(*del == *head){
		*head = (*del)->next;
		(*del)->prev = NULL;
		free(*del);
	}
	//DELETE AT TAIL
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


//DELETE AN APPOINTMENT
void deleteAppointment(appointmentNode ** apphead, employeeNode * head, int * appointmentcnt){
	char input[100]; char prompt[100]; //variable declaration/initialization
	appointmentNode * del;  //variable declaration/initialization
	int promptvalid = 0;  //variable declaration/initialization
	
	clear();
	deleteAppointmentLogo(0); //displays proper heading for delete an appoinemnt
	validAppointmentID(&del, &input, head,2); //checks if appointment number is valid

	del = *apphead; 
	while(del !=NULL && atoi(input) != del->appId){
		del = del->next; //traverses the linked list until it founds the appointment number 
	}
	if(del == NULL) {
		clear();
		printf(" Appointment No. A%04d not found\n", atoi(input)); //notification
	}
	else{ //if the appointment number exists
		clear();
		deleteAppointmentLogo(0); //displays proper heading for delete appointment
		apptData(del, head); //displays existing entries (data)
		while(promptvalid != 1){
			promptvalid = 0;
			printf("\n Do you really want to delete Appointment No. A%04d? (y/n): ",atoi(input));
			rfgets(prompt, 100); //asks the user for input
			if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){
				printf(" Do you REALLY want to delete Appointment No. A%04d? (y/n): ",atoi(input));
				rfgets(prompt, 100);
				if((strcmp(prompt, "y") == 0 || strcmp(prompt, "Y") == 0)  && strlen(prompt) == 1){
					deleteAppt(&del, apphead); //deletes the appointment in the linked list
					clear();
					printf(" Appointment No. A%04d has been successful deleted.\n",atoi(input));
					promptvalid = 1;  //input is valid
					(*appointmentcnt)--; //the total number of appointment decreases
				}
				else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0)  && strlen(prompt) == 1){
					clear();
					printf(" Appointment No. A%04d has not been deleted. Operation cancelled.\n",atoi(input));
					promptvalid = 1; //input is valid
				}
				else{
					clear();
					printf(" Invalid input. Try again.\n");
					deleteAppointmentLogo(1); //displays proper heading for delete appointment
					apptData(del, head); //displays the existing entries (data)
				}

			}
			else if((strcmp(prompt, "n") == 0 || strcmp(prompt, "N") == 0)  && strlen(prompt) == 1){
				clear();
				printf(" Appointment No. A%04d has not been deleted. Operation cancelled.\n",atoi(input));
				promptvalid = 1; //input is valid
			}
			else{
				clear();
				printf(" Invalid input. Try again.\n");
				deleteAppointmentLogo(1); //displays proper heading for delete appointment
				apptData(del, head); //displays the existing entries (data)
			}
		}
	}
}


