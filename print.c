#include "print.h"
#include <stdio.h>

//function that displays the list
void display(int list[], int size)
{
  int i;
  printf("[");

  // navigate through all items
  for(i = 0;i<size;i++)
  {
    printf("%d ",list[i]);
  }

  printf("]\n");
}

//function to print data to a file
void printOut(FILE *fp, int data1, double data2)
{
  fprintf(fp, "%d %f\n",data1, data2);
}
