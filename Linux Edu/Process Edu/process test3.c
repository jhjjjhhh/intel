#include <stdio.h>
#include <unistd.h>

int globalVal = 100;
int main()
{
	pid_t pid;
	int localVal = 100;
	localVal++;
//	printf("값증가 \n");
	pid = fork(); //자식프로세스 생성
//	printf("double\n");
//	localVal++;
	if(pid != 0){
		localVal *= 2;
		globalVal = globalVal -1;
	}else {
		localVal *= 5;
		globalVal = globalVal +1;
	}

	if(pid == 0){
		printf("child process localVal : %d\t globalVal : %d \n", localVal, globalVal);
	}else{
		printf("parent process localVal : %d\t globalVal : %d \n",localVal, globalVal);
	}
	return 0;
}
