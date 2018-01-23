#include "quick.h"
#include <stdio.h>
#include <stdbool.h>


void swap(int list[], int firstNum, int secondNum)
{
   int temp = list[firstNum];
   list[firstNum] = list[secondNum];
   list[secondNum] = temp;
}

int dPartition(int list[], int left, int right, int pivot, int size)
{
   int leftPointer = left -1;
   int rightPointer = right;
   printf("    Pivots : [%d,%d", list[leftPointer],list[right]);
   printf("]\n");
   while(true)
   {
      while(list[++leftPointer] < pivot)
      {
        //Nothing
      }

      while(rightPointer > 0 && list[--rightPointer] > pivot)
      {
        //Nothing
      }

      if(leftPointer >= rightPointer)
      {
         break;
      }
      else
      {
         printf("    Values swapped : [%d,%d", list[leftPointer],list[rightPointer]);
         printf("]\n");
         swap(list,leftPointer,rightPointer);
      }
   }

   swap(list,leftPointer,right);
   printf("Updated list: ");
   display(list, size);
   return leftPointer;
}

void dQuickSort(int list[], int left, int right, int size)
{
   if(right-left <= 0)
   {
      return;
   }
   else
   {
      int pivot = list[right];
      int position = dPartition(list, left, right, pivot,size);
      dQuickSort(list,left,position-1, size);
      dQuickSort(list,position+1,right, size);
   }
}



int bPartition(int list[], int left, int right, int pivot, int size)
{
   int leftPointer = left -1;
   int rightPointer = right;

   while(true)
   {
      while(list[++leftPointer] < pivot)
      {

      }

      while(rightPointer > 0 && list[--rightPointer] > pivot)
      {

      }

      if(leftPointer >= rightPointer)
      {
         break;
      }
      else
      {

         swap(list,leftPointer,rightPointer);
      }
   }


   swap(list,leftPointer,right);


   return leftPointer;
}

void bQuickSort(int list[], int left, int right, int size)
{
   if(right-left <= 0)
   {
      return;
   }
   else
   {
      int pivot = list[right];
      int position = bPartition(list, left, right, pivot,size);
      bQuickSort(list,left,position-1, size);
      bQuickSort(list,position+1,right, size);
   }
}
