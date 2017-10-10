#include <iostream>

int main() {
	// 정보를 보관할 변수 정의
	int age;	// 나이

	// age 값을 입력 받음
	age = 19;	// 19세

	// 조건에 따라서 다른 문자열을 출력
	if (age <= 18) {
		std::cout << "미성년자입니다" << std::endl;
	} else if (age == 19) {
		std::cout << "아쉽네요" << std::endl;
	} else {
		std::cout << "성인입니다" << std::endl;
	}

	return 0;
}