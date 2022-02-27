#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    void backTracking(string s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(path);
            for(string i:path) cout<<i<<" ";
            cout<<endl;
            return;
        }
        for(int i=startIndex; i<s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string tmp = s.substr(startIndex, i-startIndex+1);
                path.push_back(tmp);
            }else{
                continue;
            }
            backTracking(s, i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};

int main(){
    string srt="aab";
    Solution stl;
    stl.partition(srt);
}