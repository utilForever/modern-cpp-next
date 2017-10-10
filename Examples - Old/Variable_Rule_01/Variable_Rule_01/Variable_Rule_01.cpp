int main() {
	// 동일한 이름의 변수에 대한 실험
	int duplicated;		// 올바름
	int duplicated;		// 오류 : 이미 정의된 변수 이름 사용 불가능

	// 변수의 이름으로 사용할 수 있는 문자에 대한 실험
	int abcDE;		// 올바름 : 알파벳 가능
	int _abc_de;	// 올바름 : 알파벳과 언더스코어(_) 가능
	int abc123;		// 올바름 : 알파벳과 숫자 가능
	int _123abc;	// 올바름 : 알파벳, 숫자, 언더스코어(_) 가능
	int abc@!~;		// 오류 : 언더스코어(_)를 제외한 기호는 포함 불가능
	int 123abc;		// 오류 : 숫자가 맨 앞에 위치하는 것 불가능

	// 변수의 이름 길이 제한 실험
	int abcdefghijklmnopqrstuvwxyz1abcdefghijklmnopqrstuvwxyz1abcdefghijk2, lmnopqrstuvwxyz3;

	// 알파벳의 대소문자와 관련된 실험
	int Abc;		// 올바름 : 중복되지 않음
	int aBc;		// 올바름 : 중복되지 않음
	int abC;		// 올바름 : 중복되지 않음
	int ABc;		// 올바름 : 중복되지 않음
	int AbC;		// 올바름 : 중복되지 않음
	int aBC;		// 올바름 : 중복되지 않음

	// 키워드와 중복되는 경우 실험
	int namespace;		// 오류 : 키워드를 변수 이름으로 사용 불가능
}