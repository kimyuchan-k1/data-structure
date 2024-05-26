#include "Graph.h"
#include "QueueTemplate.h"

// index 벗어날 경우의 예외처리
void Graph::CheckIndex(int n)
{
	if (n < 0 || n >= GRAPH_SIZE) {
		Error("Illegal index");
	}
}


void Graph::VisitVertex(int n) {
	visited[n] = true;
	cout << label[n] << " ";
}


//방문여부를 false로 초기화한다.
void Graph::ResetVisited()
{
	for (int i = 0; i < GRAPH_SIZE;i++) visited[i] = false;
}


//그래프 생성하면 그래프의 모든 것을 초기화한다.
Graph::Graph()
{
	graphSize = 0;
	for (int i = 0; i < GRAPH_SIZE; i++) {
		label[i] = NONE;
		degree[i] = 0;
		visited[i] = false;
		for (int j = 0; j < GRAPH_SIZE; j++) {
			adj[i][j] = false;

		}
	}
}


void Graph::InsertVertex(int n, char c)
{
	//첫 번쨰 예외 index범위를 넘어갈때
	CheckIndex(n);
	//두 번째 예외 이미 값이 존재할때
	if (label[n] != NONE) Error("Occupied");
	label[n] = c;
	graphSize++;

}

void Graph::InsertEdge(int n, int m)
{
	CheckIndex(n); CheckIndex(m);
	adj[n][m] = adj[m][n] = true;
	degree[n]++; degree[m]++;
}

void Graph::PrintGraph()
{
	for (int n = 0; n < GRAPH_SIZE; n++) {
		if (label[n] == NONE) continue;
		cout << "Vertex " << label[n] << "has neighbor ";
		for (int i = 0; i < GRAPH_SIZE; i++) {
			if (adj[n][i]) cout << label[i] << " ";
		}

		cout << endl;
	}
}

void Graph::DeleteEdge(int n, int m)
{
	CheckIndex(n); CheckIndex(m);
	adj[n][m] = adj[m][n] = false;
	degree[n]--; degree[m]--;
}

void Graph::DeleteVertex(int n)
{
	CheckIndex(n);
	if (label[n] == NONE)
		Error("No vertex to delete");
	for (int i = 0; i < GRAPH_SIZE; i++) {
		if (adj[n][i] || adj[i][n]) {
			cout << "Delete edges first" << endl;
			return;
		}

	}
	label[n] = NONE; graphSize--;
}

void Graph::BFS(int n)
{
	QueueTemplate<int> q;
	ResetVisited();
	q.Insert(n);
	while (q.IsEmpty() == false) {
		n = q.Delete();
		if (visited[n]) continue;
		VisitVertex(n);
		for (int i = 0; i < QUEUE_SIZE; i++) {
			if (adj[n][i]) q.Insert(i);
		}
	}
}



void Graph::DFS(int n)
{
	ResetVisited();
	DFSRecursion(n);
}


void Graph::DFSRecursion(int n)
{
	if (visited[n]) return;
	VisitVertex(n);
	for (int i = 0; i < GRAPH_SIZE; i++) {
		if (adj[n][i]) {
			DFSRecursion(i);
		}
	}

}

