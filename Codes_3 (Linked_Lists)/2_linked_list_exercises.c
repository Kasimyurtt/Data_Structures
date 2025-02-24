#include <stdio.h>
#include <stdlib.h>


struct Node {
  int  data;
  struct Node *next;  // pointer to next node 
};

//----------------------------------------------------


struct Node * copy_list(struct Node *start) {
   if (start == NULL) return NULL;  // termination case

   // Firstly, copy data.
   struct Node *new;
   new = (struct Node *) malloc(sizeof(struct Node));
   new->data = start->data;

   // Then, call recursion.
   new->next = copy_list(start->next);

   return new; // return as new start 
}

//----------------------------------------------------


struct Node * copy_list_iterative(struct Node *P) 
{
   struct Node *start2 = NULL; // Target new list
   struct Node *new;
   struct Node *previous = NULL;

   if (P == NULL) return NULL;  // Empty Source list

   while (P != NULL)
   {
     // Copy the data.
     new = (struct Node *) malloc(sizeof(struct Node));
     new->data = P->data;
     new->next = NULL;

     if (previous != NULL)
        previous->next = new; // Link node to the list
   
     previous = new; // Update previous pointer

     if (start2 == NULL)
        start2 = new;

     P = P->next;  // Go to next node	
   } // End of loop

   return start2; // return as new start 
}


//----------------------------------------------------


struct Node *start, *end;

void remove_all(struct Node * P)   // Recursive
{
   if (P == NULL)   // Empty list
   {
       start = NULL;
       end = NULL;
       return;
  }
  
  struct Node * tmp_ptr = P->next;
  free(P);   // Built-in C function

  if (tmp_ptr == start) // Finished all deletings
  {
       start = NULL;
       end = NULL;
       return;
  }
 else
      remove_all (tmp_ptr); // Recursive call
}

//----------------------------------------------------


void print(struct Node * P)
{
  printf("LIST : ");
  if (P == NULL)
  {
     printf("Empty \n");
  	 return;
  }
  
  while (P != NULL)
  {
     printf("%d  ", P->data);
     P = P->next;
  }
 
  printf("\n");
}


//----------------------------------------------------

void Recursive1 (struct Node *start) {
   if (start == NULL) return;  // termination case

   printf("%d \n", start->data);   // Firstly, display data.
   Recursive1(start->next);       // Then, call recursion.
}

void Recursive2 (struct Node *start) {
   if (start == NULL) return;  // termination case

   Recursive2(start->next);       // Firstly, call recursion.
   printf("%d \n", start->data);   // Then, display data.
}


//----------------------------------------------------
/* Operation Codes
   0 : Average of ALL datas
   1 : Average of ODD datas
   2 : Average of EVEN datas
*/

float average(int operation_code)
{
   int sum=0, count=0;
   struct Node * P = start;

  while (P != NULL)
  {
       if ( (operation_code == 0)  ||
             (operation_code == 1 && P->data % 2 == 1) ||
             (operation_code == 2 && P->data % 2 == 0)  )
       {
           sum += P->data;
           count++;
       }
       P = P->next;
  } // end of while

  if (count != 0)
     return (float) sum / count;
  else
     return 0;
}



//*****************************************************************************

int main()
{
   start = (struct Node *) malloc(sizeof(struct Node));
   start->data = 10;

   start->next = (struct Node *) malloc(sizeof(struct Node));
   start->next->data = 25;

   start->next->next = (struct Node *) malloc(sizeof(struct Node));
   start->next->next->data = 12;

   start->next->next->next = (struct Node *) malloc(sizeof(struct Node));
   start->next->next->next->data = 27;

   start->next->next->next->next = NULL;

   struct Node * start2;
   start2 = copy_list(start);

   printf("\nprint(start) : \n");
   print(start);

   printf("\nAverage of ALL (start) : %f \n", average(0) );
   printf("\nAverage of ODDS (start) : %f \n", average(1) );
   printf("\nAverage of EVENS (start) : %f \n", average(2) );


   printf("\nprint(start2) : \n");
   print(start2);

   remove_all(start);

   printf("\nprint(start) : \n");
   print(start);

   printf("\nRecursive1 : \n");
   Recursive1(start2);

   printf("\nRecursive2 : \n");
   Recursive2(start2);

   struct Node * start3;
   start3 = copy_list_iterative(start2) ;

   printf("\nprint(start3) : \n");
   print(start3);
   
  
   system("pause");
}




