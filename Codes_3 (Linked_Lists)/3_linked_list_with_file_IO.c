// Linked List Program (with file saving) 
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
int isEmpty();
void printList();
void instructions();
void read_from_file();
void write_to_file();
void printReverse(ListNodePtr currentPtr);

int main()
{ 
   startPtr = NULL; // initially there are no nodes 
   int choice; // user's choice 
   int data;  // data entered by user 
   int modified_flag = FALSE; // File change
   char answer; // user answer for file saving

   printf( "LINKED LIST PROGRAM EXAMPLE\n" );
   read_from_file();
   printList();

   instructions(); // display the menu
   scanf( "%d", &choice );

   // loop while user does not choose exit 
   while ( choice != 5 ) { 

      switch ( choice ) { 

         case 1:
            printf( "\nEnter a number as data: " );
            scanf("%d", &data );
            add(data ); // add new data in list 
            modified_flag = TRUE;
            printList();
            break;

         case 2:

            // if list is not empty
            if ( !isEmpty() ) { 
               printf( "\nEnter data value to be deleted: " );
               scanf("%d", &data );

               // if name is found, remove it 
               if ( delete(data ) ) { // removed data's node
                  printf( "%d deleted.\n", data );
                  modified_flag = TRUE;
                  printList();
               } 
               else 
                  printf( "\n%d not found.\n\n", data );

            } 
            else 
               printf( "\nList is empty.\n\n" );

            break;

         case 3:
            printList();
            break;

         case 4:
            printf( "\nReverse list is :\n" );
            printReverse(startPtr);
            printf("\n\n");
            break;

         default:
            printf( "\nInvalid choice.\n\n" );
            break;
      
      } // end switch

      instructions(); // display the menu
      scanf( "%d", &choice );
   } // end while

   printf( "\nEnd of run.\n" );
   
   if (modified_flag == TRUE)
   {
      printf("\nList modified.Save to file (Y/N) ? ");
      fflush(stdin); //clear keyboard buffer
      answer = getchar();
      if (answer == 'y' || answer == 'Y')
         write_to_file();
   }

printf("\n\n");
system("pause");
return 0; 

} // end main


// display program instructions to user
void instructions()
{ 
   printf( "\nEnter your choice:\n"
      "   1) Add an element into the list\n"
      "   2) Delete an element from the list\n"
      "   3) Print the list\n"
      "   4) Print the list in reverse order\n"
      "   5) Exit\n? " );
} // end function instructions


// Add a new value into the list in sorted order
void add(int value )
{ 
   ListNodePtr newPtr;          // pointer to new node
   ListNodePtr previoustartPtr; // pointer to previous node in list
   ListNodePtr currentPtr;      // pointer to current node in list

   newPtr = malloc( sizeof( ListNode ) ); // new node

   if ( newPtr != NULL ) {    // is space available
      newPtr->data = value;   // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node

      previoustartPtr = NULL;
      currentPtr = startPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && value > currentPtr->data ) { 
         previoustartPtr = currentPtr;      // walk to 
         currentPtr = currentPtr->nextPtr;  // ...  next node
      } 

      // add new node at beginning of list
      if ( previoustartPtr == NULL ) { 
         newPtr->nextPtr = startPtr;
         startPtr = newPtr; // Starting node of list has been changed
      } 
      else { // add new node between previoustartPtr and currentPtr
         previoustartPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } 
   
   } // end if
   else {
      printf( "\n%s not added. No memory available.\n", value );
   } 

} // end function add


// Delete a list element
int delete(int value )
{ 
   ListNodePtr previoustartPtr; // pointer to previous node in list 
   ListNodePtr currentPtr;      // pointer to current node in list
   ListNodePtr tempPtr;         // temporary node pointer

   // delete first node if matches the value 
   if ( value == startPtr->data ) { 
      tempPtr = startPtr; // hold onto node being removed 
      startPtr = startPtr->nextPtr; // change startPtr 
      // Starting node of list has been changed
      free( tempPtr ); // free the node 
      return value;
   } // end if 
   else { 
      previoustartPtr = startPtr;
      currentPtr = startPtr->nextPtr;

      // loop to find the correct location in the list 
      while ( currentPtr != NULL && currentPtr->data != value  ) { 
         previoustartPtr = currentPtr;         // walk to   
         currentPtr = currentPtr->nextPtr;     // ...  next node  
      } // end while 

      // delete node at currentPtr 
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previoustartPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return TRUE;
      } // end if 
     
   } // end else 

   return FALSE;

} // end function delete 


// Return 1 if the list is empty, 0 otherwise 
int isEmpty()
{ 
   if (startPtr == NULL)
       return TRUE;
   else
      return FALSE;

} // end function isEmpty 


// Print the list 
void printList()
{ 
    ListNodePtr currentPtr = startPtr;
   // if list is empty 
   if ( currentPtr == NULL ) {
      printf( "\nList is empty.\n\n" );
   } // end if 
   else { 
      printf( "\nThe list is:\n" );

      // while not the end of the list 
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;   
      } // end while 

      printf( "NULL\n\n" );
   } // end else 

} // end function printList 


void read_from_file()
{
  FILE *fPtr;
  int data;  // data value read from file 
  
  fPtr = fopen("veriler.txt","r");
  if (fPtr == NULL)
  {
     printf("\nFile not found\n");
     return;
  }   

  // Read first record
  fscanf(fPtr, "%d", &data); 
  while(!feof(fPtr))
  {
     add(data ); // add data in list 
     // Read next record
    fscanf(fPtr, "%d", &data); 
  }                 
  
  fclose(fPtr);
} // end of read_from_file


void write_to_file()
{
  FILE *fPtr;

  fPtr = fopen("veriler.txt","w");
  if (fPtr == NULL)
  {
     printf("\nFile not opened for write.\n");
     return;
  }

  ListNodePtr currentPtr = startPtr;
  // while not the end of the list 
  while ( currentPtr != NULL ) { 
    fprintf(fPtr, "%d\n", currentPtr->data); 
    currentPtr = currentPtr->nextPtr;   
  } // end while 
     
  fclose(fPtr);
} // end of write_to_file



// Print the list in reverse order
// This is a recursive function
void printReverse(ListNodePtr currentPtr)
{ 
   // if list is empty 
   if ( currentPtr == NULL ) {
      printf( "\nList is empty.\n\n" );
      return;
   } 

  // Print the last node of the list
  if (currentPtr->nextPtr != NULL)
      printReverse(currentPtr->nextPtr ); // Recursive case

  if (currentPtr->nextPtr == NULL)
     printf( "NULL ");
  
  printf( " <-- %d ", currentPtr->data ); // Base case
} 


