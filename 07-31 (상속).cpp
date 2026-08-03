### 상속

++ 상속은 기존 클래스의 속성과 기능을 새로운 클래스가 물려받는 기능으로, 코드 재사용, 중복 감소, 확장성 증가를 가능하게 함
C++ 문서에서 정의하듯, 상속을 통해 부모 클래스의 멤버를 자식 클래스가 그대로 사용할 수 있음

상속의 기본 개념과 용어
부모 클래스 (기반 클래스 / Base Class) : 성질을 물려주는 기존 클래스
자식 클래스 (파생 클래스 / Derived Class): 부모 클래스로부터 성질을 물려받아 새로 만들어지는 클래스
기본 문법 : " class 자식클래스 : 접근제어자 부모클래스 형태" 로 선언

접근 제어자
public 상속 : 가장 많이 쓰이며, 부모 클래스의 public 및 protected 멤버의 접근 권한을 유지한 채 상속
protected 상속 : 부모의 public 멤버가 자식에게는 protected로 변경
private 상속: 부모의 모든 멤버가 자식에게 private로 변경

상속의 주요 장점
코드 재사용 : 공통된 코드를 부모 클래스에 한 번만 작성하고 여러 자식 클래스가 공유
유지보수 용이 : 부모 클래스만 수정하면 모든 자식 클래스에 반영
다형성 구현 : 가상 함수와 함께 사용해 객체 지향 프로그래밍의 핵심인 다형성을 지원


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Computer {	// 컴퓨터 클래스를 정의
private:			// 클래스 내부에서만 접근 가능
	char user[50];	// 사용자 이름을 저장할 문자 배열

public:										// 객체를 통해 어디서든 사용
	Computer(const char* name) {			// 컴퓨터 클래스 생성자, 객체가 생성될 때 자동으로 호출
		printf("Computer 생성자 호출!!\n");
		strcpy_s(user, name);				// 전달받은 이름을 user 배열에 복사, (Computer c("홍길동"); -> user = "홍길동")
	}

	void Calculate() {						// 계산 기능을 수행하는 멤버 함수
		cout << "요청 내용을 계산합니다." << endl;
	}
};


class NoteBook : public Computer {		// 노트북 클래스에서 컴퓨터 클래스를 public 상속, public 멤버를 그대로 사용 가능
private:
	int battery;						// 현재 배터리 용량을 저장할 변수

public:
	NoteBook(const char* name, int initChag)	// 노트북 클래스 생성자. 이름과 초기 배터리 값 전달, NoteBook n("홍길동", 5);
		: Computer(name), battery(initChag) {	// 멤버 이니셜라이저, 부모 클래스 생성자를 호출 후 battery를 초기화
		printf("Notebook 생성자 호출!!\n");
	}
	void Charging() {		// 충전 함수를 호출하면 배터리 변수 값 5증가
		battery += 5;
	}
	void UseBattery() {		// 배터리 사용 함수를 호출하면 배터리 변수 값 1감소
		battery -= 1;
	}
	void MovingCal() {				// 이동하면서 배터리의 변화를 출력 할 함수
		if (GetBatteryInfo() < 1) {	// 배터리 변수 값이 1 미만이면 "충전 필요"를 출력 후 반환
			cout << "충전이 필요합니다." << endl;
			return;
		}
		cout << "이동하면서 ";		// 배터리 변수 값이 1 이상일 경우 요청 내용을 계산 후 
		Calculate();				// 부모 클래스의 Calculate()를 호출 -> Computer::Calculate()
		UseBattery();				// 계산 후 배터리 변수 값 1감소
	}
	int GetBatteryInfo() {			// 현재 배터리 값을 반환하는 함수
		return battery;				// battery 값을 반환
	}
};


class TabletNotebook : public NoteBook {	// NoteBook을 상속
private:
	char PenModel[50];						// 등록된 펜 모델명을 저장 할 변수
public:
	TabletNotebook(const char* name, int initChag, const char* pen) : NoteBook(name, initChag) { // 부모인 NoteBook 생성자를 먼저 호출, 그 안에 Computer 생성자도 호출
		printf("TabletNotebook 생성자 호출!!\n");
		strcpy_s(PenModel, pen);			// 등록된 펜 모델명을 저장
	}
	void Write(const char* penInfo) {		// 필기 기능
		if (GetBatteryInfo() < 1) {			// 배터리 값이 1 미만이면 충전이 필요를 출력 후 반환
			cout << "충전이 필요합니다." << endl;
			return;
		}
		if (strcmp(PenModel, penInfo) != 0) {	// 등록된 펜과 입력한 펜을 비교
			cout << "등록된 펜이 아닙니다." << endl;
			return;
		}
		cout << "필기 내용을 처리합니다." << endl;
		UseBattery();							// 필기를 하면 배터리 1 감소
	}
};


int main() {
	NoteBook nc("이수종", 5);
	nc.MovingCal();

	TabletNotebook tn("정수영", 5, "ISE-241-242");
	//nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}
