#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "string"

#include "headers/mage.h"

using namespace std;

int main(){
	Mage m;
	
	cout << m.get_level() << endl;
	cout << m.get_xp() << endl;
	m.add_xp(500);
	cout << m.get_xp() << endl;
	m.add_xp(30);
	cout << m.get_xp() << endl;
	cout << m.get_level() << endl;
	



	return 0;
}
