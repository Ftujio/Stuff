#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	char* file_name = argv[1];
	char a = *argv[2], b = *argv[3];
	char buff[100];
	int bytes_read, i, c;
	
	int fd = open(file_name, O_RDONLY);
	
	while((bytes_read = read(fd, buff, 100)) > 0){
		for(i = 0; i < bytes_read; i++){
			if(buff[i] == a){
				buff[i] = b;
			}
		}
		while(c = write(STDOUT_FILENO, buff, bytes_read) > bytes_read){
			
		}
	}
	
	close(fd);
	
	printf("\n");

	return 0;
}