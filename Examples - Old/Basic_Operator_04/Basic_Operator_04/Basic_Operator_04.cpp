#include <iostream>

int main() {
	// 모든 경우의 AND 연산 수행
	bool b1, b2, b3, b4;
	b1 = false && false;
	b2 = false && true;
	b3 = true && false;
	b4 = true && true;

	// 결과를 출력
	std::cout << std::boolalpha;
	std::cout << "false AND false : " << b1 << std::endl;
	std::cout << "false AND true  : " << b2 << std::endl;
	std::cout << "true  AND false : " << b3 << std::endl;
	std::cout << "true  AND true  : " << b4 << std::endl;

	return 0;
}