#include<iostream>
using namespace std;

class A
{
private:
    int x;
    long long xy;
    int y;

public:
    virtual void f1(void)
    {
        cout<<"A::f1"<<endl;
    }
    virtual void f2(void)
    {
        cout<<"A::f2"<<endl;
    }
};
class B
{
private:
    int x;
    long long xy;
    int y;

public:
    virtual void f1(void)
    {
        cout<<"B::f1"<<endl;
    }
    virtual void f2(void)
    {
        cout<<"B::f2"<<endl;
    }
};
class C
{
private:
    int x;
    long long xy;
    int y;

public:
    virtual void f1(void)
    {
        cout<<"C::f1"<<endl;
    }
    virtual void f2(void)
    {
        cout<<"C::f2"<<endl;
    }
};
class D
{
private:
    int x;
    long long xy;
    int y;

public:
    virtual void f1(void)
    {
        cout<<"D::f1"<<endl;
    }
    virtual void f2(void)
    {
        cout<<"D::f2"<<endl;
    }
};

void normal_func1(){};
void normal_func2(){};
void normal_func3(){};


int global_int = 0;
int global_uni;

int main()
{
    static int static_int = 0;

    cout<<"(long*)normal_func1   "<<(long*)(normal_func1)<<endl;
    cout<<"(long*)normal_func2   "<<(long*)(normal_func2)<<endl;
    cout<<"(long*)normal_func3   "<<(long*)(normal_func3)<<endl;

    cout<<"(long*)(&global_int)  "<<(long*)(&global_int)<<endl;
    cout<<"(long*)(&static_int)  "<<(long*)(&static_int)<<endl;
    cout<<"(long*)(&global_uni)  "<<(long*)(&global_uni)<<endl;
    cout<<"global_uni            "<<         global_uni<<endl;

    B virtual_instance1;
    A virtual_instance0;
    D virtual_instance3;

    cout<<endl<<endl<<"虚函数相关： "<<endl<<endl;

    cout << "(long*)(&virtual_instance0)             " << (long*)(&virtual_instance0) << endl;
    cout << "(long*)(&virtual_instance1)             " << (long*)(&virtual_instance1) << endl;
    cout << "(long*)(&virtual_instance3)             " << (long*)(&virtual_instance3) << endl;
    cout << "(long*)*(long*)(&virtual_instance0)     " << (long*)*(long*)(&virtual_instance0) << endl;
    cout << "(long*)*(long*)(&virtual_instance1)     " << (long*)*(long*)(&virtual_instance1) << endl;
    cout << "(long*)*(long*)(&virtual_instance3)     " << (long*)*(long*)(&virtual_instance3) << endl;
    cout << "*(long*)*(long*)(&virtual_instance0)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance0) << endl;
    cout << "*(long*)*(long*)(&virtual_instance1)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance1) << endl;
    cout << "*(long*)*(long*)(&virtual_instance3)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance3) << endl;

    A virtual_instance00;
    int x = 0;
    cin>>x;
    if(x)
    {
        C *pC = new C();
//        C *pC = (C*)new D();
    }
    cout << "(long*)(&virtual_instance00)            " << (long*)(&virtual_instance00) << endl;
    cout << "(long*)*(long*)(&virtual_instance00)    " << (long*)*(long*)(&virtual_instance00) << endl;
    cout << "*(long*)*(long*)(&virtual_instance00)   " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance00) << endl;

    cout << "(long*)(&virtual_instance0)             " << (long*)(&virtual_instance0) << endl;
    cout << "(long*)(&virtual_instance1)             " << (long*)(&virtual_instance1) << endl;
    cout << "(long*)(&virtual_instance3)             " << (long*)(&virtual_instance3) << endl;
    cout << "(long*)*(long*)(&virtual_instance0)     " << (long*)*(long*)(&virtual_instance0) << endl;
    cout << "(long*)*(long*)(&virtual_instance1)     " << (long*)*(long*)(&virtual_instance1) << endl;
    cout << "(long*)*(long*)(&virtual_instance3)     " << (long*)*(long*)(&virtual_instance3) << endl;
    cout << "*(long*)*(long*)(&virtual_instance0)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance0) << endl;
    cout << "*(long*)*(long*)(&virtual_instance1)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance1) << endl;
    cout << "*(long*)*(long*)(&virtual_instance3)    " << hex<<"0x"<<*(long*)*(long*)(&virtual_instance3) << endl;

    typedef void(*Fun)(void);
    Fun pFunc1, pFunc2, pFunc3;
    pFunc1 = (Fun)*((long*)*(long*)(&virtual_instance0));
    pFunc1();
    pFunc2 = (Fun)*((long*)*(long*)(&virtual_instance1) + 1);
    pFunc2();
    pFunc3 = (Fun)*((long*)*(long*)(&virtual_instance3) + 1);
    pFunc3();
    return 0;
}
