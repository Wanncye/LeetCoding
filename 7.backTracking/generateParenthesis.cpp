#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void backtracking(string cur, int open, int close, int n){
        if(cur.size()==2*n){
            result.push_back(cur);
            cout<<cur<<endl;
            return;
        }
        if(open<n){
            cur.push_back('(');
            backtracking(cur, open+1, close, n);
            cur.pop_back();
        }
        if(close<open){
            cur.push_back(')');
            backtracking(cur, open, close+1, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur;
        backtracking(cur, 0, 0, n);
        return result;
    }
private:
    vector<string> result;
};

int main(){
    Solution stl;
    stl.generateParenthesis(3);
}