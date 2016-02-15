#include "cstdlib"
#include "cstdio"

#include "random.h"

Random::Random(){
	srand(time(0));
	srnad(rand());
}

int Random::get_random(){
	return rand();
}

int Random::get_random(int from, int to){
	return from + rand%(to+1 - from);
}
