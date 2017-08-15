#include "GameBoard.h"
#include "Player.h"

#include<iostream>

using namespace std;

int main(){
	Player p1(1,'X');
	Player p2(2, 'O');
	
	GameBoard PlayingBoard(p1,p2);

	//PlayingBoard.printBoard();
	PlayingBoard.playGame();
	return 0;

	
}