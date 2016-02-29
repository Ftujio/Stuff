#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "string"

#include "headers/mage.h"

using namespace std;

int main(){
	Mage m;
	
	/*
	cout << m.get_level() << endl;
	cout << m.get_xp() << endl;
	m.add_xp(500);
	cout << m.get_xp() << endl;
	m.add_xp(30);
	cout << m.get_xp() << endl;
	cout << m.get_level() << endl;
	*/
	cout << m.get_taunt(0) << endl;
	m.add_taunt("You suck!", -1);
	cout << m.get_taunt(1) << endl;
	m.add_taunt("Uninstall!", -1);
	cout << m.get_taunt(2) << endl;

	return 0;
}
