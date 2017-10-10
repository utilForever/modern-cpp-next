#include <iostream>

// 2진수의 자리 수 하나를 구하는 재귀 함수
void Convert2Bin(int dec) {
	// 10진수가 0보다 작거나 같으면 종료
	if (dec <= 0) {
		return;
	}

	// 인자를 2로 나눈 값을 인자로 다시 호출
	Convert2Bin(dec / 2);

	// 인자를 2로 나눈 나머지를 출력
	std::cout << dec % 2;
}

int main() {
	// 13을 이진수로 변환
	Convert2Bin(13);

	std::cout << "\n";

	return 0;
}