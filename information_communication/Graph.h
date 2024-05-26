#pragma once
#include<iostream>
#include <cstdlib>
using namespace std;
#define GRAPH_SIZE 20
const char NONE = '.';

class Graph {
protected:
	char label[GRAPH_SIZE];
	bool adj[GRAPH_SIZE][GRAPH_SIZE];
	int degree[GRAPH_SIZE];
	bool visited[GRAPH_SIZE];
	int graphSize;
	void CheckIndex(int n);
	void VisitVertex(int n);
	void DFSRecursion(int n);
public:
	Graph();
	void InsertVertex(int n, char c);
	void InsertEdge(int n, int m);
	void DeleteVertex(int n);
	void DeleteEdge(int n, int m);
	void PrintGraph();
	void DFS(int n);
	void BFS(int n);

	void ResetVisited();
	
};


