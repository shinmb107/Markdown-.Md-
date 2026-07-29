### 구조체

연관 있는 데이터를 하나로 묶어 프로그램의 구현 및 관리가 용이 
연관 있는 데이터들은 생성 및 소멸의 시점이 일치, 이동, 전달의 시점 및 방법이 일치하기 때문에 하나의 자료형으로 묶어서 관리

### 생성자 (Constructor)

객체를 만들기 위해서는 생성자가 호출 되어야 한다.
입력이 없는 생성자는 자동으로 만들어진다. (디폴트 생성자)
만약, 하나라도 생성자를 만들면 디폴트 생성자는 자동으로 만들어지지 않는다.

### 클래스

    #include <iostream>
    using namespace std;

    class SimpleClass {		// class 생성 및 class SimpleClass 정의
	    int num1;			// num1 멤버 변수
	    int num2;			// num2 멤버 변수

    public:
	    SimpleClass(int n1 = 0, int n2 = 0) {	// 디폴트 매개변수를 사용한 생성자
											// n1, n2가 전달되지 않으면 0으로 초기화
	    	num1 = n1;
	    	num2 = n2;
    	}

	    void ShowData() const {		// const 멤버 함수에서 상수화(const)하여 멥버 변수값을 변경하지 않음
    		cout << "num1 : " << num1 << ", num2 : " << num2 << endl;
    	}
    };

    int main() {
	    SimpleClass sc1();			// sc1() 함수 선언 // sc1() 함수는 SimpleClass 객체를 반환하는 함수
    	SimpleClass mysc = sc1();	// sc1() 함수 호출 후 반환된 객체를 mysc에 복사 생성
    	mysc.ShowData();
    	return 0;
    }

    SimpleClass sc1() {				// sc1() 함수 정의, 반환형이 SimpleClass인 함수
	    SimpleClass sc(100, 200);	// sc 객체 생성, sc1() 함수에서 반환할 객체 생성
    	return sc;					// sc1() 함수에서 반환할 객체 반환
    }
