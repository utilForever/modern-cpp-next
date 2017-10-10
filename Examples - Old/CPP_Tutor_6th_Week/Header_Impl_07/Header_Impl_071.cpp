struct Point {
	int x, y;
};

int main() {
	// 두 점을 만듦
	Point a = {100, 100};
	Point b = {200, 200};

	// 함수를 호출
	double dist;
	dist = Distance(a, b);

	return 0;
} 