//
// Created by yoonsung-mac on 03/07/2017.
//

#include <iostream>
#include <functional>
using namespace std;

bool Pred_less(int a, int b){
    return a<b;
}
struct Less{
    bool operator()(int a, int b){
        return a <b;
    }
};

typedef less<int> Less2;
void ex3_8(){
    //그럼 함수객체가 빠르다고 했으니까 이런 연산은 functional 잘 쓰면 되겠당
    cout << plus<int>()(20, 10)<< endl;
    cout << minus<int>()(20, 10)<< endl;
}
void ex3_7(){
    // less, greater는 템플릿 클래스 이므로 임시객체를 이렇게 부름
    cout << less<int>()(10, 20)<< endl;
    cout << less<int>()(20, 10)<< endl;
    cout << greater<int>()(10, 20)<< endl;
    cout << greater<int>()(20, 10)<< endl;
}
void ex3_6(){
    Less2 l;
    cout << l(10, 20) << endl;
    cout << l(20, 10) << endl;
    cout << l.operator()(10, 20) << endl; //explicit

    cout << endl;
    cout << Less2()(10, 20) << endl; //임시 객체로 implicit call
    cout << Less2()(20, 10) << endl; //임시 객체로 implicit call
    cout << Less2().operator()(10, 20 ) << endl; //explicit

}
void ex3_5(){
    Less l;

    cout << Pred_less(10, 20) << endl;
    cout << Pred_less(20, 10) << endl;
    cout << endl;
    cout << l(10, 20) << endl;
    cout << l(20, 10) << endl;
    cout << Less()(10, 20) << endl; //임시 객체로 implicit call
    cout << Less()(20, 10) << endl; //임시 객체로 implicit call
    cout << endl;
    cout << l.operator()(10, 20) << endl; //explicit
    cout << Less().operator()(10, 20 ) << endl; //explicit
}
int main(){
    ex3_8();
    return 0;
}