#include "Tree.h"

Tree::Tree(){
	root = nullptr;
}

Tree::Tree(Node *n){
	root = n;
}

Node* Tree::getParent(Node* n){
	return n->parent;
}

