int main() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i1;

	p = &i2;	// FAIL
	*p = 30;	// FAIL

	return 0;
}