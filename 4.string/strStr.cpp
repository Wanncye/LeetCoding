#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack="") return -1;
        int needleLen = needle.size();
        for(int i=0; i < haystack.size()-needle.size(); i++){
                string subStr(haystack.begin()+i, haystack.begin()+needleLen+i);
                if(subStr == needle) return i;
        }
        return -1;
    }
};

int main(){
    string str = "he0lr";
    string b = "ll";
    Solution stl;
    cout<<stl.strStr(str, b)<<endl;
}
