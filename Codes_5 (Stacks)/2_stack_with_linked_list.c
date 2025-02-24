// Stack (Dynamic Linked List Implementation)
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// self-referential structure
struct Node {   
   int data;             // define data as an int 
   struct Node *nextPtr; // Node pointer 
}; 

typedef struct Node StackNode;     // synonym for struct Node
typedef struct Node *StackNodePtr; // synonym for Node*

StackNodePtr topPtr; // Top pointer of stack

// prototypes 
void push(int data );
int pop();
int isEmpty();
void printStack();
void instructions();


int main()
{ 
   topPtr = NULL; // points to stack top 
   int choice; // user's menu choice 
   int value;  // data input by user 
 
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
            push(value );
            printStack();
            break;

         // pop value off stack 
         case 2:      
            // if stack is not empty 
            if ( !isEmpty() ) 
               printf( "\nThe popped value is %d.\n", pop() );
            printStack();
            break;

         default:
            printf( "\nInvalid choice.\n\n" );
            instructions();
            break;
      } // end switch 

      printf( "\nEnter choice : " );
      scanf( "%d", &choice );
   } // end while 

   printf( "End of run.\n\n" );
   return 0; 
} // end main 

//--------------------------------------------------------

// display program instructions to user
void instructions( void )
{ 
   printf( "STACK (LINKED LIST IMPLEMENTATION)\n"
      "1. Push a value \n"
      "2. Pop \n"
      "3. Exit \n" );
} 


// Add a node at the stack top
void push(int data )
{ 
   StackNodePtr newPtr; // pointer to new node 
   newPtr = malloc( sizeof( StackNode ) );

   // add the node at stack top 
   if ( newPtr != NULL ) {   
      newPtr->data = data;
      newPtr->nextPtr = topPtr;
      topPtr = newPtr;
   } 
   else // no space available 
      printf( "\n%d not added. No memory available.\n", data );
} 

// Remove a node from the stack top
int pop()
{ 
   StackNodePtr tempPtr; // temporary node pointer 
   int popValue; // node data value 

     // Check if stack is empty
    if ( topPtr == NULL)  {   
        printf("Stack is empty\n");
        return -1;
    }

   tempPtr = topPtr;
   popValue = topPtr->data;
   topPtr = topPtr->nextPtr;
   free( tempPtr );

   return popValue;
}  


// Print the stack
void printStack()
{ 
   printf( "\n" );
    StackNodePtr currentPtr = topPtr;
   // if stack is empty 
   if ( currentPtr == NULL ) 
      printf( "The stack is empty.\n\n" );
   else { 
      printf( "The stack is:\n" );

      // while not the end of the stack 
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } 
      printf( "NULL\n\n" );
   } 
}  


// Return 1 if the stack is empty, 0 otherwise
int isEmpty()
{ 
   if (topPtr == NULL)
       return TRUE;
   else    
       return FALSE;
} 


