#include<iostream> // need this even?
using namespace std; // need this?

class Player{
public:
	Player(); // Default constructor
	Player(int i); // constructor
	Player(const Player& p); // Copy constructor
	//~Player();  // Desturctor
	
	//Member functions
	int getPlayerNum() const;
	void setPlayerNum(int i);


private:
	int playerNum;
};
