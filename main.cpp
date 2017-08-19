#include "Node.h"
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
	//cout << PlayingBoard.Board << endl;
	PlayingBoard.playGame();
	return 0;

	
}