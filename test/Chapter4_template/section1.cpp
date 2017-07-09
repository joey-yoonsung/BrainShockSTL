//
// Created by yoonsung-mac on 03/07/2017.
//

#include <iostream>
using namespace std;

//함수 템플릿 : 여러 함수를 만들어 내는 함수의 틀
//클래스 템플릿 : 여러 클래스를 만들어내는 클래스의 틀
void Print(int a, int b){
    cout << a << ", " << b << endl;
}
void Print(double a, double b){
    cout << a << ", " << b << endl;
}
void Print(const char* a, const char* b){
    cout << a << ", " << b << endl;
}
template<typename T>
void PrintTemplate(T a, T b){
    cout << a << ", "<< b << endl;
}
void ex4_3() {
    //함수템플릿 : client 가 어떤 타입을 사용해서 함수를 호출할 지 미리 알지 못할 때
    PrintTemplate(10, 20);
    PrintTemplate(0.123, 1.123);
    PrintTemplate("ABC", "abcde");
}
void ex4_2(){
    //함수 overloading
    Print(10, 20);
    Print(0.123, 1.123);
    Print("ABC", "abcde");
}

int main(){
    ex4_2();
    return 0;
}