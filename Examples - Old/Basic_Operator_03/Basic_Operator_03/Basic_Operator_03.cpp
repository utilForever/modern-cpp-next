#include <iostream>

int main() {
	// 피연산자를 정의
	int a = 3;
	int b = 5;

	// 관계 연산자 사용
	bool b1, b2, b3, b4, b5, b6;
	b1 = a > b;		// a가 b보다 크다
	b2 = a >= b;	// a가 b보다 크거나 같다
	b3 = a < b;		// a가 b보다 작다
	b4 = a <= b;	// a가 b보다 작거나 같다
	b5 = a == b;	// a와 b가 같다
	b6 = a != b;	// a와 b가 같지 않다

	// bool 타입의 값을 문자로 출력하게 만듬
	std::cout << std::boolalpha;

	// 결과를 출력
	std::cout << a << " > " << b << " : " << b1 << std::endl;
	std::cout << a << " >= " << b << " : " << b2 << std::endl;
	std::cout << a << " < " << b << " : " << b3 << std::endl;
	std::cout << a << " <= " << b << " : " << b4 << std::endl;
	std::cout << a << " == " << b << " : " << b5 << std::endl;
	std::cout << a << " != " << b << " : " << b6 << std::endl;

	return 0;
}