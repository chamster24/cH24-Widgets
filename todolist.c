#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
	#define PATH "userdata\\todo.txt"
#else
	#define PATH "userdata/todo.txt"
#endif

void updstr(char *dest, const char *src, size_t dest_size) {
    strncpy(dest, src, dest_size - 1); // Copy, leaving space for the null terminator
    dest[dest_size - 1] = '\0'; // Manually force the null terminator at the end
}

// SETUP STUFF
char ERR_DETAIL[3][256] = { // Max str size = 255 per line due to null terminator
	"0", // Err CODE
	"UNK_ERR",
	"No Extras" // Any Extras
}; // Will malloc inside main
// check the memory init INSIDE main


void fetchfile() { // Fetches the file 

	FILE *todolist; // Creates the file pointer
	todolist = fopen(PATH, "r"); // Fetches 
	if (todolist == NULL) {
		todolist = fopen(PATH, "a"); // Creates an empty todo list if it doesn't already exist
		if (todolist == NULL) { // Failed to write blank todo file
			strcpy(ERR_DETAIL[0], "100"); // Error Code 100 - File Error (Failed to read/write file)
			strcpy(ERR_DETAIL[1], "E100 - Failed to Failed to fetch/create file 'userdate\\todo.txt'.\n\nThis is likely due to a perms error/missing folder. \nTry adding it yourself and restarting this widget."); // 170 chars < max of 255
			return;
		} else {
			fclose(todolist);
			return; // Created file
		}
	} else {
		return; // Fetched file
	}
}

struct savefile {

};



int main() {
	// Checks if all variables have initiated/initialize extra variables, as previously mentioned
	if (ERR_DETAIL == NULL) {
		printf("Program terminating - Ran out of memory before core processes initiated.");
	} else {
		strcpy(ERR_DETAIL[0], "0");
	}
	
	while (1) { // TODO: connect functions to main
		if (strcmp(ERR_DETAIL[0], "0") != "0") {
			printf("An error occured!\n\n The program is automatically quitting...\n\nDebug:\nError Code: %s\nError Info:%s\n\nExtras:%s", ERR_DETAIL[0], ERR_DETAIL[1], ERR_DETAIL[2]);
			return 1;
		}
	}
};
