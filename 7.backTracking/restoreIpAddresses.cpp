#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backTracking(string s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size()-1)){
                cout<<s<<endl;
                result.push_back(s);
            }
        }
        for(int i=startIndex; i<s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                pointNum++;
                backTracking(s, i+2, pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            }
            else break;
        }
    }

    bool isValid(string s, int start, int end){
        if(start>end) return false;
        if(s[start]=='0' && start!=end) return false;
        int num = 0;
        for(int i=start; i<=end; i++){
            num = 10*num + (s[i]-'0');
            if(num > 255) return false;
        }
        
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        backTracking(s, 0, 0);
        return result;
    }
};

int main(){
    string srt="0279245587303";
    Solution stl;
    stl.restoreIpAddresses(srt);
}