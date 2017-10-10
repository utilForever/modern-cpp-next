#include <iostream>

int main() {
	// 세 가지 종류의 배열을 정의
	char cArray[3] = {'A', 'B', 'C'};
	int iArray[4] = {100, 200, 300, 400};
	double dArray[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

	// cArray의 크기에 대한 조사
	std::cout << "sizeof(cArray) = " << sizeof(cArray) << "(Bytes)" << std::endl;
	std::cout << "sizeof(cArray[0]) = " << sizeof(cArray[0]) << "(Bytes)" << std::endl;
	std::cout << "원소의 개수 = " << sizeof(cArray) / sizeof(cArray[0]) << std::endl << std::endl;

	// iArray의 크기에 대한 조사
	std::cout << "sizeof(iArray) = " << sizeof(iArray) << "(Bytes)" << std::endl;
	std::cout << "sizeof(iArray[0]) = " << sizeof(iArray[0]) << "(Bytes)" << std::endl;
	std::cout << "원소의 개수 = " << sizeof(iArray) / sizeof(iArray[0]) << std::endl << std::endl;

	// dArray의 크기에 대한 조사
	std::cout << "sizeof(dArray) = " << sizeof(dArray) << "(Bytes)" << std::endl;
	std::cout << "sizeof(dArray[0]) = " << sizeof(dArray[0]) << "(Bytes)" << std::endl;
	std::cout << "원소의 개수 = " << sizeof(dArray) / sizeof(dArray[0]) << std::endl << std::endl;

	return 0;
}