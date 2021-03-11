#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
  int fd, fd1, r;
  char buf[50], c;
  switch(argc)
  {
    case 1:
      printf("Error:No arguments!**!");
      return 1;
    case 2:
      printf("Error:Too few arguments for mycp command!**!");
      return 1;
    case 3:
      if(strcmp(argv[1], "-i") == 0)
      {
        printf("Error: Too few arguments for mycp command!**!");
        return 1;
      }
      fd = open(argv[1], 0, 00777);
      if(fd == -1)
      {
        printf("Error:No source file!**!");
        return 1;
      }
      fd1 = creat(argv[2], 00777);
      while((r = read(fd, buf, 1)) > 0)
        write(fd1, buf, 1);
      break;
    case 4:
      if(strcmp(argv[1], "-i") == 0)
      {
        fd = open(argv[2], 0, 00777);
        if(fd == -1)
        {
          printf("Error:No source file!**!");
          return 1;
        }
        fd1 = open(argv[3], 0, 00777);
        if(fd1 > 0)
        {
          printf("mycp: overwrite '%s' (y/n)....: ", argv[3]);
          scanf("%c", &c);
          if(c == 'y')
          {
            fd1 = creat(argv[3], 00777);
            while((r = read(fd, buf, 1)) > 0)
              write(fd1, buf, 1);
          }
        }
        else if(fd1 == -1)
        {
          fd1 = creat(argv[3], 00777);
          while((r = read(fd, buf, 1)) > 0)
          write(fd1, buf, 1);
        }
      }
      break;
    default:
      printf("Error:Excess arguments supplied!**!");
      break;
  }
  return 0;
}
