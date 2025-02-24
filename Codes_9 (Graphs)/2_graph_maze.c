#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define N 11 //Number of nodes in graph (maze)
int visited[N]; // Flag array to keep the status of nodes
int starting, ending; // starting and ending node indexes
int solution_path[N];
int path_length_counter;

int total_solutions_counter= 0;
char solutions[300][N+1];

// Adjacency matrix for Undirected Graph (MAZE)
int graf[N][N]= {
//A  B  C  D  E  F  G  H  I  J  K
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, //A   
{ 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0 }, //B
{ 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 }, //C
{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0 }, //D
{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, //E
{ 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, //F
{ 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 }, //G
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, //H
{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1 }, //I
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, //J
{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 }  //K
};


//-------------------------------------------------------------------------------------

// Recursive Depth-First-Search function
void DFS(int x)
{       
      int i;

      visited[x] = TRUE; //Mark the x node as visited
      solution_path[path_length_counter] = x;
      path_length_counter++;

      if (x == ending)
      {
         for (i=0; i < path_length_counter; i++)
              solutions[total_solutions_counter][i] = 'A'+solution_path[i];

         solutions[total_solutions_counter][i] = '\0'; // null string terminator
      	 total_solutions_counter++;
      }
      else
      {
        // Visit all nodes which are adjacent to node x, if they are unvisited.
        for (i=0; i < N; i++)
             if  (graf[x][i] !=0 &&  ! visited[i])
                  DFS(i);
      }

      visited[x] = FALSE;
      path_length_counter--;
}

//--------------------------------------------------------

int main()
{
       int i;

       printf("RECURSIVE DEPTH-FIRST SEARCH METHOD\n\n");
       printf("NODES IN UNDIRECTED GRAPH:\n");
        for (i=0; i < N; i++)
            printf("%2d. %c \n", i+1, 'A'+i);

       printf("Enter numbers of Starting and Ending nodes : ");
       scanf("%d %d", &starting, &ending);
       printf("\n");

       starting--; ending--;  // C indexes should begin with 0
       
       for (i=0; i < N; i++)    
           visited[i] = FALSE; //Initially all nodes are unvisited
       path_length_counter = 0;

       DFS(starting);

       int min_index = 999;
       int min_length = 999;
       int uz;
       
       // Display all results  
       for (i=0; i < total_solutions_counter; i++)    
       {
       	   uz = strlen(solutions[i]);
           printf("%d.Solution Path (Length = %d) : %s \n", i+1, uz, solutions[i]);
           if (uz < min_length)
           {
           	  min_length = uz;
           	  min_index = i;
		   }
	   }

       printf("\n\nThe first shortest solution path (Length = %d) : %s \n", min_length, solutions[min_index]);
       printf("Solution num = %d \n", min_index+1);
}


