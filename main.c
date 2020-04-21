#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int usercount = 0;
int main(){
	Record records[MAX_RECORDS];
	char user_input[64] = "";
	usercount = loadUsers(records);
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}

// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){
		// TODO: Modify this function as you need
	if(!strcmp(input, "1")){
		createUsers(records,usercount);
		usercount++;
	}
	else if(!strcmp(input, "2"))
		print_all_records(records,usercount);

	else if(!strcmp(input, "3"))
		updateUserInfo(records,usercount);

	else if(!strcmp(input, "4")){
		deleteUser(records,usercount);
		usercount--;
	}
	else if(!strcmp(input, "5"))
		searchUser(records,usercount);
	else if(!strcmp(input, "6"))
		saveUsers(records,usercount);
	else if(!strcmp(input, "7"))
		sortUserList(records,usercount);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}

// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Game User management system \n");
	printf("******************************\n");
	printf(" 1. Add a new User\n"); //*
	printf(" 2. Print all users\n"); //*
	printf(" 3. Update User information\n");
	printf(" 4. Delete a User\n");
	printf(" 5. Search (ID/age/address)\n"); //--
	printf(" 6. Save to a data file\n"); //*
	printf(" 7. Sort\n"); //-
	printf(" 99. Quit\n");

}
