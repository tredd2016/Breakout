#ifndef TREE_H
#define TREE_H

#include "GameBoard.h"
#include<vector>

using namespace std;

struct Node{
	int data;
	Node *parent;
	vector<Node*> children;

	Node(int d, Node *p, vector<Node*> c) : data(d), parent(p), children(c) {}
};

class Tree{
private:
	Node* root;

public:	
	Tree();
	Tree(Node *n);

	Node* getParent(Node* n);


};




#endif