#include <iostream>

int main() {
	// 포인터 변수를 정의하고 초기화
	int* p = NULL;

	// 이 상태에서 퐁니터를 사용
	if (p != NULL) {
		*p = 30;
	}

	// p가 변수를 가리키게 만듬
	int a = 100;
	p = &a;

	// 이 상태에서 포인터를 사용
	if (p) {
		*p = 30;
	}

	return 0;
}