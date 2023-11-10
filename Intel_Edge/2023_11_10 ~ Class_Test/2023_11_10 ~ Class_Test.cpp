#include <iostream>

class AAA {
public:
private:
	int a1;
protected:
	int a2;
public:
	int a3;
	AAA() { printf("A\n"); }								//생성자
	~AAA() { printf("~A\n"); }								//소멸자

	virtual void name(void) { printf("this class name = AAA\n"); }
};

class BBB : public AAA {
public:
	int b1;
	int b2;
	int b3;
	BBB() { printf("B\n"); }
	~BBB() { printf("~B\n"); }

	/*void test(void) { printf("a1 = %d , a2 = %d , a3 = %d\n", a1, a2, a3); }*/
	void name(void) { printf("this class name = BBB\n"); }
};

class C { //Class 내에 순수 가상함수가 있으면 그 클래스는 개체화가 안되며 그것을 추상클래스라고한다. 상속을 위한 클래스. 최상위 클래스.
public:
	int c = 1;
	int c1 = 2;
	C() { printf("_C_\n"); }
	virtual void func() = 0 {}
	virtual void func1() = 0 {}
};

class C1 : public C {

public:
	C1() { printf("_C1_\n"); }
	virtual void func() { printf("Func_in_C1_\n"); }
	virtual void func1() { printf("Func_in_C1_\n"); }
};

class C2 : public C {

public:
	C2() { printf("_C2_\n"); }
	virtual void func() { printf("Func_in_C1_\n"); }
	virtual void func1() { printf("Func_in_C1_\n"); }
};


void func() {
	printf("in function start...\n");
	//AAA *a = new AAA();
	BBB *b = new BBB();

	b->name();									//함수의 오버라이딩 : aaa class에서의 같은 이름의 함수가 호출이 안됌.

	AAA* a = b;									//방법 1. aaa class의 name 함수 호출  캐스팅
	a->name();

	((AAA*)b)->name();							//방법 2. aaa class의 name 함수 호출  캐스팅


	/*printf("a1 = %d , a2 = %d , a3 = %d\n", b->); */
	delete b;
	printf("in function end.\n");
	
	//delete a;
}
/*
void func1() {

	printf("in function1 start...\n");
	AAA *a = new AAA();
	a->name();

	BBB* b = (BBB*)a;//방법 2. aaa class의 name 함수 호출  캐스팅

	b->name();
	printf("b1 = %d\n", ((BBB*)a)->b1);
	delete a;

	printf("in function end.\n");
}*/


// 1. 순수 가상함수를 사용해서 함수를 오버라이딩하면 일반 함수 오버라이딩한것과의 차이 (최적화 개념?)
// 2. 추상 클래스의 순수 가상함수는 상속 클래스의 함수 오버라이딩을 강제하기위함? o
// 3. 추상 클래스를 상속받은 클래스는 무조건 순수 가상 함수를 오버라이딩을 해야만 객체화 가능? o

// 동적으로 객체 생성 (포인터 객체) 는 사용이 끝나면 명시적으로 메모리 해제 해야함
// 일반 클래스 객체는 사용이 끝나면 자동으로 소멸자가 호출되어 메모리 해제 된다.

int main() {
	printf("Program start...\n");
	C1 c1;
	C2 s1;

	c1.func();
	//////
	//////BBB b;

	//////func();
	////////func1();

	printf("Program end.\n");
	
}