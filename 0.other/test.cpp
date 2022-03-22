#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

class cmp{
public:
    bool operator()(int a, int b){
        return a<b;
    }
};

int main(){
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(7);
    while(pq.empty()!=true){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}