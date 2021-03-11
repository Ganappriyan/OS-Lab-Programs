#include<stdio.h>
#include<stdlib.h>

static int full, empty, mutex;
int buffer[5], in = 0, out = 0;

void wait(int *a)
{
  while(*a<=0);
  *a = *a-1;
}

void signal(int *b)
{
  *b = *b+1;
}

void producer()
{
  int nextp;
  printf("Producer\n");
  wait(&empty);
  wait(&mutex);
  nextp=rand()%10+1;
  buffer[in]=nextp;
  printf("Produced item is %d\n", nextp);
  in = (in+1)%5;
  signal(&mutex);
  signal(&full);
  printf("Full = %d\tEmpty = %d\n", full, empty);
}

void consumer()
{
  int nextc;
  printf("consumer\n");
  wait(&full);
  wait(&mutex);
  nextc = buffer[out];
  printf("Consumerd item is %d\n", nextc);
  out = (out+1)%5;
  signal(&mutex);
  signal(&empty);
  printf("Full = %d\t Empty = %d\n", full, empty);
}

int main()
{
  int c;
  mutex = 1;
  empty = 5;
  full = 0;
  while(1)
  {
    printf("\n1. Producer\t2. Consumer\t3. Both\t4. Exit\n");
    printf("Choice: ");
    scanf("%d", &c);
    switch(c)
    {
      case 1:
        if(empty==0)
          printf("Producer has to wait\n");
        else
          producer();
        break;
      case 2:
        if(full==0)
          printf("Consumer has to wait\n");
        else
          consumer();
        break;
      case 3:
        if(!empty)
        {
          printf("Producer has to wait\n");
          consumer();
        }
        else if(!full)
        {
          printf("Consumer has to wait\n");
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
