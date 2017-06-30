//
// Created by yoonsung-mac on 29/06/2017.
//

#include <iostream>
using namespace std;
class Point {

    int x;
    int y;
public:
    Point(int _x=0, int _y=0):x(_x),y(_y){}
    void print() const{cout<< x<< ", "<< y<< ", "<< endl;}
};
class PointPtr{
    Point *ptr;
public:
    PointPtr(Point *p):ptr(p){}
    ~PointPtr(){delete ptr;}

    Point* operator->() const{
        return ptr;
    }

    Point& operator*() const{
        return *ptr;
    }
};
void ex1_22(){
    Point* p1 = new Point(2, 3);
    PointPtr p2 = new Point(5, 5);

    p1->print(); // p1.operator->()->Print() 호출
    p2->print(); // p2.operator->()->Print() 호출
    cout << endl;

    (*p1).print(); //(*p1).print()
    (*p2).print(); //p2.operator*().print()

    delete p1;
}
void ex1_21(){
    PointPtr p1 = new Point(2, 3);
    PointPtr p2 = new Point(5, 5);

    p1->print(); // p1.operator->()->Print() 호출
    p2->print(); // p2.operator->()->Print() 호출
    // p1, p2 의 destructor 에 의해서 자동으로 소멸

}

void ex1_20(){
    PointPtr p1 = new Point(2, 3);
    PointPtr p2 = new Point(5, 5);

//    p1->print(); //아직 서비스 사용 못함
//    p2->print(); //아직 서비스 사용 못함
    // p1, p2 의 destructor 에 의해서 자동으로 소멸

}

void ex1_19(){
    Point *p1 = new Point(2, 3);
    Point *p2 = new Point(5, 5);

    p1->print();
    p2->print();

    delete p1;
    delete p2;

}

class FuncObject //c++ 에서 struct ,  class 둘다 같음. 차이는 기본 필드속성이 public / private
{
    int arr[4]={1,2,3,4};
public:
    FuncObject(){
    }
    void operator()(int arg)const{
        cout<< "정수 : " << arg << endl;
    }
    void operator()(int arg1, int arg2)const{
        cout<< "정수 : " << arg1 << ", "<< arg2<< endl;
    }
    void operator()(int arg1, int arg2, int arg3)const{
        cout<< "정수 : " << arg1 << ", "<< arg2 << ", "<< arg3<< endl;
    }

    int operator[](int idx)const{
        cout<< "called const : ";
        if(idx < 4){
            return arr[idx];
        }else{
            throw "there is no value of idx";
        }

    }
    //&가 안붙으면 안불림
    int& operator[](int idx){
        cout<< "called not const : ";
        if(idx < 4){
            return arr[idx];
        }else{
            throw "there is no value of idx";
        }

    }
};

void Print1(int arg){
    cout<< "정수 : " << arg << endl;
}
void ex1_18(){
    FuncObject func;

    for(int i=0; i<4 ; i++){
        cout << func[i] << endl;
    }

    const FuncObject& func2=func;

    for(int i=0; i<4 ; i++){
        cout << func2[i] << endl;
    }

    func[0]=100;
    for(int i=0; i<4 ; i++){
        cout << func[i] << endl;
    }

//    func2[0]=100; //error
//    for(int i=0; i<4 ; i++){
//        cout << func2[i] << endl;
//    }
}
void ex1_16(){
    FuncObject func;

    for(int i=0; i<5 ; i++){
        cout << func[i] << endl;
    }
}
void ex1_15(){
    FuncObject print;
    //객체 생성 후 암시적 호출
    print(10);
    print(10, 20);
    print(10, 20, 30);
    cout << endl;

    //객체 생성후 명시적 호출
    print.operator()(10);
    print.operator()(10, 20);
    print.operator()(10, 20, 30);
    cout << endl;

    //임시 객체 암시적 호출
    FuncObject()(10);
    FuncObject()(10, 20);
    FuncObject()(10, 20, 30);
    cout << endl;

    //임시 객체 명시적 호출
    FuncObject().operator()(10);
    FuncObject().operator()(10, 20);
    FuncObject().operator()(10, 20, 30);
    cout << endl;

}
void ex1_14(){
    void (*Print2)(int) = Print1;
    FuncObject Print3;

    Print1(10);
    Print2(10);
    Print3(10);
}
int main(){
    ex1_22();
    return 0;
}