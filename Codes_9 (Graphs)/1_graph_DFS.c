// Program travels the whole Graph with recursive Depth-First-Search.

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define N 7 //Number of nodes in graph (undirected)

// Adjacency matrix
int graf[N][N]= {
//City1 City2 City3 City4 City5 City6 City7
{ 0,      1,      0,      0,      1,      0,      0 }, //City1   
{ 1,      0,      1,      0,      0,      1,      0 }, //City2  
{ 0,      1,      0,      1,      0,      0,      1 }, //City3  
{ 0,      0,      1,      0,      0,      0,      0 }, //City4  
{ 1,      0,      0,      0,      0,      1,      0 }, //City5  
{ 0,      1,      0,      0,      1,      0,      1 }, //City6 
{ 0,      0,      1,      0,      0,      1,      0 }  //City7
};

char city[7][10] = { // city names
"City1", "City2", "City3", "City4", "City5", "City6", "City7"};

int visited[N]; // Flag array to keep the status of nodes


// Recursive Depth-First-Search function
void DFS(int x)
{       
      int i;
      visited[x] = TRUE; //Mark the x node as “visited”
      printf("%s\n", city[x]); 

      // Visit all nodes which are adjacent to node x, if they are unvisited.
      for(i=0; i < N; i++)
      {
           // Check if there is a connection in graph (map) from node x
           // to node i, and node i was unvisited

           if  (graf [x][i] !=0 &&  ! visited [i] ) 
                DFS(i);   // Recursive calling
       }
}

//--------------------------------------------------------

int main()
{
        int i;
        int starting=0; // starting node index


       printf("CITIES:\n");
        for (i=0; i < N; i++)
            printf("%d. %s \n", i+1, city[i]);

       printf("\nAll nodes in graph will be visited by DEPTH-FIRST\n");
       printf("Enter the number of the starting city : ");
       scanf("%d", &starting);

        for (i=0; i<N; i++)    
             visited[i] = FALSE; //Initially all nodes are unvisited

       printf("\nVISIT ORDER OF CITIES = \n");
       DFS(starting-1); // Array index starts from 0 in C

       system("pause");
       return 0;
}


