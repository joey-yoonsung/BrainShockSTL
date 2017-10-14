# 10장 반복자 (Iterator)

## 다시 볼 부분

## 요약
### Section 01 : 반복자의 종류
포인터를 추상화한 클래스 객체 포인터가 하지 못하는 더 많은 동작을 수행할 수 있다.

순차열(sequence)와 구간(range)개념.

[begin, end) 순차 구간으로 정의
  * 입력 반복자(input iterator): 전방향 읽기(istream)
  * 출력 반복자(output iterator): 전방향 쓰기(ostream)
  * 순방향 반복자(forward iterator): 전방향 읽기, 쓰기 (-- 쓸 수 없음.)
  * 양방향 반복자(bidirectional iterator): 양방향 읽기, 쓰기(list, set, multiset, map, multimap)
  * 임의 접근 반복자(random access iterator): 랜덤 읽기 쓰기(vector, deque)
 

### Section 02 : X::iterator 와 X::const_iterator
STL의 모든 컨테이너는 iterator 와 reverse_iterator를 정의한다. 이에따라 각 형식의 const 버전도 정의.
  * X::iterator : 정방향 반복자의 내장 형식. 반복자가 가리리키는 원소의 읽기, 쓰기 가능.
  * X::const_iterator : 읽기만 가능.
  
반복자가 가리키는 원소의 위치를 변경하지 않으려면 const로 반복자의 변수를 선언.
  * const X::iterator a;
  
vector, deque 컨테이너는 배열 기반 : 임의 접근 반복자 ([], +=, -=, +, -, <, >, <=, >= 가능)
list, set, multiset, map, multimap : 양방향 반복자 (임의 접근 불가능. ++, -- 만 가능)

### Section 03 : X::reverse_iterator와 X::const_reverse_iterator 
  * reverse는 rbegin(), rend() 로 받아야 한다. 
  * 정방향은 자신의 value를 나타내지만, reverse는 다음 원소의 value를 참조한다.
  
반복자 어댑터
```cpp
    vector<int> v;
    reverse_iterator<verctor<int>::iterator> rbiter(v.end());
    reverse_iterator<verctor<int>::iterator> reiter(v.begin());
```
형변환
  * 비 const -> const
  * 정방향 -> (암묵적)reverse_iterator 
  * reverse_iterator.base() -> 정방향
  
### Section 04 : 삽입 반복자
순차열에 원소를 삽입할 수 있게 반복자를 변환하는 반복자 어댑터.

모든 iterator는 기본적으로 덮어 쓰게 되어있는데, 삽입 반복자를 이용하면 삽입 모드로 동작한다.

  * inserter()  : insert_iterator 객체를 생성. insert를 이용에 삽입.
  * back_inserter() : back_insert_iterator 객체를 생성. push_back을 이용해 뒤쪽에 삽입.
  * front_inserter() : front_insert_iterator 객체를 생성. push_front를 이용해 앞쪽에 삽입.

사용
  * inserter() : 모든 컨테이너가 사용가능.
  * back_inserter() : vector, deque, list
  * front_inserter() : deque, list
  
### Section 05 : 입/출력 스트림 반복자
스트림과 연결된 반복자로 알고리즘이 스트림에 읽고 쓸 수 있게 하는 반복자 어댑터 입니다.
  * istream_iterator<T> : 입력 스트림과 연결된 반복자로 T 형식의 값을 스트림에서 읽을 수 있습니다.
  * ostream_iterator<T> : 출력 스트림과 연결된 반복자로 T 형식의 값을 스트림에 쓸 수 있습니다.
  
예제 copy, transform
```cpp
    vector<int> v;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    list<int> lt;
    transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plust<int>());
```

###Section 06 : 반복자 특성과 보조 함수
반복자의 종류 5가지 : 입력, 출력, 순방향, 양방향, 임의 접근 반복자.

이때 각 반복자가 자신만의 특징을 저장하는 템플릿 클래스를 iterator traits 라고 한다. 

advance(), distance() 함수로 임의 접근 반복자만 가지고 있는 연산의 특성을 다른 반복자도 가능하게 한다.
  * advance() : p반복자를 p += n 의 위치로 이동시킨다.
  * n = distance(p1, p2): n은 p2-p1이다. 

STL의 iterator가 제공하는 다섯가지 반복자 특성
```cpp
template<class Iter>
struct iterator_traits
{
    typedef typename Iter::iterator_category iterator_category;
    typedef typename Iter::value_type value_type;
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
}
```
iterator_category의 5가지 태그
```cpp
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag:public input_iterator_tag{};
    struct bidirectional_iterator_tag:public forward_iterator_tag{};
    struct random_access_iterator_tag:public bidirectional_iterator_tag{};
```

STL과 같은 반복자 동작에 효율적인 알고리즘을 작성하는 법(p506~508 예제 너무 좋음)
  1. iterator_traits 의 특성을 포함하는 클래스를 작성.
  2. Iter형식을 받고 파라메터로 iterator_category를 받아서 특성에 따른 동작을 하는 함수들을 구현
  3. category에 따라서 overload 된 함수들을 불러주는 template기반 함수를 구현. 사용자는 이 함수만 사용하도록.


