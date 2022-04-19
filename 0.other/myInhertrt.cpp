#include<iostream>
using namespace std;


class A{
public:
    virtual void method(){
        cout<<"in class A"<<endl;
    }
};

class B : public A{
public:
    B
    void method(){
        cout<<"in class B"<<endl;
    }
};

int main(){
    A * obj = new B();
    obj->method();
}