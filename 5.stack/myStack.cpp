#include<iostream>
#include<queue>
using namespace std;
class MyStack {
public:
    queue<int> que1;
    queue<int> que2;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        que1.push(x);
        size++;
    }
    
    int pop() {
        for(int i=0; i<size-1; i++){
            int tmp = que1.front();
            que2.push(tmp);
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2;
        que2 = queue<int>();
        size--;
        return result;
    }
    
    int top() {
        int result = this->pop();
        this->push(result);
        return result;
    }
    
    bool empty() {
        if(size==0) return true;
        else return false;
    }
};

int main(){
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->top(); // 返回 2
    obj->pop(); // 返回 2
    obj->empty(); // 返回 False
}