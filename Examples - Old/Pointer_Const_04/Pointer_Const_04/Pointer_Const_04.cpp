int main() {
	int i1 = 10;
	int i2 = 20;
	const int* p = &i1;

	p = &i2;	// OK
	*p = 30;	// FAIL

	return 0;
}