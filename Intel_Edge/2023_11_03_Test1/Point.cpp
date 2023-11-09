#include "Point.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
//�Լ��� ����
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
Point& Point::MoveP(Point offset) { // �Է°� ��ŭ �̵��϶�. Move point position
	x += offset.x;
	y += offset.y;
	return *this;
}
Point& Point::MoveP(int x_off, int y_off) { // �Է°� ��ŭ �̵��϶�.
	this->x += x_off;
	this->y += y_off;
	return *this;
}
void Point::viewP(const char *s) { //������ x,y ��ǥ�� �����. //����Ʈ ���� proto ������ �����Ѵ� -> class ��� �Լ� ������ ����
	//cout << s <<"(" << x <<',' << y << ") " << endl;
	printf("%s(%d,%d)\n", s, x, y);
}

double Point3D::Dist3D(Point3D p) { //Distance 3D

	int w = X() - p.X(); //class point���� ������� x,y�� public �̿��� �����Ѵ�.
	int h = Y() - p.Y();
	int d = z - p.z;
	
	return sqrt(w * w + h * h + d * d);
}


Point& Point::operator+(Point p) {	//�� �� CurP�� p�� + ���� ����� (���ο� Point��) ��ȯ 
	Point* p1 = new Point(x += p.x, y += p.y); //new Ű����� ������ Ű�����̴�. malloc �� ����.
	return *p1;
}
Point& Point::operator++() { //��ü ���� ������ �����ε�
	x++; y++;
	return *this;
}
Point& Point::operator++(int) { // ��ü ���� ������ �����ε�
	
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
