#include <iostream>
using namespace std;

class A {
private:
	int num;
	char ch[10];  // 문자열을 저장할 배열

public:
	// 멤버 이니셜라이저를 사용하면 멤버 변수, 상수 멤버 변수, 참조 멤버 변수를 초기화할 수 있음
	// 이니셜라이저를 사용하는 이유는 생성자 본문에서 각각 변수를 초기화하지 않기 위해서 임 (코드 길이가 줄어듦)
	// 즉, A(){}, A(int n){}, A(int n1, int n2){} 등을 각각 정의하지 않고, A(int n1 = 0, int n2 = 0){} 하나로 정의 가능
	
	A() : num(0), ch("Hello") {	// 멤버 이니셜라이저를 사용한 생성자
		cout << "이니셜라이저 생성자 호출" << endl;
	}

	A() {	// 매개변수가 없는 생성자(기본 생성자)
		num = 0;						// num 멤버 변수 초기화
		strcpy(ch, "Hello");			// strcpy() 함수를 사용하여 문자열 복사, 문자열 마지막에 반드시 널문자 필요
		cout << "생성자 호출" << endl;
	}

	~A() {	// 소멸자 정의, 소멸자는 객체가 소멸될 때 자동으로 호출 | 동적 메모리 해제를 수행 | 소멸자는 매개변수를 가질 수 없으며, 반환형도 없음
		cout << "소멸자 호출" << endl;
	}


	A(int n) {	// 매개변수가 하나인 생성자 (이니셜라이저 생성자 사용시 필요없음, 즉 이렇게 각각 변수를 초기화하지 않기 위해 이니셜라이저 사용)
		num = n;
		strcpy(ch, "Hello");
	}


	A(int n1, int n2) {	// 매개변수가 두 개인 생성자 (이니셜라이저 사용시 필요없음)
		num = n1;
		strcpy(ch, "Hello");
	}

	A(int n1 = 0, int n2 = 0) {	// 디폴트 매개변수를 사용한 생성자 (이니셜라이저 사용시 필요없음)
		num = n1;
		strcpy(ch, "Hello");
	}


	void ShowData() const {		// const 멤버 함수에서 상수화(const)하여 멥버 변수값을 변경하지 않음
		cout << "num : " << num << ", ch : " << ch << endl;
	}

};

int main() {

	A a1;				// a1 객체 생성, 매개변수가 없는 생성자 호출
	a1.ShowData();		// 객체의 데이터 출력

	A a2(10);			// a2 객체 생성, 매개변수가 하나인 생성자 호출
	a2.ShowData();		// 객체의 데이터 출력

	A a3(20, 30);		// a3 객체 생성, 매개변수가 두 개인 생성자 호출
	a3.ShowData();		// 객체의 데이터 출력

	A a4(40, 50);		// a4 객체 생성, 디폴트 매개변수 사용
	a4.ShowData();		// 객체의 데이터 출력

	return 0;
}