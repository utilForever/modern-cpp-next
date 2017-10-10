#include <iostream>

bool SetFramesPerSec(int fps = 10) {
	// 코드 생략
	std::cout << "fps = " << fps << "\n";

	return true;
}

int main() {
	// 인자 없이 함수를 호출
	SetFramesPerSec();

	return 0;
}