#include "string"

#include "player.h"

using std::string;

class Mage: public Player{

public:
	Mage(string name, int hp, int attack, int magic);
	Mage();
	
	int attack(int attack);
};
