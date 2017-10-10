#include <iostream>

int main() {
	// 문자열 상수를 사용해서 배열을 초기화
	char cArray1[] = "ABCDE";
	char cArray2[] = {'A', 'B', 'C', 'D', 'E', 0};

	// 두 배열의 크기를 비교
	std::cout << "sizeof(cArray1) = " << sizeof(cArray1) << "(Bytes)" << std::endl;
	std::cout << "sizeof(cArray2) = " << sizeof(cArray2) << "(Bytes)" << std::endl;

	// 두 배열의 4, 5번째 원소를 출력
	std::cout << cArray1[4] << (int)cArray1[5] << std::endl;
	std::cout << cArray2[4] << (int)cArray2[5] << std::endl;

	return 0;
}