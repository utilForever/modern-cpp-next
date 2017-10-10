#include <iostream>

int main() {
	// 배열 정의
	int arrays[10];

	// 포인터가 arrays[5]를 가리키게 만듦
	int* p = &arrays[5];

	// p의 값과 arrays[5]의 주소를 출력
	std::cout << "p = " << p << std::endl;
	std::cout << "&arrays[5] = " << &arrays[5] << std::endl;

	// 포인터가 arrays[6]을 가리키게 만듦
	p++;

	// p의 값과 arrays[6]의 주소를 출력
	std::cout << "p = " << p << std::endl;
	std::cout << "&arrays[6] = " << &arrays[6] << std::endl;
	
	return 0;
}