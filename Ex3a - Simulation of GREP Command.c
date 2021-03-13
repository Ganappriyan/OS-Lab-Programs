#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
void usage()
{
  printf("usage:\t grep filename pattern\n");
  printf("example:grep grep.c int\n");
}
int main(int argc, char *argv[])
{
  FILE *fp;
  char fline[max];
  char *newline = 0;
  int count = 0;
  int occurences = 0;
  if (argc != 3)
  {
    usage();
    exit(1);
  }
  if (!(fp = fopen(argv[1], "r")))
  {
    printf("grep:could not openfile:%s\n", argv[1]);
    exit(1);
  }
  while (fgets(fline, max, fp) != NULL)
  {
    count++;
    if (newline = strchr(fline, '\n'))
      *newline = '\0';
    if (strstr(fline, argv[2]) != NULL)
    {
      printf("%s%d%s\n", argv[1], count, fline);
      occurences++;
    }
  }
  return 0;
}
