#include <stdlib.h>
#define ONE_K (1024)
int main() 
{
	char *some_memory;
	char *scan_ptr;
	some_memory = (char *)malloc(ONE_K); // Получаем килобайт
	if (some_memory == NULL) exit(EXIT_FAILURE); // Если килобайт не получен
	scan_ptr = some_memory;
	while (1) 
	{
	*scan_ptr= '3';
	scan_ptr++;
	}
	exit(EXIT_SUCCESS);
}
