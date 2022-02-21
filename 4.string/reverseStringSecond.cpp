#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            int a = s.size();
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
                continue;
            }
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
            reverse(s.begin() + i, s.begin() + 1);
        }
        cout<<s<<endl;
        return s;
    }
};

int main(){
    string s = "abcdefg";
    reverse(s.begin(),s.begin()+s.size()+1);
    cout<<s<<endl;

    Solution stl;
    stl.reverseStr(s, 3);
}