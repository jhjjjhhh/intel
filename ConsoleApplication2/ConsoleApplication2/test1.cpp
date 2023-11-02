#include <iostream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num = 10; //선언 및 초기화
	int* p1 = new int; // 포인터 p 동적할당 (heap에 포인터 p 공간 할당)
	int *p = &num; // 포인터 p는 num을 가리킴
	int& ref = *p; // p의 간접참조를 ref가 참조함 => 즉 포인터 없이 ref 도 heap 영역에 접근함.


	num = 40;
	ref = 20;
	
	cout << "num 의 주소값 :" << &num << endl;
	cout << "포인터 p 가 가르키는 주솟값 : " << p << endl;
	cout << "&(*p)의 값 :" << &(*p) << endl; //p의 간접참조 : num의 값
	cout << "p의 주솟값" << &p << endl; //포인터 p의 자체 주솟값 위와는 다른값이 나와야함.
	cout << "참조자 ref 의 주솟값 " << &ref << endl;

	cout << "* p의 값 : " << *p << endl;
	cout << "ref 값 : " << ref << endl;

	delete p1;


	return 0;
}