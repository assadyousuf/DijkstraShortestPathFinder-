//=============================================================================

// The following is a partial program that "nextCommand" in util.cpp.

//=============================================================================

#include "main.h"





//=============================================================================

// The following is a partial program that "nextCommand" in util.cpp.

//=============================================================================



int main() {
    
    // variables for the parser...
    
    
    char c;
    
    int i, v,f;
    
    
    
    
    //variables for numOfEdges and numOfnodes
    int numOfEdges = 0;
    
    int numOfNodes = 0;
    
    
    
    //setting up variables
    bool readin=false;
    
    struct ELEMENT *n1 = NULL;
    
    struct ELEMENT *vert;
    
    //array of linked list AKA adjacency list
    ELEMENT **T = NULL;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while (1) {
        
        c = nextCommand(&i, &v, &f);
        
        switch (c) {
                
            case 'w':
                
            case 'W':
                printf("COMMAND: %c.\n", c);
                if(T==NULL){ //If the adj List is empty print error
                    printf("Error:  There is no graph to print.\n");
                    break;
                }
                
                else{//otherwise loop through T and print the adjList
                    printf("%d %d\n",numOfNodes,numOfEdges);
                    for(int f=1; f<=numOfNodes; f++){
                        printf("%d :  ",f);
                        ELEMENT *traverser=T[f];//traverser is set to the head of every linked list in the array
                        while(traverser!=NULL){
                            printf("(%d, %d)",traverser->dest,traverser->weight);
                            traverser=traverser->element;
                            if(traverser!=NULL){
                                printf("; ");
                            }
                        }
                        printf("\n");
                        
                        
                        
                        
                    }
                    break;
                    
                    
                }
                
                
                
            case 'C':
                
            case 'c': printf("COMMAND: %c %d %d %d.\n", c, i,v, f);
                
                //create vertextList from adjacecny list read in
                
                if(T==NULL){ //break out of running Dijkstra's if adjList is empty and print this error
                    printf("Error:  There is no graph to run Dijkstra’s algorithm on.\n");
                    break;
                }
                
                if(i>numOfNodes|| v>numOfNodes || v<=0||i<=0){ //if the nodes typed in by the user are not within the range of nodes in the adjList than print this error and break
                    printf("Error: One or more of the nodes is invalid.\n");
                    if(f!=0 && f!=1){
                        printf("Error: Invalid flag value.\n");
                    }
                    break;
                }
                
                
                
                //call dijstkra on T
                
                Dijkstra(T, i, v, numOfNodes,f);
                
                
                
                break;
                
                
                
            case 'e':
                
            case 'E':printf("COMMAND: %c.\n", c);
                printf("The program is going to be terminated.\n");//Print quit message before ending program
                exit(0);
                
                
                
            case 'i':
                
            case 'I':
                
                printf("COMMAND: %c.\n", c);
                
                if(readin==true){ // If the adjList has alredy set than break out
                    break;
                    
                }
                
                //setting variables up to read in Ginput.txt
                FILE *file;
                
                file = fopen("Ginput.txt", "r");
                
                char c;
                
                int d = 0;

                //if file object is NULL than the OS could not find the file
                if (file == NULL) {
                    
                    printf("There was a problem opening file Ginput.txt for reading.\n");
                    
                    break;
                    
                }
                
                //use these two fscanf lines to intially set d to what the numOfEdges that the textFile says up top
                fscanf(file, "%d", &d);
                
                fscanf(file, "%d", &d);
                
                c = getc(file);
                
                
                
                
                
                while (c != EOF) {//count how many edges are in the text File
                    
                    c = getc(file);
                    
                    if (c == '\n') {
                        
                        numOfEdges++;
                        
                    }
                    
                }
                
                
                
                if (numOfEdges < d) { // if the actual number of edges is less than the number said in the textFile print this error and break
                    
                    printf("Error:  The number of edges is less than as specified in the beginning of the file.\n");
                    
                    break;
                    
                }
                
                
                
                
                fseek(file, 0, SEEK_SET); //Reset pointer back to begining of file now that we know we have correct # of edges
                
                
                
                
                
                fscanf(file, "%d", &numOfNodes);//reading in #num of nodes
                
                
                
                fscanf(file, "%d", &numOfEdges); // reading in #edges
                
                
                
                //setting up variables for read in of textfile
                int num = 0;
                
                int destination = 0;
                
                int weight = 0;
                
                //counter to make sure we are reading in correct number of edges
                int counter=numOfEdges;
                
                
                
                
                
                
                
             
                
                
                
                
                
                
                
                
                
                
                
                while (fscanf(file, "%d", &num) > 0) { //While your not at the end of the file set destination and weight variables to what is specified in the textfile
                    
                    
                    fscanf(file, "%d", &destination);
                    
                    fscanf(file, "%d", &weight);
                    
                    i = num;//i == the node in the graph that we want to set the adjList for
                    
                    
                    
                    
                    
                    ELEMENT **n2;
                    
                    if (T == NULL) {//if array holding linked list is empty
                        
                        T=new ELEMENT*[numOfNodes+1]; //allocate space for array
                        for(int g=1; g<=numOfNodes; g++){ //set all members of the array to NULL
                            T[g]=NULL;
                        }
                        
                        //allocate space and add linked list box to i
                        T[i]=new ELEMENT();
                        
                        T[i]->dest = destination;
                        
                        T[i]->weight = weight;
                        
                        T[i]->key=i;
                        
                        counter--;
                    }
                    
                    
                    
                    else if(T[i]==NULL && counter!=0){ // if the head of the linked list for the "ith" index in the array is NULL allocate space for linke list box and set variables
                        
                        T[i]=new ELEMENT;
                        
                        T[i]->dest=destination;
                        
                        T[i]->weight=weight;
                        
                        T[i]->key=i;
                        
                        counter--;
                    }
                    
                    
                    
                    
                    
                    
                    //This condtion is when the linked list of the "ith" index of the array is not empty
                    else {
                        if(counter!=0){
                        n2 = &T[i];
                        
                        while ((*n2) != NULL) {//travel down linked list until you get to empty spot
                            
                            n2 = &((*n2)->element);
                            
                        
                        }
                        
                        //allocate space for empty spot and set varaibles
                        (*n2) = new ELEMENT();
                        
                        (*n2)->dest = destination;
                        
                        (*n2)->weight = weight;
                        
                        (*n2)->key = i;
                        
                            counter--;
                        }
                        
                        
                        
                        
                        
                        
                        
                        
                    }
                    
                }
                
                
                
                readin=true;
                
                break;
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
        }
        
        
        
    }
    
    exit(0);
    
}
