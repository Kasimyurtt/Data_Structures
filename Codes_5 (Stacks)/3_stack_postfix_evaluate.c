#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Stack[10]; 
int Top = -1;

void push( int data )
{ 
      Stack[++Top] = data;
}

int pop( )
{ 
    return Stack[Top--];
}
//----------------------------------------------------------------
int main()
{
   // Postfix Notation
  char Expression[] = "15  10  +  30  *"; // Result is 750
  //char Expression[] = "10 20 30 40 50 / - * +";  // Result is 610
  //char Expression[] = "10 20 + 30 * 40 - 50 /";  // Result is 17
  
  char *token;  // a word in expression string
  int operand1, operand2, result;
  char opr;

   token = strtok( Expression, " "); // get first token 
   while( token != NULL )
   {
     opr = token[0];
     
     if ( isdigit(opr) ) // check whether token is a number
        push( atoi(token) );  // convert from ascii to integer
     else
     {
        operand2 = pop();
        operand1 = pop();
           
        if (opr == '+')  result = operand1 + operand2;
        if (opr == '-')  result = operand1 - operand2;
        if (opr == '*')  result = operand1 * operand2;
        if (opr == '/')  result = operand1 / operand2;

        push(result);

        printf("%d %c %d = %d \n", operand1 , opr, operand2, result); 

     } 

     token = strtok( NULL, " "); // get next token from expression

  }//end of while

  printf("Final result = %d \n", pop() ); 

  //printf("Validation = %d \n", ( ( (10 + 20) * 30 ) - 40 ) / 50 ); // Result is 17
  //printf("Validation = %d \n", 10 + (20 * (30 - (40 / 50) ) ) ); // Result is 610
}



