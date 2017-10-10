// a와 b 중에 큰 값을 반환하는 함수
int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	// 3과 5 중에 더 큰 값을 구함
	int ret = max(3, 5);

	return 0;
}