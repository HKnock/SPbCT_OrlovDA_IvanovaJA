#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#define M 10
#define N 5
static struct sigaction act1;
static struct sigaction act2;     
static struct sigaction act3;
int* viv = new int[M];
int* byit = new int[M];
char name[20] = "prob.txt";  
pid_t pid1, pid2, pid3;
FILE* f;
 
void func3(int signo) 
{
	act3.sa_handler=func3;      
	sigaction(SIGUSR1,&act3,0);
	printf("treti'i!\n");
	for(int i = 0;i < M;i++)
  {
    byit[i]=i;   
    fprintf(f,"%d\n",byit[i]);          
  }
	kill(pid1,SIGUSR1);             
	fclose(f);                       
 
}

void func2(int signo) 
{
   act2.sa_handler=func2;      
   sigaction(SIGUSR1,&act2,0);
   printf("vtoroy!\n");
   for(int i=0;i<M;i++)
  {
    byit[i]=i;   
    fprintf(f,"%d\n",byit[i]);         
  } 
   kill(pid3,SIGUSR1);             
}

void func1(int signo)        
 {
   act1.sa_handler=func1;
   sigaction(SIGUSR1,&act1,0);  
   f=fopen(name,"rb+");         
   printf("pervyi!\n");
   for(int i=0;i < M;i++)
   {                                                                
		fscanf(f,"%d",&viv[i]); 
		printf("%d\n",viv[i]);  
   }
 }
 
int main()
{
	f=fopen(name,"wb+");       
	act1.sa_handler=func1;
 
	pid2=fork();             
    if(pid2==0)    
	{
		act2.sa_handler=func2;   
		sigaction(SIGUSR1,&act2,0);   
		pid3 = fork();				
		if (pid3==0)
		{
			act3.sa_handler=func3;   
			sigaction(SIGUSR1,&act3,0);   
			sleep(2); 
		}
		if (pid3<0)
		{
			sleep(1);           
			printf("Cann't create process 3: error \n");	
			wait(&pid1);			
			printf("Process 2: end\n");
		}
	}
	return 0;
}
