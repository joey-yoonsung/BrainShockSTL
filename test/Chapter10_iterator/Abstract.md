# 10장 반복자 (Iterator)

## 다시 볼 부분

## 요약
### Section 01 : 반복자의 종류
포인터를 추상화한 클래스 객체 포인터가 하지 못하는 더 많은 동작을 수행할 수 있다.

순차열(sequence)와 구간(range)개념.

[begin, end) 순차 구간으로 정의
  * 입력 반복자(input iterator): 전방향 읽기(istream)
  * 출력 반복자(output iterator): 전방향 쓰기(ostream)
  * 순방향 반복자(forward iterator): 전방향 읽기, 쓰기
  * 양방향 반복자(bidirectional iterator): 양방향 읽기, 쓰기(list, set, multiset, map, multimap)
  * 임의 접근 반복자(random access iterator): 랜덤 읽기 쓰기(vector, deque)

