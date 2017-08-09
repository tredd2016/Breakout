#include "GameBoard.h"

GameBoard::GameBoard(){
	//default constructor...do something here
}

GameBoard::GameBoard(Player p1, Player p2){
	setActPlayer(p1);
	initBoard();
}


void GameBoard::initBoard(){
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(i == 0 || i == 1) Board[i][j] = 'X';
			else if(i == 6 || i == 7) Board[i][j] = 'O';
			else Board[i][j] = '_';
		}
	}
}


void GameBoard::printBoard(){
	cout << "   a b c d e f g h" << endl;
	for(int i=0; i<8; ++i){
		cout << 8-i << " |";
		for(int j=0; j<8; ++j){
			cout << Board[i][j] << "|";
		}
		cout << endl;
	}
	
}

void GameBoard::setActPlayer(Player p){
	activePlayer = p;
}

Player GameBoard::getActPlayer(){
	return activePlayer;
}
