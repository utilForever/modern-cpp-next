#include <iostream>

int main() {
	// 동일한 값을 가진 변수를 선언
	int i = 10;
	float f = 10.0f;

	// 두 변수를 동일한 수로 나눔
	float i_div_4, f_div_4;
	i_div_4 = i / 4;
	f_div_4 = f / 4;

	// 결과 출력
	std::cout << "i = " << i << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "i / 4 = " << i_div_4 << std::endl;
	std::cout << "f / 4 = " << f_div_4 << std::endl;

	return 0;
}