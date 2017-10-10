int main() {
	// 참조될 변수들을 정의
	double a, b, c;

	// 3개의 원소를 가진 포인터의 배열을 정의
	double* pArray[3];

	// 각 원소가 변수들을 가리키게 만듦
	pArray[0] = &a;
	pArray[1] = &b;
	pArray[2] = &c;

	return 0;
}

