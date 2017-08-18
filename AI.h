#ifndef AI_H
#define AI_H

#include "Player.h"
#include<vector>

using namespace std;

class GameBoard;


class AI: public Player{
public:
	AI(); // Default Constructor
	AI(int i, char c);
	AI(const AI& p); // Copy

};
#endif