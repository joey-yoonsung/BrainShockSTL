//
// Created by yoonsung-mac on 03/07/2017.
//

#include <iostream>
using namespace std;

void Print(){
    cout << "전역함수" << endl;
}
/**
 * Functor의 장점
 * 함수처럼 동작하는 객체 이므로 다른 멤버 변수와 멤버 함수를 가질 수 있고 일반 함수에서 하지 못하는 지원을 받을 수 있다
 * 함수객체의 서명이 같더라도 객체 타입이 다르면 다른 타입으로 인식
 * 속도도 일반 함수보다 함수 객체가 빠르다
 * 함수의 주소를 전달해서 콜백하는 경우 이 함수 포인터는 인라인 될 수 없지만(함수 포인터는 함수가 있어야 하므로 함수의 복사본 함수를 만든다)
 * 함수객체는 인라인 될 수 있고 , 컴파일러가 쉽게 최적화 할 수 있다  //TODO : 어떻게 최적화 하는데? 인라인과 최적화가 뭐야?
 */
struct Functor{
    void operator()(){
        // 객체가 함수처럼 동작하려면 () 연산자를 정의해야한다
        cout << "함수 객체" << endl;
    }
    void operator()(int a, int b){
        cout << "함수 객체 : " << (a+b)<< endl;
    }
};

class Adder{
    int total;
public :
    explicit Adder(int n=0):total(n){}
    int operator()(int n){
        return total+=n;
    }
};

struct Functor1{
    void operator()(int n){
        cout << n << " ";
    }
};
struct Functor2{
    void operator()(int n){
        cout << n*n << " ";
    }
};
struct Functor3{
    void operator()(int n){
        cout << "정수 : " << n << endl;
    }
};

void ex3_3(){
    Adder add(0);
    cout<< add(10)<< endl;
    cout<< add(20)<< endl;
    cout<< add(30)<< endl;
}

void ex3_4(){
    int arr[5] = {10, 20, 30, 40, 50};

    //for_each 는 템플릿을 이용해서 사용자 정의 타입 까지 받을 수 있음
    for_each(arr, arr+5, Functor1());
    cout<<endl<<endl;
    for_each(arr, arr+5, Functor2());
    cout<<endl<<endl;
    for_each(arr, arr+5, Functor3());
}
void ex3_2(){
    Functor functor;

    functor(10, 20); //functor.operator()(10,20)

}
void ex3_1(){
    Functor functor;

    Print();
    functor();

}
int main(){
    ex3_4();
    return 0;
}