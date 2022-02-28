#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tmp=0;
        int max_result=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<endl;
            tmp += nums[i];
            if(tmp>max_result) max_result = tmp;
            if(nums[i]<=0 && tmp<=0){
                tmp=0;
            }
        }
        return max_result;
    }
};

int main(){
    vector<int> g = {-2,1,-3,4,-1,2,1,-5,4};
    Solution stl;
    cout<<stl.maxSubArray(g)<<endl;
}