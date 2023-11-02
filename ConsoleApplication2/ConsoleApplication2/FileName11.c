#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_intro(void);
void register_book();
void print_book();
void seach_book();

typedef struct _book
{
	int NUM;
	char NAME[100];
	char AUTH[100];
	char PUBL[100];
	int PRICE;
}Book;
int cnt = 0;
int main()
{
	Book booklist[100] = { "" };
	char* serchbook[100];
	serchbook[0] = (char*)calloc(100, sizeof(char));
	char ch[50] = "홍길동";
	strcpy((booklist + 0)->NAME, ch);
	strcpy(serchbook[0], (booklist + 0)->NAME);
	printf("%s", serchbook[0]);
	int sel;

	while (1)
	{
		sel = print_intro();
		if (sel == 1)
		{
			register_book(booklist);
		}
		else if (sel == 2)
		{
			print_book(booklist);
		}
		else if (sel == 3)
		{
			seach_book(booklist);
		}
		else if (sel == 4)
		{
			printf("**********************\n");
			printf("프로그램을 종료합니다.\n");
			printf("**********************\n");
			break;
		}
	}
	/*	else
		{
			printf("다시입력\n");
		}
	*/

	return 0;
}

int print_intro(void)
{
	int num;
	printf("***** 메뉴 *****\n");
	printf("1.등록\n2.목록\n3.검색\n4.종료\n");
	printf("선택 > ");
	scanf("%d", &num);
	return num;
}
void register_book(Book* pl)
{
	int num = 0;
	int price = 0;
	char bookname[100];
	char bookauth[100];
	char bookpubl[100];

	printf("책을 등록합니다\n");

	printf("책 번호 입력 :\n");
	scanf("%d", &num);
	printf("책 이름 입력 :\n");
	getchar();
	gets(bookname);
	printf("책 저자 입력 :\n");
	gets(bookauth);
	printf("책 출판사 입력 :\n");
	gets(bookpubl);
	printf("책 가격 입력 :\n");
	scanf("%d", &price);

	static int i = 0;

	(pl + i)->NUM = num;
	strcpy((pl + i)->NAME, bookname);
	strcpy((pl + i)->AUTH, bookauth);
	strcpy((pl + i)->PUBL, bookpubl);
	(pl + i)->PRICE = price;
	i++;
	cnt++;
	printf("===================================================\n");
	printf("NO.%5d \n이름 :%s \n저자 :%s \n출판사 :%s \n가격 :%d 원\n이(가) 등록되었습니다.\n", num, bookname, bookauth, bookpubl, price);
	printf("===================================================\n");
}
void print_book(Book* pl)
{
	if (cnt != 0)
	{
		int i = 0;

		printf("===================================================\n");
		printf("책 목록을 출력합니다\n\n");
		printf("NO.   책 이름       저자       출판사        가격\n\n");

		for (int i = 0; i < cnt; i++)
		{
			printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);

		}
		if (i == 0 && cnt == 0)
		{
			printf("***************************************************\n\n");
			printf("               등록된 책이 없습니다 !\n\n");
			printf("***************************************************");
		}
		else
		{
			printf("\n\n       현재 등록된 책을 모두 출력하였습니다 !    \n");
		}
		printf("\n\n===================================================\n");
	}
	else
	{
		printf("===================================================\n");
		printf("\n\n ******** 책을 등록하지 않았습니다. ******** \n\n");
		printf("===================================================\n");
	}
}
void seach_book(Book* pl)
{
	if (cnt != 0)
	{
		char sc_bookname[20];
		char sc_bookauth[20];
		int booknum = 0;
		printf("어떤 책을 찾을까요?\n");
		printf("1. 책 이름명   2. 책 저자명\n");
		scanf("%d", &booknum);
		if (booknum == 1)
		{
			printf("책 이름명을 입력해주세요\n");
			getchar();
			gets(sc_bookname);
			for (int i = 0; i < cnt; i++)
			{
				if (strcmp(sc_bookname, (pl + i)->NAME) == 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** 검색하신 책의 정보입니다. ******** \n\n");
					printf("NO.   책 이름       저자       출판사        가격\n\n");
					printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);
					printf("===================================================\n");
				}
				else if (strcmp(sc_bookname, (pl + i)->NAME) != 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** 검색하신 책의 정보입니다. ******** \n\n");
					printf("\n\n ********   동일한 책이 없습니다. ********** \n\n");
					printf("===================================================\n");
				}
			}
		}

		else if (booknum == 2)
		{
			printf("책 저자명을 입력해주세요\n");
			getchar();
			gets(sc_bookauth);
			for (int i = 0; i < cnt; i++)
			{
				if (strcmp(sc_bookauth, (pl + i)->AUTH) == 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** 검색하신 책의 정보입니다. ******** \n\n");
					printf("NO.   책 이름       저자       출판사        가격\n\n");
					printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);
					printf("===================================================\n");
				}
				else if (strcmp(sc_bookauth, (pl + i)->AUTH) != 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** 검색하신 책의 정보입니다. ******** \n\n");
					printf("\n\n ********   동일한 책이 없습니다. ********** \n\n");
					printf("===================================================\n");
				}
			}
		}
	}
	else
	{
		printf("===================================================\n");
		printf("\n\n ******** 책을 등록하지 않았습니다. ******** \n\n");
		printf("===================================================\n");
	}

}