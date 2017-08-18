#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Player.h"
#include "AI.h"
#include "Human.h"
#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<random>
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
// todo: find a way to make the board private
public:
	char Board[8][8];
	// Try making these pointers?
	Player activePlayer, passivePlayer;
	
	GameBoard();
	GameBoard(Player p1, Player p2); // Constructor 2 player
	//GameBoard(Player p1, AIPlayer p2); // Constructor - human v AI
	GameBoard(const GameBoard& b); // Copy Constuctor

	//Member functions
	void printBoard();
	void initBoard();
	
	char** getBoard();

	void setActPlayer(Player p);
	Player getActPlayer(); // should be const? may cause problems later...
	void setPassivePlayer(Player p);
	Player getPassivePlayer();
	void changeTurn();


	void setBoardPiece(int rowPos, int coulmPos, char playPiece);
	Tile calcMove(Move m);

	void makeMove();
	void makeMove(Move m);

	bool isValidMove(Move m);
	bool isGG();
	Move getMove();

	//AI Moves
	vector<Move> AIAllMoves();
	void AImakeMove();

	void playGame();
};

#endif

