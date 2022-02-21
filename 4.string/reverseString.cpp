#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }

        for(int i=0; i<s.size(); i++) cout<<s[i]<<" ";
        cout<<endl;
    }
};

int main(){
    vector<char> str = {'h','e','l','l','o'};
    reverse(str.begin(), str.end());
    for(int i=0; i<str.size(); i++) cout<<str[i]<<" ";
    cout<<endl;
    Solution stl;
    stl.reverseString(str);
}