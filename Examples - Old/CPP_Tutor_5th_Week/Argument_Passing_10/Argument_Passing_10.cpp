#include <iostream>

struct Point {
	int x, y;
};

// 두 점의 거리를 구하는 함수의 원형
double Distance(Point p1, Point p2);

int main() {
	// 두 점을 만듦
	Point a = {0, 0};
	Point b = {3, 4};

	// 두 점의 거리를 구함
	double dist_a_b = Distance(a, b);

	// 결과를 출력
	std::cout << "(" << a.x << ", " << a.y << ") 와 ";
	std::cout << "(" << b.x << ", " << b.y << ") 의 거리 = " << dist_a_b << "\n";

	return 0;
}

double Distance(Point p1, Point p2) {
	std::cout << "p1 = (" << p1.x << ", " << p1.y << ")\n";
	std::cout << "p2 = (" << p2.x << ", " << p2.y << ")\n";

	return 0.0f;
}