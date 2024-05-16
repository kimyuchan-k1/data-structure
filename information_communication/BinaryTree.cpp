#include "BinaryTree.h"
#include "QueueTemplate.h"
void Error(string s) { cerr << s; exit(-1); }

int FindPath(int pos) {
	int path = 1;
	for (int n = pos; n!= 1; n /= 2) {
		path = path * 2 + n % 2;
	}
	return path;
}


void BinaryTree::InsertPos(int pos, Data d) {
	root = InsertPos(root, FindPath(pos), d);
}

Data BinaryTree::DeletePos(int pos,Data d) {
	return DeletePos(root, FindPath(pos));
}

Data BinaryTree::PeekPos(int pos) {

	return PeekPos(root, FindPath(pos));


}

Data BinaryTree::PeekPos(Node* n, int path)
{
	if (n == NULL) Error("Illegal position");
	if (path == 1) return n->data;
	if (path % 2 == 0)
		return PeekPos(n->left, path / 2);
	else return PeekPos(n->right, path / 2);
}

Node* BinaryTree::InsertPos(Node* n, int path, Data d) {
	if (path == 1 && n == NULL)
		return new Node(d);
	if (path == 0 || n == NULL)
		Error("Illegal position");
	if (path % 2 == 0)
		n->left = InsertPos(n->left, path / 2, d);
	else
		n->right = InsertPos(n->right, path / 2, d);
	return n;
}

#define DELETE(n) {Data d = n->data; delete n; n=NULL; return d; }

Data BinaryTree::DeletePos(Node* n, int path)
{
	if (n == NULL) Error("Illegal position");
	if (path == 1 && n == root) DELETE(root);
	if (path == 2) DELETE(n->left);
	if (path == 3) DELETE(n->right);
	if (path % 2 == 0)
		return DeletePos(n->left, path / 2);
	else return DeletePos(n->right, path / 2);
}

int BinaryTree::NumNode(Node*n) {

	if (n == NULL) return 0; // n이 null 이면 탈출
	return 1 + NumNode(n->left) + NumNode(n->right);
	

}



int BinaryTree::NumLeaf(Node*n) {
	if (n == NULL) return 0; //n이 null 일때는 0을 반환
	if (n->IsLeaf()) return 1; //n이 leaf일때는 1을 반환 
	return NumLeaf(n->left) + NumLeaf(n->right);


}

int BinaryTree::Height(Node* n) {
	if (n == NULL) return 0;
	return 1 + max(Height(n->right), Height(n->left));
}


void BinaryTree::PrintPreorder(Node* n) {
	if (n == NULL) return;
	cout << n->data << " ";
	PrintPreorder(n->left);
	PrintPreorder(n->right);

}

void BinaryTree::PrintInorder(Node* n) {
	if (n == NULL) return;
	PrintInorder(n->left);
	cout << n->data << " ";
	PrintInorder(n->right);

}

void BinaryTree::PrintPostorder(Node* n) {
	if (n == NULL) return;
	PrintPostorder(n->left);
	PrintPostorder(n->right);
	cout << n->data << " ";

}


void BinaryTree::PrintLevelOrder() {
	QueueTemplate < Node*> q;
	q.Insert(root);
	while (q.IsEmpty() == false) {
		Node* n = q.Delete();
		if (n == NULL) continue;
		cout << n->data << " ";
		q.Insert(n->left);
		q.Insert(n->right);

	}
	cout << endl;
}

