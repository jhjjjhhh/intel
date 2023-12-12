#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv){
	int fd, count;
	int buf[512];

	/*명령 행에서 파일 이름과 문자열을 가져오기 때문에
	인자의 개수가 2보다 작으면 사용법 출력 후 종료 */

	if(argc < 2){
		printf("usage : %s fileName[string]\n", argv[1]);
		return 0;
	}
	/*첫 번째 인자(argv[1])를 파일 이름으로 하여 파일을 "열고"
	핸들을 얻어온다. 파일에 읽기 쓰기 접근을 위해 0_RDWR 플래그를,
	만약 파일이 존재하지 않을 경우 새로 생성하라는 의미의 0_CREAT 플래그를
	함께 주었다. 역기서 퍼미션 매개변수는 생략하였다.
	open의 리턴값이 음수일 경우 open 시스템 콜의 실패를 의미하므로
	프로그램을 종료한다.*/
	if((fd = open(argv[1], O_RDWR | O_CREAT)) < 0){
		perror("open erro");
		return 1;
	}

	/*파일 이름 뒤에 인자가 하나 더 있으면 (argv[2])해당 인자를 문자열로
	하여 파일에 쓴다 여기서 문자열의 크기를 구하기 위해 strlen()함수를
	사용하였다 */

	if (argc >= 3){
		count = write(fd, argv[2], strlen(argv[2]));
		printf("write to file %d byte\n",count);
		printf("%ls\n",buf);
	}else{
		count = read(fd, buf, 512);
		printf("read from file %d byte\n",count);
		printf("%s\n",buf);
	}

	/* 열린 파일은 시스템의 자원 (메모리)을 사용하므로 사용이 끝나면
	닫아준다. 물론 명시적으로 닫지 않아도 프로그램이 종료되는 시점에
	리눅스 커널이 열린 파일들을 닫아준다 */
	printf("dis : %d\n", fd);
	close(fd);
}
