## Project 2: Navigating via Dijkstra's Algorithm

## Description:
This project implements Dijkstra's algorithim on a user inputed graph using a min heap data structure to store the labels of nodes. To do this I
simply added a module to implement Dijkstra's as an addition Project 1.


## Files included in Project:

### Main.cpp/Main.h: 
Main.cpp is where most of the essential functions of the assignment take place. This is where 
the dijkstra function is called from graph.cpp. Main.cpp also holds the adjacecny list and deals with user input as well as reading 
in the graph from the textfile "Ginput.txt" provided by the user. Some error checking is done in main.cpp but most of it 
is passed on to the functions to deal with

Main.h is the header file for main.cpp. It mostly holds all the #include preprocessor directives that is needed for Main.cpp.


### Graph.cpp/Graph.h:
Graph.cpp holds all of the functions needed to peform dijkstras on the graph provided by the user. Graph.cpp includes
functions like relax() and initsinglesource() which are essential parts in running dijstra's algorithim. Graph.cpp also holds
the dist[] array which holds all the final label values of the nodes.

Graph.H holds all the defenitions of the functions as well as the #include preprocessor directives needed for Graph.cpp

### Heap.cpp/Heap.h:
Heap.cpp holds all of the functions required for manipulating the heap that stores all of the label of nodes currently being
worked on by Dijkstra's currently in Graph.cpp.Functions used from this file include decreasekey() and initalize().

Heap.h defines all of the structs used throughout the project. The main struct being used is ELEMENT which was expaned from project 1
to hold a number of other fields.


### Util.cpp/Util.h:
Util.cpp holds the functions that deal with user input that are called from main. Util.cpp initalizes and returns 
variables to main that are needed.

Util.h holds all of the #include preprocessor directives needed for Util.cpp


# Usage:
To interact with the program the user is presented with a number of choices in what they can do:
#### E/e: quits the program and displays a message to the user knowing the program is ending.
#### I/i: reads in the graph from the user and puts it into the adjacency list in main.cpp
#### C s t flag: Reads in two nodes (s and t) from the user to use as souce and finish nodes in dijkstra's. The flag is set to 0 if the user would like to see the length of the shortest path and 1 if the user would like to see the nodes in that path.
#### W: Prints the adjacency list.


# Installation:
This project also contains a makefile to create an executable for you. To create an executable for this project please download the repo to your local machine
and type "make". A executable file named "poj2" should appear that you can run.
