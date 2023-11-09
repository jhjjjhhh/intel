#pragma once
// ������� .h �� class ����
//#include <corecrt_math.h> VS IDE ��ý�Ʈ ���� /sqrt �Լ� ���
//extern double sqrt(double); //iostream �ȿ� ���ԵǾ��ִ� �Լ�.
#include <iostream>
#define ABS(x)	(x)>0 ? (x) : (-(x))

class Point
{
private:
	int x;
	int y;
public:
	//int x, y;

	Point(int x1 = 0,int y1=0) : x(x1), y(y1){} //������ �̴ϼȶ����� (���� �ߺ���� x ����)
	
	Point& SetP(Point p); //(Self-Reference)
	Point& SetP(int x, int y); // (Self-Reference)
	//void SetP(Point p);
	//void SetP(int x, int y);
	Point& MoveP(int dx, int dy);
	Point& MoveP(Point offset);
	
	
	double Dist(Point p); //�� ���� x,y�� �Ÿ��� ����ϴ� �Լ� (Distance)
	void viewP(const char *s = NULL); //�Է°��� ū����ǥ�� �ޱ����ؼ� const ��� �� ����Ʈ NULL  (View Current Point)

	int& X() { return x; }; // private �����  �����ϱ����ؼ� ����� �Լ� 
	int& Y() { return y; };

	Point& operator+(Point p);
	Point& operator++(); //���࿬����
	Point& operator++(int); //�Ű������� �ǹ̾��� �� �߰� �� ���࿬����.
	double operator*(Point p);   //�ΰ��� ���� �̷�� �簢���� ����
};

class Point3D : public Point //x , y , z ��
{
private:
	int z;
public:
	
	Point3D(int x = 0, int y = 0, int z = 0) : Point(x, y), z(z) {}
	double Dist3D(Point3D p);
	Point3D& SetP(Point3D p);
};
