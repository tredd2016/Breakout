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
	// Calc proposed move destination
	Tile dest = calcMove(m);

	// Check if Player even has a piece at orgin
	if(Board[m.rowPosition][m.coulmPosition] != activePlayer.getPlayerPiece()){
		return false;
	}
	// Check if destination is in bounds
	else if(dest.rowPosition > 7 || dest.rowPosition < 0 || dest.coulmPosition > 7 || dest.coulmPosition < 0){
		return false;
	}
	// Check if move is attempting to jump opponents piece moving forward
	else if(m.direction == 'f' && Board[dest.rowPosition][dest.coulmPosition] == activePlayer.getOppPiece()){
		return false;
	}
	// Check if destination is occupied by that users piece already
	else if(Board[dest.rowPosition][dest.coulmPosition] == activePlayer.getPlayerPiece()){
		return false;
	}
}

void GameBoard::getMove(){
	string usrInput;
	regex validRegex("([a-h]|[A-H])[1-8] [fFlLrR]");
	bool valid = false;
	char inRow, dir;
	int inCoulm = 0;

	cout << "Player " << activePlayer.getPlayerNum() << ": please enter a move" << endl;
	while(1){
		cout << "Move: ";
		getline(cin, usrInput);
		if(regex_match(usrInput, validRegex))
			break;
		cout << "Invalid move, please try again" << endl;
	}

	cout << "Valid move";	
}