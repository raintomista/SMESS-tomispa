//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//VIEW EMPLOYEE OPERATION FUNCTIONS

//VIEW AN EMPLOYEE 
void viewAnEmployee(employeeNode * head, int * flag){
	employeeNode * temp = head;
	int input, employeeExists = 0;
	printf(" Enter employee number (e.g. E0069: E");
	scanf("%d",&input);
	getchar();
	while(temp != NULL){
		if(input == temp->id){
			clear();
			viewAnEmployeeLogo(0);
			printf("         Employee found!\n"); 
			emplData(temp);
			employeeExists++;
			enterToContinue();
			clear();
			*flag = 0;
			break;
		}
		temp = temp->next;
	}
	if(employeeExists == 0){
		clear();
		printf(" Employee No. E%04d not found.\n", input);
		*flag = 1;
	}
}

//VIEW ALL EMPLOYEE
void viewAllEmployee(employeeNode * head, int empl_cnt){
	employeeNode * temp = head;
	char name[30] = {'\0'}, position[25] = {'\0'};
	char emptyname[30], emptyposition[25];
	int i, length;
	int cnt = 0;
	emplTableHeader(); //prints the top of the table
	while(temp != NULL){
		length = strlen(temp->name);
		strcpy(name, emptyname);
		limitString(&name, temp, 30, 1); //limits the name to be displayed in the colum
		limitString(&position, temp, 25, 0); //limits the postion to be displayed in the column
		printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %02d/%02d/%04d ║\n", temp->id, name, temp->age, 	position, temp->dateHired.month,temp->dateHired.day,temp->dateHired.year);
		cnt ++;
		temp = temp->next;

		if(cnt < 5 && temp != NULL) emplTableBorder(); //kapag hindi pa 5 yung number ng row sa table maglalagay pa sya ng middle border
		
		if(cnt == 5 || temp == NULL){ //pero kapag 5 na yung rows, paglalagay na sya ng ending na border
			emplTableBottom();
			enterToContinue();
			cnt = 0;
			clear();
			viewAllEmployeeLogo(0); //iprprint nya yung headings
			if(temp!=NULL){ //kapag may susunod pa na node, iprprint nya yung table header
				emplTableHeader();
			}
		}
	}
	clear();
}



void viewByPosition(employeeNode * head, int employeecnt){
	employeeNode * temp = head;
	char ** array; int arraysize = 0, i,j;
	array = (char**)malloc(sizeof(char*)*employeecnt);
	char * strtemp = (char*)malloc(sizeof(char));
	char name[100], position[100];
	int choice;
	int isValid = 0;
	int totalcnt = 0, iterate = 0, limiter = 0;

	//checks if the position already exists in the array. if not it will be stored once
	while(temp != NULL){
		int positionExists = 0;
		for(j=0;j<arraysize;j++){
			if(strcmp(temp->position, array[j]) == 0){
				positionExists++;
			}
		}
		if(positionExists == 0){
			array[arraysize] = temp->position;
			arraysize+=1;
		}
		temp = temp->next;
	}


	//isosort nya yung position alphabetically
	for (i = 0; i < arraysize; i++) {
		int min = i; //yung unang element yng magiigng minimum
		for (j = i + 1; j < arraysize; j++) { //tapos itratraverse yung elements sa left nya
			if (strcmp(array[j],array[min]) < 0) { //kapag mas maliit yung element sa left nya, magswswap sila ng pwesto
				strtemp = array[min]; //iistore yung original na element sa tmp
				array[min] = array[j]; //tapos ililipat naman yung mas maliit na element dun sa pwesto ng min
				array[j] = strtemp; //tapos isstore sa original na pwesto ng maliit na element yung original na min 
			}
		}
	}

	//displays the view by position menu
	while(isValid != 1){
		totalcnt = 0;
		iterate = 0;
		limiter = 0;
		isValid = 0;
		for(j=0;j<i;j++){
		printf("                                       PRESS %d | %s\n",j+1,array[j]);
		}
		printf("                                       PRESS %d | Exit\n",j+1);
		getChoice(&choice);
		//checks if the choice is within the range
		if(choice >=1 && choice <=i){
			temp = head;
			//bibilangin kung ilan yung employee sa position na yun
			while(temp != NULL){
				if(strcmp(array[choice-1],temp->position) == 0) {
					totalcnt ++;
				}
				temp = temp->next;
			}

			temp = head;
			clear();
			viewByPositionLogo(0);
			//displays the table
			printf("         Employee/s (%s)\n", array[choice-1]);
			emplTableHeader(); 


			//hahanapin yung pinakahuling employee sa position na yun
			while(temp != NULL && iterate < totalcnt){
				if(strcmp(array[choice-1],temp->position) == 0) {
					limitString(&name, temp, 30, 1); //ililimit yung ididisplay na character sa column
					limitString(&position, temp, 25, 0); //ililimit yung ididisplay na character sa column
					printf("        ║ E%04d ║ %-30s ║ %-3d ║ %-25s ║ %02d/%02d/%04d ║\n", temp->id, name, temp->age, 	position, temp->dateHired.month,temp->dateHired.day,temp->dateHired.year);
					iterate++;
					limiter++;
					if(limiter < 5 && iterate != totalcnt) emplTableBorder(); //kapag hindi pa lima yung row, magprprint pa rin sya ng middle border
					else if(limiter == 5 && iterate != totalcnt){ //pero kapag lima na, maglalagay na ng bottom border tapos next screen na lalabas yung row na pang anim
						emplTableBottom();
						enterToContinue();
						limiter = 0;
						clear();
						viewByPositionLogo(0);
						if(iterate!=totalcnt){ //kapag hindi pa nareach yung huling employee sa position sa yun, pagprprint pa rin ng headings
							printf("         Employee/s (%s)\n", array[choice-1]);
							emplTableHeader();
						}
					}
				}
				temp = temp->next;
			}
			//kapag na reach na yung dulo iprprint na yung bottom border
			if(iterate == totalcnt){
				emplTableBottom();
				enterToContinue();
				limiter = 0;
				clear();
				viewByPositionLogo(0);
			}

			
		}
		else if(choice == i+1){ //exit
			clear();
			isValid = 1;
			return;
		}
		else {
			clear();
			printf(" Choice is out of range.\n");
			viewByPositionLogo(1);
		}
	}
}


//VIEW EMPLOYEE MENU
void viewEmployee(employeeNode * head, int empl_cnt){
	int choice = 0, flag = 0;
	clear();
	while(choice != 4){
		viewMenu(flag);
		getChoice(&choice);
		if(choice > 4){ //checks if the choice is out of range
			clear();
			printf(" Choice is out of range. Try again.\n");
			flag = 1;
		}
		switch(choice){
			case 1: //VIEW AN EMPLOYEE
				if(empl_cnt != 0){
					clear();
					viewAnEmployeeLogo(0);
					viewAnEmployee(head, &flag);
				}
				else{
					clear();
					printf(" Cannot view a specific employee. Employee directory is empty.\n");
					flag = 1;
				}
				break;
			case 2: //VIEW ALL EMPLOYEE
				if(empl_cnt != 0){
					clear();
					viewAllEmployeeLogo(0);
					viewAllEmployee(head, empl_cnt);
					flag = 0;
				}
				else{
					clear();
					printf(" Cannot view all employees. Employee directory is empty.\n");
					flag = 1;
				}
				break;
			case 3: //VIEW BY POSITION
				if(empl_cnt != 0){
					clear();
					viewByPositionLogo(0);	
					viewByPosition(head, empl_cnt);
					flag = 0;
				}
				else{
					clear();
					printf(" Cannot view employees by position. Employee duloirectory is empty.\n");
					flag = 1;
				}
				break;
			case 4: //EXIT
				clear();
				break;
		}
	}
}
