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
