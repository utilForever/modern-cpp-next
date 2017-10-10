#include <iostream>

// 배열을 인자로 갖는 함수의 원형
void UsingArray(const char arr[]);

int main() {
	// 배열을 만들고 초기화
	char array[20] = "Hello, World!";

	// 함수에 배열을 넘겨줌
	UsingArray(array);

	// 함수 호출 후의 배열 상태를 출력
	std::cout << "In main() : " << array << "\n";

	return 0;
}

void UsingArray(const char arr[]) {
	// 넘겨 받은 배열을 출력
	std::cout << "In UsingArray() : " << arr << "\n";

	// 배열의 원소 하나를 수정
	arr[12] = '?';
}