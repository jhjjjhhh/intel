#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	char* serchbook[3] = { 0 };
	char temp[50];
	getchar();
	gets(temp);
	serchbook[0] = (char*)calloc(50, sizeof(char));
	strcpy(serchbook[0], temp);
	printf("%s", serchbook[0]);

}