//
// Created by yoonsung-mac on 03/07/2017.
//

#include <iostream>
using namespace std;
namespace A{
    void Print(int n){
        cout << "namespace A global function : "<< n << endl;
    }
}
class Point{
    int x, y;
public:
    static void Print(int n){
        cout << "member function: "<< n << endl;
    }

    explicit Point(int _x=0, int _y=0):x(_x),y(_y){}
    void Print() const{cout << x << ", "<< y<< endl;}
    void PrintInt(int n){cout << "int : "<< n << endl;}
};
void Print(int n){
    cout << "static function : "<< n << endl;
}
void TempFunc(int n){
    cout << "Temp func : " << n  << endl;
}
void TempFunc2(int a, int b){
    cout << (a+b) << endl;
}


/**
 * 함수 호출 규약
 * 함수 호출 규약은 함수 호출 시 전달되는 인자의 순서나 함수가 종료될 때 함수의 스택을 정리하는 시점을 약속한것
 * 규약 종류 : stdcall, cdecl, thiscall, fastcall
 * 즉 규약 종류마다 함수가 호출/정리되는 방법이 다르다. 같은 Function Pointer로 활용할 수 있는 것은 같은 규약 안에서만
 *
 * 정적함수 포인터는 cdecl 을 사용
 * 멤버함수 포인터는 thiscall 을 사용
 * */
void ex2_5(){
    //멤버함수 포인터
    Point pt(2,3);
    Point* p=&pt;
    void (*pf3)() const;

    void (Point::*pf1)() const;
    pf1 = &Point::Print; //static Print(int n) 이 있으면 캐스팅 없이 못씀

    void (Point::*pf2)(int);
    pf2 = &Point::PrintInt;

    pt.Print();
    pt.PrintInt(10);
    cout <<endl;

    (pt.*pf1)();
    (pt.*pf2)(10);
    cout << endl;

    (p->*pf1)();
    (p->*pf2)(10);

    cout << &pt << endl;
}
void ex2_4(){
    //적정함수 포인터
    void (*pf)(int);

    Print(10);
    A::Print(10);
    Point::Print(10);
    cout<< endl;

    pf= Print;
    pf(10);
    pf = A::Print;      // there is no code recommendation and auto-complete 'Print' function after "A::" is typed.
    pf(10);
    pf = Point::Print;  //// there is no code recommendation and auto-complete 'Print' function after "Point::" is typed.
    pf(10);
};
void ex2_3(){
    //함수를 콜하는 세가지 방법
    Point pt;
    Point *p =&pt;

    Print(1);
    pt.Print(1);
    p->Print(1);
}
void ex2_2(){
    void (*pf)(int); //void function(int n) 의 구조를 함수 signature 구조를 갖는 함수의 주소를 가리킬 포인터

    /**
     * 함수포인터를 이런식으로 정의하게 한 것은 (어자피 할당 될 때는 주소만 가리키니까 사실 함수의 signature가 어떻든 크게 상관 없지만)
     * 컴파일 타임에 type-safety를 위해서 일거라는 reasonable 한 추측!
     *
     */
    pf = Print;
    Print(10);
    pf(10);
    (*pf)(10);


    cout<< endl;
    cout << &Print << endl; //TODO : 왜 주소가 안나오지?
    cout << &pf << endl;
    cout << (*pf) << endl;

    pf = TempFunc;
    pf(5);

    cout<< endl;
    cout << &TempFunc << endl;
    cout << &pf << endl;
    cout << pf << endl;

//    pf = TempFunc2; //compile error : incomparable number of arguments
}
void ex2_1(){
    int n=10;
    int *pn = &n;
    cout<< n << endl;
    cout << pn << " : "<< *pn << endl;

}
int main(){
    ex2_5();
    return 0;
}