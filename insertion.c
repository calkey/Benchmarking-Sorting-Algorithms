#include <stdio.h>
#include <stdbool.h>
void dInsertionSort(int list[], int size)
{
  int value;
  int position;
  int i;
  //loop through all numbers
  for(i = 1; i < size; i++)
  {
    //select a value to be inserted.
    value = list[i];
    //select the position where the element is to be inserted
    position = i;

    //check if previous element is larger than value to be inserted
    while (position > 0 && list[position-1] > value)
    {
      list[position] = list[position-1];
      position--;
      printf(" element moved : %d\n" , list[position]);
    }

    if(position != i)
    {
      printf(" element inserted : %d, at position : %d\n" , value,position);
      //insert the element at the position
      list[position] = value;
    }
    printf("Pass %d:",i);
    display(list, size);
    printf("\n");
  }
}

void bInsertionSort(int list[], int size)
{
  int value;
  int position;
  int i;

  //loop through all numbers
  for(i = 1; i < size; i++)
  {
    //select a value to be inserted.
    value = list[i];
    //select the position where the element is to be inserted
    position = i;

    //check if previous element is larger than value to be inserted
    while (position > 0 && list[position-1] > value)
    {
      list[position] = list[position-1];
      position--;
    }

    if(position != i)
    {
      //insert the element at the position
      list[position] = value;
    }
   }
}
