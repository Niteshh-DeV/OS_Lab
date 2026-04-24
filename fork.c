#include<stdio.h>
#include<unistd.h>
int main()
{
printf("Before FORK \n");
fork();
fork();
printf("After FORK \n\n");
}