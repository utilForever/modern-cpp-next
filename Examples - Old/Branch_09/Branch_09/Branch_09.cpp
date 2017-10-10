#include <iostream>

int main() {
	// a, b에 임의의 값을 넣음
	int a = 3;
	int b = 5;
	int c;

	// a, b 중 큰 값을 c에 넣음
	c = a > b ? a : b;

	// 결과 출력
	std::cout << "c = " << c << std::endl;

	return 0;
}