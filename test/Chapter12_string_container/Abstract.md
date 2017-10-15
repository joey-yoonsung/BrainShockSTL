# 12장 string container

## 다시 볼 부분

## 요약
### Section 01 : 주요 인터페이스와 특징
string은 vector 컨테이너와 비슷한 컨테이너. 시퀀스 컨테이너, 배열기반 컨테이너의 범주에 속함. c++은 string, wstring 제공.
  * string : char 형식을 다루기 위한 basic_string<char>의 typedef 형식
  * wstring : 유니코드문자(wchar_t) basic_string<wchar_t>
  
Java의 String은 선언 순간 그자체로 상수가 되는데, std::string은 그 자체로 char를 담은 배열이다.

append
  * +=, append, push_back() 모두 같다. append는 부분문자 하고싶으면.

assign
  * =, assign 모두 같다. assign은 부분문자 하고싶으면.

char array
  * c_str() - c style ('\0'을 포함) 문자열 반환
  * data() - '\0'를 포함하지 않는 순수 배열 반환.

compare
  * 부등식 비교, compare 모두 같다. 부분 문자 하고싶으면 compare.

copy
  * '\0' 없는 문자열 복사.
  
find
  * 찾은 위치를 반환. 없으면 npos를 반환(-1).
  * rfind 는 역방향 검색. 
  
insert
  * index로 삽입
  * iterator 위치로 삽입.
  
replace : insert와 사용 비슷

substr
  * substr(pos, n) : pos인덱스부터 n개
  * substr(pos, npos) : pos부터 마지막까지 
  
stream
  * cin >> string
  * getline(cin, string)
    * getline(cin, string, char) : 세번째 인자에 종료를 뜻하는 문자 지정.
  * cout << string
  
### Section 02 : 주요 멤버 함수 정리
시퀀스 컨테이너, 배열기반 컨테이너의 특성. vector처럼 메모리 공간을 reserve() 하고 사용할 수 있고 capacity로 할당된 공간을 혹인할 수 있다. reserve로 메모리 재할당으로 발생하는 비효율성을 줄이자.
