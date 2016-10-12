#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include <time.h>

DIR* dir;
struct stat st;
struct dirent* ent;
struct group* grp;
struct passwd* pwd;
mode_t mode;

char* path;
char* tmp;
char file_t;

int flag_a = 0;
int flag_l = 0;
int flag_R = 0;

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

	while(1){
		errno = 0;
		ent = readdir(d);

		if(ent == NULL){
			if(errno != 0){
				perror("readdir");
				break;
			}
			
			break;
		}	

		tmp = malloc(sizeof(char)*(strlen(p) + strlen(ent->d_name) + 2));
		strcpy(tmp, p);

		strcat(tmp, "/");
		strcat(tmp, ent->d_name);
		//printf("[LOG]tmp: %s\n", tmp);
		
		if((stat(tmp, &st)) == -1){
			perror("stat");
       		//exit(EXIT_FAILURE);
       		break;	
		}

		mode = st.st_mode;
		file_t = file_type(mode, 0);

		pwd = getpwuid(st.st_uid);
		grp = getgrgid(st.st_gid);

		if(flag_l){
			int i;
			char timbuf[80];
			time_t t = st.st_mtime;
			struct tm lt;

			for(i = 0; i < 10; i++){
				printf("%c", file_type(mode, i));
			}
		
			localtime_r(&t, &lt);
			strftime(timbuf, sizeof(timbuf), "%c", &lt);
			//strftime(buffer, 26, "%d.%m:%Y %H:%M:%S", tm_info);

			printf("\t%d", (int)st.st_nlink);
			printf("\t%s", pwd->pw_name);
			printf("\t%s", grp->gr_name);
			printf("\t%d", (int)st.st_size);
			printf("\t%s", timbuf);
			if(flag_a){
				printf(" %s\n", ent->d_name);
			} else {
				if(ent->d_name[0] != '.'){
					printf(" %s\n", ent->d_name);
				} else {
					printf("\n");
				}
			}
		} else {
			if(flag_a){
				printf("%c %s\n", file_t, ent->d_name);
			} else {
				if(ent->d_name[0] != '.'){
					printf("%c %s\n", file_t, ent->d_name);
				}
			}
		}
	}

	printf("\n");

	closedir(d);

	if((d = opendir(p)) != NULL){

	} else {
		perror("opendir");
		int errnum = errno;
		//fprintf(stderr, "Error opening directory: %s\n", strerror(errnum));
		exit(EXIT_FAILURE);
	}

	// For printing the sub directories after displaying the content
	if(flag_R){
		printf("------------------------------\n\n");
		while(1){
			errno = 0;
			ent = readdir(d);

			if(ent == NULL){
				if(errno != 0){
					perror("readdir");
					break;
				}

				break;
			}

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

				if((direct = opendir(tmp)) != NULL){
					run_dir(direct, tmp);
					closedir(direct);
				} else {
					//fprintf(stderr, "[ERROR]\t%s\n", strerror(errno));
					perror("opendir");
				}
			}
		}
	}
}

int print_dir(char* argv){
	path = argv;

	if((dir = opendir(path)) != NULL){
		run_dir(dir, path);
	} else {
		//fprintf(stderr, "[ERROR]\t%s\n", strerror(errno));
		perror("opendir");
		return EXIT_FAILURE;
	}
	closedir(dir);
}

int main(int argc, char* argv[]){
	if(argc > 1){
		int i;
		int c;
		int o = 1;

		while((c = getopt(argc, argv, "Rla")) != -1){
			switch(c){
				case 'a':
					flag_a = 1;
					break;
				case 'l':
					flag_l = 1;
					break;
				case 'R':
					flag_R = 1;
					break;
				default:
					o = 2;
			}

			if(c == 'a'){
				flag_a = 1;
			}
			if(c == 'l'){
				flag_l = 1;
			}
			if(c == 'R'){
				flag_R = 1;
			}
		}
		
		for(i = 0; i < argc - optind; i++){
			print_dir(argv[i + optind]);
			printf("\n##############################\n\n\n");	
		}
	} else { // No arguements passed
		printf("[ERROR]\tMust provide path to the directory\n");
	}

	free(tmp);

	return 0;
}