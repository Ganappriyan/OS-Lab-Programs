#include<stdio.h>

int main()
{
  int pid;
  printf("\n\nFork Function Testing");
  printf("\n\nMy Process ID = %d", getpid());
  printf("\n\nMy Parent's ID = %d", getpid());
  if(pid==-1)
  {
    printf("\n\nError occurred... \n Process cannot be created ");
  }
  if(pid!=0)
  {
    printf("\n\nParent : My ID = %d", getpid());
    printf("\n\nMy Parent ID = %d", getpid());
  }
  else
  {
    printf("\n\nChild : My ID = %d", getpid());
    printf("\n\nMy Parents's ID = %d", getpid());
  }
}
