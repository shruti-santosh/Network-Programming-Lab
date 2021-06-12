#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pipefd1[2],pipefd2[2];
    int pid,P1,P2;
    char pipewrite[30],piperead[30];
    
    P1=pipe(pipefd1);
    if( P1 == -1)
    {
        printf("\nFailed to create pipe 1");
        exit(1);
    }
    P2=pipe(pipefd2);
    if( P2 == -1)
    {
        printf("\nFailed to create pipe 2");
        exit(1);
    }
    
    pid = fork();
    
    if(pid==0)
    {
     close(pipefd1[1]);     // close write end of pipe 1
     close(pipefd2[0]);     // close read end of pipe 2
     read(pipefd1[0],piperead,sizeof(piperead));
     printf("\nI am child, I am reading from parent through pipe 1\nIncoming message:");
     fputs(piperead,stdout);
     printf("\nI am child, I am writing to pipe 2 \nEnter message:");
     fgets(pipewrite,30,stdin);
     write(pipefd2[1],pipewrite,sizeof(pipewrite));
    }
    else
    {
     close(pipefd1[0]);     // close read end of pipe 1
     close(pipefd2[1]);     // close write end of pipe 2
     printf("\nI am parent, I am writing to pipe 1 \nEnter message:");
     fgets(pipewrite,30,stdin);
     write(pipefd1[1],pipewrite,sizeof(pipewrite));
     read(pipefd2[0],piperead,sizeof(piperead));
     printf("\nI am parent, I am reading from child through pipe 2\nIncoming message:");
     fputs(piperead,stdout);
    }
    
    return 0;
}    
