# 11장 container adapter

## 다시 볼 부분

## 요약
### Section 01 : stack container
LIFO 방식의 컨테이너를 구현한 템플릿 클래스. 사용하는 기본 컨테이너는 deque 컨테이너.

해당 인터페이스를 지원하는 vector, deque, list를 사용할 수 있음.
 
해당 인터페이스를 한다면 사용자 컨테이너를 사용할 수도 있다.

### Section 02 : queue container
FIFO 방식의 컨테이너를 구현한 템플릿 클래스. 기본 컨테이너는 deque 컨테이너.

차이점은 pop_front(), front()

### Section 03 : priority_queue 컨테이너
우선순위 queue를 구현한 템플릿 클래스. 기본 컨테이너는 vector.

내부적으로 stl의 힙 알고리즘인 make_heap(), push_heap(), pop_heap()을 사용하므로 priority_queue의 container 템플릿 인자로 받는 컨테이너는 임의 접근 반복자를 제공하는 컨테이너여야 한다.

인터페이스는 stack과 비슷함. push, top, pop.
```cpp
    priority_queue<int> pql;               //int 값 자체로 priority_queue, 기본 vector container template, 정렬기준 less 
    priority_queue<int, deque<int>, greater<int>> pql2;  // vector가 아니라 deque container template, greater의 비교조건자 를 이용해서 int값의 priority_queue
```
