#include <iostream>

int main() {
	// 실험에 사용할 변수를 정의
	int target = 20;

	// 레퍼런스 변수를 정의
	int& ref = target;

	// 정보를 출력
	std::cout << "ref    = " << ref << std::endl;
	std::cout << "target = " << target << std::endl;
	std::cout << "&ref    = " << &ref << std::endl;
	std::cout << "&target = " << &target << std::endl;

	// ref의 값을 바꿈
	ref = 100;

	// 정보를 출력
	std::cout << "ref    = " << ref << std::endl;
	std::cout << "target = " << target << std::endl;
	
	return 0;
}