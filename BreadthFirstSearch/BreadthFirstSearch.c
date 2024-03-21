#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "node.h"

//BFS or Breadth First Search 
//Real World: used for calculating shortest path 

// bfs(G,0): 0

//1 - create a boolean list
//2 - add all nodes to a queue 


void freeG();
node * BuildG();
void bfs(node G[]);

extern void enqueue(int n);
extern int dequeue();
extern void show();
extern bool isholding();

void freeG(node G[])
{
    for(int x = 0; x < 5; x++)
    {
        free(G[x].neighbors);
    }
}

node * BuildG()
{
    node node0, node1, node2, node3, node4;
    node *G = malloc(sizeof(node) * 5);

    node0.number = 0;
    node0.neighbors = malloc(sizeof(int) * 2);
    node0.noOfNeighbors = 2;
    node0.neighbors[0] = 1;
    node0.neighbors[1] = 2;
    G[0] = node0;

    node1.number = 1;
    node1.noOfNeighbors = 2;
    node1.neighbors = malloc(sizeof(int)*2);
    node1.noOfNeighbors = 2;
    node1.neighbors[0] = 0;
    node1.neighbors[1] = 3;
    G[1] = node1;
 
    node2.number = 2; 
    node2.neighbors = malloc(sizeof(int)*2);
    node2.noOfNeighbors = 2;
    node2.neighbors[0] = 0;
    node2.neighbors[1] = 3;
    G[2] = node2;


    node3.number = 3;
    node3.neighbors = malloc(sizeof(int) * 3);
    node3.noOfNeighbors = 3;
    node3.neighbors[0] = 1;
    node3.neighbors[1] = 2;
    node3.neighbors[2] = 4;
    G[3] = node3;
    
    node4.number = 4;
    node4.noOfNeighbors = 1;
    node4.neighbors = malloc(sizeof(int)*4);
    node4.neighbors[0] = 3;
    G[4] = node4;

    return G;

}


void bfs(node G[]) 
{
    bool v[5] = { false, false, false, false, false };

    int step = 0;
    enqueue(G[0].number);
    while(isholding())
    {
        int n = dequeue();
        show();
        if(n == -1)
        {   
            printf("error");
            break;
        }
    
        if(v[n] == true) continue;
        
        printf("\nvisiting %d\n", n);
        v[n] = true;
        G[n].order = step;
        step++;

 
        for(int x = 0; x < G[n].noOfNeighbors; x++)
        {
            int node = G[n].neighbors[x];
            if(v[node] == false)
            {
                enqueue(node);
            }
        }
    }
}

int main(void)
{
    node *G = BuildG();
    
    bfs(G);

    for(int x = 0; x < 5; x++)
    {
        printf("node %d order %d\n", G[x].number, G[x].order);
    }

    freeG(G);



}
