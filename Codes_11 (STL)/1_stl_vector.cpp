#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
  int i;
  vector <int>  a(4); // Initial vector size

  a[0]=20;
  a[1]=40;
  a[2]=30;
  a[3]=10;

  //a[4] = 70;  //Invalid command, because a[4] does not exist.

  //Extending the vector with two more elements:
  a.push_back(50);    // As a[4]
  a.push_back(60);    // As a[5]

  printf("Data in the STL vector:\n");
  for (i=0; i<a.size(); i++)
      printf("%d \n", a[i]);
      
  system("pause");
  return 0;
}


