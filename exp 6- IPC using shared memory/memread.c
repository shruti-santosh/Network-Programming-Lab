#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
	int i,j,temp;
	
	key_t key = ftok("/home/kj/NPLabPgm/ipcmemwrite.c",69);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	int *a=(int*) shmat(shmid,(void *) 0,0);
	
	printf("The shared memory id: %d",shmid);
	
	printf("\nThe array elements of write process are:");
	for(i=1;i <= a[0];i++)
	{
		printf("%d ",a[i]);
	}
	
	for(i=1;i <= a[0];i++) 
	{
    	for(j=i+1;j <= a[0]; j++)
        {
        	if (a[i]>a[j]) 
            {
            	temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
   
   printf("\nThe sorted array elements of write process are:");
   for(i=1;i <= a[0];i++)
   {
		printf("%d ",a[i]);
   }

	shmdt(a);
	shmctl(shmid,IPC_RMID,NULL);
	printf("\n");
	return 0;
}

