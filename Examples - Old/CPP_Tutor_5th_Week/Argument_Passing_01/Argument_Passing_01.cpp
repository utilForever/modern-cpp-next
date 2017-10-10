#include <iostream>

// 함수 원형
int Factorial(int n);

int main() {
	// 펙토리얼을 구하고 결과를 저장
	int result;
	result = Factorial(5);

	// 결과를 출력
	std::cout << "5!는 " << result << "입니다.\n";

	return 0;
}

int Factorial(int n) {
	// 결과를 저장할 변수를 준비
	int result = 1;

	// 펙토리얼을 구함
	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	// 결과를 반환
	return result;
}