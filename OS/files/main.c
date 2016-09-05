#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void open_file(char* file){
	int bytes_read, i, c;
	char buff[100];

	int fd = open(file, O_RDONLY);

	printf("##########################################################\n%s:\n\n", file);
	while((bytes_read = read(fd, buff, 100)) > 0){
		while((c = write(STDOUT_FILENO, buff, bytes_read)) > bytes_read){}
	}
	printf("\n\n");
}

int main(int argc, char* argv[]){
	int i;

	if(argc > 1){
		int num_of_files = argc - 1;
		for(i = 0; i < num_of_files; i++){
			open_file(argv[i + 1]);
		}
		printf("##########################################################\n");
	} else {
		printf("Not enough arguements provided. Usage: ./f <filename>\n");
	}

	return 0;
}