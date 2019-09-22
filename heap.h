#pragma once
#include <stdio.h>
#include <stdio.h>
struct ELEMENT{
    int key;
	int dest;
	int weight;
    int nodeNumber;
	ELEMENT *element=NULL;
    
    
};


struct HEAP{
    int capacity;
    int size;
    ELEMENT *H;
    
};

HEAP* initialize(int n);

void buildHeap(HEAP* heap,ELEMENT A[],int size);

void insert(HEAP* heap, int flag, int key);

ELEMENT deleteMin(HEAP* heap, int flag);

void decreaseKey(HEAP* heap, int flag, int index, int value);

void minHeapify(ELEMENT H[],int i,int size);

void printHeap(HEAP* heap, ELEMENT A[]);
