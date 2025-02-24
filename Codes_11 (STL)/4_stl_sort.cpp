#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
  int i;
  int A[4] = {20, 10, 40, 30};
  float B[3] = {7.3,  8.5,  4.6};

  sort(A, A+4);
  printf("Sorted A array: \n");
  for (i=0; i<4; i++)
       printf("%d \n", A[i]);

  sort(B, B+3);
  printf("\nSorted B array: \n");
  for (i=0; i<3; i++)
       printf("%f \n", B[i]);

  system("pause");
  return 0;
}


