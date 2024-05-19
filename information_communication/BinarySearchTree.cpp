#include "BinarySearchTree.h"

Node* BinarySearchTree::Insert(Node* n, Data d)
{
	if (n == NULL) return new Node(d);
	if (Key(d) < Key(n->data)) n->left = Insert(n->left, d);
	else n->right = Insert(n->right, d);
	return n;
}





Data BinarySearchTree::Search(Node* n, int key)
{
	if (n == NULL) return SEARCH_FAILED;
	if (key == Key(n->data)) return n->data;
	else if (key < Key(n->data)) return Search(n->left, key);
	else return Search(n->right, key);

}




void BinarySearchTree::PrintData(Data d)
{
	if (Key(d) == SEARCH_FAILED) cout << "Search failed" << endl;
	else cout << Key(d) << "is found" << endl;

}

void BinarySearchTree::PrintInorder(Node* n) {
	if (n == NULL) return;
	PrintInorder(n->left);
	cout << n->data<<" ";
	PrintInorder(n->right);
}


Data BinarySearchTree::Delete(int key)
{
	if (root == NULL) return SEARCH_FAILED;
	Node* parent = NULL;
	Node* node = root;
	while (node!= NULL && Key(node->data)!=key) 
	{
		parent = node;
		node = (key < Key(node->data)) ? node->left : node->right;
	}
	if (node == NULL) return SEARCH_FAILED;
	Data d = node->data;
	DeleteNode(parent, node);
	return d;
}


void BinarySearchTree::DeleteNode(Node* parent, Node* n)
{
	if (n->left == NULL || n->right == NULL) {
		Node* child = (n->left != NULL) ? n->left : n->right;
		if (n == root) root = child;
		else if (parent->left == n) parent->left = child;
		else parent->right = child;
		delete n;
	}
	else {
		Node* sParent = n; Node* s = n->right;
		if (s->left == NULL)
			sParent->right = s->right;
		else {
			while (s->left != NULL) { sParent = s; s = s->left; }
			sParent->left = s->right;
		}
		n->data = s->data; delete s;
	}
}