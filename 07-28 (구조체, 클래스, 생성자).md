### 구조체

연관 있는 데이터를 하나로 묶어 프로그램의 구현 및 관리가 용이

연관 있는 데이터들은 생성 및 소멸의 시점이 일치, 이동, 전달의 시점 및 방법이 일치하기 때문에 하나의 자료형으로 묶어서 관리


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



### 생성자 (Constructor)

객체를 만들기 위해서는 반드시 생성자가 호출 되어야 함

입력이 없는 생성자는 자동으로 만들어짐 (디폴트 생성자)

만약, 하나라도 생성자를 만들면 디폴트 생성자는 자동으로 만들어지지 않음


    #define _CRT_SECURE_NO_WARNINGS //strcpy(), strlen() 같은 C 문자열 함수를 사용할 때 나오는 경고를 없애기 위한 매크로
    #include <iostream>
    using namespace std;

    class Person {	// class 생성 및 class Person 정의
    	char* name;
    	int age;

    public:
    	Person(const char* myname, int myage) {	// 생성자 오버로딩
	    	int len = strlen(myname) + 1;		// 문자열 길이 + 1(널문자), 문자열 마지막에 반드시 널문자 필요
		    name = new char[len];				// new 연산자를 사용하여 동적 메모리 할당
		    									// (동적 : 프로그램 실행 중에 메모리 할당)
	    	strcpy(name, myname);				// 문자열 복사
	    	age = myage;						// 나이 초기화
	    	cout << "call constructor(생성자 호출)" << endl;
	    }

    	void ShowPersonInfo() const {			// const 멤버 함수에서 상수화(const)하여 멥버 변수값을 변경하지 않음
    											// const 함수는 "age = 30;" -> 직접 값을 변경하면 오류,
    											// 반드시 "cout << age;" 처럼 멤버 함수를 통해 값을 변경해야 함
    		cout << "이름 : " << name << endl;
    		cout <<" 나이 : " << age << endl;
    	}

    	~Person() {					// 소멸자 정의, 소멸자는 객체가 소멸될 때 자동으로 호출, 동적 메모리 해제를 수행
	    	delete[] name;			// 동적 메모리 해제, new 연산자로 할당한 메모리는 delete 연산자로 해제해야 함
	    	cout << "call destructor(소멸자 호출)" << endl;
    	}
    };

    int main() {
    	Person man1("Lee dong woo", 29);	// man1 객체 생성
    	Person man2("Jang dong gun", 42);	// man2 객체 생성
    	man1.ShowPersonInfo();
    	man2.ShowPersonInfo();

    	return 0;
    }
