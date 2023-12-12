#include <stdio.h>
#include <pthread.h>

static int num;
void* read(void* arg);
void* accu(void* arg);
int main(){

	pthread_t t_id1,t_id2;

	pthread_create(&t_id1,NULL,read,NULL);
	pthread_create(&t_id2,NULL,accu,NULL);

	pthread_join(t_id1,NULL);
	pthread_join(t_id2,NULL);
	
	return 0;
}

void* read(void* arg)
{
	for(int i = 0; i < 5; i++){
		fputs("Input num: ",stdout);
		scanf("%d",&num);
	}
	return NULL;
}

void* accu(void* arg)
{
	int sum = 0;
	for(int i = 0; i < 5; i++){
		sum +=  num;
	}
	printf("Result : %d \n", sum);
}
