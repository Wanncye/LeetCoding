#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int result = word1.size()+word2.size()-2*dp[word1.size()][word2.size()];
        return result;
    }
};

int main(){
    string string1= "a";
    string string2= "b";
    Solution stl;
    cout<<stl.minDistance(string1, string2)<<endl;
}