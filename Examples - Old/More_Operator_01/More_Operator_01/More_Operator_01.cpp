#include <iostream>

int main() {
	// 4개의 변수를 동일한 값으로 채움
	int A, B, C, D;
	A = B = C = D = 3;

	// 다양하게 ++, -- 연산자를 사용
	int ppA, Bpp, mmC, Dmm;
	ppA = ++A; // 4
	Bpp = B++; // 3
	mmC = --C; // 2
	Dmm = D--; // 3

	// 결과를 출력
	std::cout << "A, B, C, D : " << A << ", " << B << ", " << C << ", " << D << std::endl;
	std::cout << "++A, B++, --C, D-- : " << ppA << ", " << Bpp << ", " << mmC << ", " << Dmm << std::endl;

	return 0;
}