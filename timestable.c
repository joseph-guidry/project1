#include <stdio.h>
#include <string.h>

#define MAX 20

void print_table(int x, int y, char format[]);
int check_number(char arg[]);
int myatoi(char arg[]);
void table_format(int min, int max, char format[]);

int main(int argc, char *argv[])
{
	int start = 1, end = 10;
	if (argc == 2){
		if(check_number(argv[1]) == 0){
			end = myatoi(argv[1]);
		} else {
			printf("Arguement is not a number");
			return 0;
		}
	}	
	if (argc < 2){
    	char string[MAX] = "%3d "; 
    	print_table(start, end, string);
    }
}

void print_table(int min, int max, char format[])
//Takes the start and end values, with Formatting. Prints times tables.
{
	for(min; min <= max; min++){		
		for(int x = 1; x <= max; x++){
			printf(format, x * min);
		}
		printf("\n");
	}
}

int check_number(char arg[])
//Take in first arguement.  Return integer. 
{
	for(int i = 0; arg[i] != '\0' ; i++){
		if ((arg[i] < '0') || (arg[i] > '9')){
			return 1;
		}
	}
	return 0;
}

int myatoi(char arg[])
//Take arguement value. Return integer value. 
{
	//check if character array is all numbers.
	//if yes, convert to integer
	//return arg
	printf("In myatoi Function");
	return 1;
}
