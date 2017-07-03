//
// Created by yoonsung-mac on 03/07/2017.
//

#include <iostream>
using namespace std;

//Client Server callback
void For_each(int* begin, int* end, void (*pf)(int)/* void function(int) 타입의 함수 포인터를 받겠다!*/){
    while(begin != end){
        pf(*begin++); //  클라이언트가 넘겨준 콜백함수 호출
    }
}
void Print1(int n){
    cout << n << ' ';
}
void Print2(int n){
    cout << n*n << " ";
}
void Print3(int n){
    cout << "정수 : "<< n << endl;
}
void ex2_9(){
    //std::for_each 사용, ex2_8과 결과 같음

    int arr[5] = {10, 20, 30, 40, 50,};

    std::for_each(arr, arr+5, Print1); //Print1() 의 callback 함수 주소를 전달
    cout << endl << endl;
    std::for_each(arr, arr+5, Print2); //Print2() 의 callback 함수 주소를 전달
    cout << endl << endl;
    std::for_each(arr, arr+5, Print3); //Print3() 의 callback 함수 주소를 전달
    cout << endl << endl;

}
void ex2_8(){
    int arr[5] = {10, 20, 30, 40, 50,};

    For_each(arr, arr+5, Print1); //Print1() 의 callback 함수 주소를 전달
    cout << endl << endl;
    For_each(arr, arr+5, Print2); //Print2() 의 callback 함수 주소를 전달
    cout << endl << endl;
    For_each(arr, arr+5, Print3); //Print3() 의 callback 함수 주소를 전달
    cout << endl << endl;

}
int main(){
    ex2_9();
    return 0;
}