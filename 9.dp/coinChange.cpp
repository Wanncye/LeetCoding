#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, __INT_MAX__);
        dp[0]=0;
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                if (dp[j - coins[i]] != __INT_MAX__) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        for(int i=0; i<amount+1; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        if(dp[amount]==__INT_MAX__) return -1;
        else return dp[amount];
    }
};

int main(){
    vector<int> coins = {1, 2, 5};
    Solution stl;
    cout<<stl.coinChange(coins, 11)<<endl;
}