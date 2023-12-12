#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0) puts("i'm child process!!\n");
	else{
		printf("child process ID: %d\n",pid);
		sleep(30);
	}
	if(pid == 0) puts("END Child process!!\n");
	else puts("END parent process!!\n");
	return 0;
}
