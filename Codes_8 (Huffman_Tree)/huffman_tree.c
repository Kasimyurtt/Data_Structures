// Program builds a Huffman Character Coding Tree, then generates and displays the Huffman Character Codes for letters.
// The input file should contain the letters and their statistical frequencies, pre-sorted by frequencies in increasing order.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DOSYA_ADI "frequencies.txt"

// Global definitions and variables
struct Node
{
  int freq;        //Frequency of letter
  char letter;  
  struct Node * left;   
  struct Node * right;
};

struct Node * Trees[26]; // List of Huffman trees
int N; //Count of letters in list

char path[8]; // Generated Huffman code bits for a letter

//************************************************************************
// Calculates the number of non-null elements in the list
int list_size()
{
  int i, count = 0;
  for (i=0; i < N; i++)
      if (Trees[i] != NULL) // Count all non-null nodes in list
         count++;

  return count;	
}

//================================================================

// BUBBLE SORT METHOD
// Sorts the list by frequencies in increasing order.
void list_sort() 
{
  int pass, i, j;

  struct Node * tmp;

  for (pass=1; pass < N; pass++)
  {
     for (i=0; i < N-1; i++)
     {
        if (Trees[i] == NULL) continue; //Skip i

        for (j=i+1; j < N-1; j++)
            if (Trees[j] != NULL) break; //Break j
            
        if  (Trees[j] == NULL) continue; //Skip i
        
        if (Trees[i]->freq > Trees[j]->freq)
        {
        	// Swap the node addresses
        	tmp = Trees[i];
        	Trees[i] = Trees[j];
        	Trees[j] = tmp;
        }
     }//end of i loop
  } //end of pass loop
}

//================================================================
// Removes the first non-null node from the list
struct Node * remove_node()
{
  int i;
  struct Node * tmp;

  for (i=0; i < N; i++)
      if (Trees[i] != NULL) // Find first non-null node in list
      {
            tmp = Trees[i]; // Copy address of i node
            Trees[i] = NULL; //Delete address of i node from list
            return tmp; //Return address of the removed node
      }
}

//================================================================
// Inserts a new node at the first null location in the list
void insert_node(struct Node * newnode)
{
  int i;
  for (i=0; i < N; i++)
      if (Trees[i] == NULL) // Find first null node in list
      {
         Trees[i] = newnode;
	 return;
      }
}

//================================================================
// Builds the Huffman Coding Tree
void build_huffman_tree()
{
  struct Node *tmp1, *tmp2, *tmp3 = NULL;
	
while (list_size() >= 2) 
{
  // Remove first two trees from list
  tmp1 = remove_node(); 
  tmp2 = remove_node();

  // Create a new node and attach the removed two nodes to new node
  tmp3 = (struct Node*) malloc (sizeof(struct Node));
  tmp3->freq = tmp1->freq + tmp2->freq;
  tmp3->letter = ' ';
  tmp3->left = tmp1;
  tmp3->right = tmp2;

  insert_node(tmp3); // Put the new tree back on list

  list_sort(); //Re-sort the list by new frequencies
} //end while
}

//================================================================
// Finds the first non-null node in the list, which is the root of completed final tree.
struct Node * find_root()
{
  int i;
  for (i=0; i < N; i++)
      if (Trees[i] != NULL) // Find first non-null node in list
         return Trees[i];
}


//================================================================
// Recursive Depth-First Traversal (PREORDER)
// Traverses the whole tree.
// Generates and displays the Huffman character codes for each letter.
void traverse_huffman_tree(struct Node * p)
{
  if (p == NULL) return;

  if (p->left == NULL && p->right == NULL)
     // Display generated Huffman Code for the letter at leaf node 
     printf("%c  %s \n", p->letter, path); 

  if (p->left != NULL)
  {
    strcat(path, "0");
    traverse_huffman_tree(p->left); //Goto left branch
    path[strlen(path)-1] = '\0'; // Remove last bit from path
  } 

  if (p->right != NULL)
  {
    strcat(path, "1");
    traverse_huffman_tree(p->right); //Goto right branch
    path[strlen(path)-1] = '\0'; // Remove last bit from path
  } 

}

//================================================================
// Reads letters and frequencies from input file, and creates the initial list.
// The letter frequencies in input file are assumed to be pre-sorted already.
void list_create()
{
  int i; // Loop counter
  char letter_str[2]; //Contains a letter and the null terminator '\0'
  int freq; // Frequency of a letter
  
  FILE * fPtr;
  fPtr = fopen(DOSYA_ADI, "r");
  
  if (fPtr == NULL)
  {
    printf("Input file %s not found \n", DOSYA_ADI);
    system("pause");
    exit(0); // Stop
  } 

  N = 0;
  printf("LETTERS AND FREQUENCIES READ FROM FILE: \n");
  while ( ! feof(fPtr) )
  {
     if (feof(fPtr)) break;
     fscanf(fPtr, "%s %d", letter_str, &freq);
     Trees[N] = (struct Node*) malloc (sizeof(struct Node)); // Create a node
     Trees[N]->freq = freq;
     Trees[N]->letter = letter_str[0];
     Trees[N]->left = NULL;
     Trees[N]->right = NULL;
     printf("%s  %d\n", letter_str, freq);
     N++;
  }  
         
  fclose(fPtr);
}

//************************************************************************

int main()
{
  list_create();

  build_huffman_tree();
  
  printf("\n\nLETTERS AND GENERATED HUFFMAN CHARACTER CODES: \n");
  strcpy(path, "");
  
  struct Node * root = find_root();
  traverse_huffman_tree(root); // Recursively display the generated codes
  
  system("pause");
  return 0;
} // end main


