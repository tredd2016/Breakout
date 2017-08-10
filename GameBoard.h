#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.h"
#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<regex>

using namespace std;

struct Tile{
	int rowPosition;
	int coulmPosition;

	Tile(int r, int c) : rowPosition(r), coulmPosition(c) {}
};

struct Move{
	int rowPosition;
	int coulmPosition;
	char direction; // f - forward , l - left, r - right

	Move(int r, int c, char d) : rowPosition(r), coulmPosition(c), direction(d) {}
};

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

	void setBoardPiece(int rowPos, int coulmPos, char playPiece);
	Tile calcMove(Move m);
	void makeMove(Move m);
	bool isValidMove(Move m);

	void getMove();
};

#endif

