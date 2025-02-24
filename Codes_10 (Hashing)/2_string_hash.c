#include <stdio.h>
#include <string.h>

int Hash(char Key[20], int N)
{
   //N : Size of hash table array	
   int sum = 0, i;
   int U = strlen(Key); // String length
   
   for (i=0; i < U; i++)
     sum = sum + Key[U - i - 1] * pow(128, i); //Base Sum Method

   return sum % N;
}

int main()
{
  printf("String key : TEST \n");
  printf("Hash value : %d \n", Hash("TEST", 203) ); // Displays 148
}



