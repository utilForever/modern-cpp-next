#include <iostream>

int main() {
	// ILoveYou라고 찍힌 곳으로 이동
	goto ILoveYou;

	// 이 곳을 뛰어넘는지 실험
	std::cout << "이 문자열이 출력되면 안됩니다" << std::endl;

ILoveYou:
	std::cout << "여기는 ILoveYou 다음입니다" << std::endl;

	return 0;
}