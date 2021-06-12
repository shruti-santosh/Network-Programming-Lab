#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{	
	int i;
	
	key_t key = ftok("/home/kj/NPLabPgm/ipcmemwrite.c",69);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	int *a=(int*) shmat(shmid,(void *) 0,0);
	
	printf("The shared memory id: %d",shmid);
	
	printf("\nEnter size of array:");
	scanf("%d",&a[0]);

	printf("\nEnter array elements:");
	for(i=1;i <= a[0];i++)
	{
		scanf("%d",&a[i]);
	}
	
	shmdt(a);
	return 0;
}

