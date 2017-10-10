#include <iostream>

int main() {
	// 두 개의 배열 정의
	int arrayA[3] = {1, 2, 3};
	int arrayB[3];

	// arrayA의 내용을 arrayB로 복사
	for (int i = 0; i < 3; i++) {
		arrayB[i] = arrayA[i];
	}

	// 각 원소의 값을 출력
	for (int i = 0; i < 3; i++) {
		std::cout << "arrayA[" << i << "] = " << arrayA[i] << ", arrayB[" << i << "] = " << arrayB[i] << std::endl;
	}

	return 0;
}