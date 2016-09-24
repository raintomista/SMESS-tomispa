//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//FILE MANIPULATION FUNCTIONS

#include "rfstring.h" //Contains user-defined string manipulations made by me. Named after my initials

//EMPLOYEE FILE OPERATION STARTS HERE

//LOAD EACH BLOCK OF EMPLOYEE TEXT FILE
void readEmployeeEntries(FILE ** fp, employeeNode ** newNode){ //loads each block of code (containing employee data) in the text file 
	fgets((*newNode)->name, 999, *fp); //stores the employee name from the text file
	(*newNode)->name[strlen((*newNode)->name)-1] = '\0'; //removes the excess newline character from the string
	capitalize(&((*newNode)->name)); //capitalizes the first letter of every word of the string (employee name)
	fscanf(*fp, "%d, %d\n", &((*newNode)->id), &((*newNode)->age)); //stores employee number and age from the text file
	fgets((*newNode)->position, 999,*fp); //stores employee position from the text file
	(*newNode)->position[strlen((*newNode)->position)-1] = '\0'; //removes the excess newline character from the string
	capitalize(&((*newNode)->position)); //capitalizes the first letter of every word of the string (employee position)
	fscanf(*fp, "%d,%d,%d\n", &((*newNode)->dateHired.month), &((*newNode)->dateHired.day), &((*newNode)->dateHired.year));
	//^stores the employement date from the text fire
}

//LOAD THE ENTIRE EMPLOYEE TEXT FILE
void loadEmployeeData(FILE ** empl_fp, employeeNode ** empl_head, int * empl_cnt){ //loads the whole text file
	while(!feof(*empl_fp)){ //reads every line until it reach the end of the text file
		fscanf(*empl_fp, "%d\n", empl_cnt); //stores the first line of the text file containing the total number of employee
		if(*empl_cnt != 0){ //proceeds with the operation if text file is not empty
			//ADD AT HEAD
			if(*empl_head == NULL){ //if the employee directory linked list is still empty, it will add the employee data at head
				employeeNode * newNode = (employeeNode*)malloc(sizeof(employeeNode)); //allocates memory for the node
				readEmployeeEntries(empl_fp, &newNode); //stores the employee data (from the block of code in the text file) to the node
				newNode->prev = NULL; //sets the previous node pointer to NULL since their is only one node in the linked list
				newNode->next = *empl_head; //sets the next node pointer to NULL since there is only one node in the linked list
				*empl_head = newNode; //the head pointer will now be pointed to the node
			}
			//ADD AT TAIL
			else if(*empl_head != NULL){ //if the employee directory linked list contains at least one node, it will add the employee data at tail
				employeeNode * newNode = (employeeNode*)malloc(sizeof(employeeNode)); //allocates memory for the node
				readEmployeeEntries(empl_fp, &newNode);  //stores the employee data (from the block of code in the text file) to the node
				employeeNode * temp; //declares a temporary node pointer
				temp = *empl_head; //points the temporary node pointer to the same node being pointed by head
				while(temp->next != NULL){ 
					temp = temp -> next; //looks for the tail node
				}
				temp->next = newNode; //adds new node after the tail node
				newNode->prev = temp; //points the previous pointer of the new node to the old tail node
				newNode->next = NULL; //sets the next pointer of the new node to NULL since there are no nodes after it
			}
		}
	}
}

//CALL THE FUNCTION THAT LOADS THE EMPLOYEE TEXT FILE. HOWEVER, IF IT DOES NOT EXIST, IT WILL LOAD THE EMPLOYEE TEXT FILE 
void loadEmployeeFile(FILE ** fp, employeeNode ** head, int * empl_cnt, char filename[100]){
	*fp = fopen(filename, "r"); //opens the text file in read mode
	//CREATES A TEXT FILE IF IT DOES NOT EXIST
	if(*fp == NULL){ //if the file pointer returns NULL (which mean the file does not exist)
		*fp = fopen(filename, "w"); //it will create a new text file
		fclose(*fp); //and closes it to avoid data corruption
	}
	//LOADS THE TEXT FILE IF IT EXISTS
	else{ //however, if the file pointer does not return NULL, it means that the text file exists
		loadEmployeeData(fp, head, empl_cnt); //thus, it will load every line of the text file

	}
}

//SAVE EVERY EMPLOYEE DATA IN THE EMPLOYEE LINKED LIST TO THE TEXT FILE
void saveEmployeeData(employeeNode ** head, int * employeecnt){ //saves the every node in the linked list containing employee data to the text file
	employeeNode * temp; //declares a temporary node pointer
	FILE * fp = fopen("files/employees.txt", "w"); //opens the text file for writing
	fprintf(fp, "%d\n", *employeecnt); //saves the total number of employees to the first line of the text file

	temp = *head; //the temporary pointer is pointed to the node being pointed by the head pointer
	while(temp != NULL){ //tranverses the entire linked list until it finds the end of the linked list
		if(temp->next != NULL){ //it saves the employee data contained in the node to the text file when the node is not the tail node
			fprintf(fp, "%s\n", temp->name); //saves the employee name to the text file
			fprintf(fp, "%d, %d\n", temp->id, temp->age); //saves the employee number and age to the text file
			fprintf(fp, "%s\n", temp->position); //saves the employee position to the text file
			fprintf(fp, "%d,%d,%d\n\n", temp->dateHired.month, temp->dateHired.day, temp->dateHired.year); 
			//saves the employment date to the text file and skips a line (so that the text file wont look cluttered)
		}
		else{ //when it finds the tail node
			fprintf(fp, "%s\n", temp->name); //it will save the employee data contained in the node to the text file.
			fprintf(fp, "%d, %d\n", temp->id, temp->age); //it will save the employee number and age to the text file
			fprintf(fp, "%s\n", temp->position); //saves the employee position to the text file
			fprintf(fp, "%d,%d,%d\n", temp->dateHired.month, temp->dateHired.day, temp->dateHired.year);
			//saves the employment date to the text file and doest not skip a line 
		}
		temp = temp->next; //traverses the employee linked list
	}
	fclose(fp); //closes the file to avoid data corruption

}

//EMPLOYEE FILE OPERATION ENDS HERE

//APPOINTMENT FILE OPERATION STARTS HERE


//LOAD EACH BLOCK OF APPOINTMENT TEXT FILE
void readAppointmentEntries(FILE ** fp, appointmentNode ** newNode){ //loads each block of code (containing appointment data) in the text file 
	fscanf(*fp, "%d\n", &((*newNode)->appId)); //stores the appointment number from the text file
	fscanf(*fp, "%d,%d,%d\n", &((*newNode)->reservationDate.month), &((*newNode)->reservationDate.day), &((*newNode)->reservationDate.year)); //splits and stores the date into month, day and year
	sprintf((*newNode)->reservationDate.strdate, "%02d/%02d/%04d", (*newNode)->reservationDate.month, (*newNode)->reservationDate.day,(*newNode)->reservationDate.year); //stores the date as a string for easier comparison purposes
	fscanf(*fp, "%d,%d\n", &((*newNode)->reservationTime.hours), &((*newNode)->reservationTime.minutes)); //splits and stores the time into hour and minutes
	sprintf((*newNode)->reservationTime.strtime, "%02d:%02d", (*newNode)->reservationTime.hours, (*newNode)->reservationTime.minutes); //stores the time as a string for easier comparison purposes
	fscanf(*fp, "%d\n", &((*newNode)->id)); //stores the employee number of assigned employee
}


//LOAD THE ENTIRE APPOINTMENT TEXT FILE
void loadAppointmentData(FILE ** fp, appointmentNode ** head, int * totalAppointmentCnt){ //loads the whole text file
	fscanf(*fp, "%d\n", totalAppointmentCnt);  //stores the first line of the text file containing the total number of appointments
	while(!feof(*fp)){ 	//reads every line until it reach the end of the text file
		if(*totalAppointmentCnt != 0){ //proceeds with the operation if the appointment directory is not empty
			//ADD AT HEAD
			if(*head == NULL){ //if the appointment directory linked list is still empty, it will add the appointment data at head
				appointmentNode * newNode = (appointmentNode*)malloc(sizeof(appointmentNode)); //allocates memory for the node
				readAppointmentEntries(fp, &newNode); //stores the appointment data (from the block of code in the text file) to the node
				newNode->prev = NULL; //sets the previous node pointer to NULL since their is only one node in the linked list
				newNode->next = *head; //sets the next node pointer to NULL since their is only one node in the linked list
				*head = newNode; //the head pointer will now be pointed to the new node
			}
			else if(*head != NULL){
				appointmentNode * newNode = (appointmentNode*)malloc(sizeof(appointmentNode)); //allocates memory for the node
				appointmentNode * temp; //declares a temporary node pointer
				readAppointmentEntries(fp, &newNode); //stores the appointment data (from the block of code in the text file) to the node
				temp = *head; //points the temporary node pointer to the same node being pointed by head
				while(temp->next != NULL){ //looks for the tail node
					temp = temp -> next; //traverses the entire linked list
				}
				temp->next = newNode; //adds new node after the tail node
				newNode->prev = temp; //points the previous pointer of the new node to the old tail node
				newNode->next = NULL; //sets the next pointer of the new node to NULL since there are no nodes after it
			}
		}
	}
	fclose(*fp); //closes the file to avoid data corruption
}

//CALL THE FUNCTION THAT LOADS THE APPOINTMENT TEXT FILE. HOWEVER, IF IT DOES NOT EXIST, IT WILL LOAD THE APPOINTMENT TEXT FILE 
void loadAppointmentFile(FILE ** fp, appointmentNode ** head, int * totalAppointmentCnt, char filename[100]){
	*fp = fopen(filename, "r"); //opens the text file in read mode
	//CREATES A TEXT FILE IF IT DOES NOT EXIST
	if(*fp == NULL){ //if the file pointer returns NULL (which mean the file does not exist)
		*fp = fopen(filename, "w"); //opens the text file for writing
		fclose(*fp);  //and closes it to avoid data corruption
	}
	//LOADS THE TEXT FILE IF IT EXISTS
	else{ //however, if the file pointer does not return NULL, it means that the text file exists
		loadAppointmentData(fp, head, totalAppointmentCnt); //thus, it will load every line of the text file
	}
}

//SAVE EVERY APPOINTMENT DATA IN THE APPOINTMENT LINKED LIST TO THE TEXT FILE
void saveApptData(appointmentNode ** head, int * totalAppointmentCnt){
	appointmentNode *temp; //declares a temporary node pointer
	FILE *fp = fopen("files/appointments.txt", "w"); //opens the text file for writing
	fprintf(fp, "%d\n", *totalAppointmentCnt); //saves the total number of appointments to the first line of the text file

	temp = *head;  //the temporary pointer is pointed to the node being pointed by the head pointer
	while(temp != NULL){ //tranverses the entire linked list until it finds the end of the linked list
		if(temp->next != NULL){ //it saves the employee data contained in the node to the text file when the node is not the tail node
			fprintf(fp, "%d\n", temp->appId); //saves the appointment number to the text file
			fprintf(fp, "%d,%d,%d\n", temp->reservationDate.month, temp->reservationDate.day, temp->reservationDate.year); //saves the appointment reservation date to the text file 
			fprintf(fp, "%d,%d\n", temp->reservationTime.hours, temp->reservationTime.minutes); //saves the appointment reservation time to the text file 
			fprintf(fp, "%d\n\n", temp->id); //saves the employment number of the assigned employee to the text file and skips a line (so that the text file wont look cluttered)

		}
		else{
			fprintf(fp, "%d\n", temp->appId); //saves the appointment number to the text file
			fprintf(fp, "%d,%d,%d\n", temp->reservationDate.month, temp->reservationDate.day, temp->reservationDate.year); //saves the appointment reservation date to the text file 
			fprintf(fp, "%d,%d\n", temp->reservationTime.hours, temp->reservationTime.minutes); //saves the appointment reservation time to the text file 
			fprintf(fp, "%d", temp->id); //saves the employee number of the assigned employee to the text file and doest not skip a line 
		}
		temp = temp->next; //traverses the entire linked list
	}
	fclose(fp); //closes the file to avoid data corruption
}


//APPOINTMENT OPERATION ENDS HERE

