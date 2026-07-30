<hr>

### 클래스 = 설계도 (말 그대로 실체로 구현을 하기 위한 준비(정) ), ex) -> 아파트 설계도

#### -> class Member { 철근; 기둥; 벽; }

#### -> 설계도 이름 { 아파트를 만들려면 철근;, 기둥;, 지붕;이 있어야겠네 }
<hr>

### 객체 = 실제 만들어진 물건 ( 설계도를 토대로 실제 물건을 만듬 ), ex) -> 1층의(철근, 기둥, 지붕)

#### -> Member m1("shin", "010-1111-1111", "@@@"); == 객체 1개 완성

#### -> 설계도 1층("철근 사서 박았다", "기둥을 세웠다", "지붕 올렸다"); == 아파트의 1층 완성

###### **철근 이라는 이름은 동일하지만 각 층에 사용하는 철근은 다름, 1층의 철근을 2층에 써버리면 1층은 무너져버림**
<hr>

### static = 아파트 전체가 공유해서 사용 ( 딱 하나만 존재 ), ex) -> 엘리베이터

#### -> 엘리베이터가 1층에 도착 -> 현재 엘리베이터는 1층이 사용

#### -> 2층에서 엘리베이터 호출 -> 현재 엘리베이터는 2층이 사용

##### 일반 멤버 함수 -> 객체에 속함

##### static 멤버 함수 -> 클래스에 속함

<hr>

    class Member {
    private:
 
        /** 일반 멤버 변수( 객체마다 각각 하나 씩 생성 ) **/
	    /** Member m1(name, phone, addr); | Member m2(...); | Member m3(...); **/
	    /** 즉, 'm1'의 'name' 과 'm2'의 'name' 그리고 'm3'의 'name' 은 각각 다름 **/
		
    	char name[20];      
		char phone[20]; 	
		char addr[20];		


		/** 객체마다 생성되지 않음! 즉 프로그램 전체에서 딱 하나만 존재! **/
		/** 즉, 'm1'의 'count' == 'm2'의 'count' == 'm3'의 'count' 모든 객체는 count를 공유! **/
		
	    static int count;	

<hr>

	/** 클래스 이름과 같은 이름이고 반환형이 없으면 생성자 **/
    /** 앞에 void, int, double, char 등이 있으면 일반 함수 **/
	
    public:													// 클래스 안에는 "이런 것들이 있다."라고 알려주는 역할 -> 그러므로 public
    	Member(const char*, const char*, const char*);		// 클래스 밖에서 사용할 *생성자* 선언, (객체가 생성될 때 자동으로 호출)
    	void print();										// 일반 멤버 *함수* 선언, (객체를 통해 호출하는 함수)
		static void MemberCount(int);						// static(정적) 멤버 *함수* 선언 (객체가 아닌 클래스에 속한 함수)
    };

<hr>

	/** 실제 내용(구현)은 클래스 밖에서 작성 **/
	/** Member:: -> Member 클래스에 속한 생성자를 의미, Member() → 생성자 **/
	
    Member::Member(const char* _name, const char* _phone, const char* _addr) {	// 객체를 만들 때 전달받는 값
    	strcpy(name, _name);	// 전달 받은 이름을 객체의 name 변수에 복사 ( _name -> "shin" -> 객체의 name에 저장 )
	    strcpy(phone, _phone);	// ( _phone -> "010-" -> 객체의 phone에 저장 )
    	strcpy(addr, _addr);	// ( _addr -> "@@@" -> 객체의  addr에 저장 )
	    count++;				// 모든 객체는 같은 count를 공유하기, 객체가 만들어질 때마다 1씩 증가
    }

<hr>

    /** 위 코드와 기능은 완전히 같음, 차이점은 this 포인터를 명시적으로 사용 했느냐의 안했느냐 차이 **/
	/** 멤버 변수와 매개변수의 이름이 같을 때 많이 사용
	/** 위 코드 -> ( 멤버변수 : name / 매개변수 : _name ), 아래 코드 -> ( 멤버변수 : name / 매개변수 : name ) **/
	
    //Member::Member(const char* name, const char* phone, const char* addr) {
    //	strcpy(this->name, name);
    //	strcpy(this->phone, phone);
    //	strcpy(this->addr, addr);
    //	count++;
    //}

<hr>

	/** 실제 내용(구현)은 클래스 밖에서 작성 **/
	/** Member:: -> Member 클래스에 속한 생성자를 의미, Member() → 생성자 **/
	
    void Member::print() {	// 객체의 정보를 출력하는 함수
    	cout << "이름 : " << name << " 전화번호 : " << phone << " 주소 : " << addr << " 객체 수 : " << count << endl;
    }

<hr>

    int Member::count = 0;		// static 변수는 반드시 초기화 ( 그러지 않으면 오류 발생, 실행X )

<hr>

    int main() {
    	Member m1("shin", "010-1111-1111", "@@@");	// -> 객체 1개, count = 1
    	m1.print();
	    Member m2("kkim", "010-2222-2222", "@@@");	// -> 객체 2개, count = 2
	    m2.print();
	    Member m3("park", "010-3333-3333", "@@@");	// -> 객체 3개, count = 3
    	m3.print();

	    return 0;
    }

<hr>
