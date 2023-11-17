#include "Classes.h"
#include <iostream>
#define MIN(x,y) (x)<(y) ? (x):(y)
#define MAX(x,y) (x)>(y) ? (x):(y)
using std::cout;
using std::cin;
using std::endl;
//�Լ��� ����
double Point::Dist(Point p) {
	int w = x - p.x;
	int h = y - p.y;

	return sqrt(w * w + h * h);

}

void Point::Show(const char* s) { //������ x,y ��ǥ�� �����. //����Ʈ ���� proto ������ �����Ѵ� -> class ��� �Լ� ������ ����
	//cout << s <<"(" << x <<',' << y << ") " << endl;
	//cout << s << "(" << x << "," << y << ")" << endl;
	printf("%s(%d,%d)\n", s, x, y);
}

void Point::ShowEx(const char* s) { //������ x,y ��ǥ�� �����. //����Ʈ ���� proto ������ �����Ѵ� -> class ��� �Լ� ������ ����
	//cout << s <<"(" << x <<',' << y << ") " << endl;
	printf("%s(%d,%d)", s, x, y);
}

Point& Point::operator+(Point p) {	//�� �� CurP�� p�� + ���� ����� (���ο� Point��) ��ȯ 
	return *(new Point(x += p.x, y += p.y)); //new Ű����� ������ Ű�����̴�. malloc �� ����.
	
}

Rect& Rect::Show(const char* s) //Rect(p1(x1,y1),p2(x2,y2))

{
	printf("%s(", s);
	LL.ShowEx("LL");
	UR.ShowEx("UR");
	printf(")\n");

	return *this;
}

double Rect::Area() {
	return (double)(ABS((p1.x - p2.x) * (p1.y - p2.y)));
}

Rect& Rect::operator+(Rect other) {
	int x1 = MIN(MIN(this->x1, this->x2), MIN(other.x1, other.x2));
	int x2 = MAX(MAX(this->x1, this->x2), MAX(other.x1, other.x2));
	int y1 = MIN(MIN(this->y1, this->y2), MIN(other.y1, other.y2));
	int y2 = MAX(MAX(this->x1, this->x2), MAX(other.x1, other.x2));

	return *(new Rect(x1, y1, x2, y2));
}
Rect& Rect::operator-(Rect other) 
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;

	Rect& rr = *this;

	//�� �簢���� ��ġ�� �ʴ� ��� 0 Rect ��ȯ
	if ((rr.LR.x < other.LL.x) || (rr.LL.x > other.LR.x)) return *(new Rect(0, 0, 0, 0));
	if ((rr.UL.y < other.LL.y) || (rr.LL.y > other.UL.y)) return *(new Rect(0, 0, 0, 0));
	
	x1 = MIN(MIN(rr.x1, rr.x2), MIN(other.x1, other.x2));
	x2 = MAX(rr.LL.x, other.LL.x);
	x3 = MIN(rr.LR.x, other.LR.x);
	x4 = MAX(MAX(rr.x1, rr.x2), MAX(other.x1, other.x2));
	
	y1 = MIN(MIN(rr.y1, rr.y2), MIN(other.y1, other.y2));
	y2 = MIN(rr.UL.y, other.UL.y);
	y3 = MAX(rr.LL.y, other.LL.y);
	y4 = MAX(MAX(rr.y1, rr.y2), MAX(other.y1, other.y2));
	
	return *(new Rect(x2, y2, x3, y3));
}
double Rect::operator*(Rect other) {

	double d1 = this->Area();
	double d2 = other.Area();
	double d3 = (*(this) - other).Area();

	return d1 + d2 - d3;
}


