#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t mt;
int ret = pthread_mutex_init(&mt, NULL);

class SingletonSafe{
public:
    int num;
    static SingletonSafe* getInstance(){
        pthread_mutex_lock(&mt);
        if(instance == NULL){
            instance = new SingletonSafe(2);
            cout << "空，实例化" << endl;
        }
        pthread_mutex_unlock(&mt);
        return instance;
    } 

private:
    static SingletonSafe* instance;
    SingletonSafe() = delete;
    SingletonSafe(int n):num(n){};
    SingletonSafe(SingletonSafe& obj) = delete;
    SingletonSafe(SingletonSafe&& obj) = delete;
};
SingletonSafe* SingletonSafe::instance = NULL;


template<class T>
class TemplateSingleton{
public:
    static T* GetInstance(){
        static T p;
        return &p;
    }
};

class A{
public:
    int a;
};


int main(){
    SingletonSafe* ptr1 = SingletonSafe::getInstance();
    SingletonSafe* ptr2 = SingletonSafe::getInstance();
    cout << ptr1->num << endl;
    cout << ptr2->num << endl;
    A* intP = TemplateSingleton<A>::GetInstance();
    intP->a = 3;
    cout << intP->a << endl;
    return 0;
}