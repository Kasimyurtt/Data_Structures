// Binary Search of an array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 15

// function prototype
int binarySearch(int b[], int searchKey, int first_index, int last_index );

int main()
{
   int a[ SIZE ]; 
   int i;           // loop counter
   int key;      // value to locate in array a
   int result;  // variable to hold location of key or -1

   // prepare data
   for ( i = 0; i < SIZE; i++ ) {
      a[ i ] = 2 * i;
   } 

   printf( "Enter a number between 0 and 28: " );
   scanf( "%d", &key );

   // search for key in array a
   result = binarySearch( a, key, 0, SIZE - 1 );

   // display results
   if ( result != -1 ) {
      printf( "\n%d found in array element %d\n", key, result );
   } 
   else {
      printf( "\n%d not found\n", key );
   } 
   
printf("\n");
system("pause");
return 0;
} // end main

//-----------------------------------------------------
// function to perform binary search of an array
int binarySearch(int b[], int searchKey, int first_index, int last_index )
{
   int middle_index; // variable to hold middle_index element of array

   // loop until first_index subscript is greater than last_index subscript
   while ( first_index <= last_index ) {

      // determine middle_index element of subarray being searched
      middle_index = ( first_index + last_index ) / 2;

      // if searchKey matched middle_index element, return middle_index
      if ( searchKey == b[ middle_index ] ) {
         return middle_index;
      } 

      // if searchKey less than middle_index element, set new last_index
      else if ( searchKey < b[ middle_index ] ) {
         last_index = middle_index - 1; // search left half of array
      } 

      // if searchKey greater than middle_index element, set new first_index
      else {
         first_index = middle_index + 1; // search right half of array
      }

   } // end while

   return -1;   // searchKey not found

} // end function binarySearch

