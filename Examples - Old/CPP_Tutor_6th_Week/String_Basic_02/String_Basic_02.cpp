#include <iostream>
#include <cstring>

int main() {
	// 두 문자열을 준비
	char str1[20] = "abcde";
	char str2[] = "fghij";

	// 두 문자열을 결합
	strcat(str1, str2);

	// 결합한 문자열의 내용을 비교
	if (strcmp(str1, "abcdefghij") == 0) {
		std::cout << "str1 and \"abcdefghij\" are identical.\n";
	}

	// 일부러 엉뚱한 문자열과 비교
	if (strcmp(str1, "123456") != 0) {
		std::cout << "str1 and \"123456\" are NOT identical.\n";
	}

	return 0;
}