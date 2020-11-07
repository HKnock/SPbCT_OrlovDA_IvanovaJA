#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define A_MEGABYTE (1024 * 1024)
int main() 
{
	char *some_memory;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE;
	some_memory = (char*)malloc(megabyte); // Получение мегабайта
	if (some_memory != NULL) // Если память была получена, то это условие выполниться
	{
	sprintf(some_memory, "Hello World\n"); // Помещение в массив Hello World
	printf("%s", some_memory); // Вывод массива на экран
	exit_code = EXIT_SUCCESS; // Код успешного завершения программы
	}
	exit(exit_code);
}
