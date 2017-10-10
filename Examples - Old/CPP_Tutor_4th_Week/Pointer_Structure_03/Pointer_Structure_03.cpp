#include <iostream>

struct Dizzy {
	int id;		// 구조체 변수마다 갖는 고유한 값
	Dizzy* p;	// Dizzy 구조체를 가리키는 포인터
};

int main() {
	// Dizzy 객체를 3개 만들고, 서로를 가리키게 만듦
	Dizzy a, b, c;

	a.id = 1;
	a.p = &b;
	b.id = 2;
	b.p = &c;
	c.id = 3;
	c.p = &a;

	// a만 사용해서 a, b, c에 모두 접근
	std::cout << "a.id = " << a.id << std::endl;
	std::cout << "b.id = " << a.p->id << std::endl;
	std::cout << "c.id = " << a.p->p->id << std::endl;
	std::cout << "a.id = " << a.p->p->p->id << "(again)" << std::endl;

	return 0;
}