#include <iostream>

int main() {
	// 두 개의 변수 정의 및 초기화
	int d = 1000, e = 2000;

	// 변수의 값 확인
	std::cout << "d = " << d << ", e = " << e << "\n";

	// e의 값을 읽어서 d로 복사
	d = e;

	// 변수의 값 확인
	std::cout << "d = " << d << ", e = " << e << "\n";

	return 0;
}