#include "bubble.h"
#include <stdio.h>
#include <stdbool.h>
void dBubbleSort(int list[], int size)
{
  int temp;
  int i,j;
  bool swap = false;
  //loop through elements
  for(i = 0; i < size-1; i++)
  {
    swap = false;
    //loop through elements ignoring rightmost sorted element
    for(j = 0; j < size-1-i; j++)
    {
      printf("     Comparing: [ %d, %d ] ", list[j],list[j+1]);
      //Check if the current element is greater than the next element
      //if greater, swap elements
      if(list[j] > list[j+1])
      {
        //swap the elements
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;

        swap = true; //boolean set to true to keep the for loop running

        printf("   Swapping: [%d, %d]\n",list[j],list[j+1]);
      }
      else
      {
        printf("   No swap\n");
      }
    }
    //Sort is finished if no swaps are made
    if(!swap)
    {
      printf("\nNo swaps made so list is sorted\n");
      break;
    }
    printf("Pass %d: ",(i+1));
    display(list, size);
  }
}



void bBubbleSort(int list[], int size)
{
  int temp;
  int i,j;
  bool swap = false;
  // loop through all elements
  for(i = 0; i < size-1; i++)
  {
    swap = false;
    //loop through elements ignoring rightmost sorted element
    for(j = 0; j < size-1-i; j++)
    {
      //Check if the current element is greater than the next element
      //if greater, swap elements
      if(list[j] > list[j+1])
      {
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;

        swap = true; //boolean set to true to keep the for loop running
      }
    }

    //Sort is finished if no swaps are made
    if(!swap)
    {
      break;
    }
  }
}
