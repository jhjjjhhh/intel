#include <stdio.h>
#include <pthread.h>

#define THREADS 100

void* thread_inc(void*);
void* thread_des(void*);
long long num = 0;
int main()
{
	pthread_t thread_id[THREADS];
	int i;
	printf("size of long long : %ld \n", sizeof(long long));
	for(i = 0; i < THREADS; i++){
		if(i % 2){
			pthread_create(&(thread_id[i]),NULL,thread_inc,NULL);
		}
		else{
			pthread_create(&(thread_id[i]),NULL,thread_des,NULL);
		}
	}
	for(i = 0; i< THREADS; i++){
		pthread_join(thread_id[i], NULL);
	}
	printf("result : %lld \n",num);
	
	return 0;
}
void* thread_inc(void* arg)
{
	int i;
	for(i = 0; i < 50000000; i++){
		num += 1;
	}
	return NULL;
}
void* thread_des(void* arg)
{
	int i;
	for(i = 0; i < 50000000; i++){
		num -= 1;
	}
	return NULL;
}
