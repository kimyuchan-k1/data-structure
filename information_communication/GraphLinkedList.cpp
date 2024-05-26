#include "GraphLinkedList.h"
#include "QueueTemplate.h"



void GraphLinkedList::CheckIndex(int n) {
	if (n < 0 || n >= GRAPH_SIZE) Error("Illegal index");

}

GraphLinkedList::GraphLinkedList() {
	graphSize = 0;
	for (int i = 0; i < GRAPH_SIZE; i++) {
		label[i] = NONE;
		degree[i] = 0;
		visited[i] = false;
		adjacent[i] = NULL;

	}
}

void GraphLinkedList::InsertVertex(int n,char c) {
	CheckIndex(n);
	if (label[n] != NONE)Error("Occupied");
	label[n] = c;
	graphSize++;
}

void GraphLinkedList::InsertEdge(int n, int m) {
	CheckIndex(n);
	CheckIndex(m);
	adjacent[n] = new Node(m, adjacent[n]);
	adjacent[m] = new Node(n, adjacent[m]);
	degree[n]++; degree[n]++;

}


void GraphLinkedList::PrintGraph()
{
	for (int i = 0; i < GRAPH_SIZE; i++) {
		if (label[i] == NONE) continue;
		cout << "Vertex " << label[i] << " has neighbor ";
		Node* p = adjacent[i];
		for (;p != NULL; p = p->next) {
			cout << label[p->vertex] << " ";
		}
		cout << endl;
	}
}


void GraphLinkedList::VisitVertex(int n) {
	visited[n] = true;
	cout << label[n] << " ";
}

void GraphLinkedList::DFS(int n) {
	if (visited[n]) return;
	VisitVertex(n);
	Node* p = adjacent[n];
	for (;p != NULL; p = p->next) {
		DFS(p->vertex);
	}
}

//큐를 생성하여 BFS 를 추가.
void GraphLinkedList::BFS(int n) {
	//BFS 는 재귀가 아니라 Queue 를 사용
	QueueTemplate<int> q;
	q.Insert(n);
	while (q.IsEmpty() == false)
	{
		n = q.Delete();
		if (visited[n]) continue;
		VisitVertex(n);
		Node* p = adjacent[n];
		for (;p != NULL; p = p->next) {
			q.Insert(p->vertex);
		}
	}
}