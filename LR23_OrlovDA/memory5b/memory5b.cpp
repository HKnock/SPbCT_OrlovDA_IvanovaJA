#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() 
{
	char z = *(const char *)0;
	printf("I read from location zero %d\n", z);
	exit(EXIT_SUCCESS);
}
