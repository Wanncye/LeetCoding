#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums) sum+=i;
        if((sum + target) % 2 == 1 || abs(target) > sum) return 0;
        int bagSize = (sum + target) / 2;
        vector<int> dp(bagSize+1, 0);
        dp[0]=1;
        for(int i=0; i<nums.size(); i++){
            for(int j=bagSize; j>=nums[i]; j--){
                dp[j] = dp[j] + dp[j-nums[i]];
                cout<<dp[j]<<endl;
            }
        }
        return dp[bagSize];
    }
};

int main(){
    vector<int> cost = {1,1,1,1,1};
    Solution stl;
    cout<<stl.findTargetSumWays(cost, 3)<<endl;
}