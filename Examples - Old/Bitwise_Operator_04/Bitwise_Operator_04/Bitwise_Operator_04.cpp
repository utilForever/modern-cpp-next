#include <bitset>
#include <iostream>

int main() {
	// unsigned와 signed 변수에 같은 값을 넣음
	unsigned short us = 0xff00;
	short s = (short)0xff00;
	
	// 동일한 쉬프트 연산을 수행
	unsigned short us_shift = us >> 4;
	short s_shift = s >> 4;

	// 결과 출력
	std::cout << "us      = " << std::bitset<16>(us) << "(" << us << ")" << std::endl;
	std::cout << "s       = " << std::bitset<16>(s) << "(" << s << ")" << std::endl;
	std::cout << "us >> 4 = " << std::bitset<16>(us_shift) << "(" << us_shift << ")" << std::endl;
	std::cout << "s >> 4  = " << std::bitset<16>(s_shift) << "(" << s_shift << ")" << std::endl;

	return 0;
}