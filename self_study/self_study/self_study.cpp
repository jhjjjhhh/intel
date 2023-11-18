//#include "student.h"
//#include <iostream>
//
//
//int main() {
//
//	/*person s1("hi", 30);
//	s1.show();
//	s1.rename("hihi").show();*/
//	student s1("jonghyeon", 20, "전기공학과", 3, "전자이론", 40);
//	s1.show();
//	printf("\n=====\n");
//	s1.remajor("").show();
//	printf("\n=====\n");
//	s1.rename("eunha");
//	s1.age = 18;
//	s1.grade = 1;
//	s1.show();
//
//	return 0;
//}
#include <iostream>
#include <vector>
#include <string>

class person {
protected:
    std::string name;
public:
    int Age;

    person(int age = 0) : Age(age) {}

    person(const std::string& Nam, int age) : name(Nam), Age(age) {}

    void Show() const {
        std::cout << name << " (" << Age << ")";
    }
};

class subject {
private:
    std::string name;
public:
    int score;

    subject() : score(0) {}

    subject(const std::string& Nam, int s = 0) : name(Nam), score(s) {}

    void addSubject(const std::string& Nam, int Score) {
        name = Nam;
        score = Score;
    }

    void Show() const {
        std::cout << "과목: " << name << " (" << score << "점)" << std::endl;
    }
};

class haksang : public person {
private:
    std::string Major;
    std::vector<subject> subjects;

public:
    int Grade;

    haksang(const std::string& Nam, int age, const std::string& major, int grade)
        : person(Nam, age), Major(major), Grade(grade) {}

    void Show() const {
        person::Show();
        std::cout << ":" << Major << " " << Grade << "학년" << std::endl;
        for (const auto& sub : subjects) {
            sub.Show();
        }
    }

    void addSubject(const std::string& Nam, int sco) {
        if (subjects.size() < 10) {
            subject newSubject;
            newSubject.addSubject(Nam, sco);
            subjects.push_back(newSubject);
        }
    }
};

int main() {
    haksang student("홍길서", 19, "전자공학과", 1);
    student.addSubject("Math", 90);
    student.addSubject("English", 85);
    student.Show();

    return 0;
}
