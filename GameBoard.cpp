#include "GameBoard.h"

GameBoard::GameBoard(){
	//default constructor...do something here
}

GameBoard::GameBoard(Player p1, Player p2){
	activePlayer = p1;
	passivePlayer = p2;
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
	// Player 1 Board View
	if(activePlayer.getPlayerNum() == 1){
		cout << "   a b c d e f g h" << endl;
		for(int i=0; i<8; ++i){
			cout << 8-i << " |";
			for(int j=0; j<8; ++j){
				cout << Board[i][j] << "|";
			}
			cout << endl;
		}
	}
	// Player 2 Board View
	else{
		cout << "   h g f e d c b a" << endl;
		for(int i=0; i<8; ++i){
			cout << i+1 << " |";
			for(int j=0; j<8; ++j){
				cout << Board[7-i][7-j] << "|";
			}
			cout << endl;
		}
	}	
}

void GameBoard::setActPlayer(Player p){
	activePlayer = p;
}

Player GameBoard::getActPlayer(){
	return activePlayer;
}

void GameBoard::setPassivePlayer(Player p){
	passivePlayer = p;
}

Player GameBoard::getPassivePlayer(){
	return passivePlayer;
}

void GameBoard::changeTurn(){
	Player swap = activePlayer;
	activePlayer = passivePlayer;
	passivePlayer = swap;
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

void GameBoard::makeMove(){	
	bool valid = false;
	while(!valid){
		Move m = getMove();	
		if(isValidMove(m)){
			Tile dest = calcMove(m);	
			// Make move
			setBoardPiece(dest.rowPosition, dest.coulmPosition, activePlayer.getPlayerPiece());
			//Replace old piece
			setBoardPiece(m.rowPosition, m.coulmPosition, '_');
			valid = true;
		}
		else cout << "Invalid move, please try again.." << endl;
		
	}
}

//Not yet tested or proven comperhensive 
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

	else return true;
}

Move GameBoard::getMove(){
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
	// Convert Coulm to lowercase and subtract ascii value of 'a' to get integer representation
	char coulmChar = tolower(usrInput[0]);
	int coulmInt = coulmChar - 97;
	
	// Convert to int - Must adjust index from board to array
	int rowInt = abs(8 - atoi(&usrInput[1]));	

	// Direction, convert to lower and leave as is
	char dirChar = tolower(usrInput[3]);

	Move rtnVal(rowInt, coulmInt, dirChar);
	return rtnVal;
	
}

// Should probably make player 1 and 2 members of gameboards to be able to reference their piece chars
bool GameBoard::isGG(){
	for(int i=0;i<8;++i){
		if(Board[0][i] == 'X') return true;
		if (Board[7][i] == 'O') return true;
	}
	return false;
}

void GameBoard::playGame(){
	while(!isGG()){
		//cout << "Player: " << activePlayer.getPlayerNum() << " Please enter a move" << endl;
		printBoard();
		makeMove();
		changeTurn();
	}
	printBoard();
	cout << "The game is over" << endl;
}