#include "GraphLinkedList.h"


int main() {
	GraphLinkedList g;

	g.InsertVertex(0, 'S');
	g.InsertVertex(1, 'A');
	g.InsertVertex(2, 'B');
	g.InsertVertex(3, 'C');
	g.InsertVertex(4, 'D');
	g.InsertEdge(3,4);
	g.InsertEdge(2, 4);
	g.InsertEdge(1,4);
	g.InsertEdge(0, 3);
	g.InsertEdge(0, 2);
	g.InsertEdge(0, 1);
	g.PrintGraph();

	cout << "Breadth First Search: ";
	g.BFS(0);
	return 0;

	



}





