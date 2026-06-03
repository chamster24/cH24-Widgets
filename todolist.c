#include <stdio.h>
#include <string.h>

#ifdef _WIN32
	#define PATH "userdata\\todo.txt"
#else
	#define PATH "userdata/todo.txt"
#endif

void updstr(char *dest, const char *src, size_t dest_size) {
    strncpy(dest, src, dest_size - 1); // Copy, leaving space for the null terminator
    dest[dest_size - 1] = '\0'; // Manually force the null terminator at the end
}

void fetchfile() { // Fetches the file 

	FILE *todolist; // Creates the file pointer
	todolist = fopen(PATH, "r"); // Fetches 
	if (todolist == NULL) {
		todolist = fopen(PATH, "a"); // Creates an empty todo list if it doesn't already exist
		if (todolist == NULL) { // Failed to write blank todo file
			SYS_STATUS = 100; // File Error

			char *tmp = realloc(ERR_DETAIL, 170 * sizeof(char));
			if (tmp == NULL) {
				strcpy(ERR_DETAIL, "OOM E100"); // TODO: upd to updstr
			} else {
				ERR_DETAIL = tmp;
				strcpy(ERR_DETAIL, "E100 - Failed to Failed to fetch/create file 'userdate\\todo.txt'.\n\nThis is likely due to a perms error/missing folder. \nTry adding it yourself and restarting this widget."); // TODO: upd to updstr
			};
			fclose(todolist);
			return;
		} else {
			fclose(todolist);
			return; // Created file
		};
	} else {
		return; // Fetched file
	};
};

struct savefile {

};



int main() {
	unsigned char SYS_STATUS = 1;
	char *ERR_DETAIL = malloc(11 * sizeof(char)); // max str size = 19, since it's leaving space for a null terminator
	unsigned ERR_DETAIL_SIZE = 11;
	if ((SYS_STATUS == 0) || (ERR_DETAIL == NULL) {
		printf("Program terminating - Ran out of memory before core processes initiated.");
	} else {
		SYS_STATUS = 0;
		updstr(ERR_DETAIL, "UNK_ERR", sizeof(ERR_DETAIL_SIZE));
	};
	
	while (1) { // todo: connect functions to main
		if (SYS_STATUS != 0) {
			printf("An error occured!\n\n The program is automatically quitting...\n\nDebug:\nError Code: %u\nError Info:%s\n", SYS_STATUS, ERR_DETAIL);
			return 1;
		};
	};
};
