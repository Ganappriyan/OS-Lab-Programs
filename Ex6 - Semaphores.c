#include <stdio.h>
#include <stdlib.h>
static int full, empty, mutex;
int buffer[5], in = 0, out = 0;
void wait(int *a);
void signal(int *b);
void producer()
{
  int nextp;
  printf("producer\n");
  wait(&empty);
  wait(&mutex);
  nextp = rand() % 10 + 1;
  buffer[in] = nextp;
  printf("produced item is %d\n", nextp);
  in = (in + 1) % 5;
  signal(&mutex);
  signal(&full);
  printf("full=%d\t empty=%d\n", full, empty);
}
void consumer()
{
  int nextc;
  printf("consumer\n");
  wait(&full);
  wait(&mutex);
  nextc = buffer[out];
  printf("consumerd item is %d\n", nextc);
  out = (out + 1) % 5;
  signal(&mutex);
  signal(&empty);
  printf("full=%d\t empty=%d\n", full, empty);
}
void wait(int *a)
{
  while (*a <= 0)
    ;
  *a = *a - 1;
}
void signal(int *b)
{
  *b = *b + 1;
}
int main()
{
  int c;
  mutex = 1;
  empty = 5;
  full = 0;
  while (1)
  {
    printf("1.producer\t 2.consumer\t 3.both\t 4.Exit\n");
    printf("choice\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
      if (empty == 0)
        printf("producer has to wait\n");
      else
      {
        producer();
      }
      break;
    case 2:
      if (full == 0)
        printf("consumer has to wait");
      else
      {
        consumer();
      }
      break;
    case 3:
      if (!empty)
      {
        printf("producer has to wait\n");
        consumer();
      }
      else if (!full)
      {
        printf("consumer has to wait\n");
        producer();
      }
      else
      {
        consumer();
        producer();
      }
      break;
    case 4:
      exit(0);
      break;
    }
  }
  return 0;
}
