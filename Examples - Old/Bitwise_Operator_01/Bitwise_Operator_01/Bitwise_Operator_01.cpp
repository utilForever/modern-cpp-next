#include <bitset>		// bitset 사용을 위한 준비 작업
#include <iostream>

int main() {
	// 다양한 타입의 변수를 준비
	char c = 1;
	short int si = 2;
	int i = 4;

	// 각각 2진수와 10진수로 출력
	std::cout << "c = " << std::bitset<8>(c) << "(" << (int)c << ")" << std::endl;
	std::cout << "si = " << std::bitset<16>(si) << "(" << si << ")" << std::endl;
	std::cout << "i = " << std::bitset<32>(i) << "(" << i << ")" << std::endl;

	return 0;
}