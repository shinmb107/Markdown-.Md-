#### 헤더파일 
###### cout, cin, endl 등을 선언
    #include <iostream>

#### 출력
    // 정수
    std::cout << 123;
    std::cout << 123 << 456 << 789;
    
    // 문자 ( " " )
    std::cout << "abc";
    std::cout << "ab" << "cd" << "ef";
    
    // 공백 ( ' ' )
    std::cout << ' ';
    std::cout << "ab" << ' ' << "cd";

### 입력
    // 정수
    int num;
    std::cin >> num;
    
    // 문자 
    char ch[100];
    std::cin >> ch;
    
    // 여러개
    int num1, num2;
    std::cin >> num1 >> num2;
    
    char ch1[10], ch2[10];
    std::cin >> ch1 >> ch2;
    
### 반복을 이용한 입/출력
    int num1, num2, result;
    
    std::cout << "숫자입력";
    std::cin >> num1 >> num2;
    
    for (int i = num1; i < num2; i++) {
        result += i;
	} 
    std::cout << num1 << " ~ " << num2 << "의 합 : " << result;

    /* 반복1 result = (1), 반복2 result = (1)+(2), 반복3 result = (3)+(3), 반복4 result = (6)+(4) , result = 10 */
###### 결과 
<pre>
    숫자 입력 : 1 5
    1 ~ 5의 합 : 10
</pre>

#### using namespace ' '
###### namespace '이름' 및 :: 를 붙이지 않고 사용할 수 있도록 하는 문법
###### namespace 'std::' 를 생략 가능
    using namespace std;
    
    int num;
    cin >> num;
    cout << num;

### 함수 오버로딩
###### 함수의 이름은 같지만 전달되는 정보(매개변수)가 다르기에 정보(매개변수)가 같은 함수를 참조하여 결정
###### 매개변수(개수, 자료형, 순서)가 다르기 때문에 컴파일러가 알맞은 함수를 선택하는 기능
###### 컴파일러는 어떤 함수를 호출할지 다음 기준으로 결정
###### 1. 매개변수의 개수 2. 매개변수의 자료형 3. 매개변수의 순서

    void MyFunc(char a) { return a }     // 문자 한 개 전달 = return(1번 MyFunc)
    void MyFunc(char a, char b) {...}    // 문자 두 개 전달(2번 MyFunc)
    void MyFunc(int a) {...}             // 숫자 한 개 전달(3번 MyFunc)
    void MyFunc(int a, int b) {...}      // 숫자 두 개(a, b) 전달(4번 MyFunc)
    void MyFunc(int b, int a) {...}      // 숫자 두 개(b, a) 전달(5번 MyFunc)
    
    MyFunc('A');                      // 문자 한 개 (1번 MyFunc)
    MyFunc('A', 'B');                 // 문자 두 개 (2번 MyFunc)
    MyFunc(10);                       // 숫자 한 개 (3번 MyFunc)
    MyFunc(10, 20);                   // 숫자 두 개(a, b) (4번 MyFunc)
    MyFunc(20, 30);                   // 숫자 두 개(b, a) (5번 MyFunc)

### 매개변수의 디폴트 값
###### 
