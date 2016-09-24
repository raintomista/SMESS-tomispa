//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//ADD EMPLOYEE OPERATION FUNCTIONS
void eflush(employeeNode ** newNode){
	(*newNode)->prev = 0;
	(*newNode)->id = 0;
	strcpy((*newNode)->name, "\0");
	(*newNode)->age = 0;
	strcpy((*newNode)->position, "\0");
	(*newNode)->dateHired.month= 0;
	(*newNode)->dateHired.day= 0;
	(*newNode)->dateHired.year= 0;
	(*newNode)->next = NULL;
}//deletes all the garbage values and sets it to NULL or 0

//ADDS EMPLOYEE TO THE LINKED LIST
void addEmployee(employeeNode ** head){
	employeeNode * temp;
	clear(); //clears the screen
	addEmployeeLogo(0);
	employeeNode * newNode, * empty;
	newNode = (employeeNode*)malloc(sizeof(employeeNode)); //allocates memory
	eflush(&newNode); //sets the values in the node to zero or null 
	getEmployeeID(&newNode, head); //get empl id
	getName(&newNode, 0); //get emp name
	getAge(&newNode, 0); //get empl age
	getPosition(&newNode, 0); //get empl position
	getDateHired(&newNode); //get date hired
	//ADD AT HEAD
	if(*head == NULL || newNode->id < (*head)->id){ 
		newNode->prev = NULL;
		newNode->next = *head;
		*head = newNode;
	}
	//ADD AT TAIL
	else{
		temp = *head;
		while(temp->next != NULL && temp->next->id < newNode->id){ 
			temp=temp->next;
		}
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
	}
	clear();
	printf(" Employee No. E%04d has been successfully added. \n", newNode->id);
	
}