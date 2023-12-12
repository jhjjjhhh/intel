#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void* thread_main(void* arg);

int main()
{
	pthread_t t_id;
	int thread_param = 5;
	void* t_ret;
	if(pthread_create(&t_id, NULL, thread_main, &thread_param)!= 0){
		puts("pthread_create error!!!");
		return -1;
	}
	if(pthread_join(t_id, &t_ret) !=0){
		puts("pth\n");
         sleep(10);
     }
read_join error!!!");
		return -1;
	}
	printf("thread return message : %s\n", (char*)t_ret);
	free (t_ret);
	return 0;
}
void* thread_main(void* arg)
{
	int cnt = *((int*)arg);
	char* msg = (char*)malloc(sizeof(char) * 50);
	strcpy(msg,"hello,I'm thread !\n");
	for(int i = 0; i < cnt; i++){
		puts("running thread!!");
//		puts(msg);
		sleep(1);
	}
	return (void*)msg;
}
