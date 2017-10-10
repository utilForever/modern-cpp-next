#include <iostream>

int main() {
	int i = 1;		// 1부터 10까지 증가할 변수
	int sum = 0;	// 전체 합을 보관할 변수

	// 무한정 반복
	while (true) {
		// 현재까지의 합에 i를 더함
		sum += i;

		// i에 1을 더함
		++i;

		// i의 값을 검사
		if (i > 10)
			break;
	}

	// 결과 출력
	std::cout << "현재 i의 값 = " << i << std::endl;
	std::cout << "1 ~ 10까지의 합 = " << sum << std::endl;

	return 0;
}