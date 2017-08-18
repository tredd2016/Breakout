#include "Human.h"

using namespace std;

Human::Human() {} // default ... do something here

Human::Human(int i, char c){
	playerNum = i;
	playerPiece = c;
	isHuman = true;
}

Human::Human(const Human& h){
	playerNum = h.playerNum;
	playerPiece = h.playerPiece;
	isHuman = h.isHuman;
}

