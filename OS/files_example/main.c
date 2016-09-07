#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[]){
	char* path = argv[1];
	int fd;
	ssize_t bytes_read;
	ssize_t bytes_written;
	char buff[100];
	int comma_count = 0;
	int sentence_count = 0;

	if((fd = open(path, O_RDONLY)) == -1){
		perror("open");
		return 1;
	}

	while(1){
		bytes_read = read(fd, buff, 100);
		int i;

		if(bytes_read == -1){
			perror("read");
			return 1;
		}

		for(i = 0; i < bytes_read; i++){
			if(buff[i] == ','){
				comma_count++;
			}

			if(buff[i] == '.' || buff[i] == '?' || buff[i] == '!'){
				if(buff[i - 1] != '.'){
					sentence_count++;
				}
			}
		}

		if(bytes_read == 0){
			break;
		} else {
			int total_written = 0;
			while(total_written < bytes_read){
				bytes_written = write(STDOUT_FILENO, buff, bytes_read);

				if(bytes_written == -1){
					perror("write");
					return 1;
				}

				total_written += bytes_written;
			}
		}
	}


	printf("\n");
	printf("Number of commas: %d\n", comma_count);
	printf("Number of sentences: %d\n", sentence_count);

	return 0;
}