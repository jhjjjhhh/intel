#pragma once
#include <iostream>

class person {
private:
	char* name = NULL;
public:
	int age;
	//person(int Age = 0) : age(Age) {}
	person(const char* nam, int Age = 0) :age(Age) //������
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
		printf("�̸� :%s (%d��)\n", name, age);
	}
	~person()
	{
		delete[] name;
	}
};
//���� Ŭ����. ���� , ���� , ��� , �հ� �Լ�..!
//������ �����ε� ���.
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
		printf("���� :%s (%d��)\n", subjectName, score);
	}

	
};
//�л� Ŭ�������� �̸� ���� ,��, �г�
class student : public person //��� 
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
		printf("���� :%s (%d�г�)\n", major, grade);
		p1.show();

		return *this;
	}
	

};


