#include <iostream>

/*

구조:목표: 기본 클래스와 파생 클래스를 사용하여 도형의 계층 구조 만들기

구현: Shape이라는 기본 클래스를 만들고, Circle, Rectangle, Triangle 등의 도형 클래스를 파생시킵니다. 각 도형 클래스는 넓이를 계산하는 함수를 포함해야 합니다.

설명: Shape 클래스를 만들어 기본 도형의 속성과 면적을 계산하는 가상 함수를 구현합니다. 그리고 Circle, Rectangle,
Triangle 등의 클래스를 만들어 기본 클래스를 상속받아 특정 도형들의 면적을 구합니다.

*/

class Shape { 
public:
	virtual double getArea();

};

class Circle : public Shape{
private:
	double Rad;
public:

};

class Rectangle : public Shape {
private:
	double W; //width
	double H;


};

class Triangle : public Shape {
private:
	double B; //base
	double H; //height

};

int main() {



	return 0;
}