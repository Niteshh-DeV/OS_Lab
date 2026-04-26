#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
pid=fork();
if(pid>0)
{
printf("From Parent \n");
printf("Parent process id %d\n",getpid());
}
else
{
printf("From Child \n");
printf("Child process id %d\n",getpid());
}
}