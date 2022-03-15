#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[1]=nums[0];
        for(int i=2; i<=nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[nums.size()];
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution stl;
    cout<<stl.rob(nums)<<endl;
}