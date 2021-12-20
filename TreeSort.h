#include <iostream>
#include <conio.h>
#include <stdio.h>

struct Node
{
	int key;
	Node *left;
	Node *right;
	int height;
	int count;
	//add new node as leaf
	Node(int key_) { key = key_; left = right = NULL; height = 1; count = 1; }
};

int height(Node *node)
{
	return (node == NULL) ? 0 : node->height;
}

Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *temp = x->right;
	x->right = y;
	y->left = temp;

	//change heights
	y->height = std::max(height(y->left),
		height(y->right)) + 1;
	x->height = std::max(height(x->left),
		height(x->right)) + 1;

	//new root
	return x;
}

//same but left
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *temp = y->left;
	y->left = x;
	x->right = temp;

	x->height = std::max(height(x->left),
		height(x->right)) + 1;
	y->height = std::max(height(y->left),
		height(y->right)) + 1;

	return y;
}

Node* insert(Node* node, int key)
{
	//normal insert
	if (node == NULL) {
		Node * ptr = new Node(key);
		//std::cout << ptr << ": new node\n";
		return ptr;
	}
	else if (key == node->key) {
		(node->count)++;
		return node;
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	//change height
	node->height = 1 + std::max(height(node->left),
		height(node->right));

	//check if balanced
	int balance_ = (node == NULL) ? 0 : height(node->left) - height(node->right);

	// If unbalanced, then there are 4 cases
	if (balance_ > 1) {
		if (key < node->left->key)// Left Left Case
			return rightRotate(node);
		else if (key > node->left->key) {  // Left Right Case
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}

	if (balance_ < -1) {
		if (key > node->right->key)// Right Right Case
			return leftRotate(node);
		else if (key < node->right->key) {	// Right Left Case
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}

	//return node pointer without changes
	return node;
}

template<typename T>
Node* Create_AVLtree(T*a, int n, Node *root) {
	root = insert(root, a[0]);
	for (int i = 1; i < n; i++)
		root = insert(root, a[i]);

	return root;
}

template<typename T>
void Content_AVLtree(T* a, int n, Node *root) {
	if (root != NULL) {
		int i = 0;
		sort(root, a, i);
	}
}

//sorts balanced tree
void sort(Node *root, int a[], int &i)
{
	if (root != NULL)
	{
		sort(root->left, a, i);
		for (int j = 0; j < root->count; ++j) {
			a[i++] = root->key;
		}
		sort(root->right, a, i);
	}
}

void _deleteTree(Node* node)
{
	if (node == NULL) return;

	//delete subtrees
	_deleteTree(node->left);
	_deleteTree(node->right);
	//std::cout << node << ": delete node\n";
	delete node;
}

void Delete_AVLtree(Node *root)
{
	_deleteTree(root);
	root = NULL;
}

template<typename T>
void SORT_AVL(T*arr, int n) {
	struct Node *root = NULL;
	root = Create_AVLtree(arr, n, root);
	Content_AVLtree(arr, n, root);
	Delete_AVLtree(root);
}
