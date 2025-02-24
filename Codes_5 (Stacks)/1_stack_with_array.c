/* Stack (Array Implementation) */

#include <stdio.h>

// Global Stack Array and Top variable :
#define N 5 // Maximum stack size
int Stack[N];
int Top;  // index of stack top element

// prototypes
void push(  int data );
int pop( );
void printStack( );
void instructions( );

int main()
{ 
   Top = -1;  // Initially stack is empty

   int choice; // user's menu choice 
   int value;  // int input by user 
 
   instructions(); // display the menu 
   printf( "\nEnter choice : " );
   scanf( "%d", &choice );

   // while user does not enter exit
   while ( choice != 3 ) { 

      switch ( choice ) { 

         // push value onto stack
         case 1:      
            printf( "\nEnter an integer: " );
            scanf( "%d", &value );
            push( value );
            printStack();
            break;

         // pop value off stack
         case 2:      

            // if stack is not empty
            if ( Top != -1) 
               printf( "The popped value is %d.\n", pop() );

            printStack();
            break;

         default:
            printf( "Invalid choice.\n\n" );
            instructions();
            break;

      } // end switch

      printf( "Enter choice : " );
      scanf( "%d", &choice );
   } // end while

   printf( "End of run.\n" );

   return 0; 
} // end main

//--------------------------------------------------------

// display program instructions to user
void instructions( )
{ 
   printf( "STACK  (ARRAY IMPLEMENTATION)\n"
      "1. Push a value \n"
      "2. Pop \n"
      "3. Exit \n" );
} 


// Add a data at the stack top
void push( int data )
{ 
   // add the data at stack top
   if ( Top < N-1)  {   
      Top++;
      Stack[Top] = data;
   } // end if
   else { // no space available
      printf( "\n%d not added. Stack size (%d) has been exceeded.\n", data , N);
   } 

} 


// Remove a data from the stack top 
int pop(  )
{ 
   int popValue; // popped value

    if ( Top == -1)  {   
        printf("Stack is empty\n");
        return -1;
    }

   popValue = Stack[Top];
   Top--;
   return popValue;
} 

// Print the stack
void printStack(  )
{ 
   int i;
   printf( "\n" );
   // if stack is empty
   if ( Top == -1 ) 
      printf( "\nThe stack is empty.\n\n" );
   else { 
      printf( "\nThe stack is:\n" );
      // while not the end of the stack
      for (i=Top; i >= 0; i--)
         printf( "%d --> ", Stack[i] );
      printf( "\n" );
   }
} 

