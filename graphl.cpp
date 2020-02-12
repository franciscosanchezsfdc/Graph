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
	for (int i = 1; i < MAXNODES; i++)
	{
		nodeData[i].visited = false;
		nodeData[i].edgeHead = NULL;
		nodeData[i].data = NULL;
	}
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
		NodeData* temp = new NodeData(node);
		nodeData[i].data = temp;

	}
	while (!file1.eof())
	{
		getline(file1, node);
		file1 >> to >> from;
		if ( from == 0 )
		{
			break;
		}
		
	}
}

// ---------------------DFS--------------------------------
// DFS: 
// preconditions: 
// postconditions: 
// ---------------------------------------------------------
void GraphL::dFS()
{
	for (int i = 0; i <= size; i++)
	{
		nodeData[i].visited = false;
	}
	cout << "Depth-first : ";
	for (int v = 1; v <= size; v++)
	{
		if (!nodeData[v].visited)
		{
			dFSHelper(v);
		}
	}
}

// ---------------------DFSHelper--------------------------------
// DFSHelper: 
// preconditions: 
// postconditions: 
// ---------------------------------------------------------
void GraphL::dFSHelper(int v)
{
	nodeData[v].visited = true;
	EdgeNode* curr = nodeData[v].edgeHead;

	while (curr != NULL)
	{
		if (!nodeData[curr->adjGraphNode].visited)
		{
			dFSHelper(curr->adjGraphNode);

		}
		curr = curr->nextEdge;
	}

}
// ---------------------displayGraph--------------------------------
// displayGraph: 
// preconditions: 
// postconditions: 
// --------------------------------------------------------------------------
void GraphL::displayGraph()
{
	for (int i = 1; i <= size; i++)
	{
		cout << "Node" << i << "    " << *nodeData[i].data << endl;
		EdgeNode* temp = nodeData[i].edgeHead;

		while (temp != NULL)
		{

		}
	}
}