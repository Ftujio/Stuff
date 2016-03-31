#include "cstdlib"
#include "cstdio"
#include "time.h"

#include "random.h"

Random::Random(){}

int Random::get_rand(){
    srand(time(0)%rand());
	return rand();
}

int Random::get_rand(int from, int to){
    srand(time(0)%rand());
	return from + rand()%(to+1 - from);
}
