#include <iostream>

int main() {
	// 그냥 문자의 배열을 만듬
	char ThisIsNotString[] = {'H', 'e', 'l', 'l', 'o'};

	// 문자열을 만듬
	char ThisIsString[] = {'H', 'e', 'l', 'l', 'o', '\0'};

	// 두 배열을 cout 객체로 보냄
	std::cout << ThisIsNotString << std::endl;
	std::cout << ThisIsString << std::endl;

	return 0;
}