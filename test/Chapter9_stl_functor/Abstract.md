# 9장 STL 함수객체 (functor)

## 다시 볼 부분

 * p472 : ptr_fun()구현 부분. 코드 이해가 안됨.
 * p476~478 : mem_fun(), mem_fun_ref()의 차이

## 요약
### Section 01 : 함수객체의 종류
STL functor의 두 종류
  * 일반 함수 객체
    * 산술 : plus, minus, multipies, divides, modulus, negate
    * 비교 : equal_to, not_equal_to, less, greater, greater_equal, less_equal
      * 모든 비교의 base functor는 less
    * 논리 : logical_and(&&), logical_or(||), logical_not(!)

  * 함수 어댑터

정의 방법 : 기본클래스를 상속 받는다. (first_argument_type, second_argument_type, return_type을 정의하는 수고를 덜 수 있다)
  * binary_function<T,T,T>
  * unary_function<T,T>

### Section 05 : 바인더(binder)
binder는 이항 함수자를 단항 함수자로 변환 한다. (이항의 하나를 원하는 값으로 고정 시킨다.)
  * bind1st : 이항 함수자의 첫 번째 인자(left)를 고정하여 단항 함수자로 변환
  * bind2nd : 두 번째 인자 고정

### Section 06 : 부정자(negator)
  * not1 : 단항 조건자를 반대의 조건자로 변환
  * not2 : 이항 조건자를 "

### Section 07 : 함수 포인터 어댑터
일반 함수를 함수 어댑터 적용이 가능한 함수객체로 변환 해준다.
  * std::ptr_fun()


### Section 08 : 멤버 함수 포인터 어댑터
멤버 함수를 함수 객체로 변환해서 알고리즘이 객체 원소의 멤버함수를 호출할 수 있게 한다.
  * mem_fun_ref() : 객체로 멤버 함수 호출
  * mem_fun() : 객체의 주소로 멤버 함수 호출


