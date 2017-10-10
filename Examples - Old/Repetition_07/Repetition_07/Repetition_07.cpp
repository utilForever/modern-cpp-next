#include <iostream>

int main() {
	// 전체 합을 보관할 변수
	int sum = 0;

	int i = 1;

	// 1 ~ 10까지 반복하면서 더함
	for (;;) {
		sum += i;	// 현재까지의 합에 i를 더함
		++i;		// i를 증가시킴

		// 조건을 비교함
		if (i > 10)
			break;
	}

	// 결과 출력
	std::cout << "1 ~ 10까지의 합 = " << sum << std::endl;

	return 0;
}