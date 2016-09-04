#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
	if(argc > 1){
		int path = *argv[1];

		if((dir = opendir(path)) != NULL){
			while((ent = readdir(dir)) != NULL){
				
			}
		}

	} else {
		printf("Provide path to the directory\n");
	}

	return 0;
}