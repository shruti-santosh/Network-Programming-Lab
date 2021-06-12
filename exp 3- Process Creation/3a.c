#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   int i=0,pid;
   pid=fork();
   if(pid==0)
   {
    printf("\nI am child, my id is %d and my parent is %d\n",getpid(),getppid());
   }
   else
   {
    printf("\nI am parent, my id is %d",getpid());
    printf("\nMy child is %d and my parent is %d\n",pid,getppid());
   }
   return 0;
}
