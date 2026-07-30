#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Member {
private:
	char name[20];
	char phone[20];
	char addr[20];
	static int cnt;

public:
	Member();
	Member(const char*, const char*, const char*);
	void insert();
	void print();
};

Member::Member() { }

Member::Member(const char* name, const char* phone, const char* addr) {
	strcpy(this->name, name);
	strcpy(this->phone, phone);
	strcpy(this->addr, addr);
}

int Member::cnt = 0;

void Member::insert() {
	cout << "이름, 전화번호, 주소 입력 : ";
	cin >> name >> phone >> addr;
	cnt++;
}

void Member::print() {
	cout << "이름 : " << name << "전화번호 : " << phone << "주소 : " << addr << "객체 수 : " << cnt << endl;
}


int main() {
	Member m;

	for (int i = 0; i < 3; i++) {
		m.insert();
		m.print();
	}
	return 0;
}
