#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


typedef struct Book {

	int NUM;
	char NAME[30];
	char AUBL[30];
	char PUBL[30];
	int PRICE;

}Book;
//func
void intro_menu();
void register_book(Book*);
void list_book();
void serch_book();
void print_book();
void print_intro();
//
int MAX_BOOK = 100;
int select;
int book_cnt = 0;

//Book* booklist;

int main() {
	Book* booklist;
	booklist = malloc(MAX_BOOK, sizeof(Book));

	printf("Library Program Start...\n");

	while (1) {
		intro_menu();
		switch (select) {
		case 1:
			register_book(booklist);
			break;
		case 2:
			list_book();
			break;
		case 3:
			serch_book();
			break;
		case 4:
			free(booklist);
			exit(1);
		}
	}
	return 0;
}

void intro_menu(){
	printf("*****************\n");
	printf("1. Book Register\n");
	printf("2. Book List\n");
	printf("3. Book Serch\n");
	printf("4. Program END\n");
	printf("*****************\n");
	printf("Menu select : ");
	scanf("%d", &select);
}

void register_book(Book* pb){

	printf("Book Register Start...\n");
	printf("Book Num : ");

	printf("Before scanf NUM\n");
	scanf("%d", &(pb[book_cnt].NUM));
	printf("After scanf NUM\n");
	printf("Book Name : ");
	printf("End");
}

void list_book(){

}

void serch_book(){

}

void print_book(){

}

void print_intro(){

}