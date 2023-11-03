#pragma once
// 헤더파일 .h 는 class 정의
//#include <corecrt_math.h> VS IDE 어시스트 내용 /sqrt 함수 사용
//extern double sqrt(double); //iostream 안에 포함되어있는 함수.
#include <iostream>


class Point
{
private:
	int x;
protected:
	int y;
public:
	//int x, y;

	Point(int x1 = 0,int y1=0) : x(x1), y(y1){} //생성자 이니셜라이저 (변수 중복사용 x 권장)
	
	Point& SetP(Point p); //(Self-Reference)
	Point& SetP(int x, int y); // (Self-Reference)
	//void SetP(Point p);
	//void SetP(int x, int y);
	Point& MoveP(int dx, int dy);
	Point& MoveP(Point offset);
	
	
	double Dist(Point p); //한 점의 x,y의 거리를 계산하는 함수 (Distance)
	void viewP(const char *s = NULL); //입력값을 큰따음표를 받기위해서 const 사용 및 디폴트 NULL  (View Current Point)

	int& X() { return x; }; // private 멤버를  접근하기위해서 만드는 함수 
	int& Y() { return y; };
};

class Point3D : public Point //x , y , z 축
{
private:
	int z;
public:
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) {}
	double Dist3D(Point3D p);

};
