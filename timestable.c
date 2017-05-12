/*
    Author: Joseph Guidry
    Date  : 12 May 2017
    
    Print out multiplication tables.
*/

#include <stdio.h>
#include <string.h>

#define MAX 10

void print_table(int x, int y, int z, char s[]);
void print_header(int x, int y, int z, char s[]);
int check_number(char s[]);
int myatoi(char s[]);
void table_format(int x, int y);

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
			printf("Arguement is not a valid number\n");
			return 0;
		}
	}
    if (argc > 2){    //Takes first two command line arguements
    	if((check_number(argv[1]) == 0) && (check_number(argv[2]) == 0)){
			start = myatoi(argv[1]);
			end = myatoi(argv[2]);
            if (start > end){
                printf("Error: MAX less than MIN\n");
                return 0;
            }
			table_format(start, end);
		} else {
			printf("Not all arguements is not a valid numbers\n");
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
//Takes integers start and end as parameters. Calls print_table.
{
    int offset = 0;
	if (end < 32){                      
        // For 3-digit integer multiples.
		char string[MAX] = " %3d";
		print_table(start, end, offset, string);
	} else if (end < 99){				
        // For up to 4-digit integer multiples.
		char string[MAX] = " %4d";
        offset = 1;  
		print_table(start, end, offset, string);
	} else {				
        // For up to 5-digit integer multiples.
		char string[MAX] = " %5d";
        offset = 2;
		print_table(start, end, offset, string);
	}
}
void print_table(int min, int max, int mod, char format[])
//Takes the start and end values, with Formatting. Prints times tables.
{
	int count, start, hold = min;         //changed to hold min value on second for loop.
	print_header(min, max, mod, format);
	for (start = min; start <= max; start++){	

        // Print left side header. Add Vertical Bar unicode char.
		printf("%3d %s", start, "\u2503"); 

		for(count = hold; count <= max; count++){
			printf(format, count * start);
		}
		printf("\n");
		count = hold;              //reset x to hold value
	}
}
void print_header(int min, int max, int mod, char format[])
//Takes two integers for width of the multiplication table.
{
    char horizontal_bar[] = "\u2501";
    printf("%3c %s", '*', "\u2503");    //Print first block with '*" and vertical bar.

    //Loop through numbers, min through max.
    for( int x = min; x <= max ; x++){  
        printf(format, x);
    }
    printf("\n");

    //Start horizontal line over table.
    for ( int x = 0; x < 4; x++){
        printf("%s", horizontal_bar);
    }

    //Unicode '+' character to connect lines.
    printf("%s", "\u254B"); 

    //Loop to print remaining horizontal line over table.  
    for (int x = 0; x < ((strlen(format) + mod ) * (max - min + 1)); x++){
         printf("%s", horizontal_bar);
    }
    printf("\n");
}
