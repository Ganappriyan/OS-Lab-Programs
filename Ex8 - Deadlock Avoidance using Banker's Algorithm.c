#include <stdio.h>
int main()
{
    int max[20], all[20], need[20], seq[20], avail, work, i, j = 0, d, m, n, e;
    printf("Enter no of process");
    scanf("%d", &n);
    printf("Enter max allocated resources to the process");
    for (i = 0; i < n; i++)
    {
        printf("max of p %d is", i);
        scanf("%d", &max[i]);
        printf("\nAllocation of p %d is", i);
        scanf("%d", &all[i]);
        need[i] = max[i] - all[i];
        printf("\nneed of p %d is : %d", i, need[i]);
    }
    printf("\nEnter available resources");
    scanf("%d", &avail);
    printf("\nMax allocation need \n");
    for (i = 0; i < n; i++)
        printf("%d %d %d", max[i], all[i], need[i]);
    m = d = n;
    e = m + 1;
    while (m > 0)
    {
        if (d == e)
            m = 0;
        else
        {
            d = e;
            e = 0;
            for (i = 0; i < n; i++)
                if ((need[i] > 0) && (need[i] <= avail))
                {
                    need[i] = 0;
                    work = all[i] + avail;
                    avail = work;
                    seq[j] = i;
                    m--;
                    j++;
                }
                else
                    e++;
        }
    }
    if (d == e)
        printf("\n an unsafe sequence");
    else
    {
        printf("\n safe sequence");
        printf("\nThe sequence of process is :");
        for (i = 0; i < n; i++)
            printf("p %d\t", seq[i]);
    }
}
