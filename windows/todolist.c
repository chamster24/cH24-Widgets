#include <stdio.h>
#include <string.h>

void fetchfile() { // Fetches the file 

	FILE *todolist; // Creates the file pointer
	todolist = fopen("userdata\\todo.txt", "r"); // Fetches 
	if (todolist == NULL) {
		todolist = fopen("userdata\\todo.txt", "a"); // Creates an empty todo list if it doesn't already exist
		fclose(todolist);

		if (todolist == NULL) { // Failed to write blank todo file
			printf("Error fetch2\n----------\nFailed to fetch/create file 'userdate\\todo.txt'. This is likely due to a perms error/missing folder. Try adding it yourself and restarting this widget.\n")
			STATUS = 1; // General error
			return;
		} else {
			return; // Created file
		};
	} else {
		return; // Fetched file
	};
};

struct savefile {

};



int main() {
	unsigned char SYS_STATUS;
	
	while (1) {
		if (SYS_STATUS != 0) {
			printf("An error occured! The program is automatically quitting...")
			return 1;
		};
	};
};
