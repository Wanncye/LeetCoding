#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int target = 0;
        int sum = 0;
        for(int i : stones) sum += i;
        target = sum/2;
        vector<int> dp(target+1, 0);
        for(int i=0; i<stones.size(); i++){
            for(int j=target; j>=stones[i]; j--){
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
                cout<<dp[j]<<endl;
            }
        }
        return sum-dp[target]-dp[target];
    }
};

int main(){
    vector<int> cost = {2,7,4,1,8,1};
    Solution stl;
    cout<<stl.lastStoneWeightII(cost)<<endl;
}