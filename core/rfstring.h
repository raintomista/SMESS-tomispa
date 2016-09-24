//Made by Rainier Francis S. Tomista with love, blood, sweat and tears (November-December 2015). 
//USER DEFINED STRING MANIPULATION FUNCTIONS
#include <ctype.h>
#include <string.h>

//CHECK IF ALL OF THE CHARACTERS OF THE STRING ARE ALPHABET
int isstralpha(char input[100]){ //function name patterned with isalpha()
	int i, length, alphacnt = 0, spacecnt = 0; //initializes the values of the variables
	length = strlen(input); //gets the total number of characters in the string
	for(i=0;i<length;i++){ //traverses the entire string
		if(isalpha(input[i])!=0){ //checks if the character is an alpha
			alphacnt++; //counter will increase by one if the character is an alpha
		}
		else if(isspace(input[i])!=0){ //checks if the character is a whitespace character
			spacecnt++; //counter will increase by one if the character is a space
		}
	}
	if(alphacnt != 0 && alphacnt == length - spacecnt){ //checks if the counter (counts the number of the alphabetical characters in the string) is not zero and if it is equal to the the total number of the characters (minus the number of stirng)
		return 1; //return 1 (which means all the characters of the string are alphabets)
	}
	else{
		return 0;//then it will return 0 (which means not all the characters of the string are alphabet)
	}
}

//CHECK IF ALL OF THE CHARACTERS OF THE STRING ARE DIGITS
int isstrdigit(char input[100]){ //function name patterned with isdigit()
	int i, length, cnt=0;
	length = strlen(input); //gets the length of the string inputted by the user
	for(i=0;i<length;i++){ //traverses the entire string
		if(isdigit(input[i])!=0) cnt++; //if the character is a digit, the cnt will increase by 1
	}
	if(cnt!=0 && cnt == length){ //if all the characters of the string are digits, then it will 
		return 1; //return 1 (which means all the characters of the string are digits)
	}
	else{ //however, if atleast one character of the string is not a digit, 
		return 0; //then it will return 0 (which means not all the characters of the string are digits)
	} 
}

//CHECK IF TIME IS DIGIT
int isstrtimedigit	(int * index, char string[]){
	int length = strlen(string); int i; //variable initialization/declaration
	int cnt = 0, digitcnt = 0; //variable initialization/declaration

	*index = 0; //sets the index of the colon to zero
	for(i=0;i<length;i++){ //finds the colon in the string
		if(string[i] == ':'){
			*index = i; //saves the index of the string
			cnt++;
			break;
		}
	}

	for(i=0;i<length;i++){
		if(isdigit(string[i])!=0) digitcnt++; //if the character is a digit, the cnt will increase by 1
	}

	if(digitcnt !=0 && digitcnt == length-cnt){ //if all the characters of the string are digits and the digitcnt is equal to the length of the string minus the number of the colon
		return 1; //then it will return 1 (which means all the characters of the string are digits)
	}
	else{ //however, if atleast one character of the string is not a digit, 
		return 0; //then it will return 0 (which means not all the characters of the string are digits)
	} 
}



//LOWERCASE STRING FUNCTION
void tostrlower(char (*input)[100]){ //lowercases the entire string
	int i, length;  //initializes the variable that will be used
	length = strlen(*input); //gets the length of the string inputted by the user
	for(i=0;i<length;i++){  //traverses the entire string
		(*input)[i] = tolower((*input)[i]); //converts the every character to lowercase (to remove jejecase)
	}
}
//CAPITALIZE STRING FUNCTION
void capitalize(char (* input)[100]){ //removes jejemoncase and capitalizes the first letter of every word
	int i, length; //initializes the variable that will be used
	length = strlen(*input); //gets the length of the string inputted by the user
	for(i=0;i<length;i++){ //traverses the entire string
		(*input)[i] = tolower((*input)[i]); //converts the every character to lowercase (to remove jejecase)
	}

	//NOTE: I did not use tostrlower() since I cannot figure out why segfault occurs. 

	(*input)[0] = toupper((*input)[0]); //capitalizes the first character of the string
	
	for(i=0;i<length;i++){ //traverses the entire string
		if((*input)[i] == ' ' && (*input)[i]!='\0'){ //checks if the character is a whitespace character or a null terminator
			(*input)[i+1] = toupper((*input)[i+1]); //capitalizes the next character after the whitespace character
		}
	}
}

//STRING INPUT FUNCTION
void rfgets(char input[100], int size){ //modified fgets() which removes newline character at the end of the string.
	fgets(input,size,stdin); //gets the string (with or without space) inputted by the user 
	input[strlen(input)-1] = '\0'; //removes the newline character inputted by the user after pressing enter
}


	