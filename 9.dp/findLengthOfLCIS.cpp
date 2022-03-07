#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]) dp[i] = max(dp[i], dp[i-1]+1);
            result = max(dp[i], result);
        }
        
        for(int i: dp) cout<<i<<" ";
        cout<<endl;

        return result;
    }
};

int main(){
    vector<int> nums = {1,3,5,4,7};
    Solution stl;
    cout<<stl.findLengthOfLCIS(nums)<<endl;
}