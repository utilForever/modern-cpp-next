#include <iostream>
#include <cstring>

int main() {
	// 원본 문자열을 하나 만듦
	char src[] = "KNUCSE C++ Tutor";

	// 원본 문자열 복사하기!
	
	// 1. 원본 문자열의 길이를 잼
	int len = strlen(src);

	// 2. 새 문자열이 담길 메모리를 할당함
	char* dest = new char[len + 1];

	// 3. 문자열을 복사함
	strcpy(dest, src);

	// 결과를 출력
	std::cout << "src = " << src << "\n";
	std::cout << "dest = " << dest << "\n";

	// 메모리를 해제함
	delete[] dest;
	dest = NULL;

	return 0;
}