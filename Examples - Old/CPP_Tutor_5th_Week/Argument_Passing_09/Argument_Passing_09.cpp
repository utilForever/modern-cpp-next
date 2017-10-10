#include <iostream>

// 이차원 배열을 인자로 받는 함수의 원형
void Using2DArray(int arr[][3]);

int main() {
	// 이차원 배열을 정의하고 초기화
	int array[5][3] = {
		{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}
	};

	// 배열을 넘겨줌
	Using2DArray(array);

	return 0;
}

void Using2DArray(int arr[][3]) {
	// 모든 원소를 출력
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << "\n";
		}
	}
}