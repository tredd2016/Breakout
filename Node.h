#ifndef NODE_H
#define NODE_H

#include "GameBoard.h"
#include<vector>

using namespace std;

class GameBoard;

class Node{
public:
	GameBoard board;
	Node *parent;
	vector<Node*> children;

	Node(GameBoard b, Node *p, vector<Node*> c) : board(b), parent(p), children(c) {}
	Node(GameBoard b, Node *p) : board(b), parent(p) {}
	~Node(); // Delete a single node my deleting all of its children

	Node* getParent();
	void addChildren(vector<Node*> c);
	void printChildren();
	void addChild(Node* n);
};


#endif