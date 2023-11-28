#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXBooks 100

typedef struct bookinfo
{
	int num;
	char title[100];
	char writer[100];
	char publish[100];
	int price;
	int borrownum;

} book;
char stitle[100];
int i, count, found;
book list[MAXBooks];
void registerbooks(book list[]);
void deletebook();
void listofbook();
void searchbook(book list[], char stitle[]);
void borrow();
void return_();
void BACKMENU();
void print();
int typo(const char* type);

int main()
{
	while (1) {

		printf("��  ��  ��  ��  ��  ��\n\n******MENU******\n\n");
		printf("1. ���\n2. ���\n3. �˻�\n4. ����\n5. �ݳ�\n6. ���� ����\n0. ����\n\n\n");
		int menu = typo("����ϰ��� �ϴ� ����� ���ڸ� �Է��Ͻÿ� :");

		switch (menu)
		{
		case 1:
			registerbooks(list);
			BACKMENU();
			break;

		case 2:
			listofbook();
			BACKMENU();
			break;

		case 3:
			searchbook(list, stitle);
			BACKMENU();
			break;

		case 4:
			borrow();
			BACKMENU();
			break;

		case 5:
			return_();
			BACKMENU();
			break;

		case 6:
			deletebook();
			BACKMENU();
			break;

		case 0:
			printf("\n\n���α׷��� �����մϴ�.\n\n");
			exit(0);
			break;

		default:
			printf("\n\n��ȿ�� �޴��� �����ϼ���.\n\n");
			break;
		}
	}
	return 0;
}

void registerbooks(book list[])
{
	int numbook = typo("����� å�� �� ���� �Է��ϼ���\n");
	//printf("����� å�� �� ���� �Է��ϼ���\n");
	//scanf("%d", &numbook);

	if (numbook > MAXBooks)
	{
		printf("100�� �̻� å ��� �Ұ��մϴ�.\n");
		return;
	}

	for (i = 0; i < numbook; i++)
	{
		printf("\n%d��° å ������ �Է��ϼ���:\n\n", count + i + 1);
		list[count + i].num = count + i + 1;
		printf("������ �Է��ϼ��� : ");
		scanf("%s", list[count + i].title);
		printf("�۰��� �Է��ϼ��� : ");
		scanf("%s", list[count + i].writer);
		printf("���ǻ縦 �Է��ϼ��� : ");
		scanf("%s", list[count + i].publish);
		list[count + i].price = typo("������ �Է��ϼ��� : ");
		//printf("������ �Է��ϼ��� : ");
		//scanf("%d", &list[count + i].price);
	}

	count += numbook;

	for (i = count - numbook; i < count; i++)
	{
		list[i].borrownum = 0;
	}

	printf("����� å ����\n\n");
	for (i = count - numbook; i < count; i++)
	{
		print();
	}
}

void listofbook()
{
	printf("\n\n   å ���\n\n");
	for (i = 0; i < count; i++)
	{
		print();
	}
}

void searchbook(book list[], char stitle[])
{
	printf("�˻��� å ������ �Է��ϼ���. : ");
	scanf("%s", stitle);

	for (i = 0; i < count; i++)
	{
		if (strcmp(list[i].title, stitle) == 0)
		{
			print();
			found = 1;
		}
	}

	if (!found)
	{
		printf("\n\nã���ô� å�� �����ϴ�.\n\n\n");
	}
}

void borrow()
{
	printf("���� ������ å\n");
	for (i = 0; i < count; i++)
	{
		if (list[i].borrownum == 0)
		{
			print();
		}
	}

	int cborrownum = typo("������ å ��ȣ�� �Է��ϼ���.\n");

	for (i = 0; i < count; i++)
	{
		if (cborrownum == list[i].num)
		{
			found = 1;
			if (list[i].borrownum == 0)
			{
				list[i].borrownum = 1;
				printf("%d�� å ���� �߽��ϴ�.\n\n", cborrownum);
			}
			else
			{
				printf("���� �Ұ����մϴ�.\n\n");
			}
		}
	}

	if (!found)
	{
		printf("å ��ȣ�� �������� �ʽ��ϴ�.\n\n");
	}

}

void return_()
{
	printf("�ݳ� ������ å\n");
	for (i = 0; i < count; i++)
	{
		if (list[i].borrownum == 1)
		{
			print();
		}
	}

	int cborrownum = typo("�ݳ��� å ��ȣ�� �Է��ϼ���.\n");

	for (i = 0; i < count; i++)
	{
		if (cborrownum == list[i].num)
		{
			found = 1;
			if (list[i].borrownum == 1)
			{
				list[i].borrownum = 0;
				printf("%d�� å �ݳ� �߽��ϴ�.\n\n", cborrownum);
			}
			else
			{
				printf("�ݳ� �Ұ����մϴ�.\n\n");
			}
		}
	}

	if (!found)
	{
		printf("å ��ȣ�� �������� �ʽ��ϴ�.\n\n");
	}

}

void BACKMENU()
{
	int back = typo("�޴��� ���ư��ðڽ��ϱ� ? \n\nYes[1]	  No[0]\n\n");

	if (back == 0)
	{
		printf("\n���α׷��� �����մϴ�.\n\n");
		exit(0);
	}
}

void deletebook()
{
	printf("���� ������ å ���\n");

	for (i = 0; i < count; i++)
	{
		if (list[i].borrownum == 0)
		{
			print();
		}
	}

	int delete = typo("������ å ��ȣ�� �Է��ϼ���.\n");
	int deletenum = -1;

	for (i = 0; i < count; i++)
	{
		if (delete == list[i].num)
		{
			deletenum = i;
			break;
		}
	}

	if (deletenum != -1)
	{
		if (list[deletenum].borrownum == 1)
		{
			printf("���� ���� å�� ������ �� �����ϴ�.\n");
		}
		else
		{
			for (int j = deletenum; j < count - 1; j++)
			{
				list[j] = list[j + 1];
			}
			list[count - 1].num = 0;
			strcpy(list[count - 1].title, "");
			strcpy(list[count - 1].writer, "");
			strcpy(list[count - 1].publish, "");
			list[count - 1].price = 0;
			list[count - 1].borrownum = 0;
			count--;
			for (int j = 0; j < count; j++)
			{
				list[j].num = j + 1;
			}
		}
	}
	else
	{
		printf("å�� ã�� �� �����ϴ�.\n");
	}
}

void print()
{
	printf("\n\n%d  %s  %s  %s  %d",
		list[i].num, list[i].title, list[i].writer, list[i].publish, list[i].price);
	if (list[i].borrownum == 1) {
		printf("\t������...\n");
	}
	else printf("\n\n");
}

int typo(const char* type)
{
	int num;

	while (1) {
		printf("%s", type);
		if (scanf("%d", &num) == 1 && num >= 0) {
			break;
		}
		else {
			printf("�ùٸ� ���ڸ� �Է��ϼ���.\n");
			while (getchar() != '\n');  // �Է� ���� ����
		}
	}

	return num;
}
