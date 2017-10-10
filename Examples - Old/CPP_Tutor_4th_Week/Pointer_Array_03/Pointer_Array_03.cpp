#include <iostream>

int main() {
	// 두 개의 포인터를 초기화
	short sArrays[10];
	short* ps1 = &sArrays[3];
	short* ps2 = &sArrays[7];

	// 결과를 출력
	std::cout << "ps1 = " << ps1 << std::endl;
	std::cout << "ps2 = " << ps2 << std::endl;
	std::cout << "ps2 - ps1 = " << ps2 - ps1 << std::endl;

	return 0;
}