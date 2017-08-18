#ifndef PLAYER_H
#define PLAYER_H

#include<iostream> // need this even?

using namespace std; // need this?

class Player{
public:

	//Member functions
	int getPlayerNum() const;
	char getPlayerPiece() const;
	char getOppPiece();
	
	void setPlayerNum(int i);
	void setPlayerPiece(char c);

	bool isHumanPlayer();

protected:
	int playerNum;
	char playerPiece;
	bool isHuman;
};
#endif

