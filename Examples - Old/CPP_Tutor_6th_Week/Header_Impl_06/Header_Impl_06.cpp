struct Point {
	int x, y;
};

double Distance(const Point& pt1, const Point& pt2) {
	// 이 함수의 내용은 생략
	return 0.0f;
}

int main() {
	// 두 점을 만듦
	Point a = {100, 100};
	Point b = {200, 200};

	// 함수를 호출
	double dist;
	dist = Distance(a, b);

	return 0;
} 