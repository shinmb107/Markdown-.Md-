### static

일반 멤버 함수 -> 객체에 속함
static 멤버 함수 -> 클래스에 속함

    class Member {
    private:
    	char name[20];      // 일반 멤버 변수( 객체마다 각각 하나 씩 생성 )
    	char phone[20];     // 일반 ...
    	char addr[20];      // 일반 ...
	    static int count;

    public:
    	Member(const char*, const char*, const char*);
	    static void MemberCount(int);
    	void print();
    };

    Member::Member(const char* _name, const char* _phone, const char* _addr) {
    	strcpy(name, _name);
	    strcpy(phone, _phone);
    	strcpy(addr, _addr);
	    count++;
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

    int Member::count = 0;

    int main() {
    	Member m1("shin", "010-1111-1111", "@@@");
    	m1.print();
	    Member m2("kkim", "010-2222-2222", "@@@");
	    m2.print();
	    Member m3("park", "010-3333-3333", "@@@");
    	m3.print();

	    return 0;
    }
