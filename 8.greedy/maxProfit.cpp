#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int result=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                result += nums[i+1]-nums[i];
            }
        }
        return result;
    }
};

int main(){
    vector<int> g = {7,6,4,3,1};
    Solution stl;
    cout<<stl.maxProfit(g)<<endl;
}