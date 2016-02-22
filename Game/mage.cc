#include "headers/mage.h"

Mage::Mage(string name, int hp, int attack, int magic): Player(name, hp, attack, magic){}

int Mage::attack() const {
	return get_magic();
}
