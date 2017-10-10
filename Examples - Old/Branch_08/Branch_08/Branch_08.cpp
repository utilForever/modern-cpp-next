#include <iostream>

int main() {
	// 시험 점수 : 임의의 값 대입
	int score = 1;

	// 점수에 따른 적절한 메시지를 출력
	switch (score) {
	case 0:
	case 1:
	case 2:
		std::cout << "열심히 하세요~" << std::endl;
		break;
	case 3:
		std::cout << "멋있어요~" << std::endl;
		break;
	default:
		std::cout << "올바르지 않은 점수입니다!!" << std::endl;
	}

	return 0;
}