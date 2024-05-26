#pragma once
#include <iostream>
#include <cstdlib>	
using namespace std;
#define GRAPH_SIZE 5
const char NONE = '.';

struct Node {
	int vertex;
	int weight;
	Node* next;
	Node(int v = 0, Node* n = NULL, int w = 0) {
		vertex = v;
		next = n;
		weight = w;

	}
};


class GraphLinkedList {
protected:
	char label[GRAPH_SIZE];
	Node* adjacent[GRAPH_SIZE];
	int degree[GRAPH_SIZE];
	bool visited[GRAPH_SIZE];
	int graphSize;
	void VisitVertex(int n);
	void CheckIndex(int n);
public:
	GraphLinkedList();
	void InsertVertex(int n, char c);
	void InsertEdge(int n, int m);
	void PrintGraph();
	void DFS(int n);
	//BFS Ãß°¡
	void BFS(int n);

};

