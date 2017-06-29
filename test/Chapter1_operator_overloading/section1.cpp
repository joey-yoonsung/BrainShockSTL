//
// Created by yoonsung-mac on 28/06/2017.
//

#include <iostream>
using namespace std;
class Point {

    int x;
    int y;
public:
    Point(int _x=0, int _y=0):x(_x),y(_y){}
    Point operator+(Point& arg){ cout<< "operator+() call "<< endl;
        Point pt;
        pt.x=this->x + arg.x;
        pt.y=this->y + arg.y;
        return pt;
    }
    const Point& operator++(){
        ++x;
        ++y;
        return *this;
    }

    const Point operator++(int){
        Point pt(x, y);
        ++x;
        ++y;
        return pt; //연산 전의 값을 리턴
    }
    const Point& operator--(){
        cout << "member operator -- called"<< endl;
        --x;
        --y;
        return *this;
    }

    const Point operator--(int){
        Point pt(x, y);
        --x;
        --y;
        return pt; //연산 전의 값을 리턴
    }
    bool operator==(const Point& arg)const{
        return x==arg.x && y==arg.y ? true : false;
    }
    bool operator!=(const Point& arg)const{
        return !(*this==arg);
    }
    void print() const{cout<< x<< ", "<< y<< ", "<< endl;}
    friend const Point operator-(const Point& argL, const Point& argR); //friend 를 이용하면 global operator 정의할 때, private member에 접근이 가능하다.
};
const Point operator-(const Point& argL, const Point& argR){
    return Point(argL.x - argR.x, argL.y - argR.y);
}
//const Point& operator--(Point &argL){
//    cout << "global operator -- called"<< endl;
//    --argL.x;
//    --argL.y;
//    return argL;
//}

//*  여기까지 Section 5 : 전역 함수를 이용한 연산자 오버로딩
void ex1_13() {
    Point p1(2, 3), p2(5, 5);

    Point p3 = p1 - p2;
    p3.print();

    //* TODO : global operator 와 member operator 모두 선언 되어있으면 ambiguous하다고 빌드에러
    --p1;
    p1.print();
}
//*  여기까지 Section 4 : 이항 연산자 오버로딩
void ex1_11(){
    Point p1(2, 3), p2(2, 5), p3(2, 3);

    if(p1!=p2)
        cout<< "p1 != p2" << endl;
    if(p1!=p3)
        cout<< "p1 != p3" << endl;

}
void ex1_10(){
    Point p1(2, 3), p2(2, 5), p3(2, 3);

    if(p1==p2)
        cout<< "p1 == p2" << endl;
    if(p1==p3)
        cout<< "p1 == p3" << endl;

}
//*  여기까지 Section 3 : 단항 연산자 오버로딩
void ex1_9(){
    Point p1(2, 3), p2(2, 5);
    Point result = --p1;
    p1.print();
    result.print();

    result = p2--;
    p2.print();
    result.print();
}

void ex1_8(){
    Point p1(2, 3), p2(2, 5);
    Point result = ++p1;
    p1.print();
    result.print();

    result = p2++;
    p2.print();
    result.print();
}


//* 여기까지 Section 2
void ex1_6(){
    Point p1(2, 3), p2(2, 5);
    Point p3 = p1+p2;
    p3.print();
    p3 = p1.operator+(p3);
    p3.print();
}
void ex1_3(){
    Point p1(2, 3), p2(2, 5);
    p1+p2;//p1.operator+(p2);
//    p1*p2;//p1.operator*(p2);
//    p1=p2;//p1.operator=(p2); 할당
//    p1==p2;//p1.operator==(p2);
//    p1+=p2;//p1.oeprator+=(p2);

}
void ex1_2(){
    Point p1(2, 3), p2(2, 5);
    p1.print();
    p2.print();
//    p1+p2;//compile Error
}
void ex1_1(){
    int n1=10, n2=20;

    cout<< n1+n2<< endl;
}
int main(){
    ex1_13();
}
