//Made by Rainier Francis Tomista with blood, sweat and tears (November-December 2015). 

//STRUCTURES

//DATE STRUCTURE
typedef struct{ //defines the structure of a date
	char strdate[10]; // STRING FORMAT (MM/DD/YYYY)
	int month; //contains the month of the date in decimal
	int day; //contains the day of the date in decimal
	int year; //contains the year of the date in decimal
}date;

//TIME STRUCTURE
typedef struct{ //defines the structure of a time
	char strtime[5]; //STRING FORMAT (HH:MM) MILITARY TIME
	int hours; //contains the hour of the time in decimal
	int minutes; //contains the minutes of the time in decimal
}rsvntime;

//EMPLOYEE NODE
typedef struct employee_data{ //defines the structure of a employee linked list node
	struct employee_data * prev; //node pointer that points to the previous node 
	int id, age; //holds the employee number and age of the employee
	char name[100], position[100]; //holds the name and position of the employee
	date dateHired; //contains the structure of a date 
	struct employee_data * next; //node pointer that points to the next node 
}employeeNode;

//APPOINTMENT NODE
typedef struct appointment_data{ //defines the structure of a appointment linked list node
	struct appointment_data * prev; //node pointer that points to the previous node 
	int appId, id; //holds the appointment number and employee number of assigned employee
	date reservationDate; //contains the structure of a reservation date 
	rsvntime reservationTime; //contains the structure of a reservation time
	char name[999]; //holds the name of the assigned employee
	struct appointment_data * next; //node pointer that points to the next node 
}appointmentNode;

