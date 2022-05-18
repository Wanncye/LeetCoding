#include<iostream>
#include<vector>

using namespace std;



unsigned char bits_reverse(unsigned char b){
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    return b;
}



// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(amount + 1, 0);
//         dp[0] = 1;
//         for (int i = 0; i < coins.size(); i++) { // 遍历物品
//             for (int j = coins[i]; j <= amount; j++) { // 遍历背包
//                 dp[j] += dp[j - coins[i]];
//             }
//         }
//         return dp[amount];
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 注意最后一步可以理解为不用花费，所以取倒数第一步，第二步的最少值
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};

int main(){
    // char a = 'a';
    // cout << bitset<4>(a) << endl;;
    // cout << bitset<4>(bits_reverse(a)) << endl;;
    // Solution stl;
    // vector<int> coins = {1,2,5,10};
    // cout << stl.change(37, coins) << endl;
    vector<int> goods = {2,100,2,3,3,90,3,2,80,2};
    Solution stl;
    cout << stl.minCostClimbingStairs(goods) << endl;
}