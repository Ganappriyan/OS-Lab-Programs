#include <stdio.h>

int main()
{
    int bursttime[10][10], bt[10][10];
    int i, j, nop, k = 0, tq, sum = 0;
    float avg;
    printf("\nEnter the Number of processes:");
    scanf("%d", &nop);
    printf("\n\tEnter the time quantum;");
    scanf("%d", &tq);
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
        {
            bursttime[i][j] = 0;
            bt[i][j] = 0;
        }
    for (i = 0; i < nop; i++)
    {
        j = 0;
        printf("\n\tEnter the process time for process %d;", i + 1);
        scanf("%d", &bursttime[i][j]);
    }
    for (j = 0; j < 10; j++)
        for (i = 0; i < nop; i++)
        {
            bt[2 * j][i] = k;
            if ((bursttime[i][j] <= tq) && (bursttime[i][j] != 0))
            {
                k = k + bursttime[i][j];
                bt[2 * j + 1][i] = k;
            }
            else if (bursttime[i][j] != 0)
            {
                bursttime[i][j + 1] = bursttime[i][j] - tq;
                k = k + tq;
                bt[2 * j + 1][i] = k;
            }
            else
            {
                bt[2 * j][i] = 0;
                bt[2 * j + 1][i] = 0;
            }
        }
    for (i = 0; i < nop; i++)
        sum = sum + bt[0][i];
    for (i = 0; i < nop; i++)
        for (j = 1; j < 10; j++)
        {
            if ((bt[j][i] != 0) && (bt[j + 1][i] != 0) && ((j + 1) % 2 == 0))
            {
                sum = sum + ((bt[j + 1][i] - bt[j][i]));
            }
        }
    avg = (float)sum / nop;
    printf("\n\n\t\tAverage waiting time:%0.2f millisecs", avg);
    sum = avg = 0;
    for (j = 0; j < nop; j++)
    {
        i = 1;
        while (bt[i][j] != 0)
            i++;
        sum = sum + bt[i - 1][j];
    }
    avg = (float)sum / nop;
    printf("\n\n\t\tAverage Turnaround time: %0.2f ms\n", avg);
    return 0;
}
