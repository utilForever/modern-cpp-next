#include <iostream>

int main() {
	// 문자를 준비
	char c = 'A';

	// 문자열을 준비
	char s[] = "This is a String.";

	// 문자열을 cout 객체에 넘겨줌
	std::cout << s << "\n";
	std::cout << &s[0] << "\n";

	// 문자의 주소를 cout 객체에 넘겨줌
	std::cout << &c << "\n";

	return 0;
}