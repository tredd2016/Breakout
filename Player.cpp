#include "Player.h"
Player::Player(int i){
	playerNum = i;
}

Player::Player(const Player& p){
	playerNum = p.playerNum;
}

int Player::getPlayerNum() const {
	return playerNum;
}

void Player::setPlayerNum(int i){
	playerNum = i;
}



