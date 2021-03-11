#include<stdio.h>

int main()
{
  int nop, i, j, t;
  int bt[10], wt = 0, tat = 0;
  float totwt = 0.0, tottat = 0.0, avgwt = 0.0, avgtat = 0.0;
  printf("\nEnter the number of processes: ");
  scanf("%d", &nop);
  for(i=1; i<=nop; i++)
  {
    printf("\nEnter the burst time for process %d in ms: ", i);
    scanf("%d", &bt[i]);
  }
  for(i=1; i<=nop; i++)
  {
    for(j=1; j<=nop; j++)
    {
      if(bt[i] < bt[j])
      {
        t = bt[i];
        bt[i] = bt[j];
        bt[j] = t;
      }
    }
  }
  for(i=0; i<nop; i++)
  {
    bt[0] = 0;
    wt += bt[i];
    totwt += wt;
  }
  printf("\nTotal waiting time: %0.2f ms", totwt);
  avgwt = (float)totwt / (float)nop;
  printf("\nAverage waiting time: %0.2f ms", avgwt);
  for(i=1; i<=nop; i++)
  {
    tat += bt[i];
    tottat += tat;
  }
  printf("\n\nTotal turn around time: %0.2f ms", tottat);
  avgtat = (float)tottat / (float)nop;
  printf("\nAverage Turn around time: %0.2f ms", avgtat);
  return 0;
}
