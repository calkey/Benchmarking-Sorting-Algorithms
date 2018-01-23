#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>




//#define ARRAY_SIZE 10
//int list[ARRAY_SIZE] = {82,15,51,86,74,19,18,14,49,22};



int* list;

int* generateArray(int arraySize)
{
  int i;
  int* list=(int*)calloc(arraySize,sizeof(int)); //initialise array
  srand(time(NULL)); //seed rand with time to get different integers each time

  //fill array with random ints between 1 and 100, Size of array will be the array size that the user inputs
  for(i=0; i<arraySize; i++)
  {
    list[i]= rand() % 100 + 1;
  }
  return list;
}



//selects which sort to run based on user input
void preference(int amountOfArrays, int arraySize, char sortInput, char testInput)
{
  int j;
  //'amountOfArrays' is an int given by the user - this is the amount of arrays to sort through
  for(j=0; j<amountOfArrays; j++)

    list = generateArray(arraySize);
    if(sortInput=='b')
    {
        if(testInput == 'd')
        {
          //call the functions that prints out and shows steps of sort
          printf("Initial list: ");
          display(list, arraySize);
          printf("\n");

          dBubbleSort(list, arraySize);
          printf("\nSorted list: ");
          display(list, arraySize);
        }
        else if(testInput == 't'||'w')
        {
          //call the benchmarking sort
          bBubbleSort(list, arraySize);
        }
    }
    else if(sortInput=='q')
    {
        if(testInput=='d')
        {
          //call the functions that prints out and shows steps of sort
          printf("Initial list: ");
          display(list, arraySize);

          dQuickSort(list,0,arraySize-1,arraySize);
          printf("\nSorted list: ");
          display(list, arraySize);

        }
        else if(testInput=='t'||'w')
        {
          //call the benchmarking sort
          bQuickSort(list,0,arraySize-1,arraySize);
        }
    }
    else if(sortInput=='i')
    {
      if(testInput=='d')
      {
        //call the functions that prints out and shows steps of sort
        printf("Initial list: ");
        display(list, arraySize);
        dInsertionSort(list, arraySize);
        printf("\nSorted list: ");
        display(list, arraySize);
      }
      else if(testInput == 't'||'w')
      {
        //call the benchmarking sort
        bInsertionSort(list, arraySize);
      }
    }

}

int main( int argc, char **argv )
{

  bool write=false; //boolean that determines weather or not to write to a file

  //arraySize is the size of the array//
  //i and j are used for for amountOfArrays//
  //'amountOfArrays' is the amount of arrays to sort through//
  int arraySize, i, amountOfArrays, j;

  //values for the total time of sorts and the mean time of sorts
  double totalTime, meanTime;

  //testInput determines which test to preform//
  //sortInput determines which sort to use//
  char testInput, sortInput;

  printf("Bubble, Quick or Insertion?: 'b', 'q' or 'i'\n");
  //user input determines which sort to use
  if(scanf(" %c",&sortInput) !=1)
  {
    printf("\nRead error");
  }


  //user input determines which method to use
  printf("Test, Write or Demonstration: 't', 'w' or 'd'\n");
  if(scanf(" %c",&testInput) !=1)
  {
    printf("\nRead error");
  }

  //t indicates Test - this will output the total time and mean time of the sort
  if(testInput=='t')
  {
    //prompt user for the size of the array
    printf("Enter size of array\n");
    if(scanf(" %d",&arraySize) !=1)
    {
      printf("\nRead error");
      return 0;
    }

    //prompt user for the amount of lists to sort
    printf("Enter number of lists to sort\n");
    if(scanf(" %d",&amountOfArrays)!=1)
    {
      printf("\nRead error");
    }
  }

  //d indicates demonstration - this will print out each step that the sort does
  //to demonstrate how the sort works
  else if(testInput=='d')
  {

    arraySize = 10; //demonstration will be an array of size 10
    amountOfArrays = 1;  //amountOfArrays set to 1 - this means only one list will be sorted and displayed
  }

  //w indicates write - this will print the output to a file
  else if(testInput=='w')
  {
    write = true; //we will write to file so 'write' boolean set to true

    //prompt user for the size of the array (how many elements to sort)
    printf("Enter size of array\n");
    if(scanf(" %d",&arraySize) !=1)
    {
      printf("\nRead error");
      return 0;
    }

    //prompt user for the name of the file to write to
    FILE *fp;
    char fname[128];
    printf("\nEnter filename\n");
    if(scanf("%s",fname)!=1)
    {
      printf("Read error");
    }
    strcat(fname, ".dat"); //add '.dat' to the end of the users filename
    fp=fopen(fname,"w"); //open the file
    if(fp) //if the file is opened
    {
      //sort 1000 arrays, 1500, 2000 etc. up to 10000 arrays
      for(amountOfArrays=1000; amountOfArrays<=10000;amountOfArrays+=500)
      {

        struct timeval tim;
        gettimeofday(&tim, NULL); //get the time of day before the sort is excecuted
        double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
        preference(amountOfArrays, arraySize, sortInput, testInput); //call the sort function
        gettimeofday(&tim, NULL); //get the time of day after the sort is excecuted
        double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
        totalTime = t2-t1; //the total time will be equal to time after minus time before
        printOut(fp, amountOfArrays, totalTime); //call the printout method to write data to file
      }
      fclose(fp); //close the file
      exit(0); //finish execution of program
    }
    else
    {
      printf("Could not open file\n"); //error checking code
    }
  }
  if(!write) //if there is no need to write to a file
  {

    struct timeval tim;
    gettimeofday(&tim, NULL); //get the time of day before the sort is excecuted
    double t1=tim.tv_sec+(tim.tv_usec/1000000.0);
    preference(amountOfArrays, arraySize, sortInput, testInput); //call the sort function
    gettimeofday(&tim, NULL); //get the time of day after the sort is excecuted
    double t2=tim.tv_sec+(tim.tv_usec/1000000.0);
    totalTime = t2-t1; //the total time will be equal to time after minus time before
    meanTime = totalTime/amountOfArrays; //the mean time will be the total time divided by the amount of lists that were sorted
    //print out the total and mean time of the sort
    printf("Total time: %.6f\n", totalTime);
    printf("Mean time: %.6f \n", meanTime);

  }





}
