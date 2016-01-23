#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "unistd.h"

#include "include/rand.h"
#include "include/maze.h"

using namespace std;

int main(){
	Rand r;
	while(1){
		cout << r.get_rand(15, 14) << endl;
		sleep(1);
	}
	
	return 0;
}
