#include <iostream>

int main() {
	// 구조체를 정의 : 2차원에서의 점에 대한 정보
	struct Point {
		int x;	// x 좌표
		int y;	// y 좌표
	};

	// 변수 두 개를 선언 또는 정의
	Point pt1 = {30, 50};
	Point pt2;

	// pt1을 pt2에 대입
	pt2 = pt1;

	// 멤버 값을 출력
	std::cout << "pt1 = (" << pt1.x << ", " << pt1.y << ")" << std::endl;
	std::cout << "pt2 = (" << pt2.x << ", " << pt2.y << ")" << std::endl;

	return 0;
}