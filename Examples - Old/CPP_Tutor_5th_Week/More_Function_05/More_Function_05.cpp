#include <iostream>

void Dog() {
	std::cout << "I'm a Dog.\n";
}

void Cat() {
	std::cout << "I'm a Cat.\n";
}

int main() {
	// 함수의 포인터를 정의
	void (*p)();

	// Dog() 함수를 가리키게 한 후에 호출
	p = &Dog;
	(*p)();

	// Cat() 함수를 가리키게 한 후에 호출
	p = &Cat;
	(*p)();

	return 0;
}