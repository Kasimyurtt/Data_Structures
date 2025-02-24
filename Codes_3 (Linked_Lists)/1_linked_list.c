// Linked List Program 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// GLOBAL DEFINITIONS
// self-referential structure 
struct Node 
{
  int  data;
  struct Node *nextPtr;  // pointer to next node 
};

typedef struct Node ListNode; // synonym for struct Node 
typedef ListNode *ListNodePtr;  // synonym for ListNode*   

ListNodePtr startPtr; // Starting pointer (head) of linked list

// Function prototypes 
void add(int value );
int delete(int value );
void printList();
void instructions();
void instructions2();
//-----------------------------------------------------
int main()
{ 
   startPtr = NULL; // initially there are no nodes 
   int choice; // user's choice 
   int choice2;
   int data;  // data entered by user 

   printf( "LINKED LIST PROGRAM\n" );

   instructions(); // display the menu for operation
   scanf( "%d", &choice );



   // loop while user does not choose exit 
   while ( choice != 4 ) { 

      switch ( choice ) { 

         case 1:
         	instructions2(); //display the menu for location
    		scanf("%d",&choice2);
            printf( "\nEnter a number as data: " );
            scanf("%d", &data );
            add(data ); // add new data in list 
            printList();
            break;

         case 2:
               printf( "\nEnter data value to be deleted: " );
               scanf("%d", &data );

               // remove data 
               if ( delete(data ) ) { // removed data's node
                  printf( "%d deleted.\n", data );
                  printList();
               } 
               else 
                  printf( "\n%d not found.\n\n", data );
            break;

         case 3:
            printList();
            break;
      
      } // end switch
      
    
      

      instructions(); // display the menu
      scanf( "%d", &choice );
      
      	instructions2(); //display the menu for location
    	scanf("%d",&choice2);

   } // end while

   printf( "\nEnd of run.\n" );
   
return 0; 

} // end main

//-----------------------------------------------------
// display program instructions to user
void instructions()
{ 
   printf( "\nEnter your choice:\n"
      "   1) Add operation\n"
      "   2) Delete operation\n"
     );
} // end function instructions

//-----------------------------------------------------

// display program instructions to user
void instructions2()
{ 
   printf( "\nEnter your choice:\n"
      "   1) Perform operation at the BEGINNING location in Linked List\n"
      "   2) Perform operation at the END location in Linked List\n");
} // end function instructions

//-----------------------------------------------------
// Add a new value into the list in sorted order
void add(int value )
{ 
   ListNodePtr newPtr;          // pointer to new node
   ListNodePtr previous; // pointer to previous node in list
   ListNodePtr current;      // pointer to current node in list

   newPtr = malloc( sizeof( ListNode ) ); // new node

   if ( newPtr != NULL ) {    // is space available
      newPtr->data = value;   // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previous = NULL;
      current = startPtr;

      // loop to find the correct location in the list
      while ( current != NULL && value > current->data ) { 
         previous = current;          // walk to 
         current = current->nextPtr;  // next node
      } 

      // add new node at beginning of list
      if ( previous == NULL ) { 
         newPtr->nextPtr = startPtr;
         startPtr = newPtr; // Starting node of list has been changed
      } 
      else { // add new node between previous and current
         previous->nextPtr = newPtr;
         newPtr->nextPtr = current;
      } 
   
   } // end if
   else {
      printf( "\n%s not added. No memory available.\n", value );
   } 

} // end function add
//-----------------------------------------------------

// Delete a list element
int delete(int value )
{ 
   ListNodePtr previous; // pointer to previous node in list 
   ListNodePtr current;      // pointer to current node in list
   ListNodePtr tempPtr;         // temporary node pointer

   // delete first node if matches the value 
   if ( value == startPtr->data ) { 
      tempPtr = startPtr; // hold onto node being removed 
      startPtr = startPtr->nextPtr; // change startPtr 
      // Starting node of list has been changed
      free( tempPtr ); // free the node 
      return TRUE;
   } // end if 
   else { 
      previous = startPtr;
      current = startPtr->nextPtr;

      // loop to find the correct location in the list 
      while ( current != NULL && current->data != value  ) { 
         previous = current;         // walk to   
         current = current->nextPtr; // next node  
      } // end while 

      // delete node at current 
      if ( current != NULL ) { 
         previous->nextPtr = current->nextPtr;
         free( current );
         return TRUE;
      } // end if 
     
   } // end else 

   return FALSE;

} // end function delete 

//-----------------------------------------------------
// Print the list 
void printList()
{ 
    ListNodePtr current = startPtr;
   // if list is empty 
   if ( current == NULL ) {
      printf( "List is empty.\n" );
   } // end if 
   else { 
      printf( "The list is:\n" );

      // while not the end of the list 
      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->nextPtr;   
      } // end while 

      printf( "NULL\n" );
   } // end else 

} // end function printList 

