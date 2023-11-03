#include <iostream>
#include "Point.h"

#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define MAX(x,y) (((x) > (y)) ? (x) : (y)) //만약 x,y가 같은 값이면 false 인 y 값이 반환됌

using namespace std;



void swap(int& a, int& b);

int main()
{
	point p1(10, 10), p2(20, 30), p3, p4; //객체 선언..!! 객체는 생성자를 거쳐 초기화 된 멤버가 있는 걸 객체라고한다.
	//p4 = p3; // class 객체 값은 대입이 가능함.
	//
	//rect r(p1, p2);
	//
	//double res = p1.Dist(p1, p2);
	//double res1 = p1.Dist(p2);
	//double res2 = p3.Dist(p1, p2);
	//
	//p3.PrintP(p2);
	//p3.PrintP(p4);

	//cout << fixed;
	//cout.precision(2); //소숫점

	//cout << res << endl;
	//cout << res1 << endl;
	//cout << res2 << endl;

	//point LL = r.getLL(p1, p2);
	//point LR = r.getLR(p1, p2);
	//point UL = r.getUL(p1, p2);
	//point UR = r.getUR(p1, p2);

	//cout << LL.x << LL.y << endl;
	//cout << LR.x << LR.y << endl;
	//cout << UL.x << UL.y << endl;
	//cout << UR.x << UR.y << endl;
	//
	///*int a, b;
	//a = 10; b = 20;*/

	int a(10), b(20);
	
	swap(a, b);

	/* class, 구조체 배열은 default 초기화가 되지만. 포인터 배열은  default 초기화가 안된다.
		포인터 배열은 반드시 초기화 해줘야한다. ( 동적 할당 ) 필수
	*/

	point arr[3]; //  point p1,p2,p3 와 동일하다 보면됌. 3개의 point 클래스 객체가 초기화됨.(default 초기화)  실변수는 . (점) 포인터는 ->
	arr[0].SetP(10, 10);
	arr[1].SetP(20, 30);
	arr[2].SetP(40, 60);
	cout << sizeof(arr) << endl;
	point* parr[3]; // point 객체 포인터( * ) 배열 현재 각각의 요소엔 실체가 없다. 빈 주소만 있다. (default 초기화가 안됌) :객체화 되어 있지 않음 
	parr[0] = new point;
	parr[1] = new point(20, 30);
	parr[2] = new point(40, 60);
	cout << sizeof(parr) << endl;
	parr[0]->SetP(33, 10);
	p3.PrintP(arr[0]);
	p3 .PrintP(arr[1]);
	p3 .PrintP(arr[2]);
	p3.PrintP(*parr[0]);


	cout << "변수a =" << a <<endl<< "변수b =" << b << endl;
	
	return 0;
}

