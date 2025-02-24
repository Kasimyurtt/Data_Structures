// SELECTION SORT: Program sorts an array's values into ascending order.

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

void display(int array[], int N )
{
   int i;
   for ( i = 0; i < N; i++ )
      printf( "%d  ", array[ i ] );
   printf("\n");
}

int main() 
{   
   int a[SIZE] = {5,2,4,6,1,3}; 

   int i;         // passes counter
   int j;         // comparisons counter
   int index_min; // location of current minimum
   int hold; // temporary location used to swap array elements
   
   printf( "SELECTION SORT METHOD\n\n" );
   printf( "Original unsorted array: " );
   display(a, SIZE);
   printf("\n");

   for (i = 0; i < SIZE-1; i++)
   { 
        index_min = i;

        for (j = i+1; j < SIZE; j++) 
            if (a[j] < a[index_min]) 
               index_min = j;

        if ( a[i] > a[index_min] ) //Swap elements if out of order.
        {
             hold = a[i];                   
             a[i] = a[index_min];
             a[index_min] = hold;
        }// end of if

   } // end of i loop

   printf( "Sorted array: " );
   display(a, SIZE);

printf("\n");
system("pause");
return 0;
} // end of main
