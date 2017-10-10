#include <iostream>

int main() {
	// 2 ~ 9단까지 반복함
	for (int i = 2; i <= 9; ++i) {
		// i단의 시작을 표시함
		std::cout << i << "단 ---------" << std::endl;
		
		// 1 ~ 9까지 반복함
		for (int j = 1; j <= 9; ++j) {
			std::cout << i << " * " << j << " = " << i * j << std::endl;
		}
	}

	return 0;
}