#include <iostream>

int main() {
	// 키와 시력을 보관할 변수를 정의
	int height;
	float eyesight;

	// height, eyesight 값을 입력 받음
	height = 175;
	eyesight = 0.8f;

	// 조건을 만족하는지 검사
	bool ok;	// 자격을 갖춘 사람인가?
	ok = ((height >= 160 && height <= 180) || (eyesight >= 1.0f && eyesight <= 2.0f));

	// 결과 출력
	std::cout << std::boolalpha;
	std::cout << "ok = " << ok << std::endl;

	return 0;
}