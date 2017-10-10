#include <bitset>
#include <iostream>

int main() {
	// 피연산자를 준비
	unsigned char a;
	a = 178;

	// 쉬프트 연산을 수행
	unsigned char a_rshift, a_lshift;
	a_rshift = a >> 3;	// 오른쪽 쉬프트 연산(3칸 쉬프트)
	a_lshift = a << 3;	// 왼쪽 쉬프트 연산(3칸 쉬프트)

	// 결과를 출력(괄호 안에는 10진수가 출력)
	std::cout << "a      = " << std::bitset<8>(a) << "(" << (unsigned int)a << ")" << std::endl;
	std::cout << "a >> 3 = " << std::bitset<8>(a_rshift) << "(" << (unsigned int)a_rshift << ")" << std::endl;
	std::cout << "a << 3 = " << std::bitset<8>(a_lshift) << "(" << (unsigned int)a_lshift << ")" << std::endl;

	return 0;
}