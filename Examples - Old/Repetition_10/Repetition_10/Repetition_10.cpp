#include <iostream>

int main() {
	int i = 1;		// 1부터 10까지 증가할 변수
	int sum = 0;	// 전체 합을 보관할 변수

	// 'i <= 10'을 만족하는 동안만 반복
	do {
		// 현재까지의 합에 i를 더함
		sum += i;

		// i에 1을 더함
		++i;
	} while (i <= 10);

	// 결과 출력
	std::cout << "현재 i의 값 = " << i << std::endl;
	std::cout << "1 ~ 10 까지의 합 = " << sum << std::endl;

	return 0;
}