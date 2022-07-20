#include <stdio.h>

struct pstruct
{
  int fno;
  int pbit;
} ptable[10];
int pmsize, lmsize, psize, frame, page, ftable[20], frameno;

void info()
{
  printf("Memory Management Using Paging:-");
  printf("\n\nEnter the Size of Physical Memory: ");
  scanf("%d", &pmsize);
  printf("Enter the Size of Logical Memory: ");
  scanf("%d", &lmsize);
  printf("Enter the Partition Size: ");
  scanf("%d", &psize);
  frame = (int)pmsize / psize;
  page = (int)lmsize / psize;
  printf("\nThe Physical memory is divided into %d no.of frames", frame);
  printf("\nThe Logical memory is divided into %d no.of pages\n\n", page);
}

void assign()
{
  int i;
  for (i = 0; i < page; i++)
  {
    ptable[i].fno = -1;
    ptable[i].pbit = -1;
  }
  for (i = 0; i < frame; i++)
    ftable[i] = 32555;
  for (i = 0; i < page; i++)
  {
    printf("Enter the Frame number where page %d must be placed: ", i);
    scanf("%d", &frameno);
    ftable[frameno] = i;
    if (ptable[i].pbit == -1)
    {
      ptable[i].fno = frameno;
      ptable[i].pbit = 1;
    }
  }
  printf("\n\n\t\tPage Table:-");
  printf("\n\nPage Address   Frame No   Presence Bit\n");
  for (i = 0; i < page; i++)
    printf("  %d\t\t%d\t\t%d\n", i, ptable[i].fno, ptable[i].pbit);
  printf("\n\n\tFrame Table:-");
  printf("\n\nFrame Address   Page No\n\n");
  for (i = 0; i < frame; i++)
    printf("  %d\t\t%d\n", i, ftable[i]);
}

void cphyaddr()
{
  int laddr, paddr, disp, phyaddr, baddr;
  printf("\n\nProcess to Create the Physical Address:-");
  printf("\n\nEnter the Base Address: ");
  scanf("%d", &baddr);
  printf("Enter the Logical Address: ");
  scanf("%d", &laddr);
  paddr = laddr / psize;
  disp = laddr % psize;
  if (ptable[paddr].pbit == 1)
    phyaddr = baddr + (ptable[paddr].fno * psize) + disp;
  printf("\nThe Physical Address where the Instruction Present: %d\n", phyaddr);
}

void main()
{
  info();
  assign();
  cphyaddr();
}
