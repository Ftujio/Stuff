#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int i;
	char param = *argv[1];
	int n = param - '0';
	char* path = argv[2];
	int pr_num = argc - 3;
	char* pr_args[pr_num];
	char* args[pr_num + 1];
	
	for(i = 0; i < pr_num; i++){
		pr_args[i] = argv[i + 3];
	}
	
	args[0] = path;
	for(i = 0; i < pr_num; i++){
		args[i + 1] = pr_args[i];
	}
	args[pr_num + 1] = (char*) 0;
	// ./a.out,	4,	/bin/ls,	-l,	-a
	// 0		1	2			3	4
	
	/*for(i = 0; i < pr_num + 1; i++){
		printf("%s\n", args[i]);
	}*/
	
	for(i = 0; i < n; i++){
		pid_t pid = fork();
	
		if(pid == 0){ // Child process
			if(execv(path, args) == -1){
				printf("Error!\n");
			}
			break;
		} else if(pid < 0){
			printf(" - Failed to fork!\n");
		} else { // Parent process
			int status;
			waitpid(pid, &status, 0);
		}
	
	}

	return 0;
}