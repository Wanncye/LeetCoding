#include<iostream>
using namespace std;

class A{
public:
    virtual void method(){
    // void method(){
        cout<<"in class A"<<endl;
    }
    void other(){
        cout<<"in class A, other fun"<<endl;
    }
};

class B : public A{
public:
    void method(){
        cout<<"in class B"<<endl;
    }
    void other(){
        cout<<"in class B, other fun"<<endl;
    }
};

int main(){
    A * obj = new B();
    obj->method();
    obj->other();
}