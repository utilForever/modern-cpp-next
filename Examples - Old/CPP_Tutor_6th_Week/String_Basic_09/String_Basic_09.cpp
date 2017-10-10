#include <iostream>
#include <string>

int main() {
	// 전체 경로를 가진 문자열을 만듦
	std::string path = "C:\\My Document\\Pictures\\33.jpg";

	// 문자열의 길이를 얻어둠
	int len = path.size();

	// 맨 뒤쪽의 3 문자만 얻어옴
	std::string ext = path.substr(len - 3, 3);

	// 결과를 출력
	std::cout << "extention = " << ext << "\n";

	return 0;
}