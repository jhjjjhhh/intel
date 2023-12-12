#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

//static int num;
void* read(void* arg);
void* accu(void* arg);
static int num;
static sem_t sema_one; 
static sem_t sema_two;

int main(){

	pthread_t t_id1,t_id2;

	sem_init(&sema_one, 0, 0); //세마포어 생성 초기값 0
	sem_init(&sema_two, 0, 1); // 세마포어 생성 초기값 1
	
	pthread_create(&t_id1,NULL,read,NULL);
	pthread_create(&t_id2,NULL,accu,NULL);

	pthread_join(t_id1,NULL);
	pthread_join(t_id2,NULL);

	sem_destroy(&sema_one); // 세마포어 소멸
	sem_destroy(&sema_two);
	return 0;
}

void* read(void* arg)
{
	for(int i = 0; i < 5; i++){
		fputs("Input num: ",stdout);
		sem_wait(&sema_two);
		scanf("%d",&num);
		sem_post(&sema_one);
	}
	return NULL;
}

void* accu(void* arg)
{
	int sum = 0;
	for(int i = 0; i < 5; i++){
		sem_wait(&sema_one); //one : 0 two : 1
		sum +=  num;
		sem_post(&sema_two);
	}
	printf("Result : %d \n", sum);
}
