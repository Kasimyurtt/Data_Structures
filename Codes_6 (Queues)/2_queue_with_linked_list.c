// Queue (Dynamic Linked List Implementation)

#include <stdio.h>
#include <stdlib.h>

// self-referential structure
struct Node {   
   int data;             // define data as a int
   struct Node *nextPtr; // queueNode pointer
}; 

typedef struct Node QueueNode;
typedef struct Node *QueueNodePtr;

QueueNodePtr firstPtr, lastPtr; // Queue first and last pointers.

/* function prototypes */
void printQueue();
int isEmpty();
int dequeue();
void enqueue(int value );
void instructions();

int main()
{ 
   firstPtr = NULL; // initialize firstPtr
   lastPtr = NULL;  // initialize lastPtr
   int choice;      // user's menu choice
   int item;        // integer data input by user

   instructions(); // display the menu
   printf( "Enter choice : " );
   scanf( "%d", &choice );

   // while user does not enter exit
   while ( choice != 3 ) { 

      switch( choice ) { 

         // enqueue value
         case 1:
            printf( "Enter a number: " );
            scanf( "\n%d", &item );
            enqueue(item );
            printQueue();
            break;

         // dequeue value
         case 2:

            // if queue is not empty
            if ( !isEmpty() ) { 
               item = dequeue();
               printf( "%d has been dequeued.\n", item );
            } 

            printQueue();
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
void instructions()
{ 
   printf ( "QUEUE (DYNAMIC LINKED LIST IMPLEMENTATION) \n"
           "   1. Enqueue an item \n"
           "   2. Dequeue \n"
           "   3. Exit \n" );
} 

// Add a new node at queue last
void enqueue(int value )
{ 
   QueueNodePtr newPtr; // pointer to new node

   newPtr = malloc( sizeof( QueueNode ) );

   if ( newPtr != NULL ) { // is space available
      newPtr->data = value;
      newPtr->nextPtr = NULL;

      // if empty, add node at first
      if ( isEmpty() ) {
         firstPtr = newPtr;
      } 
      else {
         lastPtr->nextPtr = newPtr;
      }

      lastPtr = newPtr;
   }
   else {
      printf( "%d not added. No memory available.\n", value );
   } 

} 


// Delete node from queue first
int dequeue()
{ 
   int value;            // node value
   QueueNodePtr tempPtr; // temporary node pointer

   if (firstPtr == NULL)  {
      printf("Queue is empty\n");
      return -1; // Deleting can not be done
   }

   value = firstPtr->data;
   tempPtr = firstPtr;
   firstPtr = firstPtr->nextPtr;

   // if queue is empty
   if ( firstPtr == NULL ) {
      lastPtr = NULL;
   } 

   free( tempPtr );

   return value;

} 


// Return 1 if the list is empty, 0 otherwise
int isEmpty()
{ 
   return firstPtr == NULL;

} 

// Print the queue
void printQueue(  )
{ 
   printf( "\n" );
   QueueNodePtr currentPtr = firstPtr;

   // if queue is empty
   if ( currentPtr == NULL ) {
      printf( "Queue is empty.\n\n" );
   } 
   else { 
      printf( "The queue is:\n" );

      // while not end of queue
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;
      } 

      printf( "NULL\n\n" );
   } 

} 


