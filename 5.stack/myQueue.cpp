#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> stack1; 
    stack<int> tmp;
    int size;

    MyQueue() {
        size=0;
    }
    
    void push(int x) {
        stack1.push(x);
        size++;
    }
    //stack的pop方法不提供返回值！！！！！！！！！！！！！！！！！！！！！
    // ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    int pop() {
        while(!stack1.empty()){
            tmp.push(stack1.top());
            stack1.pop();
        }
        int result = tmp.top();
        tmp.pop();
        size--;
        while(!tmp.empty()){
            stack1.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    int peek() {
        while(!stack1.empty()){
            tmp.push(stack1.top());
            stack1.pop();
        }
        int result = tmp.top();
        while(!tmp.empty()){
            stack1.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
    
    bool empty() {
        if(size == 0) return true;
        else return false;
    }
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1); // queue is: [1]
    obj->push(2); // queue is: [1, 2] (leftmost is front of the queue)
    obj->peek(); // return 1
    obj->pop(); // return 1, queue is [2]
    obj->empty(); // return false
}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */