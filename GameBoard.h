#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.h"
#include<iostream>

using namespace std;

class GameBoard{

private:
	char Board[8][8];
	Player activePlayer;


public:	
	
	GameBoard();
	GameBoard(Player p1, Player p2); // Constructor
	GameBoard(const GameBoard& b); // Copy Constuctor

	//Member functions
	void printBoard();
	void initBoard();
	void setActPlayer(Player p);

	Player getActPlayer(); // should be const? may cause problems later...


};
#endif

