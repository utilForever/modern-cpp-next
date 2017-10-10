#include <iostream>
#include <string>

int main() {
	// 문자열을 정의
	std::string s1;
	std::string s2 = "123";
	std::string s3 = "abcdefg";

	// 문자열의 길이를 출력
	std::cout << "s1 = " << s1.size() << "\n";
	std::cout << "s2 = " << s2.size() << "\n";
	std::cout << "s3 = " << s3.size() << "\n";

	return 0;
}