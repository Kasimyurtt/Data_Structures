#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

int main() {
  stack <int>   S;

  // Add data to stack
  S.push(20); 
  S.push(40); 
  S.push(10); 
  S.push(30); 

  printf("Popping data from STL Stack:\n");
  while (!S.empty() )  
  {
     printf("%d \n",  S.top() );   // Print top element
     S.pop();  // Delete top element
  }

 system("pause"); 
 return 0; 
}

