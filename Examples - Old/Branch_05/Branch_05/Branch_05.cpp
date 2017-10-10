#include <iostream>

int main() {
	// 시험 점수 : 임의의 값 대입
	int score = 2;

	// 점수에 따른 적절한 메시지를 출력
	switch (score) {
	case 0:
		std::cout << "밀려 쓰셨군요~" << std::endl;
		break;
	case 1:
		std::cout << "조금 더 노력하세요~" << std::endl;
		break;
	case 2:
		std::cout << "안타깝네요~" << std::endl;
		break;
	case 3:
		std::cout << "멋있어요~" << std::endl;
		break;
	}

	return 0;
}