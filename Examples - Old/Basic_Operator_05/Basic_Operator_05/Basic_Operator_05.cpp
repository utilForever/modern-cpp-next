#include <iostream>

int main() {
	// 정보를 보관할 변수 정의
	int age;	// 나이
	bool male;	// 남성인가?

	// age, male 값을 입력 받음
	age = 20;		// 20세
	male = true;	// 남성

	// 조건을 만족하는지 검사
	bool ok;	// 자격을 갖춘 사람인가?
	ok = age > 19 && male == true;

	// 결과 출력
	std::cout << std::boolalpha;
	std::cout << "ok = " << ok << std::endl;

	return 0;
}