#include <iostream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int num = 10; //���� �� �ʱ�ȭ
	int* p1 = new int; // ������ p �����Ҵ� (heap�� ������ p ���� �Ҵ�)
	int *p = &num; // ������ p�� num�� ����Ŵ
	int& ref = *p; // p�� ���������� ref�� ������ => �� ������ ���� ref �� heap ������ ������.


	num = 40;
	ref = 20;
	
	cout << "num �� �ּҰ� :" << &num << endl;
	cout << "������ p �� ����Ű�� �ּڰ� : " << p << endl;
	cout << "&(*p)�� �� :" << &(*p) << endl; //p�� �������� : num�� ��
	cout << "p�� �ּڰ�" << &p << endl; //������ p�� ��ü �ּڰ� ���ʹ� �ٸ����� ���;���.
	cout << "������ ref �� �ּڰ� " << &ref << endl;

	cout << "* p�� �� : " << *p << endl;
	cout << "ref �� : " << ref << endl;

	delete p1;


	return 0;
}