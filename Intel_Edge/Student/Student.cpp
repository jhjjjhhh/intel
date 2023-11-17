#include <iostream>
#include "haksang.h"

int main() {

	haksang p1("James", 20, "전자공학", 2);
	p1.Show();
	p1.SetSub("국어", 90).Show();
	p1.SetSub("수학", 90).Show();
	p1.SetSub("영어", 90).Show();
	p1.SetSub("과학", 90).Show();

	return 0;
	
}
