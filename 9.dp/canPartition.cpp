#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i : nums) target += i;
        if(target%2==1) return false;
        target /= 2;
        vector<int> dp(target,0);
        cout<<dp.size()<<endl;
        for(int i=0; i<nums.size(); i++){
            for(int j=target; j>=nums[i]; j--){
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        if(dp[target]==target) return true;
        return false;
    }
};

int main(){
    vector<int> cost = {1,5,11,5};
    Solution stl;
    cout<<stl.canPartition(cost)<<endl;
}