#include <iostream>
#include <cmath>

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
	// 피타고라스의 정리를 사용
	double distance;
	distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));

	// 결과를 반환
	return distance;
}