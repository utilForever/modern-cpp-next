#include <iostream>
#include <string>

int main() {
	// 긴 문자열을 만듦
	std::string text = "Napster's pay-to-play service is officially out, and we have a review of the now-legit Napster. We also size up its companion music player from Samsung.";

	// 이 문자열 안에서 'official'이라는 단어의 위치를 찭음
	std::cout << "Offset of 'official' = " << text.find("official") << "\n";

	return 0;
}