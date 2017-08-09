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
			if(i == 0 || i == 1) Board[i][j] = 'O';
			else if(i == 6 || i == 7) Board[i][j] = 'X';
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

void GameBoard::setBoardPiece(int rowPos, int coulmPos, char playPiece){
	Board[rowPos][coulmPos] = playPiece;
}

Tile GameBoard::calcMove(Move m){
	int parity, newRow, newCoulm;

	if(activePlayer.getPlayerNum() == 1){
		parity = -1;
	}
	else if(activePlayer.getPlayerNum() == 2){
		parity = 1;
	}
	else{
		cout << "INVALID PLAYER NUMBER GameBoard::calcMove()" << endl;
	}
	//Forward
	if(m.direction == 'f' || m.direction == 'F'){
		newCoulm = m.coulmPosition;
		newRow = m.rowPosition + parity;
	}
	//Left
	else if(m.direction == 'l' || m.direction == 'L'){
		newCoulm = m.coulmPosition + parity;
		newRow = m.rowPosition + parity;
	}
	//Right
	else if(m.direction == 'r' || m.direction == 'R'){
		newCoulm = m.coulmPosition - parity;
		newRow = m.rowPosition + parity;
	}
	Tile dest(newRow, newCoulm);
	return dest;
}

void GameBoard::makeMove(Move m){	
	Tile dest = calcMove(m);	
	// Make move
	setBoardPiece(dest.rowPosition, dest.coulmPosition, activePlayer.getPlayerPiece());
	//Replace old piece
	setBoardPiece(m.rowPosition, m.coulmPosition, '_');
}


bool GameBoard::isValidMove(Move m){

	return 1;
}