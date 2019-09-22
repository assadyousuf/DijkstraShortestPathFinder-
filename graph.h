#include "heap.h"



//setting defenitions of functions
void initsinglesource(HEAP* heap,int numOfNodes,int source,ELEMENT* dist);
void relax(ELEMENT* dist, int v, int u, ELEMENT* crawler);
void Dijkstra(ELEMENT** adjList, int source, int target,int numOfNodes,int flag);
void printNode(ELEMENT** node, int index);
void printList(ELEMENT** adjList);
  





