#include <iostream>

int main() {
	// 사용자로부터 값을 받을 변수
	char yn;

	do {
		std::cout << "Continue? (Y/N) : ";
		// 사용자로부터 값을 받음
		std::cin >> yn;
	} while (yn != 'N' && yn != 'n');
}