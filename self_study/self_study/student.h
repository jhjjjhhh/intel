#pragma once
#include <iostream>

class person {
private:
	char* name = NULL;
public:
	int age;
	//person(int Age = 0) : age(Age) {}
	person(const char* nam, int Age = 0) :age(Age) //생성자
	{
		rename(nam);
	}

	person& rename(const char* nam)
	{
		if (name) {
			delete[] name;
		}
		name = new char[strlen(nam) + 1];
		strcpy(name, nam);

		return *this;
	}
	void show() {
		printf("이름 :%s (%d살)\n", name, age);
	}
	~person()
	{
		delete[] name;
	}
};
//과목 클래스. 과목 , 점수 , 평균 , 합계 함수..!
//연산자 오버로딩 사용.
class subject {
private:
	char* subjectName = NULL;
public:
	
	int score;
	subject(int Score = 0) : score(Score) {}
	subject(const char* SubjectName,int Score):score(Score) {
		if (subjectName) delete[] subjectName;
		subjectName = new char[strlen(SubjectName) + 1];
		strcpy(subjectName, SubjectName);
	}
	~subject() {
		delete[] subjectName;
	}
	void show() {
		printf("과목 :%s (%d점)\n", subjectName, score);
	}

	
};
//학생 클래스에는 이름 나이 ,과, 학년
class student : public person //상속 
{
private:
	char* major = NULL;
public:
	int grade;
	subject p1;

	student(const char* Nam, int Age, const char* Major, int Grade, const char* SubjectName, int SubjectScore) : person(Nam, Age), grade(Grade),p1(SubjectName, SubjectScore)
	{
		remajor(Major);
	}
	student& remajor(const char* Major) {
		if (major)delete[] major;

		major = new char[strlen(Major) + 1];
		strcpy(major, Major);

		return *this;
	}
	~student() {
		delete[] major;
	}

	student& show() {
		((person*)this)->show();
		printf("전공 :%s (%d학년)\n", major, grade);
		p1.show();

		return *this;
	}
	

};


