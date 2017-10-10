#include <iostream>
#include <string>

int main() {
	// 원본 문자열을 준비
	std::string src = "KNUCSE C++ Tutor";
	
	// 새 문자열을 준비
	std::string desc;

	// 문자열의 내용을 복사
	desc = src;

	// 두 문자열의 내용을 출력
	std::cout << "src = " << src << "\n";
	std::cout << "desc = " << desc << "\n";

	return 0;
}