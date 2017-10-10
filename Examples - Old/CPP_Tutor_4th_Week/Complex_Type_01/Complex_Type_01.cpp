#include <iostream>

// 공용체 정의
union MyUnion {
	int i;
	void* p;
};

int main() {
	// 공용체 변수 정의
	MyUnion uni;

	// uni.i와 uni.p의 주소를 확인
	std::cout << "&uni.i = " << &uni.i << std::endl;
	std::cout << "&uni.p = " << &uni.p << std::endl;

	// uni.i에 값을 넣고 결과를 출력
	uni.i = 0x12345678;
	std::cout << std::hex;
	std::cout << "uni.i = " << uni.i << std::endl;
	std::cout << "uni.p = " << uni.p << std::endl;

	// uni.p에 값을 넣고 결과를 출력
	uni.p = (void*)0x87654321;
	std::cout << "uni.i = " << uni.i << std::endl;
	std::cout << "uni.p = " << uni.p << std::endl;

	return 0;
}