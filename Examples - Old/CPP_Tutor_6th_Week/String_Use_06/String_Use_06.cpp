#include <iostream>
#include <string>

int main() {
	// 문자열을 준비함
	char cs[20];		// C 스타일
	std::string cpps;	// C++ 스타일

	// 문자열을 입력 받음
	std::cin.getline(cs, 20);
	std::getline(std::cin, cpps);

	// 문자열을 출력
	std::cout << "cs = " << cs << "\n";
	std::cout << "cpps = " << cpps << "\n";

	return 0;
}