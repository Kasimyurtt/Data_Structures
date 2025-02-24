// BUBBLE SORT: Program sorts an array's values into ascending order.

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

   int pass; // passes counter
   int i;    // comparisons counter
   int hold; // temporary location used to swap array elements
   
   printf( "BUBBLE SORT METHOD\n\n" );
   printf( "Original unsorted array: " );
   display(a, SIZE);
   printf("\n");

   // loop to control number of passes
   for ( pass = 1; pass < SIZE; pass++ ) { 
      // loop to control number of comparisons per pass
      for ( i = 0; i < SIZE - 1; i++ ) {      
         /* compare adjacent elements and swap them if first 
         element is greater than second element */
         if ( a[i] > a[i+1] )
         {
             hold = a[i];                   
             a[i] = a[i+1];
             a[i+1] = hold;

         } // end of if 
      } // end of i loop
   } // end of pass loop

   printf( "Sorted array: " );
   display(a, SIZE);

printf("\n");
system("pause");
return 0;
} // end of main

