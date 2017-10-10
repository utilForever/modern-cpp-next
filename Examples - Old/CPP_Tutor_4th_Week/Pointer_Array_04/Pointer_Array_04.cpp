#include <iostream>

int main() {
	float f[5];

	if (f == &f[0]) {
		// 항상 이 곳이 실행
		std::cout << "배열의 이름은 첫 번째 원소의 주소!" << std::endl;
	}

	return 0;
}