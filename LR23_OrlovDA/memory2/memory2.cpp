#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define A_MEGABYTE (1024 * 1024 * 1024)
#define PHY_MEM_MEGS 2048
int main() 
{
char *some_memory;
size_t size_to_allocate = A_MEGABYTE;
int megs_obtained = 0;
while (megs_obtained < (PHY_MEM_MEGS * 2)) // Выполнять пока меньше физической памяти * 2
{
	some_memory = (char *)malloc(size_to_allocate); // Получаем мегабайт
	if (some_memory != NULL) // Выполняется если мегабайт был получен
	{
		megs_obtained++; // Получено мегабайт
		sprintf(some_memory, "Hello World"); // Помещаем фразу Hello World в массив
		printf("%s —now allocated %d Megabytes\n", some_memory, megs_obtained); // Вывод на экран
	} 
	else 
	{
		exit(EXIT_FAILURE);
	}
}
	exit(EXIT_SUCCESS);
}
