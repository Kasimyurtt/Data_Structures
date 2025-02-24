// Queue (Circular Array Implementation)
#include <stdio.h>

// Global Queue Array :
#define N 5
int Queue[N];
int first;
int last;

void enqueue(int data)
{
    if ( (last + 1 ) % N == first)
    { 
        printf("Queue is full!\n");
        return;
    }

   if (last == -1)
   {
     // This is the initial element to be added.
     first = 0;
     last = 0;
   }
   else
      last = (last + 1 ) % N; // Increment last

    Queue[last] = data; // Put data to queue
}


int dequeue()
{
   int data;

   if (first == -1)  {
      printf("Queue is empty\n");
      return -1; // Deleting can not be done
   }

   // remove first element from the queue
   data = Queue[first];  
   Queue[first] = 0; // data in queue is deleted

   if (first == last)
   {
     // Last element is deleted, queue will be empty.
     first = -1;
     last = -1;
   } 
   else
      first = (first + 1) % N;

   return data;
}


// Print the queue
void printQueue()
{ 
   int i;
   printf( "\n" );
  
  // if queue is empty
   if ( first == -1) 
      printf( "\nThe queue is empty.\n\n" );
   else { 
      printf( "\nThe queue is (first to last):\n" );

     //for (i=0; i < N; i++)
     //   printf( "%d --> ", Queue[i] );

     // print items between first and last
     i=first;
     do
     {
        printf( "%d --> ", Queue[i] );
        if (i == last)
           break; // Stop loop
        i = (i+1)%N;
     } while (1); // infinite loop
     
     printf( "\n" );
   } // end else 

} 


// display program instructions to user
void instructions( )
{ 
   printf( "QUEUE  (ARRAY IMPLEMENTATION)\n"
      "1. Enqueue a value \n"
      "2. Dequeue \n"
      "3. Exit \n" );
} 

//--------------------------------------------------------
int main()
{ 
   // Initially queue is empty
   first = -1;
   last = -1;

   int choice; // user's menu choice 
   int value;  // int input by user 
 
   instructions(); // display the menu 
   printf( "\nEnter choice : " );
   scanf( "%d", &choice );

   // while user does not enter exit
   while ( choice != 3 ) { 

      switch ( choice ) { 

         // Enqueue value to queue
         case 1:      
            printf( "\nEnter an integer: " );
            scanf( "%d", &value );
            enqueue(value );
            printQueue();
            break;

         // Dequeue value from queue
         case 2:      
            // if queue is not empty
            if ( first != -1) 
               printf( "The dequeued value is %d.\n", dequeue());

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







