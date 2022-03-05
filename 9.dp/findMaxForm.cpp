#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
         for(string str : strs){
             int numsZero=0;
             int numsOne=0;
             for(char chr : str)
                if(chr=='0') numsZero++;
                else numsOne++;
            for(int i=m; i>=numsZero; i--){
                for(int j=n; j>=numsOne; j--){
                    dp[i][j] = max(dp[i][j], dp[i-numsZero][j-numsOne]+1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> cost = {"10", "0001", "111001", "1", "0"};
    Solution stl;
    cout<<stl.findMaxForm(cost, 5, 3)<<endl;
}