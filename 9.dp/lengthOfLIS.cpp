#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]) 
                    dp[i] = max(dp[i], dp[j]+1);
            }
            if (dp[i] > result) result = dp[i];
        }

        for(int i: dp) cout<<i<<" ";
        cout<<endl;

        return result;
    }
};

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution stl;
    cout<<stl.lengthOfLIS(nums)<<endl;
}