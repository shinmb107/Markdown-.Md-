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