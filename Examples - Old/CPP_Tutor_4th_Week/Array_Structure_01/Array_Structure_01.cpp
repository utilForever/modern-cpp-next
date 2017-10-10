#include <iostream>

// 학생 정보를 갖는 구조체
struct StudentInfo {
	char name[20];	// 이름
	int stdNumber;	// 학번
	float grade[2];	// 최근 2학기 평점
};

int main() {
	// 학생에 대한 정보를 보관
	StudentInfo si = {"Kim Chol-Su", 200121233, {3.2f, 3.5f}};

	// 학생의 정보를 출력
	std::cout << si.name << std::endl;
	std::cout << si.stdNumber << std::endl;
	std::cout << si.grade[0] << ", " << si.grade[1] << std::endl;

	return 0;
}