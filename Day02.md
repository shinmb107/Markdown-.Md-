### 참조자와 함수
###### Call-by-value

값을 전달하며 호출하는 함수 -> 그 함수는 Call-by-value -> 함수 밖에 선언한 변수에는 접근이 불가능하다.

    // Call-by-value
    void Swap(int num1, int num2) {    // num1 = 10, num2 = 20 일 경우
        int temp = num1;               // temp = 10
        num1 = num2;                   // num1 = 20 
        num2 = temp                    // num2 = 10
    }
    /* num1, num2 는 함수 안에서만 사용, main이나 다른 함수에는 사용 불가능(지역변수) */

###### Call-by-reference
    // Call-by-y-reference
    void Swap(int* num1, int* num2) {    // num1 = 10, num2 = 20 일 경우
        int temp = *num1;               // temp = 10
        *num1 = *num2;                   // num1 = 20 
        *num2 = temp                    // num2 = 10
    }
    /* num1, num2를 주소 값으로 전달, 전달된 주소의 메모리 공간에 접근이 가능(전역변수) */

### 참조자
#### 변수에 다가 주소 값을 넣겠다는 선언 -> 변수 값을 모든 함수, main에서 사용하기 위해 주소 형태를 사용
#### 아쉽지만 c언어나, c++에서는 변수끼리 값을 못 주고 받기에 어쩔 수 없이 참조자나 포인터를 사용
#### int*, int& 도 어쨌든 int 형태이므로 int로 받을 수 있음 ( 전달 : int*, int& -> 받음 : int )
#### 함수 안에 있는 변수에는 반드시 주소 형태로 선언하여야 main에서 받을 수 있음 ( int는 '*', '&' int로만, char는 '*', '&' char로만 가능 )
#### 함수 구조

    int Func(int num1 = 10, int num2 = 20); // 함수 선언

    int main() {
        Func();		// 함수 호출
    }
    int Func(int num1, int num2) {   // 함수 정의
        return num1 + num2;
    }
#### 참조자 사용

    void SwapByReference(int& ref1, int& ref2) { // 변수에다가 주소 값을 넣겠다는 선언
	     int temp = ref1;   // ref1 값에는 int형 주소 형태, 즉 temp에는 int형 주소가 들어가 있음
	     ref1 = ref2;       // ref1, ref2 값도 int형 주소 형태
	     ref2 = temp;       // ref2, temp 값도 int형 주소 형태
    }
    int main() {
        int val1 = 10;   // int형
        int val2 = 20;   // int형

	     SwapByReference(val1, val2);   // int형 안에 int&를 넣음
	     cout << "val1 : " << val1 << ", val2 : " << val2 << endl;
	     return 0;
    }

### const 참조자
#### 함수의 정의 형태와 함수의 호출 형태에서 변수의 변경 유무(주소 -> 일반, 일반 -> 주소)를 알 수 없음
#### 즉, 코드가 길어지면 주소 -> 일반, 일반 -> 주소로 변경을 해도 되는지 확인하기 위해 전체 코드를 살펴봐야 함
#### 근데 제일 위쪽 함수 선언 또는 함수 정의 부분에 const로 선언을 하면 "아! 이거는 못 바꾸겠네" 를 빨리 알 수 있어서 const 사용 
#### -사실 고의로 바꿀 일은 없겠지만 실수 방지를 위해 아예 값 형태를 고정 시킬려고 사용-

