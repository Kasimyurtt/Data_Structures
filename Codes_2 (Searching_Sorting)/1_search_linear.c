// Linear Search of an array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// function prototype 
int linearSearch(int array[], int key, int size ); 

int main()
{   
   int a[ SIZE ];  
   int x;          // counter for initializing elements 0-99 of array a 
   int searchKey;  // value to locate in array a 
   int element;    // variable to hold location of searchKey or -1 

   // prepare data 
   for ( x = 0; x < SIZE; x++ ) { 
      a[ x ] = 2 * x;
   }

   printf( "Enter integer search key:\n" );
   scanf( "%d", &searchKey );

   // attempt to locate searchKey in array a 
   element = linearSearch( a, searchKey, SIZE );

   // display results 
   if ( element != -1 ) {
      printf( "Found value in element %d\n", element );
   }
   else {
      printf( "Value not found\n" );
   }

printf("\n");
system("pause");
return 0;
} // end main 

//---------------------------------------------
/* compare key to every element of array until the location is found
   or until the end of array is reached; return subscript of element
   if key or -1 if key is not found */

int linearSearch(int array[], int key, int size ) {
   int i; // counter 

   // loop through array 
   for ( i = 0; i < size; i++ ) {
      if ( array[ i ] == key ) { 
         return i; // return location of key
      } // end if 
   } // end for 

   return -1; // key not found 
} // end function linearSearch 
