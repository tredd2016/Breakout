#include "GameBoard.h"
#include "Player.h"

#include<iostream>

using namespace std;

int main(){
	Player p1(1,'X');
	Player p2(2, 'O');
	
	GameBoard PlayingBoard(p1,p2);

	//PlayingBoard.setActPlayer(p2);

	PlayingBoard.printBoard();
	//cout << endl;

	//Move s1(6,5,'f');
	//PlayingBoard.makeMove(s1);

	//PlayingBoard.printBoard();
	//cout << endl;

	Move p1Move = PlayingBoard.getMove();
	PlayingBoard.makeMove(p1Move);
	PlayingBoard.printBoard();
	PlayingBoard.setActPlayer(p2);
	PlayingBoard.printBoard();

	Move p2Move = PlayingBoard.getMove();
	PlayingBoard.makeMove(p2Move);
	PlayingBoard.setActPlayer(p1);
	PlayingBoard.printBoard();
	return 0;

	
}