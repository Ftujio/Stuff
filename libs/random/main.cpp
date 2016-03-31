#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "unistd.h"

#include "random.h"

using namespace std;

int main(){
	cout << Random::get_rand() << endl;
	cout << Random::get_rand(1, 10) << endl;

	return 0;
}
