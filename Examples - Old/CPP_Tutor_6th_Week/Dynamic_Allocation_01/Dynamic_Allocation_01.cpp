#include <iostream>

int main() {
	// 몇 개의 정수를 입력할지 물어봄
	int size;
	std::cout << "몇 개의 정수를 입력하시겠습니까? ";
	std::cin >> size;

	// 필요한 만큼의 메모리를 할당
	int* arr = new int[size];

	// 정수를 입력 받음
	std::cout << "정수를 입력하세요.\n";
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}

	// 평균을 계산하고 출력
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}

	float avg = (float)(sum) / (float)(size);
	std::cout << "합 = " << sum << ", 평균 = " << avg << "\n";

	// 사용한 메모리를 해제
	delete[] arr;

	return 0;
}