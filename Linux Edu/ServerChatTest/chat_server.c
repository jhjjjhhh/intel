#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUF_SIZE 100
#define MAX_CLNT 256

void* handle_clnt(void* arg);
void send_msg(char* msg, int len);
void error_handling(char* msg);

int clnt_cnt =0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	pthread_t t_id;
	if(argc!=2){
		printf("Usage : %s <port>\n",argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutx,NULL); //mutex 초기화
	serv_sock = socket(PF_INET, SOCK_STREAM, 0); //소켓 함수 호출 후 sock에 저장 PF_INET 는  IP V4 , sock_stream 는 TCP 방식  코드 자체는 거의 고정

	memset(&serv_adr, 0, sizeof(serv_adr)); // 멤버들을 초기화 한다 . memset 함수.1번 매개변수에 있는 주소(&serv_adr)들을 0으로 초기화 한다. 구조체 멤버 초기화.
	serv_adr.sin_family = AF_INET; //멤버에 값 입력
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY); //adr 구조체 -> sin_addr 구조체 안에 있는 s_addr 멤버 변수에 값 을 넣음. (htonl의  l 은 long type 4바이트)
	serv_adr.sin_port=htons(atoi(argv[1]));  // htons 의 s 는 short 이며 2바이트 크기의 port 를 atoi -> a 를 i 로바꿔라  ex) 8080 은 char -> int로 변환

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)))
		error_handling("bind()error");
	if(listen(serv_sock,5) == -1) //5는 동시접속 가능자 5명
		error_handling("listen()error");
	while(1) //접속이 되면 서버 소켓을 닫는다 ?
	{
		clnt_adr_sz=sizeof(clnt_adr);
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr,&clnt_adr_sz);

		pthread_mutex_lock(&mutx);
		clnt_socks[clnt_cnt++]=clnt_sock;
		pthread_mutex_unlock(&mutx);

		pthread_create(&t_id, NULL, handle_clnt,(void*)&clnt_sock);
		pthread_detach(t_id);
		printf("Connected client IP %s \n",inet_ntoa(clnt_adr.sin_addr));
	}
	close(serv_sock);
	return 0;
}
void* handle_clnt(void* arg)
{
	int clnt_sock=*((int*)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];

	while((str_len = read(clnt_sock, msg, sizeof(msg))) != 0)
		send_msg(msg,str_len);

	pthread_mutex_lock(&mutx);
	for(i = 0; i < clnt_cnt; i++){
		if(clnt_sock == clnt_socks[i]){
			while(i++ < clnt_cnt-1)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}
	clnt_cnt--;
	pthread_mutex_unlock(&mutx);
	close(clnt_sock);
	return NULL;
}
void send_msg(char* msg,int len)
{
	int i;
	pthread_mutex_lock(&mutx);
	for(i=0;i<clnt_cnt;i++){
		write(clnt_socks[i],msg,len);
	}
	pthread_mutex_unlock(&mutx);
}
void error_handling(char* msg)
{
	fputs(msg, stderr);
	fputc('\n',stderr);
	exit(1);
}
