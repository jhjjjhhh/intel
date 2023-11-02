#pragma once
#include <iostream>
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define MAX(x,y) (((x) > (y)) ? (x) : (y)) //���� x,y�� ���� ���̸� false �� y ���� ��ȯ��

class point
{
	//private:		//���� ������ ���� private(�ܺ� ���� �Ұ�) ���� �����ڴ� ������ ���� �����ڱ��� ��ȿ�ϴ�.
public:
	//��� ���� ����
	int x, y, z;

	//������ ���� �����ڴ� class �̸��� �����ؾ���. !! ���� Ÿ�Ե� ����, �Է��� �ִ� (�ƱԸ�Ʈ)
	point(int x1 = 0, int y1 = 0) : x(x1), y(y1) //�̴ϼȶ�����
	{
		z = 0;
		//x = x1;
		//y = y1;
	}
	void SetP(int x1 = 0, int y1 = 0) { x = x1; y = y1; }
	//�� ������ �Ÿ� ��� �Լ� Dist ����
	double Dist(point);
	double Dist(point, point); //�Լ��� �����ε�
	void PrintP(point p); //����Ʈ ��ü�� �޾Ƽ� ����Ʈ ��ǥ�� ����ִ� �Լ�
};
//class rect 
//{
//public:
//	point p11, p22; // class point�� �ִ� ������� ������ //Ŭ���� ��� ���� ���� //�̰� ��ü ������ �ƴ�.
//	point LL, LR, UL, UR; //4���� ����Ʈ ����. RECT�� �����Ҷ� �ʱ�ȭ �� �� �ִ�. // �ܺ����� ���
//	rect(point p1, point p2)  // ������.
//	{
//
//		int xl, xr, yl, yu; //x�� left , x�� right  y�� lower y�� upper    //��������
//		int xl = MIN(p1.x, p2.x);
//		int xr = MAX(p1.x, p2.x);
//		int yl = MIN(p1.y, p2.y);
//		int yu = MAX(p1.y, p2.y);
//
//		LL = point(xl, yl);
//		LR = point(xr, yl);
//		UL = point(xl, yu); // ������ ���ο��� �ʱ�ȭ
//		UR = point(xr, yu);
//
//		p11 = p1, p22 = p2; //class ��ü �� ���� ����.
//	}
//};
class rect
{
public:
	point p11, p22; // class point�� �ִ� ������� ������ //Ŭ���� ��� ���� ���� //�̰� ��ü ������ �ƴ�.
	point LL, LR, UL, UR; //4���� ����Ʈ ����. RECT�� �����Ҷ� �ʱ�ȭ �� �� �ִ�. // �ܺ����� ���
	rect(point p1, point p2)  // ������.
	{

		//int xl, xr, yl, yu; //x�� left , x�� right  y�� lower y�� upper    //��������
		//int xl = MIN(p1.x, p2.x);
		//int xr = MAX(p1.x, p2.x);
		//int yl = MIN(p1.y, p2.y);
		//int yu = MAX(p1.y, p2.y);

		//LL = point(xl, yl);
		//LR = point(xr, yl);
		//UL = point(xl, yu); // ������ ���ο��� �ʱ�ȭ
		//UR = point(xr, yu);

		p11 = p1, p22 = p2; //class ��ü �� ���� ����.
	}
	point getLL(point px1, point px2);
	point getLR(point px1, point px2);
	point getUL(point px1, point px2);
	point getUR(point px1, point px2);
};

void swap(int& aa, int& bb) {
	int temp = 0;
	temp = aa;
	aa = bb;
	bb = temp;

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
	printf("�� : %d ,%d \n", p.x, p.y);
}
double point::Dist(point p)
{
	int w = (x - p.x);
	int h = (y - p.y);

	return sqrt(w * w + h * h); // sqrt �Լ��� ��Ʈ ������. //sqrt ��ȯ���� double ���̴�.

}
double point::Dist(point p1, point p2)
{
	int w = p1.x - p2.x;
	int h = p1.y - p2.y;

	return sqrt(w * w + h * h);
}
