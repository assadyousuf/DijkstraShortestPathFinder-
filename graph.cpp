#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>






void initsinglesource(HEAP* heap,int numOfNodes,int source,ELEMENT* dist) {//Sets up heap values
    
    for (int v = 1; v <= numOfNodes; v++) // Loops through to set every memeber of the heap
    {
        dist[v].key=2147483647;//Set dist arrays keys to "infinify"
        heap->H[v].key=2147483647;//Set heap array keys to "infinity"
        heap->H[v].nodeNumber=v;//Set the node number of each node in the heap to keep track of them
        heap->H[v].element=NULL;//using "element" in the ELEMENT struct to set a parent for each ndoe in the heap
        dist[v].element=NULL; //Setting above line but instead for dist array
      
    }
    
    dist[source].key=0;//set source dist array index's key to 0
    decreaseKey(heap, 1, source, 0);//set the source's key to 0
    dist[source].element=NULL;//set the source's parent to NULL
    
    
    
    
    
}


void relax(ELEMENT* dist, int v, int u, ELEMENT* crawler){
    
    dist[v].key=dist[u].key+crawler->weight;
    dist[v].element=new ELEMENT();
    dist[v].element->key=crawler->key;
    
}


void Dijkstra(ELEMENT** adjList, int source, int target,int numOfNodes,int flag) {
    //Setting up variables
    char stringToPrint [1000];
    sprintf(stringToPrint,"%d",source);
    HEAP *mainHeap = NULL;
    
    
    
    //Setting up an ELEMENT array called dist[] that will hold all final dist values from the source node
    ELEMENT* dist=new ELEMENT[numOfNodes+1];
    
    //initalizing and setting up variables
    int V=numOfNodes;
    mainHeap=initialize(numOfNodes);
    mainHeap->size=numOfNodes;
    
    //calling initsinglesource to set each node in the heap's key as well as node number
    initsinglesource(mainHeap, numOfNodes, source, dist);
    
    
    
    
    while(mainHeap->size!=0){//As long as the heap isnt empty continue
        
        ELEMENT e=deleteMin(mainHeap, 1);//Grab min element of heap each time
        int u=e.nodeNumber;//Grab node number so you can set the distance in the dist[] array
        
        
        ELEMENT *navigator=adjList[u];//Setting pointer to travel down the adjacency list of the node from deletemin() up top
        
        while(navigator!=NULL){//While the pointer isn't null
            int v=navigator->dest;//Grab what the node's adjacent node is
            
            //Relaxing
            if(e.key!=2147483647 && navigator->weight + dist[u].key < dist[v].key ){
                relax(dist,v,u,navigator);//relax adjacent node
                
                for(int k=1; k<=mainHeap->size; k++){//Loop through current heap and set the node that has the same nodeNumber as v to the updated label/result
                    if(mainHeap->H[k].nodeNumber==v){
                        decreaseKey(mainHeap, 1, k, dist[v].key);
                        
                    }
                    
                    
                }
            
                
               
                
            }
            navigator=navigator->element;//proceed to next adjacent node.
        
            
        }
    }
    
    if(flag!=0 && flag!=1){
        
        printf("Error: Invalid flag value.\n"); //print this error out if flag!=0 or != 1
    }
    
    if(flag==0){
        if(dist[target].key!=2147483647){ //if the distance in the final dist[] array of the node being searched for is not infinity that means it's discoverable and you should print out its length
        printf("LENGTH: %d\n", dist[target].key);
        }
        
        else{ // if the above condtion fails then that means the node that you are trying to find the single shortest path for is not reachable from your start node
            
            printf("Sorry, node %d is not reachable from node %d.\n",target,source);
               return;
        }
        
    }
    
    if(flag==1){
        ELEMENT* p=&dist[target];
        char str1 [1000];
        
        if(dist[target].key==2147483647){ //same as the else statement when flag==0
            printf("Sorry, node %d is not reachable from node %d.\n",target,source);
               return;
        }
        
        if(p!=&dist[source]){//reset the value of the string that is going to be printed which currently has just the source node to 0 if the target and source are not the same node.
            memset(stringToPrint, 0, 1000);
            
        }
        
        while(p!=&dist[source]){//Start from target until you reach the source node

            if(p==&dist[target]){
                sprintf(stringToPrint,"%d, %d",p->element->key,target); // if p is at the very start  which is the target node since it's printing from the back,append the string with the target node and parent of target
            }
            
            else{ //If p is not at the very start of printing then it is anywhere else besides the target node. So go ahead and append it to the front of the current string
                 strcpy(str1, stringToPrint);
                 sprintf(stringToPrint,"%d, %s",p->element->key,str1);
                
                
            }
        
            p=&dist[p->element->key];//go to the parent of p
            
            
            
    }
        
        printf("PATH: %s\n",stringToPrint); //print path 
               }
    
}
        
        
        
        
    




    
   
    
    
    





               
               
               
               
               

    



