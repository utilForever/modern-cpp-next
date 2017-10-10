#include <iostream>

int main() {
	// 다양한 타입의 변수 출력
	int i = 65;
	float f = 66.89f;
	char c = 'C';

	// 명시적으로 형변환
	std::cout << "int i = " << i << "\n";
	std::cout << "(char)i = " << (char)i << "\n";
	std::cout << "(bool)i = " << (bool)i << "\n\n";

	std::cout << "float f = " << f << "\n";
	std::cout << "(int)f = " << (int)f << "\n\n";

	std::cout << "char c = " << c << "\n";
	std::cout << "(int)c = " << (int)c << "\n";
}