enum JOB_KINDS { JOB_DWARF, JOB_WARRIOR, JOB_SORCERER };

struct Character {
	JOB_KINDS jobType;

	// 다른 멤버들이 더 있음
};

int main() {
	Character c;

	// c가 누군가에 의해 초기화됨

	// c가 마법사인 경우
	if (c.jobType == JOB_SORCERER) {
		// 필요한 일을 함
	}

	return 0;
}