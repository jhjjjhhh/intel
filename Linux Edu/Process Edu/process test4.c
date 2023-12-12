#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void timeout (int sig)
{
	if(sig == SIGALRM) puts("Time OUT!!\n");
	alarm(2);
}
int main()
{
	struct sigaction act;
	act.sa_handler = timeout; // 커널이 호출할 함수 등록
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGALRM, &act, 0);
	alarm(2);

	for(int i = 0; i < 3; i++){
		puts("wait...\n");
		sleep(10);
	}
	return 0;
}
