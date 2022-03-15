#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1]=1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                int tmp = max(dp[i-j]*j, j*(i-j));
                if(tmp > dp[i]) dp[i] = tmp;
            }
            cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};

int main(){
    Solution stl;
    cout<<stl.integerBreak(10)<<endl;
}