#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main() 
{
	char *some_memory = (char*)0;
	printf("A read from null %s\n", some_memory);
	sprintf(some_memory, "A write to null\n"); // Записываем в массив фразу
	printf("%s", some_memory);
	exit(EXIT_SUCCESS);
}
