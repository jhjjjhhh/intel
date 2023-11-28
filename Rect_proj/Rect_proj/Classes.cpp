//#include "Classes.h"
//#include <iostream>
//#define MIN(x,y) (x)<(y) ? (x):(y)
//#define MAX(x,y) (x)>(y) ? (x):(y)
//using std::cout;
//using std::cin;
//using std::endl;
////함수만 정의
//double Point::Dist(Point p) {
//	int w = x - p.x;
//	int h = y - p.y;
//
//	return sqrt(w * w + h * h);
//
//}
//
//void Point::Show(const char* s) { //본인의 x,y 좌표를 찍어줌. //디폴트 값은 proto 에서만 정의한다 -> class 멤버 함수 내에서 정의
//	//cout << s <<"(" << x <<',' << y << ") " << endl;
//	//cout << s << "(" << x << "," << y << ")" << endl;
//	printf("%s(%d,%d)\n", s, x, y);
//}
//
//void Point::ShowEx(const char* s) { //본인의 x,y 좌표를 찍어줌. //디폴트 값은 proto 에서만 정의한다 -> class 멤버 함수 내에서 정의
//	//cout << s <<"(" << x <<',' << y << ") " << endl;
//	printf("%s(%d,%d)", s, x, y);
//}
//
//Point& Point::operator+(Point p) {	//두 점 CurP와 p의 + 연산 결과를 (새로운 Point로) 반환 
//	return *(new Point(x += p.x, y += p.y)); //new 키워드는 포인터 키워드이다. malloc 과 같다.
//	
//}
//
//Rect& Rect::Show(const char* s) //Rect(p1(x1,y1),p2(x2,y2))
//
//{
//	printf("%s(", s);
//	LL.ShowEx("LL");
//	UR.ShowEx("UR");
//	printf(")\n");
//
//	return *this;
//}
//
//double Rect::Area() {
//	return (double)(ABS((p1.x - p2.x) * (p1.y - p2.y)));
//}
//
//Rect& Rect::operator+(Rect other) {
//	int x1 = MIN(MIN(this->x1, this->x2), MIN(other.x1, other.x2));
//	int x2 = MAX(MAX(this->x1, this->x2), MAX(other.x1, other.x2));
//	int y1 = MIN(MIN(this->y1, this->y2), MIN(other.y1, other.y2));
//	int y2 = MAX(MAX(this->x1, this->x2), MAX(other.x1, other.x2));
//
//	return *(new Rect(x1, y1, x2, y2));
//}
//Rect& Rect::operator-(Rect other) 
//{
//	int x1, x2, x3, x4;
//	int y1, y2, y3, y4;
//
//	Rect& rr = *this;
//
//	//두 사각형이 겹치지 않는 경우 0 Rect 반환
//	if ((rr.LR.x < other.LL.x) || (rr.LL.x > other.LR.x)) return *(new Rect(0, 0, 0, 0));
//	if ((rr.UL.y < other.LL.y) || (rr.LL.y > other.UL.y)) return *(new Rect(0, 0, 0, 0));
//	
//	x1 = MIN(MIN(rr.x1, rr.x2), MIN(other.x1, other.x2));
//	x2 = MAX(rr.LL.x, other.LL.x);
//	x3 = MIN(rr.LR.x, other.LR.x);
//	x4 = MAX(MAX(rr.x1, rr.x2), MAX(other.x1, other.x2));
//	
//	y1 = MIN(MIN(rr.y1, rr.y2), MIN(other.y1, other.y2));
//	y2 = MIN(rr.UL.y, other.UL.y);
//	y3 = MAX(rr.LL.y, other.LL.y);
//	y4 = MAX(MAX(rr.y1, rr.y2), MAX(other.y1, other.y2));
//	
//	return *(new Rect(x2, y2, x3, y3));
//}
//double Rect::operator*(Rect other) {
//
//	double d1 = this->Area();
//	double d2 = other.Area();
//	double d3 = (*(this) - other).Area();
//
//	return d1 + d2 - d3;
//}
#pragma once
#include <iostream>

// 템플릿 함수 선언
template <typename T>
T ABS(T x) {
    return (x > 0) ? x : (-x);
}

template <typename T>
T MIN(T x, T y) {
    return (x < y) ? x : y;
}

template <typename T>
T MAX(T x, T y) {
    return (x > y) ? x : y;
}

// 템플릿 클래스 선언
template <typename T>
class Point {
public:
    T x;
    T y;

    Point(T x1 = 0, T y1 = 0) : x(x1), y(y1) {
        if (x != 0 && y != 0) {
            std::cout << "Point 생성(" << x << "," << y << ")" << std::endl;
        }
    }

    ~Point() {
        if (x != 0 && y != 0) {
            std::cout << "Point 소멸(" << x << "," << y << ")" << std::endl;
        }
    }

    double Dist(Point p);

    void Show(const char* s = nullptr);

    void ShowEx(const char* s = nullptr);

    Point<T>& operator+(Point<T> p);
};

// 템플릿 클래스 선언
template <typename T>
class Rect {
public:
    Point<T> p1, p2;
    T x1, x2, y1, y2;
    Point<T> LL, LR, UL, UR;

    Rect(Point<T> pp1, Point<T> pp2) : p1(pp1), p2(pp2),
        x1(pp1.x), y1(pp1.y), x2(pp2.x), y2(pp2.y) {
        Init();
    }

    Rect(T x11 = 0, T y11 = 0, T x22 = 0, T y22 = 0) : x1(x11), y1(y11),
        x2(x22), y2(y22),
        p1(Point<T>(x11, y11)),
        p2(Point<T>(x22, y22)) {
        Init();
    }

    double Area();

    Rect<T>& Show(const char* s);

    Rect<T>& operator+(Rect<T> other);

    Rect<T>& operator-(Rect<T> other);

    double operator*(Rect<T> other);

private:
    void Init() {
        LL = Point<T>(MIN(p1.x, p2.x), MIN(p1.y, p2.y));
        LR = Point<T>(MAX(p1.x, p2.x), MIN(p1.y, p2.y));
        UL = Point<T>(MIN(p1.x, p2.x), MAX(p1.y, p2.y));
        UR = Point<T>(MAX(p1.x, p2.x), MAX(p1.y, p2.y));
    }
};

// 템플릿 클래스의 멤버 함수 정의
template <typename T>
double Point<T>::Dist(Point<T> p) {
    T w = x - p.x;
    T h = y - p.y;
    return sqrt(w * w + h * h);
}

template <typename T>
void Point<T>::Show(const char* s) {
    std::cout << s << "(" << x << ", " << y << ")\n";
}

template <typename T>
void Point<T>::ShowEx(const char* s) {
    std::cout << s << "(" << x << ", " << y << ")";
}

template <typename T>
Point<T>& Point<T>::operator+(Point<T> p) {
    return *(new Point<T>(x += p.x, y += p.y));
}

template <typename T>
double Rect<T>::Area() {
    return static_cast<double>((ABS(LL.x - UR.x) * ABS(LL.y - UR.y)));
}

template <typename T>
Rect<T>& Rect<T>::Show(const char* s) {
    std::cout << s << "(";
    LL.Show("LL");
    UR.Show("UR");
    std::cout << ")\n";
    return *this;
}

template <typename T>
Rect<T>& Rect<T>::operator+(Rect<T> other) {
    T x1 = MIN(MIN(LL.x, UR.x), MIN(other.LL.x, other.UR.x));
    T x2 = MAX(MAX(LL.x, UR.x), MAX(other.LL.x, other.UR.x));
    T y1 = MIN(MIN(LL.y, UR.y), MIN(other.LL.y, other.UR.y));
    T y2 = MAX(MAX(LL.y, UR.y), MAX(other.LL.y, other.UR.y));

    return *(new Rect<T>(Point<T>(x1, y1), Point<T>(x2, y2)));
}

template <typename T>
Rect<T>& Rect<T>::operator-(Rect<T> other) {
    T x1 = MAX(LL.x, other.LL.x);
    T x2 = MIN(UR.x, other.UR.x);
    T y1 = MAX(LL.y, other.LL.y);
    T y2 = MIN(UR.y, other.UR.y);

    if (x1 > x2 || y1 > y2) {
        return *(new Rect<T>(Point<T>(0, 0), Point<T>(0, 0)));
    }

    return *(new Rect<T>(Point<T>(x1, y1), Point<T>(x2, y2)));
}

template <typename T>
double Rect<T>::operator*(Rect<T> other) {
    double d1 = this->Area();
    double d2 = other.Area();
    double d3 = (this->operator-(other)).Area();

    return d1 + d2 - d3;
}
