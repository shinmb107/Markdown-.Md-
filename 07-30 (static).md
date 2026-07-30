### static

일반 멤버 함수 -> 객체에 속함
static 멤버 함수 -> 클래스에 속함

클래스 = 설계도 (말 그대로 실체로 구현을 하기 위한 준비, ex) -> 아파트 설계도)
-> class Member { 철근; 기둥; 벽; }
-> 설계도 이름 { 아파트를 만들려면 철근;, 기둥;, 지붕;이 있어야겠네 }

객체 = 실제 만들어진 물건 ( 설계도를 토대로 실제 물건을 만듬, ex) -> 1층의(철근, 기둥, 지붕)) 
-> Member m1("shin", "010-1111-1111", "@@@"); == 객체 1개 완성
-> 설계도 1층("철근 사서 박았다", "기둥을 세웠다", "지붕 올렸다"); == 아파트의 1층 완성

###### **철근 이라는 이름은 동일하지만 각 층에 사용하는 철근은 다름, 1층의 철근을 2층에 써버리면 1층은 무너져버림**


static = 아파트 전체가 공유해서 사용 ( 딱 하나만 존재, ex) -> 엘리베이터 )
-> 엘리베이터가 1층에 도착 -> 현재 엘리베이터는 1층이 사용
-> 2층에서 엘리베이터 호출 -> 현재 엘리베이터는 2층이 사용


    class Member {
    private:
    	char name[20];      // 일반 멤버 변수( 객체마다 각각 하나 씩 생성 )
		char phone[20]; 	// Member m1(name, phone, addr); | Member m2(...); | Member m3(...);
		char addr[20];		// 즉, 'm1'의 'name' 과 'm2'의 'name' 그리고 'm3'의 'name' 은 각각 다름
    	    
	    static int count;	// 객체마다 생성되지 않음! 즉 프로그램 전체에서 딱 하나만 존재!
							// 즉, 'm1'의 'count' == 'm2'의 'count' == 'm3'의 'count' 의 모든 객체는 count를 공유!
    public:
    	Member(const char*, const char*, const char*);		// 클래스 외부에서 사용하기 위한 정의
	    static void MemberCount(int);						// 외부에서 
    	void print();										// 
    };

    Member::Member(const char* _name, const char* _phone, const char* _addr) {
    	strcpy(name, _name);
	    strcpy(phone, _phone);
    	strcpy(addr, _addr);
	    count++;					// 모든 객체는 같은 count를 공유하기, 객체가 만들어질 때마다 1씩 증가
    }

    //Member::Member(const char* _name, const char* _phone, const char* _addr) {
    //	strcpy(this->name, _name);
    //	strcpy(this->phone, _phone);
    //	strcpy(this->addr, _addr);
    //	count++;
    //}

    void Member::print() {
    	cout << "이름 : " << name << " 전화번호 : " << phone << " 주소 : " << addr << " 객체 수 : " << count << endl;
    }

    int Member::count = 0;		// static 변수는 반드시 초기화 ( 그러지 않으면 오류 발생, 실행X )

    int main() {
    	Member m1("shin", "010-1111-1111", "@@@");
    	m1.print();
	    Member m2("kkim", "010-2222-2222", "@@@");
	    m2.print();
	    Member m3("park", "010-3333-3333", "@@@");
    	m3.print();

	    return 0;
    }
