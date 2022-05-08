#include<iostream>
using namespace std;

int main(){
    // auto_ptr
    auto_ptr<string> p1(new string("我是爱南开的"));
    auto_ptr<string> p2;
    p2 = p1;
    cout<<*p2<<endl;
    // cout<<*p1<<endl; //报错～野指针

    // unique_ptr
    unique_ptr<string> p3(new string("我也是爱南开的"));
    unique_ptr<string> p4;
    // p4 = p3;
    p4 = move(p3);
    // cout<<*p3<<endl;
    cout<<*p4<<endl;

}