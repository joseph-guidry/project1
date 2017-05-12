#include <stdio.h>

#define MAX 10

void print_table(int x, int y, char format[]);
int check_number(char arg[]);
int myatoi(char arg[]);
void table_format(int min, int max);

int main(int argc, char *argv[])
{
	int start = 1, end = 10;
	if (argc == 2){
		if(check_number(argv[1]) == 0){
			end = myatoi(argv[1]);
			table_format(start, end);
		} else {
			printf("Arguement is not a number");
			return 0;
		}
	}
    if (argc < 2){
    	table_format(start, end);
    }
}

int check_number(char arg[])
{
	for(int i = 0; arg[i] != '\0' ; i++)
		if ((arg[i] < '0') || (arg[i] > '9'))
			return 1;
	return 0;
}
int myatoi(char arg[])
//Take arguement value. Return integer value. 
{
	int return_int = 0, i = 0;
	while( arg[i] >= '0' && arg[i] <= '9'){
		return_int = 10 * return_int + arg[i++] - '0';
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
	for (min; min <= max; min++){	
		printf("%3d ", min);	
		for(int x = 1; x <= max; x++){
			printf(format, x * min);
		}
		printf("\n");
	}
}
