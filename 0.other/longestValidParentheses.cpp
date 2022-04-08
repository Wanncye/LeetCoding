#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// 暴力解法，自然超时
// class Solution {
// public:
//     bool isValidParenthese(string s){
//         stack<char> mystack;
//         for(char i : s){
//             if(i == '(') mystack.push('(');
//             if(i == ')' && mystack.empty() == false) mystack.pop();
//             else if(i == ')' && mystack.empty() == true) return false;
//         }
//         if(mystack.empty()) return true;
//         else return false;
//     }

//     int longestValidParentheses(string s) {
//         int maxLen = 0;
//         for(int i=1; i<s.size(); i++){
//             for(int j=0; j<i; j++){
//                 string subString = s.substr(j, i-j+1);
//                 if(isValidParenthese(subString)) maxLen = max(maxLen, i-j+1);
//             }
//         }
//         cout<<maxLen<<endl;
//         return maxLen;
//     }

// };

// dp
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int maxLen = 0;
//         int n = s.size();
//         vector<int> dp(n, 0);
//         for(int i=1; i<n; i++){
//             if(s[i] == ')'){
//                 if(s[i-1] == '('){
//                     dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
//                 }else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '('){
//                     dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
//                 }
//                 cout<<dp[i]<<endl;
//                 maxLen = max(maxLen, dp[i]);
//             }
            
//         }
//         cout << maxLen << endl;
//         return maxLen;
//     }
// };

// stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};


int main(){
    string str = "(()(())";
    Solution stl;
    stl.longestValidParentheses(str);
}