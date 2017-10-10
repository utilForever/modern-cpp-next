#include <iostream>

int main() {
	// 전체 합을 보관할 변수
	int sum = 0;

	// 1 ~ 10까지 반복하면서 더함
	for (int i = 1; i <= 10; ++i) {
		// i가 5인 경우는 그냥 넘어감
		if (i == 5)
			continue;

		// 현재까지의 합에 i를 더함
		sum += i;
	}

	// 결과 출력
	std::cout << "1 ~ 4, 6 ~ 10 까지의 합 = " << sum << std::endl;

	return 0;
}