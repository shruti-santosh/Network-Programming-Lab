#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
   int i=0,pid1,pid2,pid3;
   pid1=fork();
   if(pid1==0)
   {   
       printf("\nI am child1, my id is %d and the id of my parent P1 is:%d\n",getpid(),getppid());
       pid2=fork();
       if(pid2==0)
       {
           printf("\nI am child2, my id is %d and the id of my parent P2 is: %d\n",getpid(),getppid());
           pid3=fork();
           if(pid3==0)
           { 
              printf("\nI am child3, my id is %d and the id of my parent P3 is: %d\n",getpid(),getppid());  
           }
           else
           {
                printf("\nI am parent P3 of child3, my id is %d and my child's id is:%d\n",getpid(),pid3);
           }
        }
        else
        {
           printf("\nI am parent P2 of child2, my id is %d and my child's id is:%d\n",getpid(),pid2);
       }
   }
   else
   {
    printf("\nI am root parent P(ppid), my id is:%d\n\n",getppid());
    printf("\nI am parent P1 of child1, my id is %d and my child's id is:%d\n",getpid(),pid1);
   }
   return 0;
}
