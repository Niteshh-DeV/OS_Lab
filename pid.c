#include<stdio.h>
#include<unistd.h>
int main()
{
printf("\n Parent Process ID %d",getppid());
printf("\n Child Process ID %d\n",getpid());
}