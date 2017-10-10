#include <iostream>

// 최대공약수와 최소공배수를 구함
void GCD_LCM(int a, int b, int gcd, int lcm) {
	// 유클리드의 호제법을 사용해서 GCD를 구함
	int z;
	int x = a;
	int y = b;

	while (true) {
		z = x % y;

		if (z == 0) {
			break;
		}

		x = y;
		y = z;
	}

	// 결과를 저장
	gcd = y;
	lcm = a * b / gcd;
}

int main() {
	// 28과 35의 최대공약수와 최소공배수를 구함
	int gcd = 0;
	int lcm = 0;
	GCD_LCM(28, 35, gcd, lcm);

	// 결과를 출력
	std::cout << "GCD = " << gcd << "\n";
	std::cout << "LCM = " << lcm << "\n";

	return 0;
}