#include <iostream>

int main() {
	double d;
	int i;
	char a;

	// siszeof의 다양한 사용
	std::cout << "sizeof(d) = " << sizeof(d) << "(Bytes)" << std::endl;
	std::cout << "sizeof(i) = " << sizeof(i) << "(Bytes)" << std::endl;
	std::cout << "sizeof(a) = " << sizeof(a) << "(Bytes)" << std::endl;
	std::cout << "sizeof(double) = " << sizeof(double) << "(Bytes)" << std::endl;
	std::cout << "sizeof(int) = " << sizeof(int) << "(Bytes)" << std::endl;
	std::cout << "sizeof(char) = " << sizeof(char) << "(Bytes)" << std::endl;

	return 0;
}