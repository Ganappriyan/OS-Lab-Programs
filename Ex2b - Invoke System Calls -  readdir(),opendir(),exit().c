#include<stdio.h>
#include<dirent.h>

struct dirent *dptr;
int main(int argc, char *argv[])
{
  char buff[256];
  DIR *dirp;
  printf("\n\nEnter directory Name: ");
  scanf("%s", buff);
  if((dirp = opendir(buff))==NULL)
  {
    printf("Error");
    exit(1);
  }
  while(dptr = readdir(dirp))
  {
    printf("%s\n", dptr->d_name);
  }
  closedir(dirp);
}
