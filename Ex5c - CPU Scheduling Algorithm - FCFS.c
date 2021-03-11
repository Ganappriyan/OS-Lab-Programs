#include<stdio.h>

int main()
{
  int nop, wt = 0, tat = 0, i, bt[10];
  float totwt = 0.0, tottat = 0.0, avgwt = 0.0, avgtat = 0.0;
  printf("\nEnter the number of process: ");
  scanf("%d", &nop);
  for(i=1; i<=nop; i++)
  {
    printf("\nEnter the burst time for the process %d in msecs: ", i);
    scanf("%d", &bt[i]);
  }
  for(i=0; i<nop; i++)
  {
    bt[0] = 0;
    wt += bt[i];
    totwt += wt;
  }
  printf("\n\nTotal waiting time: %0.2f ms", totwt);
  avgwt = (float)totwt / (float)nop;
  printf("\nAverage waiting time:%0.2f ms", avgwt);
  for(i=0; i<=nop; i++)
  {
    tat += bt[i];
    tottat += tat;
  }
  printf("\n\nTotal Turn around time: %0.2f ms", tottat);
  avgtat = (float)tottat / (float)nop;
  printf("\nAverage Turn around time: %0.2f ms", avgtat);
  return 0;
}
