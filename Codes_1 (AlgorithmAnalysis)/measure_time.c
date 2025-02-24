#include <stdio.h>
#include <time.h>

int main()
{
  int i;	
  time_t  first = time(NULL); //Capture initial time
  
  for (i=1; i <= 1000; i++) // Loop 1 thousand times
      printf("%d \n", i);   // One printf is 3 mili seconds

  printf("\nELAPSED TIME = %d SECONDS \n", time(NULL) - first); 
}

 
