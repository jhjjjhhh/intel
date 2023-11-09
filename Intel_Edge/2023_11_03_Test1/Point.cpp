#include "Point.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
//함수만 정의
double Point::Dist(Point p) {
	int w = x - p.x;
	int h = y - p.y;

	return sqrt(w * w + h * h);

}

Point& Point::SetP(Point p) {
	x = p.x; y = p.y;
	return *this;
}
//void Point::SetP(Point p) {
//	x = p.x; y = p.y;
//}
//void Point::SetP(int x, int y) {
//	this->x = x; this->y = y;
//}
Point& Point::SetP(int x, int y) {
	this->x = x; this->y = y;
	return *this;
}
Point& Point::MoveP(Point offset) { // 입력값 만큼 이동하라. Move point position
	x += offset.x;
	y += offset.y;
	return *this;
}
Point& Point::MoveP(int x_off, int y_off) { // 입력값 만큼 이동하라.
	this->x += x_off;
	this->y += y_off;
	return *this;
}
void Point::viewP(const char *s) { //본인의 x,y 좌표를 찍어줌. //디폴트 값은 proto 에서만 정의한다 -> class 멤버 함수 내에서 정의
	//cout << s <<"(" << x <<',' << y << ") " << endl;
	printf("%s(%d,%d)\n", s, x, y);
}

double Point3D::Dist3D(Point3D p) { //Distance 3D

	int w = X() - p.X(); //class point에서 멤버변수 x,y가 public 이여야 접근한다.
	int h = Y() - p.Y();
	int d = z - p.z;
	
	return sqrt(w * w + h * h + d * d);
}


Point& Point::operator+(Point p) {	//두 점 CurP와 p의 + 연산 결과를 (새로운 Point로) 반환 
	Point* p1 = new Point(x += p.x, y += p.y); //new 키워드는 포인터 키워드이다. malloc 과 같다.
	return *p1;
}
Point& Point::operator++() { //객체 선행 연산자 오버로딩
	x++; y++;
	return *this;
}
Point& Point::operator++(int) { // 객체 후행 연산자 오버로딩
	
	Point* p1 = new Point(x++, y++);
	return *p1;
}
double Point::operator*(Point p) {

	int w = x - p.x;
	int h = y - p.y;
	double a = w * h;
	return ABS(a);
}
Point3D& Point3D::SetP(Point3D p) {
	X() = p.X(); Y() = p.Y(); z = p.z;
	return *this;
}
