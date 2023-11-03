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
	int h = y - p.y;
	int d = z - p.z;
	
	return sqrt(w * w + h * h + d * d);
}