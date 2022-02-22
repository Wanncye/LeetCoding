#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
//priority_queue<Type, Container, Functional>
class Solution {
public:
    class My_Compare{
    public:
        bool operator()(pair<int,int>& left, pair<int,int>&right){
            return left.second>right.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, My_Compare> pq;
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        for(unordered_map<int, int>::iterator it=freq.begin(); it!=freq.end(); it++){
            pq.push(*it);
            if(pq.size()>k) pq.pop();
        }
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(pq.top().first);
            pq.pop();
        }
        for(int i : result){
            cout<<i<<" ";
        }
        cout<<endl;
        return result;
    }
    
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution obj;
    obj.topKFrequent(nums, 2);
}