#include "Player.h"

int Player::getPlayerNum() const {
	return playerNum;
}

char Player::getPlayerPiece() const {
	return playerPiece;
}

//Not super safe
char Player::getOppPiece(){
	if(playerPiece == 'X') return 'O';
	else return 'X';
}

void Player::setPlayerNum(int i){
	playerNum = i;
}

void Player::setPlayerPiece(char c){
	playerPiece = c;
}

bool Player::isHumanPlayer(){
	if(isHuman) return true;
	else return false;
}
