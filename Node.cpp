#include "Node.h"

Node::~Node(){
	for(int i=0; i<children.size(); ++i){		
		delete(children[i]);
		//cout << "Deleted: " << i << " Child Nodes" << endl;
	}
	//cout << "Deleted this parent node" << endl;
	children.clear();
}

Node* Node::getParent(){
	return parent;
}

void Node::addChildren(vector<Node*> c){
	children = c;
}

void Node::addChild(Node* n){
	children.push_back(n);
}

void Node::printChildren(){
	for(int i=0; i < children.size();++i){
		cout << "Gameboard: " << i+1 << endl;
		children[i]->board.printBoard();
	}
}

