#include <iostream>
#include <string>

int main() {
	// 두 문자열을 준비
	std::string str1 = "abcde";
	std::string str2 = "fghij";

	// 두 문자열을 결합
	str1 = str1 + str2;

	// 결합한 문자열의 내용을 비교
	if (str1 == "abcdefghij") {
		std::cout << "str1 and \"abcdefghij\" are identical.\n";
	}

	// 일부러 엉뚱한 문자열과 비교
	if (str1 != "123456") {
		std::cout << "str1 and \"123456\" are NOT identical.\n";
	}

	return 0;
}