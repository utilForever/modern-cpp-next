void sub();

int main() {
	// 변수를 정의
	int a = 3;

	// 함수 호출
	sub();

	return 0;
}

void sub() {
	// 오류 : 변수를 사용
	++a;	
}