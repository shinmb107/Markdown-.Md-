### 기본 함수

##### 함수 오버라이딩시 포인터 형에 따름
##### 함수 호출시 사용 된 포인터의 형에 따라 호출되는 함수가 결정
##### 즉, 포인터의 형에 정의된 함수가 호출

<hr>

### virtual -> 가상함수

##### 포인터의 형에 상관 없이 포인터가 가리키는 객체의 마지막 오버라이딩 함수를 호출
##### 오버라이딩 된 함수가 virtual이면 오버라이딩 한 함수도 자동 virtual

<hr>

### 예시
    /* 기본 함수 */
    class First {
    public:
	    void MyFunc() {		// 각각 자신의 함수를 출력 -> "First class" (기본)
	    	cout << "First class" << endl;
    	}
    };

<hr>

    /* virtual 함수 */
    class First {
    public:
    	virtual void MyFunc() {	// 가장 마지막 함수를 출력 -> "Third class" (가상함수)
	    	cout << "First class" << endl;
    	}
    };

<hr>

### 전체코드

    class First {
    public:
	    //void MyFunc() {		// 각각 자신의 함수를 출력 -> "First class" (기본)
    	virtual void MyFunc() {	// 가장 마지막 함수를 출력 -> "Third class" (가상함수)
	    	cout << "First class" << endl;
    	}
    };

    class Second : public First {
    public:
    	//void MyFunc() {		// 각각 자신의 함수를 출력 -> "Second class" (기본)
    	virtual void MyFunc() {	// 가장 마지막 함수를 출력 -> "Third class" (가상함수)
    	    	cout << "Second class" << endl;
    	}
    };

    class Third : public Second {
    public:
    	//void MyFunc() {		// 각각 자신의 함수를 출력 -> "Third class" (기본)
    	virtual void MyFunc() {	// 가장 마지막 함수를 출력 -> "Third class" (가상함수)
    		cout << "Third class" << endl;
    	}
    };

    int main() {
    	Third* tptr = new Third();	// 세번째 클래스의 포인터 생성
    	Second* sptr = tptr;		// 두번째 클래스의 포인터에 세번째 클래스의 포인터를 대입
	    First* fptr = sptr;			// 첫번째 클래스의 포인터에 두번째 클래스의 포인터를 대입
	
    	fptr->MyFunc();				// 기본일 경우 각각의 함수를 출력(virtual일 경우 가장 마지막 함수 출력)
    	sptr->MyFunc();
    	tptr->MyFunc();
    	delete tptr;

    	return 0;
    }
