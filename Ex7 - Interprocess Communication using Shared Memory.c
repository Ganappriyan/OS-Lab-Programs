#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
  int child, shmid, i;
  char * shmptr;
  child = fork();
  if(!child)
  {
    shmid = shmget(2041,32,0666 | IPC-CREAT);
    shmptr = shmat(shmid, 0, 0);
    printf("\nParent Writing \n");
    for(i=0;i<10;i++)
    {
      shmptr[i] = 'a' + i;
      putchar(shmptr[i]);
    }
    printf("\n\n%s", shmptr);
    wait(NULL);
  }
  else
  {
    shmid=shmget(2041,32,0666);
    shmptr=shmat(shmid,0,0);
    printf("\n CHILD IS READING:");
    for(i=0;i<10;i++)
    putchar(shmptr[i]);
    shmdt(NULL);
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}
