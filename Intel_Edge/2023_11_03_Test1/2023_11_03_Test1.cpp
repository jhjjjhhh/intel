/*
self ref & this 포인터 사용
*/
#include <iostream>
#include "Point.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	Point p1(10, 10), p2, p3;

	p1.viewP("P1"); p2.viewP(); p3.viewP();
	Point p4 = p3;																//p4는 p3의 x,y (멤버변수)가 각각 대입된다. ex) p3(20,10) 이면 p4(20,10) 이 됌.
	Point p5(p2);																//윗 코드와 동일한 표현

	p2.SetP(Point(20, 30)).viewP("P2");											// self-ref 이용 리턴값에 . 사용 후 뒤에 함수 호출이 가능
	p3.SetP(40,80).viewP("P3");
	printf("두 점으로 정의되는 사각형의 넓이는 %f 입니다.\n", p2 * p3);
	//
	//printf("\n\nPoint Move Test .... \n\n");
	//p1.MoveP(5, 5).viewP("move_p1");
	//p1.MoveP(Point(1, -1)).viewP("move_p1"); 
	//p3.MoveP(p1).viewP("move_p3");												//객체 대입 가능.
	//
	//printf("\n\nPoint print Test ..P1(%d,%d).. \n\n", p1.X(), p1.Y());			//리턴 함수에 의해서 자료형 int는 value 값만 돌려주기에.. 단방향
	
	//p1.X() = 10; p1.Y() = 10;													//함수 반환형에 참조자 없이는 안됌 잘안씀..

	//printf("\n\nPoint Ref. Acess Test ...");  p1.viewP("P1");					//아랫줄 문제 해결 .단방향
	//																			// printf("\n\nPoint print Test ..P1(%d,%d).. \n\n",p1.x,p1.y); class에 멤버 변수 x,y를 private로 설정했기에 사용불가.
	Point p6 = p1 + p2;															//p1.X() = 10; //참조자 없이는 안됌
	printf("\n\nPoint [Operator+] Test ...");  p6.viewP("P6");					//self-ref 이용하므로 사용하지않아도 됌.
	printf("\n\nPoint [Operator++ 후행] Test ...");  (p6++).viewP("P6");
	printf("\n\nPoint [Operator++ 선행] Test ...");  (++p6).viewP("P6");				//p1.viewP("P1"); p2.viewP("P2"); p3.viewP("P3");// 함수의 입력값에  "" 를 쓰면 상수가 된다. const가 달림. const char*  //문자열에 빨간줄그어져있으면 const를 붙혀야함
	//p1.x = 10;																//public 이 아닌 접근제어 (private , protected) 이므로 접근 못함.
	//p1.y = 20;
	
	Point3D pp0, pp1(10, 20, 30);
	double d3 = pp0.Dist3D(pp1);
	double d2 = pp0.Dist(Point (10,20));	
	printf("\npp0(0,0,0)과 pp1(10,20,30)의 거리는 %f \n", d3);
	printf("pp0(0,0,0)과 p1(10,20)의 거리는 %f \n", d2);
																					

	return 0;
}