#include<dirent.h>
#include<stdio.h>

int main()
{
  struct dirent **namelist;
  int n,i;
  char pathname[100];
  getcwd(pathname);
  n = scandir(pathname,&namelist,0,alphasort);
  if(n<0)
  printf("Error");
  else
  {
    for(i=0; i<n; i++)
      printf("%s\n", namelist[i]->d_name);
  }
}
