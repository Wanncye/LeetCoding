/*
* 关键代码：构造函数是私有的，不能通过赋值运算，拷贝构造等方式实例化对象。
*/
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton_unsafe
{
public:
    static Singleton_unsafe* getInstance(){
        if(m_pSingleton_unsafe == NULL)
        {
            m_pSingleton_unsafe = new Singleton_unsafe();
            cout<<"unsafe singleton construct successfully!"<<endl;
        }
        return m_pSingleton_unsafe;
    };
    ~Singleton_unsafe(){}

private:
    Singleton_unsafe(){}                                        //构造函数私有
    Singleton_unsafe(const Singleton_unsafe& obj) = delete;            //明确拒绝
    Singleton_unsafe& operator=(const Singleton_unsafe& obj) = delete; //明确拒绝

    static Singleton_unsafe* m_pSingleton_unsafe;
};
//静态成员变量必须类外初始化
Singleton_unsafe* Singleton_unsafe::m_pSingleton_unsafe = NULL;

// mutex mt;
// class Singleton_safe
// {
// public:
//     static Singleton_safe* getInstance(){
//         if(m_pSingleton_safe == NULL)
//         {
//             mt.lock();
//             if(m_pSingleton_safe == NULL)
//             {
//                 m_pSingleton_safe = new Singleton_safe();
//                 cout<<"safe singleton construct successfully!"<<endl;
//             }
//             mt.unlock();
//         }
//         return m_pSingleton_safe;
//     };
// private:
//     Singleton_safe(){}                                    //构造函数私有
//     Singleton_safe(const Singleton_safe&) = delete;            //明确拒绝
//     Singleton_safe& operator=(const Singleton_safe&) = delete; //明确拒绝

//     static Singleton_safe* m_pSingleton_safe;

// };
// Singleton_safe* Singleton_safe::m_pSingleton_safe = NULL;

//饿汉式：线程安全，注意一定要在合适的地方去delete它
class Singleton_hungry
{
public:
    static Singleton_hungry* getInstance(){
        return m_pSingleton;
    };
private:
    Singleton_hungry(){}                                    //构造函数私有
    Singleton_hungry(const Singleton_hungry&) = delete;            //明确拒绝
    Singleton_hungry& operator=(const Singleton_hungry&) = delete; //明确拒绝

    static Singleton_hungry* m_pSingleton;
};
//船创建时就实例化
Singleton_hungry* Singleton_hungry::m_pSingleton = new Singleton_hungry();

int main()
{
    Singleton_unsafe* unsafeObject = Singleton_unsafe::getInstance();
    Singleton_hungry* hungryObject = Singleton_hungry::getInstance();
    // Singleton_safe* safeObject = Singleton_safe::getInstance();
    return 0;
}
