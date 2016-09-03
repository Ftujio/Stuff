#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int flag_a = 0, flag_l = 0, flag_R = 0;

DIR* dir;
struct stat st;
struct dirent* ent;
struct group* gr;
struct passwd* pwd;
mode_t mode;

char* path;
char* tmp;
char file_t;

char file_type(mode_t mode, int index){
	char str[11] = "----------";

	// Types
	switch(mode & S_IFMT){
		case S_IFBLK: str[0] = 'b'; break; // block device
		case S_IFCHR: str[0] = 'c'; break;// char device
		case S_IFDIR: str[0] = 'd'; break; // directory
		case S_IFIFO: str[0] = 'p'; break; // pipe
		case S_IFLNK: str[0] = 'l'; break; // link
		case S_IFREG: str[0] = '-'; break; // regular file
		case S_IFSOCK: str[0] = 's'; break; // socket
	}

    // Permissions
    if( mode & S_IRUSR ) str[1] = 'r';
    if( mode & S_IWUSR ) str[2] = 'w';
    if( mode & S_IXUSR ) str[3] = 'x';

    if( mode & S_IRGRP ) str[4] = 'r';
    if( mode & S_IWGRP ) str[5] = 'w';
    if( mode & S_IXGRP ) str[6] = 'x';

    if( mode & S_IROTH ) str[7] = 'r';
    if( mode & S_IWOTH ) str[8] = 'w';
    if( mode & S_IXOTH ) str[9] = 'x';

    return str[index];
}

void run_dir(DIR* d, char* p){
	printf("%s: \n", p);

	while((ent = readdir(d)) != NULL){
		tmp = malloc(sizeof(char)*(strlen(p) + strlen(ent->d_name) + 2));
		strcpy(tmp, p);

		strcat(tmp, "/");
		strcat(tmp, ent->d_name);
		//printf("[LOG]tmp: %s\n", tmp);
		
		if((stat(tmp, &st)) == -1){
			perror("stat");
       		exit(EXIT_FAILURE);
		}

		mode = st.st_mode;
		file_t = file_type(mode, 0);

		printf("%c %s\n", file_t, ent->d_name);
	}

	printf("\n");

	closedir(d);

	if((d = opendir(p)) != NULL){

	} else {
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	while((ent = readdir(d)) != NULL){
		tmp = malloc(sizeof(char)*(strlen(p) + strlen(ent->d_name) + 2));
		strcpy(tmp, p);

		strcat(tmp, "/");
		strcat(tmp, ent->d_name);
		//printf("[LOG]tmp: %s\n", tmp);
		
		if((stat(tmp, &st)) == -1){
			perror("stat");
       		exit(EXIT_FAILURE);
		}

		mode = st.st_mode;
		file_t = file_type(mode, 0);

		if(file_t == 'd' && strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, ".") != 0){ // Recursion
			DIR* direct;
			//printf("[LOG]Dir found!\n");
			if((direct = opendir(tmp)) != NULL){
				//printf("[LOG]Going into new dir\n");
				run_dir(direct, tmp);
				closedir(direct);
			} else {
				perror("opendir");
			}
		}
	}
}

int print_dir(int argc, char* argv[]){
	path = argv[1];

	if((dir = opendir(path)) != NULL){
		run_dir(dir, path);
	} else {
		perror("opendir");
		return EXIT_FAILURE;
	}
	closedir(dir);
}

int main(int argc, char* argv[]){
	print_dir(argc, argv);

	return 0;
}