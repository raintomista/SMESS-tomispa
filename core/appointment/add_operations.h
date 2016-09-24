//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//ADD APPOINTMENT OPERATION FUNCTIONS


//RESETS THE VALUE OF THE NODE TO NULL OR ZERO
void aflush(appointmentNode ** newNode){
	(*newNode)->prev = 0;
	(*newNode)->appId = 0;
	(*newNode)->reservationDate.month= 0;
	(*newNode)->reservationDate.day= 0;
	(*newNode)->reservationDate.year= 0;
	(*newNode)->reservationTime.hours= 0;
	(*newNode)->reservationTime.minutes = 0;
	strcpy((*newNode)->name, "\0");
	(*newNode)->id = 0;
	(*newNode)->next = NULL;
}//deletes all the garbage values and sets it to NULL or 0

//ADD APPOINTMENT FUNCTION
void addAppointment(appointmentNode ** apphead, employeeNode * head){
	char input[100]; //variable declaration
	appointmentNode * newNode = (appointmentNode*)malloc(sizeof(appointmentNode)); //allocates memory for the node
	appointmentNode * temp; //temporary pointer declaration
	aflush(&newNode); //removes the garbage value by setting the value to null or zero
	clear(); //clears the screen
	addAppointmentLogo(0); //prints the proper heading for add an appointment screen

	getAppointmentID(&newNode, apphead, head); //gets appointment id from the user 

	getAssignedEmployeeID(&newNode, apphead, head,0); //gets employee number of assigned employee from the user 
	getRsvnDate(&newNode, head, 0); //gets reservation date from the user 
	getRsvnTime(&newNode, *apphead, head,0); //gets reservation time from the user 

	addAppointmentLogo(1);	//displays proper heading for add an appointment screen
	printf("                  Appointment data have been filled out: \n"); 
	apptData(newNode, head); //prints the filled out entries
	printf("\n                                        Press ENTER to continue.");
	getchar();

	//ADD AT HEAD
	if(*apphead == NULL || newNode->appId < (*apphead)->appId){ //add at head
		newNode->prev = NULL;
		newNode->next = *apphead;
		*apphead = newNode;
	}
	//ADD AT TAIL
	else{
		temp = *apphead;
		while(temp->next != NULL && temp->next->appId < newNode->appId){ 
			temp=temp->next;
		}
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
	}
	clear();
	printf(" Appointment No. A%04d has been successfully added. \n", newNode->appId);
}
