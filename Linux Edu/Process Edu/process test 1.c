#include <stdio.h>
#include <unistd.h>

int main(){
	printf("the process id is %d \n", (int)getpid());
	printf("the parent process id is %d\n", (int)getppid());
}
