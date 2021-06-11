#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100
struct mesg_buffer
{
long mesg_type;
char mesg_text[1000];
}message1,message2;
int main()
{
message1.mesg_type = 1;
key_t key = ftok("ipcchatwrite.c",25);
int msgid = msgget(key,0666|IPC_CREAT);
while(1)
{
printf("\nWrite message to process 2: ");
fgets(message1.mesg_text,MAX,stdin);
msgsnd(msgid,&message1,sizeof(message1),0);

msgrcv(msgid,&message2,sizeof(message2),1,0);
printf("\nMessage received from process 2: %s", message2.mesg_text);
getchar();
}
msgctl(msgid,IPC_RMID,NULL);
return 0;
}

