//#pragma once
//#include <iostream>
//#define ABS(x)	(x)>0 ? (x) : (-(x))
//#define MIN(x,y) (x)<(y) ? (x):(y)
//#define MAX(x,y) (x)>(y) ? (x):(y)
//class Point
//{
//private:
//public:
//	int x;
//	int y;
//
//	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {
//		if (x != 0 && y != 0) {
//			std::cout << "Point 생성(" << x << "," << y << ")" << std::endl;
//		}
//	} //생성자 이니셜라이저 (변수 중복사용 x 권장)
//	~Point() {
//		if (x != 0 && y != 0) {
//			std::cout << "Point 소멸(" << x << "," << y << ")" << std::endl;
//		}
//	}
//
//	double Dist(Point p); //한 점의 x,y의 거리를 계산하는 함수 (Distance)
//	void Show(const char* s = NULL); //입력값을 큰따음표를 받기위해서 const 사용 및 디폴트 NULL  (View Current Point)
//	void ShowEx(const char* s = NULL); //입력값을 큰따음표를 받기위해서 const 사용 및 디폴트 NULL  (View Current Point)
//
//	Point& operator+(Point p);
//
//};
//
//class Rect { 
//private:
//	void Init()
//	{
//		LL = Point(MIN(p1.x, p2.x), MIN(p1.y, p2.y));
//		LR = Point(MAX(p1.x, p2.x), MIN(p1.y, p2.y));
//		UL = Point(MIN(p1.x, p2.x), MAX(p1.y, p2.y));
//		UR = Point(MAX(p1.x, p2.x), MAX(p1.y, p2.y));
//
//	}
//public:
//	Point p1, p2;
//	int x1, x2, y1, y2;
//	Point LL, LR, UL, UR;
//
//	Rect(Point pp1, Point pp2) :p1(pp1), p2(pp2),
//		x1(pp1.x),y1(pp1.y),x2(pp2.x),y2(pp2.y) 
//	{
//		Init();
//	}
//
//	Rect(int x11 = 0, int y11 = 0, int x22 = 0, int y22 = 0){
//		
//		
//		x1 = x11; y1 = y11;
//		x2 = x22; y2 = y22;
//		p1 = Point(x11, y11);
//		p2 = Point(x22, y22);
//		Init();
//	}
//	double Area();
//	
//	Rect& Show(const char* s); //Rect(p1(x1,y1),p2(x2,y2))
//	Rect& operator+(Rect other);
//	Rect& operator-(Rect other);
//	double operator*(Rect other);
//};
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
private:
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
private:
    void Init() {
        LL = Point<T>(MIN(p1.x, p2.x), MIN(p1.y, p2.y));
        LR = Point<T>(MAX(p1.x, p2.x), MIN(p1.y, p2.y));
        UL = Point<T>(MIN(p1.x, p2.x), MAX(p1.y, p2.y));
        UR = Point<T>(MAX(p1.x, p2.x), MAX(p1.y, p2.y));
    }

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
    return *(new Point<T>(x + p.x, y + p.y));
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
