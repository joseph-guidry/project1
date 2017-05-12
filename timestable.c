/*
    Author: Joseph Guidry
    Date  : 12 May 2017
    
    Print out multiplication tables.
*/

#include <stdio.h>

#define MAX 10

void print_table(int x, int y, char format[]);
void print_header(int min, int max, char format[]);
int check_number(char arg[]);
int myatoi(char arg[]);
void table_format(int min, int max);

int main(int argc, char *argv[])
//Takes optional input from the command line.  
{
	int start = 1, end = 10;
	if (argc < 2){     //no command line arguements.
    	table_format(start, end);
    }
	if (argc == 2){    // only 1 command line arguement.
		if(check_number(argv[1]) == 0){
			end = myatoi(argv[1]);
			table_format(start, end);
		} else {
			printf("Arguement is not a number");
			return 0;
		}
	}
    if (argc > 2){    //Takes first two command line arguements
    	if((check_number(argv[1]) == 0) && (check_number(argv[2]) == 0)){
			start = myatoi(argv[1]);
			end = myatoi(argv[2]);
			table_format(start, end);
		} else {
			printf("Arguement is not a number");
			return 0;
		}
    }
}

int check_number(char arg[])
//Takes character array. Returns integer value.
{
	for(int i = 0; arg[i] != '\0' ; i++) {
		if ((arg[i] < '0') || (arg[i] > '9')) {
			return 1;  //If non-digit. 
		}
	}
	return 0;   // Successful check 
}
int myatoi(char arg[])
//Take char arguement value. Return integer value. 
{
	int return_int = 0, i = 0;
	while( arg[i] >= '0' && arg[i] <= '9'){
		return_int = 10 * return_int + arg[i++] - '0'; //Convert ASCII to INT.
	}
	return return_int;  
}
void table_format(int start, int end)
//Takes integers start and end as parameters. Calls print_table
{
		
	if (end < 32){
		char string[MAX] = "%3d ";
		print_table(start, end, string);
	} else if (end < 99){
		char string[MAX] = "%4d ";
		print_table(start, end, string);
	} else {
		char string[MAX] = "%5d ";
		print_table(start, end, string);
	}
}
void print_table(int min, int max, char format[])
//Takes the start and end values, with Formatting. Prints times tables.
{
	int x, hold = min;             //changed to hold min value on second for loop.
	print_header(min, max, format);
	for (min; min <= max; min++){	
		printf("%3d ", min);	   // Print left side header.
		for(x = hold; x <= max; x++){
			printf(format, x * min);
		}
		printf("\n");
		x = hold;                  //reset x to hold value
	}
}
void print_header(int min, int max, char format[])
//Takes two integers for width of the multiplication table.
{
    printf("%3c ", '*');
    for( int x = min; x <= max ; x++){
        printf(format, x);
    }
    printf("\n");
}
