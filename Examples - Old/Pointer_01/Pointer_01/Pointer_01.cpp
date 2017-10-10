#include <iostream>

int main() {
	// 변수를 정의
	char c = 'B';
	int i = 19;
	float f = 4.5f;

	// 주소를 출력
	std::cout << "c의 주소 = " << (int*)&c << std::endl;
	std::cout << "i의 주소 = " << &i << std::endl;
	std::cout << "f의 주소 = " << &f << std::endl;

	return 0;
}