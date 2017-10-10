#include <iostream>

int main() {
	// p가 a를 가리키게 만듬
	int a = 123;
	int* p = &a;

	// p가 가리키는 변수의 값을 얻음
	std::cout << "*p = " << *p << std::endl;

	// p가 가리키는 변수의 값을 변경
	*p = 789;

	// 관련 정보를 출력
	std::cout << "a = " << a << std::endl;
	std::cout << "*p = " << *p << std::endl;

	return 0;
}