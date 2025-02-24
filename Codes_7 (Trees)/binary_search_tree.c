/*  Binary Search Tree Operations:
    - Travel (Recursive DFS: Preorder, Inorder, and Postorder)
    - Add node
    - Delete node
    - Build tree with random data
    - Search for a value in tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random data generation

// self-referential structure
struct Node { 
   struct Node *left;  // pointer to left subtree
   int data;           // node value 
   struct Node *right; // pointer to right subtree
}; 

typedef struct Node TreeNode; // synonym for struct Node 
typedef TreeNode *TreeNodePtr; // synonym for TreeNode* 

TreeNodePtr rootPtr; // Root pointer of tree

// Function prototypes 
// Travel functions are recursive:
void inOrder( TreeNodePtr node );
void preOrder( TreeNodePtr node );
void postOrder( TreeNodePtr node );

// addNode is not recursive.
void addNode(int value );

// buildTree is not recursive. It calls addNode function.
void buildTree();

// searchNode is not recursive.
void searchNode(int value );


// display program instructions to user
void instructions()
{ 
   printf( "\n\nBINARY SEARCH TREE OPERATIONS\n(POINTER IMPLEMENTATION)\n\n"
      "1. Add a value into tree\n"
      "2. Delete a value from tree\n"
      "3. Travel tree \n"
      "4. Build tree with random data \n"
      "5. Search for a value in tree \n"
      "6. Exit \n" );
} 


int main()
{ 
   rootPtr = NULL; // tree initially empty

   int choice; // user's menu choice 
   int value;  // data input by user 
 
   instructions(); // display the menu 
   printf( "\nEnter choice : " );
   scanf( "%d", &choice );

   // while user does not enter exit 
   while ( choice != 6 ) { 

      switch ( choice ) { 
         // Add value into tree
         case 1:      
            printf( "\nEnter an integer to add: " );
            scanf( "%d", &value );
            addNode(value);
            break;

         // Remove value from tree
         case 2:      
            // if tree is empty 
            if ( rootPtr == NULL) 
               printf( "\nTree is empty, deletion can not be done.\n\n");
            else
               printf( "\n\n ** DELETE FUNCTION NOT WRITTEN ** \n\n");
            break;

         // Travel and print the tree
         case 3:      
            // if tree is empty 
            if ( rootPtr == NULL) 
            {
               printf( "\nTree is empty, Travel can not be done.\n\n");
               break;
            }
            printf("\nEnter Travel method\n");
            printf("(1.Preorder, 2. Inorder, 3. Postorder) : " );
            scanf( "%d", &choice );
            switch ( choice ) 
            { 
              case 1:      
                  // Travel the tree preOrder
                  printf( "\n\n\nThe preOrder travel is:\n" );
                  preOrder( rootPtr );
                  break;
              case 2:      
                  // Travel the tree inOrder
                  printf( "\n\n\nThe inOrder travel is:\n" );
                  inOrder( rootPtr );
                  break;
              case 3:      
                  // Travel the tree postOrder
                  printf( "\n\n\nThe postOrder travel is:\n" );
                  postOrder( rootPtr );
                  break;
              default:
                  printf( "Invalid Travel choice.\n" );
            } // end of Travel switch
            break;

         case 4:      
            buildTree();
            break;

         case 5:      
            // if tree is empty 
            if ( rootPtr == NULL) 
            {
               printf( "\nTree is empty, search can not be done.\n\n");
               break;
            }
            printf( "\nEnter data to search for in tree: " );
            scanf( "%d", &value );
            searchNode(value );
            break;

         default:
            printf( "Invalid choice.\n\n" );
            system("pause");
            instructions();
            break;

      } // end of switch

      instructions(); // display the menu 
      printf( "Enter choice : " );
      scanf( "%d", &choice );
   } // end of while

   printf( "End of run.\n" );
   return 0; 
} // end of main

//--------------------------------------------------------

// Add node into tree
void addNode(int value )
{ 
  TreeNodePtr current;
  TreeNodePtr parent; // reference
  TreeNodePtr newnode;

  newnode = malloc( sizeof( TreeNode ) ); 
  // if memory was allocated then assign data 
  if ( newnode == NULL )
  { 
     printf( "%d not added. No memory available.\n", value );
     return;
  }
  newnode->data = value;
  newnode->left = NULL;
  newnode->right = NULL;
 
   // if tree (represented by node) is empty
   if ( rootPtr == NULL ) 
   { 
     // This is the first node (i.e. root) in tree
     rootPtr = newnode; // Make the newnode as root of tree
     return; // Immediately return
   }
    
  // Adding is always done at leaf level.
  // First, search and find the appropriate leaf place to add newnode.

  current = rootPtr; // Start searching from root
  while (current != NULL)  
  {
    parent = current;
    if (value < current->data)
       current = current->left; // goto left
    else
       current = current->right; //goto right
  }

  // We have reached a leaf node whose address (non-null) is stored at parent.
  if (value < parent->data)
     parent->left = newnode;
  else
     parent->right = newnode;

} // end function addNode



void inOrder( TreeNodePtr node )
{ 
   // if tree (represented by node) is not empty then Travel
   if ( node != NULL ) { 
      inOrder( node->left );
      printf( "%6d", node->data );
      inOrder( node->right );
   } 
} 


void preOrder( TreeNodePtr node )
{ 
   // if tree (represented by node) is not empty then Travel
   if ( node != NULL ) { 
      printf( "%6d", node->data );
      preOrder( node->left );
      preOrder( node->right );
   }
} 

void postOrder( TreeNodePtr node )
{ 
   // if tree (represented by node) is not empty then Travel
   if ( node != NULL ) { 
      postOrder( node->left );
      postOrder( node->right );
      printf( "%6d", node->data );
   }
}

// Build a tree with random values.
void buildTree()
{ 
   int i, N; 
   int item; // variable to hold random values 
   char response; // user's response 

   if ( rootPtr != NULL)
   {
     printf("\nTree already has some nodes.\n");
     printf("Do you want to discard them (y/n) ? ");
     fflush(stdin);
     scanf( "%c", &response );
     if (response != 'y' && response != 'Y')
         return;
   }         
   
   rootPtr = NULL; // Tree is discarded!!

   printf( "\nEnter number of nodes (max 20) : " );
   scanf( "%d", &N );
   if (N < 1 || N > 20)
   {
      printf( "Invalid input!\n" );
      return;
   }
   
   srand( time( NULL ) ); 
   printf( "The random data being added to tree are: \n" );

   // Add random values between 1 and 100 in the tree 
   for ( i = 1; i <= N; i++ )
   { 
      item = rand() % 100 + 1;
      printf( "%6d", item );
      addNode(item );
   } 
}    


// search for a value in tree
void searchNode(int Key )
{ 
  // Key is the searched target value.
  TreeNodePtr current;

  // Search until a leaf place is reached.
  current = rootPtr; // Start searching from root
  while (current != NULL && current->data != Key)  
  {
    if (Key < current->data)
       current = current->left; // goto left
    else
       current = current->right; //goto right
  }

  if (current != NULL)
      printf( "\n\nData found.\n\n" );
  else
      printf( "\n\nData NOT found!\n\n" );
} 

