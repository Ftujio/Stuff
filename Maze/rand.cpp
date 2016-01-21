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
	srand(time(0));
	return from + rand()%(to - from) + 1;
}
