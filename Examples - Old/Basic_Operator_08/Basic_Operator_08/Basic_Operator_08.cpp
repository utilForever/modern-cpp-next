#include <iostream>

int main() {
	// ! 연산자의 사용
	bool b1, b2;
	b1 = !true;
	b2 = !false;

	// 결과 출력
	std::cout << std::boolalpha;
	std::cout << "NOT true : " << b1 << std::endl;
	std::cout << "NOT false : " << b2 << std::endl;

	return 0;
}