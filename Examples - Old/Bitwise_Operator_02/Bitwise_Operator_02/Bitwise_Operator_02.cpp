#include <bitset>
#include <iostream>

int main() {
	// 피연산자를 준비
	unsigned char a, b;
	a = 178;
	b = 113;

	// 비트 단위 논리 연산을 수행
	unsigned char c1, c2, c3, c4;
	c1 = a & b;		// AND
	c2 = a | b;		// OR
	c3 = a ^ b;		// XOR
	c4 = ~a;		// NOT

	// 결과를 출력(괄호 안에는 10진수가 출력)
	std::cout << "a     = " << std::bitset<8>(a) << "(" << (unsigned int)a << ")" << std::endl;
	std::cout << "b     = " << std::bitset<8>(b) << "(" << (unsigned int)b << ")" << std::endl;
	std::cout << "a & b = " << std::bitset<8>(c1) << "(" << (unsigned int)c1 << ")" << std::endl;
	std::cout << "a | b = " << std::bitset<8>(c2) << "(" << (unsigned int)c2 << ")" << std::endl;
	std::cout << "a ^ b = " << std::bitset<8>(c3) << "(" << (unsigned int)c3 << ")" << std::endl;
	std::cout << "~a    = " << std::bitset<8>(c4) << "(" << (unsigned int)c4 << ")" << std::endl;

	return 0;
}