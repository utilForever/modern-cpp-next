#include <iostream>

int main() {
	// 일반적인 변수를 정의
	int a = 123;

	// 포인터 변수를 정의
	int* p;

	// p가 a를 가리키게 만듬
	p = &a;

	// 관련 정보를 출력
	std::cout << "&a = " << &a << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "&p = " << &p << std::endl;

	return 0;
}