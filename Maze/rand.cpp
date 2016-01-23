#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "time.h"

#include "include/rand.h"

using namespace std;

Rand::Rand(){
	
}

int Rand::get_rand(){
	srand(time(0));
	return rand();
}

int Rand::get_rand(int from, int to){
	if(from > to){
		throw RandError(1);
	}
	srand(time(0));
	return from + rand()%(to+1 - from);
}

//------------------------------------------------------------------------------------------------------------------

Rand::RandError::RandError(){
	cout << "Random Error" << endl;
}

Rand::RandError::RandError(int err){
	switch(err){
		case 1:
			cout << "Random Error, invalid use: from should be \"smaller\" than \"to\"" << endl;
			break;
		default:
			cout << "Random Error" << endl;
	}
}
