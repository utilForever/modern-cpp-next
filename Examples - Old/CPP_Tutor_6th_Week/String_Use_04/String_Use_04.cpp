#include <iostream>
#include <string>

int main() {
	// string 객체를 만듦
	std::string cppstyle = "Yes, I am.";

	// C 스타일 문자열을 담을 공간을 준비
	char* cstyle = new char[cppstyle.size() + 1];

	// C 스타일 문자열을 얻어서 복사
	strcpy(cstyle, cppstyle.c_str());

	// cstyle의 첫 번째 문자를 바꿔봄
	cstyle[0] = 'Z';

	// 두 문자열을 출력
	std::cout << "cstyle = " << cstyle << "\n";
	std::cout << "cppstyle = " << cppstyle << "\n";

	// 메모리를 해제
	delete[] cstyle;
	cstyle = NULL;

	return 0;
}