#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "string"

#include "headers/mage.h"

using namespace std;

int main(){
	Mage m;
	
	cout << m.get_name() << " attacked you with " << m.attack() << " magic. GET REKT" << endl;

	return 0;
}
