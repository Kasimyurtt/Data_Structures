#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
   int num_to_find = 30;
 
   vector<int>  vekt;

   // Build a vector with integer data
   for ( int i = 1; i < 5; i++ )
        vekt.push_back(i*10);
 
   vector<int>::iterator  result;
   result = find( vekt.begin(), vekt.end(), num_to_find );
 
   if ( result == vekt.end() )
      printf("Not found \n");
   else
      printf("Found \n");
}

