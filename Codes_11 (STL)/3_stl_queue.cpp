#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int main()
{	
  queue <int>  K;

  for (int i=1;i<=5;i++)
       K.push(i*10); // Add (enqueue) data to queue

   // Poping and printing:
   printf("Popping (dequeueing) data from STL Queue:\n");
   while (!K.empty()) 
   {
       printf("%d \n", K.front() );
       K.pop();
    }

    system("pause");
    return 0;
}
