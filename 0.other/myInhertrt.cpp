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

    // int a = 1;
    A& 
};

class B : public A{
public:
    virtual void method(){
        cout<<"in class B"<<endl;
    }
    void other(){
        cout<<"in class B, other fun"<<endl;
    }
};

int main(){
    A *p = new A();
    // // p->a = 2;
    // B *b = new B();
    A p;
    A c;
    // p = b;
    // obj.method();
    // obj.other();
}