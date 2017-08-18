#include "Tree.h"
#include "GameBoard.h"
#include "Player.h"
#include "Human.h"
#include "AI.h"

#include<iostream>

using namespace std;

int main(){
	Human h1(1,'X');
	AI a2(2,'O');

	GameBoard PlayingBoard(h1,a2);
	
	//PlayingBoard.printBoard();
	//PlayingBoard.AIAllMoves();
	//Move sample(6,0,'f');
	//PlayingBoard.makeMove(sample);
	//PlayingBoard.printBoard();
	vector<Node*> empty;

	Node myNode(1, nullptr, empty);
	
	//PlayingBoard.playGame();
	return 0;

	
}