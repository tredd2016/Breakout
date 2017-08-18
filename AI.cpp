#include "AI.h"

AI::AI() {} // default constructor (to fill in?)

AI::AI(int i, char c){
	playerNum = i;
	playerPiece = c;
	isHuman = false;
}

AI::AI(const AI& p){
	playerNum = p.playerNum;
	playerPiece = p.playerPiece;
	isHuman = p.isHuman;
}
