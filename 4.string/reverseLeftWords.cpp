#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
//申请了额外空间
    string reverseLeftWords_1(string s, int n) {
        string a(s.begin(), s.begin()+n);
        int ai=0;
        for(int i = 0; i<s.size(); i++){
            if(i<s.size()-n) s[i] = s[i+n];
            else{
                s[i] = a[ai++];
            }
        }

        cout<<s<<endl;
        return s;
    }
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin()+n);
        reverse(s.begin()+n, s.begin()+s.size());
        reverse(s.begin(), s.end());
        cout<<s<<endl;
        return s;
    }
};

int main(){
    string str = "abcdefg";
    Solution stl;
    stl.reverseLeftWords(str, 2);
}
