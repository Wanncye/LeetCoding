#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > dp(2, vector<int>(k + 1));
    dp[0][0] = 1;
    const int mod = 1000000007;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 0; j <= k; j++) {
            int now = i & 1, last = now ^ 1;
            dp[now][j] = (j - 1 >= 0 ? dp[now][j - 1] : 0) + dp[last][j] - (j - i >= 0 ? dp[last][j - i] : 0);
            if (dp[now][j] >= mod)
                dp[now][j] -= mod;
            if (dp[now][j] < 0)
                dp[now][j] += mod;

        }
    }
    int res = 0;
    for(int i = 0; i < n - 1 && i <= k / 2; ++i){
        for(int j = i + 1; j < n && i + j - 1 <= k; ++j){
            int cur = i + j - 1;
            for(int m = 0; m <= k - cur; ++m){
                res += dp[(n - 2) & 1][m];
                if(res >= mod){
                    res -= mod;
                }
            }
        }
    }
    cout << res;


    return 0;
}