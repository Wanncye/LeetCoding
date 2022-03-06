#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = subRob(nums, 0, nums.size()-1); // 情况二
        cout<<result1<<endl;
        int result2 = subRob(nums, 1, nums.size()); // 情况三
        cout<<result2<<endl;
        return max(result1, result2);
    }

    int subRob(vector<int>& nums, int start, int end){
        if (end == start) return nums[start];
        vector<int> dp(end-start+1, 0);
        dp[1]=nums[start];
        for(int i=2; i<=end-start; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[start+i-1]);
        }
        return dp[end-start];
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    Solution stl;
    cout<<stl.rob(nums)<<endl;
}