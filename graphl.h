// ----------------- graphl.h --------------------
// Andrea Shirley-Bellande, 343C
// Created: Feb 10, 2020
// Last Modified: Feb 10, 2020
// ---------------------------------------------------------------------------------
// Purpose: Creates a graphm class and its related functions. 
// ----------------------------------------------------------------------------------------
//	Assumptions: No error checking.
// ------------------------------------------------------------------------------------------
#pragma once
#include "nodedata.h"
#include <fstream>
#include <iostream>



int const MAX_NODES = 101;

class GraphL {

public:

    GraphL();
    ~GraphL();
    void buildGraph(istream& file);
    void displayGraph();
    void depthFirstSearch();
   

private:

    struct EdgeNode;      // forward reference for the compiler

    struct GraphNode {    // structs used for simplicity, use classes if desired
        EdgeNode* edgeHead; // head of the list of edges
        NodeData* data;     // data information about each node
        bool visited;

        GraphNode() {
            edgeHead = NULL;
            data = NULL;
            visited = false;
        }
        
        ~GraphNode() {
            if (data) { delete data; }
            EdgeNode *node = edgeHead;
            while(node) {
                EdgeNode *next = node->nextEdge;
                delete node;
                node = next;
            }
        }
    };

    struct EdgeNode {
        int adjGraphNode;  // subscript of the adjacent graph node
        EdgeNode* nextEdge;
        
        EdgeNode(int n) {
            adjGraphNode = n;
            nextEdge = NULL;
        }

    };
    GraphNode nodeData[MAX_NODES];
    int size;

    void makeEmpty();
    void dFSHelper(int);
    void insertEdge(int, int);
};
