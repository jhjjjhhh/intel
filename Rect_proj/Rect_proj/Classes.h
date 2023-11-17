#pragma once
#include <iostream>
#define ABS(x)	(x)>0 ? (x) : (-(x))
#define MIN(x,y) (x)<(y) ? (x):(y)
#define MAX(x,y) (x)>(y) ? (x):(y)
class Point
{
private:
public:
	int x;
	int y;

	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {
		if (x != 0 && y != 0) {
			std::cout << "Point 생성(" << x << "," << y << ")" << std::endl;
		}
	} //생성자 이니셜라이저 (변수 중복사용 x 권장)
	~Point() {
		if (x != 0 && y != 0) {
			std::cout << "Point 소멸(" << x << "," << y << ")" << std::endl;
		}
	}

	double Dist(Point p); //한 점의 x,y의 거리를 계산하는 함수 (Distance)
	void Show(const char* s = NULL); //입력값을 큰따음표를 받기위해서 const 사용 및 디폴트 NULL  (View Current Point)
	void ShowEx(const char* s = NULL); //입력값을 큰따음표를 받기위해서 const 사용 및 디폴트 NULL  (View Current Point)

	Point& operator+(Point p);

};

class Rect { 
private:
	void Init()
	{
		LL = Point(MIN(p1.x, p2.x), MIN(p1.y, p2.y));
		LR = Point(MAX(p1.x, p2.x), MIN(p1.y, p2.y));
		UL = Point(MIN(p1.x, p2.x), MAX(p1.y, p2.y));
		UR = Point(MAX(p1.x, p2.x), MAX(p1.y, p2.y));

	}
public:
	Point p1, p2;
	int x1, x2, y1, y2;
	Point LL, LR, UL, UR;

	Rect(Point pp1, Point pp2) :p1(pp1), p2(pp2),
		x1(pp1.x),y1(pp1.y),x2(pp2.x),y2(pp2.y) 
	{
		Init();
	}

	Rect(int x11 = 0, int y11 = 0, int x22 = 0, int y22 = 0){
		
		
		x1 = x11; y1 = y11;
		x2 = x22; y2 = y22;
		p1 = Point(x11, y11);
		p2 = Point(x22, y22);
		Init();
	}
	double Area();
	
	Rect& Show(const char* s); //Rect(p1(x1,y1),p2(x2,y2))
	Rect& operator+(Rect other);
	Rect& operator-(Rect other);
	double operator*(Rect other);
};