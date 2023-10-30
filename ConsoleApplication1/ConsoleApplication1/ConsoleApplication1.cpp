#include <iostream> 

#define SQUARE(x) ((x) + (x)) // 매크로함수 #deinfe + 함수이름 + 함수
#define ABS(x)  (((x) < 0) ? (x)*(-1):(x))  //삼항연산자를 이용한 매크로함수 모든 인수에 괄호 사용 젓댓값 함수
// 전역변수 / 데이터타입 (구조체)선언

//typedef struct Point // Point 이름의 구조체 선언  (구조체로 구현)
//{
//    int x;
//    int y;
//} _Point; //typedef 사용
//double Dist(_Point p1, _Point p2); //함수의 proto 타입 선언 (proto 타입이란 함수의 몸체를 제외)


class Point // Point 이름의 구조체 선언 (class로 구현)
{
public: // 접근제어지시자는 17열 아래부터인 17~25행까지 외부 접근 가능
    int x;
    int y;

    Point(int x1, int y1) //생성자.. 클래스 이름과 동일해야함 생성자에 접근하기위해선 접근제어지시자 public을 사용해야함
    {
        x = x1; y = y1;
    }
    double Dist(Point p);
    
    int Area(Point p)
    {
        int w = ABS(x - p.x);
        int h = ABS(y - p.y);
        int a = w * h;
        return a;
    }
};

double Point::Dist(Point p)
{
    int w = (x - p.x); 
    int h = (y - p.y);
    printf("x 값 : %d\n", x);
    printf("p.x 값 : %d\n", p.x);
    printf("\ny 값 : %d\n", y);
    printf("p.y 값 : %d\n", p.y);
    printf("\nw 값 : %d\n", w);
    printf("h 값 : %d\n", h);

    double d = sqrt(w * w + h * h);
    return d; //double 타입의 d 값 리턴
}
int main()
{

    //int x = 7;
    //std::cout << "안녕하세요 C++의 세계에 오신것을 열렬히 환영합니다!\n";
    //printf("안녕하세요 C++의 세계에 오신것을 환영합니다\n");
    //std::cout << SQUARE(5) << std::endl;
    //printf("%d의 제곱 : %d\n", x,SQUARE(x));

    //printf("===================================\n");

    ////int a = -8;
    //printf("%d의 절댓값은 :%d\n", -8, ABS(-8));
    //printf("%d의 절댓값은 :%d\n", -5, SQUARE(5));

    //_Point p1, p2; //Point 구조체 변수 p1,p2 선언
    //p1.x = 10; p1.y = 10; // xy 10,10 점 찍음
    //p2.x = 20; p2.y = 30; // xy 20,30 점 찍음
    //// 두 점의 길이를 나타내는 함수?

    Point p1(10, 10), p2(20, 30);
    
    double d = p1.Dist(p2);
    printf("두 점 p1(%d, %d), p2 (%d, %d)의 거리는 %.2f 입니다, 면적은 %d입니다.\n",
        p1.x, p1.y, p2.x, p2.y, d, p2.Area(p1));


    //double d = Dist(p1, p2); //p1,p2 변수는 구조체 _Point 타입
    //printf("두 점 p1(%d, %d), p2 (%d, %d)의 거리는 %.2f 입니다.\n",
    //    p1.x, p1.y, p2.x, p2.y, d);

    return 0;
}

//double Dist(_Point p1, Point p2) //두 점간의 거리를 구하는 함수  d = 루트 (x제곱 +y 제곱) 이며 루트 함수 sqrt 이용
//{
//    int w = ABS(p1.x - p2.x); //가로를 구하는 방법
//    int h = ABS(p1.y - p2.y); //세로를 구하는 방법 음수가 나올수 있으므로 절댓값 함수 ABS 이용
//    int w1 = w * w; //제곱 식 w의 제곱은 w1
//    int h1 = h * h; //제곱 식 h의 제곱은 h1
//
//    double d = sqrt(w1 + h1);
//    
//    return d; //double 타입의 d 값 리턴
//}