int main() {
	// 배열의 크기를 const 변수에 보관
	const unsigned int arraySize = 100;

	// 배열을 정의
	char characters[arraySize] = {0};

	// 배열에 1 ~ arraySize의 값을 넣음
	for (int i = 0; i < arraySize; i++) {
		characters[i] = i + 1;
	}

	return 0;
}