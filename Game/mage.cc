#include "headers/mage.h"

Mage::Mage(string name, int hp, int attack, int magic): Player(name, hp, attack, magic){}
Mage::Mage(): Player("Gandalf", 15, 2, 10){};

int Mage::attack() const {
	return get_magic();
}
