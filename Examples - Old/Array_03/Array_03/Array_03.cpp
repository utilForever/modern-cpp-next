#include <iostream>

int main() {
	// 배열을 정의하면서 초기화시킴
	int kor_scores[5] = {100, 88, 92, 40, 76};

	// 각 원소의 값을 출력
	for (int i = 0; i < 5; i++) {
		std::cout << i << " 번째 원소 = " << kor_scores[i] << std::endl;
	}

	return 0;
}