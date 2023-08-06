// Splay tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: http://algorithmtutor.com/Data-Structures/Tree/Splay-Trees/

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <queue>
#include <utility>
#include <ctime>
#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

// data structure that represents a node in the tree
struct Node {
	long long data; // holds the key
	Node *parent; // pointer to the parent
	Node *left; // pointer to left child
	Node *right; // pointer to right child
};

typedef Node *NodePtr;

// class SplayTree implements the operations in Splay tree
class SplayTree {
private:
	NodePtr root;

	NodePtr searchTreeHelper(NodePtr node, long long key) {
		if (node == nullptr || key == node->data) {
			return node;
		}

		if (key < node->data) {
			return searchTreeHelper(node->left, key);
		} 
		return searchTreeHelper(node->right, key);
	}

	// rotate left at node x
	void leftRotate(NodePtr x) {
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != nullptr) {
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->left) {
			x->parent->left = y;
		} else {
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void rightRotate(NodePtr x) {
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != nullptr) {
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr) {
			this->root = y;
		} else if (x == x->parent->right) {
			x->parent->right = y;
		} else {
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// splaying
	void splay(NodePtr x) {
		while (x->parent) {
			if (!x->parent->parent) {
				if (x == x->parent->left) {
					// zig rotation
					rightRotate(x->parent);
				} else {
					// zag rotation
					leftRotate(x->parent);
				}
			} else if (x == x->parent->left && x->parent == x->parent->parent->left) {
				// zig-zig rotation
				rightRotate(x->parent->parent);
				rightRotate(x->parent);
			} else if (x == x->parent->right && x->parent == x->parent->parent->right) {
				// zag-zag rotation
				leftRotate(x->parent->parent);
				leftRotate(x->parent);
			} else if (x == x->parent->right && x->parent == x->parent->parent->left) {
				// zig-zag rotation
				leftRotate(x->parent);
				rightRotate(x->parent);
			} else {
				// zag-zig rotation
				rightRotate(x->parent);
				leftRotate(x->parent);
			}
		}
	}

public:
	SplayTree() {
		root = nullptr;
	}

	// search the tree for the key k
	// and return the corresponding node
	NodePtr searchTree(long long k) {
		NodePtr x = searchTreeHelper(this->root, k);
		if (x) {
			splay(x);
		}
		return x;
	}

	// insert the key to the tree in its appropriate position
	void insert(long long key) {
		// normal BST insert
		NodePtr node = new Node;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
		node->data = key;
		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != nullptr) {
			y = x;
			if (node->data < x->data) {
				x = x->left;
			} 
			else {
				x = x->right;
			}
		}

		// y is parent of x
		node->parent = y;
		if (y == nullptr) {
			root = node;
		} else if (node->data < y->data) {
			y->left = node;
		} else {
			y->right = node;
		}

		// splay the node
		splay(node);
	}

	NodePtr getRoot(){
		return this->root;
	}
};