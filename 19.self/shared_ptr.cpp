#include<iostream>

using namespace std;

template<class T>
class Shared{
public:
    T* ptr;
    int count=0;

    Shared(T* p)
        :ptr(p){
        count++;
        cout << "普通构造函数" << endl;
    }
    Shared(Shared& p){
        ptr = p.ptr;
        count = p.count;
        count++;
        cout << "拷贝构造函数" << endl;
    }
    void operator= (Shared& p){
        ptr = p.ptr;
        count  = p.count;
        count++;
        cout << "赋值构造函数" << endl;
    }
    ~Shared(){
        if(count == 1){
            delete ptr;
            cout << "count=1，析构，delete" << endl;
        }else{
            cout << "count!=1，当前引用计数为：" << count << endl;
        }
    }
    T* get(){return ptr;}
    T operator* (){return *ptr;}
    T* operator-> (){return ptr;}
    int use_count(){return count;}
};

class Foo{
public:
    int a;
};

int main(){
    Shared<Foo> sp1(new Foo());
    cout << sp1.use_count() << endl;
    Shared<Foo> sp2(new Foo());
    cout << sp2.use_count() << endl;
    Shared<Foo> sp3 = sp1;
    cout << sp1.use_count() << endl;
    cout << sp2.use_count() << endl;
    cout << sp3.use_count() << endl;

}