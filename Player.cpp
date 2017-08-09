#include "Player.h"

Player::Player(){
	// default constructor...do something here
}

Player::Player(int i, char c){
	playerNum = i;
	playerPiece = c;
}

Player::Player(const Player& p){
	playerNum = p.playerNum;
	playerPiece = p.playerPiece;
}

int Player::getPlayerNum() const {
	return playerNum;
}

char Player::getPlayerPiece() const {
	return playerPiece;
}

void Player::setPlayerNum(int i){
	playerNum = i;
}

void Player::setPlayerPiece(char c){
	playerPiece = c;
}
