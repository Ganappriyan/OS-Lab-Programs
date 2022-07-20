#include <stdio.h>

int main()
{
  int pid;
  printf("\n\n Fork Function Testing");
  printf("\n\n My Process ID=%d", getpid());
  printf("\n\n My Parent's ID=%d", getpid());
  if (pid == -1)
  {
    printf("\n\n Error occurred... \n Process cannot be created ");
  }
  if (pid != 0)
  {
    printf("\n\n Parent : My ID=%d", getpid());
    printf("\n\n My Parent ID=%d", getpid());
  }
  else
  {
    printf("\n\nChild : My ID=%d", getpid());
    printf("\n\n My Parents's ID=%d", getpid());
  }
  return 0;
}
