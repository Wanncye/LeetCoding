#include<iostream>
#include<vector>
// #include<algo.h>
// #include<limits>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0]=1;
        for(int j=0; j<=target; j++)
            for(int i=0; i<nums.size(); i++){
                if(j>=nums[i] && dp[j] < __INT_MAX__ - dp[j - nums[i]]) dp[j] += dp[j-nums[i]];
            }
        return dp[target];
    }
};

int main(){
    vector<int> cost = {9};
    Solution stl;
    cout<<stl.combinationSum4(cost, 4)<<endl;
}