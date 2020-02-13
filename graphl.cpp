// ----------------- graphl.cpp --------------------
// Andrea Shirley-Bellande, 343C
// Created: Feb 10, 2020
// Last Modified: Feb 10, 2020
// ---------------------------------------------------------------------------------
// Purpose: This class implements a graph and its related functions. 
// ----------------------------------------------------------------------------------------
//	Assumptions: No error checking.
// ------------------------------------------------------------------------------------------

#include "graphm.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "graphl.h"

// ---------------------Default Constructor--------------------------------
// Constructor: Default constructor for graphl.
// preconditions: Does not take any parameters. 
// postconditions: Sets and initializes to null or false. 
// --------------------------------------------------------------------------
GraphL::GraphL()
{
	size = 0;
}

// ---------------------Destructor--------------------------------
// Destructor: Deallocates memory
// preconditions: Does not take any parameters.
// postconditions: Deallocates memory
// --------------------------------------------------------------------------
GraphL::~GraphL()
{
}

// ---------------------buildGraph--------------------------------
// buildGraph: opens and reads file creates graph node info
// preconditions: takes in ifstream file
// postconditions: reads data creates graph node info
// --------------------------------------------------------------------------
void GraphL::buildGraph(istream& file1)
{
	int to, from;
	file1 >> size;
	string node;
	getline(file1, node);

	for (int i = 1; i <= size; i++)
	{
		getline(file1, node);
		nodeData[i].data = new NodeData(node);
	}
	while (!file1.eof())
	{
		file1 >> from >> to;
		if ( from == 0 )
		{
			break;
		}
        insertEdge(from, to);
	}
}

void GraphL::insertEdge(int from, int to)
{
    // make sure the nodes are valid
    if (from > 0 && from <= size && to > 0 && to <= size) {
        EdgeNode *newNode = new EdgeNode(to);
        newNode->nextEdge = nodeData[from].edgeHead;
        nodeData[from].edgeHead = newNode;
    }
}

// ---------------------DFS--------------------------------
// DFS: 
// preconditions: 
// postconditions: 
// ---------------------------------------------------------
void GraphL::depthFirstSearch()
{
	for (int i = 0; i <= size; i++)
	{
		nodeData[i].visited = false;
	}
	cout << "Depth-first ordering: ";
	for (int v = 1; v <= size; v++)
	{
		if (!nodeData[v].visited)
		{
			dFSHelper(v);
		}
	}
    cout << endl;
}

// ---------------------DFSHelper--------------------------------
// DFSHelper: 
// preconditions: 
// postconditions: 
// ---------------------------------------------------------
void GraphL::dFSHelper(int v)
{
	if(!nodeData[v].visited) {
        std::cout << v << " ";
        nodeData[v].visited = true;
        EdgeNode *edge = nodeData[v].edgeHead;
        while(edge) {
            dFSHelper(edge->adjGraphNode);
            edge=edge->nextEdge;
        }
    }
}
// ---------------------displayGraph--------------------------------
// displayGraph: 
// preconditions: 
// postconditions: 
// --------------------------------------------------------------------------
void GraphL::displayGraph()
{
	for(int n=1; n <= size; n++) {
        std::cout << "Node " << n << "\t" << *nodeData[n].data << endl;
        EdgeNode *node = nodeData[n].edgeHead;
        while (node) {
            std::cout << "\t\tedge " << n << " " << node->adjGraphNode << endl;
            node = node->nextEdge;
        }
        std::cout << endl;
    }
}
