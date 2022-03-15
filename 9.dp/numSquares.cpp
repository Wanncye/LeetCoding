#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int thingSize = sqrt(n);
        cout<<thingSize<<endl;
        vector<int> dp(n+1, __INT_MAX__);
        dp[0]=0;
        for(int i=1; i<=thingSize; i++){
            for(int j=i*i; j<=n; j++){
                dp[j] = min(dp[j], dp[j-i*i]+1);
            }
        }
        for(int i=0; i<n+1; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return dp[n];
    }
};

int main(){
    Solution stl;
    cout<<stl.numSquares(12)<<endl;
}