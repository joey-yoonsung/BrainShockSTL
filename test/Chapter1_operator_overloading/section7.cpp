//
// Created by yoonsung-mac on 30/06/2017.
//
#include <cmath>
#include <iostream>
using namespace std;

class A{

};
class B{
public :
    B(){cout<< "B() constructor" << endl;}
    B(A& _a){ cout<< "B(A _a) constructor" << endl;}
    B(int n){ cout<< "B(int n) constructor" << endl;}
    B(double d){ cout<< "B(double d) constructor" << endl;}

    operator A(){
        cout<< "operator A() call" << endl;
        return A();
    }
    operator int(){ // conversion function cannot have any parameters
        cout<< "operator int() call" << endl;
        return 10;
    }
    operator double(){ // conversion function cannot have any parameters
        cout<< "operator double() call" << endl;
        return 5.5;
    }
};
class Point {

    int x;
    int y;
public:
    explicit Point(int _x=0, int _y=0):x(_x),y(_y){}
    void print() const{cout<< x<< ", "<< y<< ", "<< endl;}
    operator double() const{
        return sqrt(pow(x, 2.0)+ pow(y, 2.0)); // 두변이 직각을 이루는 대각선의 거리
    }
};

void ex1_27(){
    Point pt(3, 4);

    double d=pt;
    cout << d << " must be 5 " << endl;
}
void ex1_26(){
    A a;
    int n=10;
    double d = 5.5;

    B b;
    a=b;
    n=b;
    d=b;

    cout << n <<","<< d << endl;

    a=b.operator A();
    n=b.operator int();
    d=b.operator double();

    cout << n <<","<< d << endl;

}

void ex1_25(){
    Point pt;
    pt.print();

//    pt=10; //Point(10,0) implicit call : compile error
    pt=Point(10,0);
    pt.print();
}
void ex1_24(){
    Point pt;
    pt.print();

//    pt=10; //Point(10,0) implicit call
    pt.print();
}
void ex1_23(){
    A a;
    int n=10;
    double d = 5.5;

    B b;
    b = a;
    b = n;
    b = d;
}
int main(){
    ex1_27();
    return 0;
}