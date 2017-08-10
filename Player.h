#ifndef PLAYER_H
#define PLAYER_H

//#include "GameBoard.h"
#include<iostream> // need this even?

using namespace std; // need this?

class Player{
public:
	Player(); // Default constructor
	Player(int i, char c); // constructor
	Player(const Player& p); // Copy constructor
	//~Player();  // Desturctor
	
	//Member functions
	int getPlayerNum() const;
	char getPlayerPiece() const;
	char getOppPiece();
	
	void setPlayerNum(int i);
	void setPlayerPiece(char c);

private:
	int playerNum;
	char playerPiece;
};
#endif

