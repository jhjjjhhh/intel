#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd1, fd2;
	fd1 = open("test1.txt",O_CREAT | O_RDWR);
	fd2 = open("test2.txt",O_CREAT | O_RDWR);

	printf("file descriptor 1 : %d\n",fd1);
	printf("file descriptor 2 : %d\n",fd2);
	return 0;
}
