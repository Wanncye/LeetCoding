#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

class MyQueue{
public:
    deque<int> dq;
    //出队列，如果要出队的元素的值等去双端队列的front，则出队；
    //其余不做操作
    void pop(int i){
        if(!dq.empty() && i==dq.front()){
            dq.pop_front();
        }
    }
    //保证双端队列排序为由大到小
    void push(int i){
        while(!dq.empty() && i>dq.back()){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //返回双端队列front
    int top(){
        return dq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue mq;
        vector<int> result;
        for(int i=0; i<k; i++){
            mq.push(nums[i]);
        }
        result.push_back(mq.top());
        for(int i=k; i<nums.size(); i++){
            mq.pop(nums[i-k]);
            mq.push(nums[i]);
            result.push_back(mq.top());
        }
        return result;
    }

};

int main(){
    vector<int> a={1,3,1,2,0,5};
    Solution obj;
    a = obj.maxSlidingWindow(a,3);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
}