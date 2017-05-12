/*
    Author: Joseph Guidry
    Date  : 12 May 2017
    
    Print out multiplication tables.
*/

#include <stdio.h>
#include <string.h>

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
//Takes integers start and end as parameters. Calls print_table.
{
		
	if (end < 32){                      
        // For 3-digit integer multiples.
		char string[MAX] = "%3d ";
		print_table(start, end, string);
	} else if (end < 99){				
        // For up to 4-digit integer multiples.
		char string[MAX] = "%3d ";	   
		print_table(start, end, string);
	} else {				
        // For up to 5-digit integer multiples.
		char string[MAX] = "%5d ";
		print_table(start, end, string);
	}
}
void print_table(int min, int max, char format[])
//Takes the start and end values, with Formatting. Prints times tables.
{
	int x, hold = min;         //changed to hold min value on second for loop.
	print_header(min, max, format);
	for (min; min <= max; min++){	

        // Print left side header. Add Vertical Bar unicode char.
		printf("%3d %s", min, "\u2503"); 

		for(x = hold; x <= max; x++){
			printf(format, x * min);
		}
		printf("\n");
		x = hold;              //reset x to hold value
	}
}
void print_header(int min, int max, char format[])
//Takes two integers for width of the multiplication table.
{
    char horizontal_bar[] = "\u2501";
    printf("%3c %s", '*', "\u2503");
    for( int x = min; x <= max ; x++){
        printf(format, x);
    }
    printf("\n");
    //Start horizontal line over table.
    for ( int x = 0; x < 4; x++){
        printf("%s", horizontal_bar);
    }
    printf("%s", "\u254B"); //Unicode '+' character to connect lines.
    //Loop to print remaining horizontal line over table.
    for (int x = 5; x < (strlen(format) * (max - min + 1)) + 4; x++){
         printf("%s", horizontal_bar);
    }
    printf("\n");

}
