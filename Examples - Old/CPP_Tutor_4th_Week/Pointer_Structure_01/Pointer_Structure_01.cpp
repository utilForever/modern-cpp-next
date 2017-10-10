#include <iostream>

// 사각형의 정보를 갖는 구조체
struct Rectangle {
	int x, y;
	int width, height;
};

int main() {
	// 사각형 구조체 변수를 만듦
	Rectangle rc = {100, 100, 50, 50};

	// 포인터가 이 변수를 가리키게 만듦
	Rectangle* p = &rc;

	// 구조체의 멤버에 접근
	(*p).x = 200;
	p->y = 250;

	// 구조체의 내용을 출력
	std::cout << "rc = (" << rc.x << ", " << rc.y << ", ";
	std::cout << rc.width << ", " << rc.height << ")" << std::endl;

	return 0;
}