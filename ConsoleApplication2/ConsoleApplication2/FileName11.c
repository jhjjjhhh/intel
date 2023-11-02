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
	char ch[50] = "ȫ�浿";
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
			printf("���α׷��� �����մϴ�.\n");
			printf("**********************\n");
			break;
		}
	}
	/*	else
		{
			printf("�ٽ��Է�\n");
		}
	*/

	return 0;
}

int print_intro(void)
{
	int num;
	printf("***** �޴� *****\n");
	printf("1.���\n2.���\n3.�˻�\n4.����\n");
	printf("���� > ");
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

	printf("å�� ����մϴ�\n");

	printf("å ��ȣ �Է� :\n");
	scanf("%d", &num);
	printf("å �̸� �Է� :\n");
	getchar();
	gets(bookname);
	printf("å ���� �Է� :\n");
	gets(bookauth);
	printf("å ���ǻ� �Է� :\n");
	gets(bookpubl);
	printf("å ���� �Է� :\n");
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
	printf("NO.%5d \n�̸� :%s \n���� :%s \n���ǻ� :%s \n���� :%d ��\n��(��) ��ϵǾ����ϴ�.\n", num, bookname, bookauth, bookpubl, price);
	printf("===================================================\n");
}
void print_book(Book* pl)
{
	if (cnt != 0)
	{
		int i = 0;

		printf("===================================================\n");
		printf("å ����� ����մϴ�\n\n");
		printf("NO.   å �̸�       ����       ���ǻ�        ����\n\n");

		for (int i = 0; i < cnt; i++)
		{
			printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);

		}
		if (i == 0 && cnt == 0)
		{
			printf("***************************************************\n\n");
			printf("               ��ϵ� å�� �����ϴ� !\n\n");
			printf("***************************************************");
		}
		else
		{
			printf("\n\n       ���� ��ϵ� å�� ��� ����Ͽ����ϴ� !    \n");
		}
		printf("\n\n===================================================\n");
	}
	else
	{
		printf("===================================================\n");
		printf("\n\n ******** å�� ������� �ʾҽ��ϴ�. ******** \n\n");
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
		printf("� å�� ã�����?\n");
		printf("1. å �̸���   2. å ���ڸ�\n");
		scanf("%d", &booknum);
		if (booknum == 1)
		{
			printf("å �̸����� �Է����ּ���\n");
			getchar();
			gets(sc_bookname);
			for (int i = 0; i < cnt; i++)
			{
				if (strcmp(sc_bookname, (pl + i)->NAME) == 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** �˻��Ͻ� å�� �����Դϴ�. ******** \n\n");
					printf("NO.   å �̸�       ����       ���ǻ�        ����\n\n");
					printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);
					printf("===================================================\n");
				}
				else if (strcmp(sc_bookname, (pl + i)->NAME) != 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** �˻��Ͻ� å�� �����Դϴ�. ******** \n\n");
					printf("\n\n ********   ������ å�� �����ϴ�. ********** \n\n");
					printf("===================================================\n");
				}
			}
		}

		else if (booknum == 2)
		{
			printf("å ���ڸ��� �Է����ּ���\n");
			getchar();
			gets(sc_bookauth);
			for (int i = 0; i < cnt; i++)
			{
				if (strcmp(sc_bookauth, (pl + i)->AUTH) == 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** �˻��Ͻ� å�� �����Դϴ�. ******** \n\n");
					printf("NO.   å �̸�       ����       ���ǻ�        ����\n\n");
					printf("%d%10s%10s%12s%15d\n", (pl + i)->NUM, (pl + i)->NAME, (pl + i)->AUTH, (pl + i)->PUBL, (pl + i)->PRICE);
					printf("===================================================\n");
				}
				else if (strcmp(sc_bookauth, (pl + i)->AUTH) != 0)
				{
					printf("===================================================\n");
					printf("\n\n ******** �˻��Ͻ� å�� �����Դϴ�. ******** \n\n");
					printf("\n\n ********   ������ å�� �����ϴ�. ********** \n\n");
					printf("===================================================\n");
				}
			}
		}
	}
	else
	{
		printf("===================================================\n");
		printf("\n\n ******** å�� ������� �ʾҽ��ϴ�. ******** \n\n");
		printf("===================================================\n");
	}

}