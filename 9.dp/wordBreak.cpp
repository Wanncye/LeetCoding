#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(int j=1; j<=s.size(); j++){
            for(int i=0; i<j; i++){
                string subStr = s.substr(i, j-i);
                cout<<subStr<<endl;
                if(dict.find(subStr) != dict.end() && dp[i])
                    dp[j] = true;
            }
        }
        for(int i=0; i<s.size()+1; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return dp[s.size()];
    }
};

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution stl;
    cout<<stl.wordBreak(s, wordDict)<<endl;
}