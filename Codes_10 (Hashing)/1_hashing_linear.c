// Hashing Program 
// Collision handling method : Linear Probing
#include <stdio.h>
#include <string.h>

// GLOBAL DEFINITIONS
#define N 11  //Size of Hash table array

struct RecordDef 
{
  int  phone_num; // Record key
  char name[20]; // Person name
};
typedef struct RecordDef Record;

Record  Hash_table[N]; // Hash table array
//-----------------------------------------------------
int Hash_function(int Key)
{
   return Key % N;
}

// Function prototypes 
void add(Record  R);
void delete(int Key);
int search(int Key);
//-----------------------------------------------------
int main()
{ 
   int choice; // user's choice 
   Record  R;  // data entered by user 
   int i;

   //Initialize the hash table as empty:
   for (i=0; i<N; i++)
   {
       Hash_table[i].phone_num=0;
       strcpy(Hash_table[i].name, "");
   }

   printf( "HASHING PROGRAM\n" );

Islemler: // Label for goto (loop)
   printf( "\nEnter your choice:\n"
      "   1- Add a record\n"
      "   2- Delete a record\n"
      "   3- Search for a Key\n"
      "   4- Exit\n? " );
   scanf( "%d", &choice );

   if (choice == 4)
      return 0; // Exit program  

   switch ( choice ) 
   { 
         case 1:
            printf( "\nEnter phone number and person name for adding : " );
            scanf("%d %s", &R.phone_num, R.name);
            add(R);
            break;

         case 2:
               printf( "\nEnter phone number for deleting : " );
               scanf("%d", &R.phone_num);
               delete(R.phone_num);
               break;

         case 3:
               printf( "\nEnter phone number for searching : " );
               scanf("%d", &R.phone_num);
               search(R.phone_num);
               break;

         default:
               printf( "\nInvalid choice!\n " );
      
    } // end switch

    goto Islemler;
} // end main

//------------------------------------------------------------------------
void add(Record  R)
{ 
  int x, i;

   if (search(R.phone_num) != -1)  // Found in hash table
   {
          printf("KEY IS ALREADY IN TABLE, ADD IS UNSUCCESFUL \n");
          return;
    }

   // Linear probing to find an empty location:
   x = Hash_function(R.phone_num);

  i = x; // Initial search location
  do
  {
     if (Hash_table[i].phone_num == 0 && strcmp(Hash_table[i].name, "DELETED")!=0 )
    {
          Hash_table[i] = R;
          printf("ADD IS SUCCESFUL \n");
          return;
    }
    else
        i = (i+1)%N; // Circular increment
  } while (i != x); // Full circling is completed.

  printf("TABLE HAS NO EMPTY LOCATIONS, ADD IS UNSUCCESFUL \n");
} // end function add
//-----------------------------------------------------

void delete(int Key)
{ 
  int j;
   j = search(Key);

   if (j == -1) // Not found in hash table
   {
          printf("DELETION IS UNSUCCESFUL \n");
          return;
    }

    Hash_table[j].phone_num=0;
    strcpy(Hash_table[j].name, "DELETED"); // Marking as deleted
    printf("DELETION IS SUCCESFUL \n");
} // end function delete 

//-----------------------------------------------------
//Function returns an index if it founds the Key in hash table, otherwise returns -1.
int search(int Key)
{ 
  int x, i;
   x = Hash_function(Key);

  i = x; // Initial search location
  do
  {
     if (Key == Hash_table[i].phone_num)
    {
          printf("RECORD FOUND \n");
          printf("%d - %s \n", Key, Hash_table[i].name);
          return i;
    }
    else
        i = (i+1)%N; // Circular increment for next location
  } while (i != x); // Full circling is completed.

   printf("RECORD NOT FOUND \n");
   return -1;
} // end function search 
