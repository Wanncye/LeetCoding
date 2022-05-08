#include<iostream>
using namespace std;

class Base
{
	public:
		virtual void f() {
			cout << "Base: f" << endl;
		}
		virtual void g() {
			cout << "Base: g" << endl;
		}
		virtual void h() {
			cout << "Base: h" << endl;
		}
};

typedef void(*Fun)(void);

int main()
{
	Base b;
	Fun pFun = NULL;
	
	cout << "虚函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表——第一个函数地址：" << (int*)*(int*)(&b) << endl; 

	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();                      // Base:f
	
	(Fun)*((int*)*(int*)(&b)+0); // Base::f()

	(Fun)*((int*)*(int*)(&b)+1); // Base::g()

	(Fun)*((int*)*(int*)(&b)+2); // Base::h()
}