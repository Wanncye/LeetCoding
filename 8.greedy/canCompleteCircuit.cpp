#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum=0;
        int totalSum=0;
        int start=0;
        for(int i=0; i<gas.size(); i++){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum<0){
                start = i+1;
                curSum=0;
            }
        }
        if(totalSum<0) return -1;
        return start;
    }
};

int main(){
    vector<int> g = {1,2,3,4,5};
    vector<int> c = {3,4,5,1,2};
    Solution stl;
    cout<<stl.canCompleteCircuit(g, c)<<endl;
}