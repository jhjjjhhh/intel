#pragma once
#include <iostream>

class person {
private:
protected:
	char* name = NULL;
public:
	int Age;
	person(int age = 0) : Age(age) {} //NULL 생성자
	person(const char* Nam, int age) :Age(age)
	{
		rename(Nam);
	}
	person& rename(const char* Nam)
	{
		if (name) delete name;
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);

		return *this;
	}
	void Show()
	{
		printf("%s (%d)", name, Age);
	}
	~person() {
		if (name)delete name;
	}
};

class subject {
private:
	char* name = NULL;
public:
	int score;
	subject() {};
	subject(const char* Nam, int s = 0) : score(s)
	{
		reSub(Nam);
	}
	subject& reSub(const char* Nam = NULL)
	{
		if (name) delete name;
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);
		return *this;
	}

	char* NAME() {return (char*)name;} //name이 private 이기 때문에 사용

};


class haksang : public person
{
private:
	char* Major = NULL;
public:
	int Grade;
	int SubNum = 0; //수강과목 수
	subject sub[10];  //kor, eng;

	haksang(const char* Nam, int age, const char* major, int grade) : person(Nam, age), Grade(grade)
	{
		
		remajor(major);
	}

	haksang& remajor(const char* major) {
		if (Major) delete Major;
		Major = new char[strlen(major) + 1];
		strcpy(Major, major);

		return *this;
	}

	void Show() 
	{
		((person*)this)->Show();			//홍길서(19) //person 클래스에 있는 show 함수 실행.
		printf(":%s %d학년\n", Major, Grade);	//전자공학과 1학년
		for (int i = 0; i < SubNum; i++) {
			printf("%s:%d\n", sub[i].NAME(), sub[i].score);
		}
	}

	~haksang() {
		delete Major;
	}
	haksang& SetSub(const char*Nam, int sco)
	{
		if (SubNum > 10) return *this;
		sub[SubNum].reSub(Nam).score = sco;
		SubNum++;
		return *this;

	}
};
