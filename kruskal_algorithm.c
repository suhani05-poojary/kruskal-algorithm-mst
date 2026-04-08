#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Structure to store an edge 

struct Edge {
  int u, v, w;
};

// Parent array for Union-Find 
int parent[MAX];

// Function to find parent (for cycle detection)
int find(int i) { 
    while (parent[i]!=i) 
      i = parent[i]; 
    return i; 
 }

// Function to perform union of two sets 
void unionSet(int a, int b) {
     parent[a] = b;
}

//Function to sort edges based on weight 
void sortEdges(struct Edge edges[], int e) {
   int i, j; 
   struct Edge temp;
   for (i=0; i<e-1; i++) { 
    for (j=i+1; j<e; j++) {
         if (edges[i].w>edges[j].w) {
             temp = edges[i];
             edges[i]=edges[j];
             edges[j] = temp;
         }
    } 
   }
} 
int main() {
     int v, e, i; 
     struct Edge edges[MAX];
     printf("Enter number of vertices: "); 
     scanf("%d", &v);
     printf("Enter number of edges: "); 
     scanf("%d", &e);

// Input edges 
for (i=0; i<e; i++) {
     printf("Enter source, destination and weight for edge %d: ", i + 1); 
     scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
}

// Initialize parent array 
for (i=0; i<v; i++) 
  parent[i]=i;

// Sort edges by weight
 sortEdges(edges, e);
 printf("\nEdges in the Minimum Spanning Tree:\n"); 
 int count=0,cost = 0;

// Process edges
for (i=0; i<e && count <v-1; i++) { 
    int u=find(edges[i].u);
    int v2=find(edges[i].v);

  // If adding edge does not form a cycle 
      if (u!=v2) { 
        printf("%d--%d==%d\n", edges[i].u, edges[i].v, edges[i].w); 
        cost +=edges[i].w;
        unionSet(u, v2);
        count++;
      }
 }
printf("Total cost of MST=%d\n", cost); 
return 0;
}