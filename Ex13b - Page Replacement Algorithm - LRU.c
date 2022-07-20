#include <stdio.h>

int n, ref[100], fs, frame[100], count = 0;

void input()
{
  int i;
  printf("Enter the Frame Size: ");
  scanf("%d", &fs);
  printf("Total Page Faults: ");
  scanf("%d", &count);
  printf("Enter no of pages in Refrence String: ");
  scanf("%d", &n);
  printf("Enter the Reference String: ");
  for (i = 0; i < n; i++)
    scanf("%d", &ref[i]);
  printf("Enter the Frame Size: ");
  scanf("%d", &fs);
}

void cal()
{
  int i, j, k = 0, c1, c2[100], r, temp[100], t;
  frame[k] = ref[k];
  count++;
  k++;
  for (i = 1; i < n; i++)
  {
    c1 = 0;
    for (j = 0; j < fs; j++)
    {
      if (ref[i] != frame[j])
        c1++;
    }
    if (c1 == fs)
    {
      count++;
      if (k < fs)
      {
        frame[k] = ref[i];
        k++;
      }
      else
      {
        for (r = 0; r < fs; r++)
        {
          c2[r] = 0;
          for (j = i - 1; j < n; j--)
          {
            if (frame[r] != ref[j])
              c2[r]++;
            else
              break;
          }
        }
        for (r = 0; r < fs; r++)
          temp[r] = c2[r];
        for (r = 0; r < fs; r++)
        {
          for (j = r; j < fs; j++)
          {
            if (temp[r] < temp[j])
            {
              t = temp[r];
              temp[r] = temp[j];
              temp[j] = t;
            }
          }
        }
        for (r = 0; r < fs; r++)
        {
          if (c2[r] == temp[0])
            frame[r] = ref[i];
        }
      }
    }
  }
}

void show()
{
  printf("Page Faults = %d\n", count);
}

void main()
{
  printf("******* LRU Page Replacement Algo *******\n");
  input();
  cal();
  show();
}
