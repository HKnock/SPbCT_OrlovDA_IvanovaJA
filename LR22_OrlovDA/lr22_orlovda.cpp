#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{	
	int pid2, pid3, st, x = 8;
	FILE* f;
	f = fopen("./kekw.txt", "w");
	fprintf(f, "Изначальный х = %d\n", x);
	printf("Изначальный х = %d\n\n", x);
	fprintf(f, "Я Parent процесс, мой PID = %d\n", getpid());
	printf("Я Parent процесс, мой PID = %d\n", getpid());
	pid2 = fork();
	if (pid2 == 0) 
	{
		x -= 3;
		fprintf(f, "Я First_Child, мой родитель PARENT и мой PID = %d. X который я изменил = %d\n", getpid(), x);
		printf("Я First_Child, мой родитель PARENT и мой PID = %d. X который я изменил = %d\n", getpid(), x);
		pid3 = fork();
		if (pid3 == 0) 
		{
			x += 5;
			fprintf(f, "Я Second_Child, мой родитель FIRST_CHILD. Мой PID =  %d, Х который я изменил = %d\n", getpid(), x);
			printf("Я Second_Child, мой родитель FIRST_CHILD. Мой PID =  %d, Х который я изменил = %d\n", getpid(), x);
			sleep(5);
		}
		if (pid3 < 0) printf("Невозможно создать процесс 3: ошибка %d\n", pid3);
		sleep(2);
	}
	else 
	{
		fprintf(f, "Parent процесс завершил свою работу\n");
		printf("Parent процесс завершил свою работу\n");
	}
	if (pid2 < 0) printf("Невозможно создать процесс 2: ошибка %d\n", pid2);
	waitpid(&st, &pid3, NULL);
	return 0;
}
