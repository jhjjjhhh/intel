#include <iostream>
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define MAX(x,y) (((x) > (y)) ? (x) : (y)) //만약 x,y가 같은 값이면 false 인 y 값이 반환됌

using namespace std;



class point
{
	//private:		//접근 지시자 선언 private(외부 참조 불가) 접근 지시자는 다음번 접근 지시자까지 유효하다.
public:
	//멤버 변수 선언
	int x, y;

	//생성자 정의 생성자는 class 이름과 동일해야함. !! 또한 타입도 없다, 입력이 있다 (아규먼트)
	point(int x1 = 0, int y1 = 0) : x(x1), y(y1) //이니셜라이져
	{
		//x = x1;
		//y = y1;
	}

	//두 점간의 거리 계산 함수 Dist 선언
	double Dist(point); 
	double Dist(point, point); //함수의 오버로딩
	void PrintP(point p); //포인트 객체를 받아서 포인트 좌표를 찍어주는 함수
};
//class rect 
//{
//public:
//	point p11, p22; // class point에 있는 멤버변수 가져옴 //클래스 멤버 변수 선언 //이건 객체 선언이 아님.
//	point LL, LR, UL, UR; //4개의 포인트 정보. RECT에 선언할때 초기화 할 수 있다. // 외부참조 대상
//	rect(point p1, point p2)  // 생성자.
//	{
//
//		int xl, xr, yl, yu; //x의 left , x의 right  y의 lower y의 upper    //지역변수
//		int xl = MIN(p1.x, p2.x);
//		int xr = MAX(p1.x, p2.x);
//		int yl = MIN(p1.y, p2.y);
//		int yu = MAX(p1.y, p2.y);
//
//		LL = point(xl, yl);
//		LR = point(xr, yl);
//		UL = point(xl, yu); // 생성자 내부에서 초기화
//		UR = point(xr, yu);
//
//		p11 = p1, p22 = p2; //class 객체 값 대입 가능.
//	}
//};
class rect
{
public:
	point p11, p22; // class point에 있는 멤버변수 가져옴 //클래스 멤버 변수 선언 //이건 객체 선언이 아님.
	point LL, LR, UL, UR; //4개의 포인트 정보. RECT에 선언할때 초기화 할 수 있다. // 외부참조 대상
	rect(point p1, point p2)  // 생성자.
	{

		//int xl, xr, yl, yu; //x의 left , x의 right  y의 lower y의 upper    //지역변수
		//int xl = MIN(p1.x, p2.x);
		//int xr = MAX(p1.x, p2.x);
		//int yl = MIN(p1.y, p2.y);
		//int yu = MAX(p1.y, p2.y);

		//LL = point(xl, yl);
		//LR = point(xr, yl);
		//UL = point(xl, yu); // 생성자 내부에서 초기화
		//UR = point(xr, yu);

		p11 = p1, p22 = p2; //class 객체 값 대입 가능.
	}
	point getLL(point px1, point px2);
	point getLR(point px1, point px2);
	point getUL(point px1, point px2);
	point getUR(point px1, point px2);
	

};

int main()
{
	point p1(10, 10), p2(20, 30), p3, p4; //객체 선언..!! 객체는 생성자를 거쳐 초기화 된 멤버가 있는 걸 객체라고한다.
	p4 = p3; // class 객체 값은 대입이 가능함.
	
	rect r(p1, p2);
	
	double res = p1.Dist(p1, p2);
	double res1 = p1.Dist(p2);
	double res2 = p3.Dist(p1, p2);
	
	p3.PrintP(p2);
	p3.PrintP(p4);
	cout << res << endl;
	cout << res1 << endl;
	cout << res2 << endl;

	point LL = r.getLL(p1, p2);
	point LR = r.getLR(p1, p2);
	point UL = r.getUL(p1, p2);
	point UR = r.getUR(p1, p2);

	cout << LL.x << LL.y << endl;
	cout << LR.x << LR.y << endl;
	cout << UL.x << UL.y << endl;
	cout << UR.x << UR.y << endl;
	
	return 0;
}
point rect::getLL(point px1, point px2)
{
	/*int xl = MIN(px1.x, px2.x);
	int yl = MIN(px1.y, px2.y);*/

	/*return point(xl, yl);*/
	return point(MIN(px1.x, px2.x), MIN(px1.y, px2.y));
}
point rect::getLR(point px1, point px2)
{
	/*int xr = MAX(px1.x, px2.x);
	int yl = MIN(px1.y, px2.y);*/

	return point(MAX(px1.x, px2.x), MIN(px1.y, px2.y));
}
point rect::getUL(point px1, point px2)
{
	/*int xl = MIN(px1.x, px2.x);
	int yu = MAX(px1.y, px2.y);*/

	return point(MIN(px1.x, px2.x), MAX(px1.y, px2.y));
}
point rect::getUR(point px1, point px2)
{
	/*int xr = MAX(px1.x, px2.x);
	int yu = MAX(px1.y, px2.y);*/

	return point(MAX(px1.x, px2.x), MAX(px1.y, px2.y));

}
void point::PrintP(point p)
{
	printf("값 : %d ,%d \n", p.x, p.y);
}
double point::Dist(point p)
{
	int w = (x - p.x);
	int h = (y - p.y);

	return sqrt(w * w + h * h); // sqrt 함수는 루트 씌워줌. //sqrt 반환형이 double 형이다.

}
double point::Dist(point p1, point p2)
{
	int w = p1.x - p2.x;
	int h = p1.y - p2.y;
	
	return sqrt(w * w + h * h);
}
