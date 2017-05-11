#include <stdio.h>

void print_table(int x, int y);

int main(int argc, char *argv[])
{
	int start, end;
	if (argc == 2){
		end = atoi(argv[1]);
	}
    if (argc < 2){
    	start = 1; end = 10;
    	print_table(start, end);
    }
}

void print_table(int min, int max)
{
	printf("%d %d\n", min, max);
	for (min; min <= max; min++){		
		for(int x = 1; x <= max; x++){
			printf(" %3d", x * min);
		}
		printf("\n");
	}
}
