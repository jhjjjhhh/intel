#include <stdio.h>
#include <pthread.h>

int sum = 0;
void* thread_summation(void*);

int main()
{

	pthread_t t_id1, t_id2;
	int range1[] = {1, 5};
	int range2[] = {6, 10};

	pthread_create(&t_id1, NULL, thread_summation, (void*)range1);
	pthread_create(&t_id2, NULL, thread_summation, (void*)range2);

	pthread_join(t_id1, NULL);
	pthread_join(t_id2, NULL);
	printf("result: %d\n",sum);

	return 0;
}

void* thread_summation(void* arg)
{
	int start = ((int*)arg)[0];
	int end = ((int*)arg)[1];
	while(start <=end){
//		sum += start;
//		start++;
		printf("start : %d , end : %d ",start , end);
		printf("sum : %d\n",sum);
		sum += start;
		start++;
	}
	return NULL;
}
