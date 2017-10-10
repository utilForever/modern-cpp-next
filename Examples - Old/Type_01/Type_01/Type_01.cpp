int main() {
	// 변수의 정의
	short int si;				// short int 타입
	unsigned short int usi;		// unsigned short int 타입
	int i;						// int 타입(그동안 사용하던 타입)
	unsigned int ui;			// unsigned int 타입
	long int li;				// long int 타입
	unsigned long ul;			// unsigned long 타입

	// 작은 값을 대입
	si = 40000;		// ERROR : short int에게는 너무 큰 값
	usi = 40000;	// OK : unsigned short int는 아직 괜찮음
	i = 40000;		// OK
	ui = 40000;		// OK
	li = 40000;		// OK
	ul = 40000;		// OK

	// 조금 더 큰 값을 대입
	si = 70000;		// ERROR : short int에게는 너무 큰 값
	usi = 70000;	// ERROR : unsigned short int에게도 너무 큰 값
	i = 70000;		// OK
	ui = 70000;		// OK
	li = 70000;		// OK
	ul = 70000;		// OK

	// 더 큰 값을 대입
	si = 2200000000;	// ERROR : short int에게는 너무 큰 값
	i = 2200000000;		// ERROR : int에게는 너무 큰 값
	li = 2200000000;	// ERROR : long int에게는 너무 큰 값
	usi = 2200000000;	// ERROR : unsigned short int에게는 너무 큰 값
	ui = 2200000000;	// OK
	ul = 2200000000;	// OK

	// unsigned int와 unsigned long int의 한계는 어디?
	ui = 4300000000;	// ERROR : unsigned int에게도 너무 큰 값
	ul = 4300000000;	// ERROR : unsigned long int에게도 너무 큰 값

	// 음수를 대입
	si = -100;		// OK
	usi = -100;		// ERROR : unsigned short int는 음수 보관 불가능
	i = -100;		// OK
	ui = -100;		// ERROR : unsigned int는 음수 보관 불가능
	li = -100;		// OK
	ul = -100;		// ERROR : unsigned loing int는 음수 보관 불가능

	return 0;
}