#include <iostream>

int main() {
	// 메모리를 할당
	short* p = new short[100];

	// p에 보관한 주소 값을 확인
	std::cout << "p = " << p << "\n";

	// 메모리를 해제
	delete[] p;
	p = NULL;

	// p에 보관한 주소 값을 확인
	std::cout << "p = " << p << "\n";

	// 메모리를 해제
	delete[] p;
	p = NULL;

	return 0;
}