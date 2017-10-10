#include <iostream>
#include <string>

int main() {
	// string 객체를 만듦
	std::string cppstyle = "Yes, I am.";

	// C 스타일 문자열을 가리킬 포인터를 준비
	const char* cstyle = NULL;

	// C 스타일 문자열을 얻음
	cstyle = cppstyle.c_str();

	// 두 문자열을 출력
	std::cout << "cstyle = " << cstyle << "\n";
	std::cout << "cppstyle = " << cppstyle << "\n";

	return 0;
}