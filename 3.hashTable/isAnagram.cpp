#include<iostream>
// #include<string>
using namespace std;

class Solution {
public:
/*
用数组来记录字母出现的次数
*/
    bool isAnagram(string s, string t) {
        int sArray[26] = {0};
        int tArray[26] = {0};
        for(int i=0; i<s.size();i++){
            sArray[s[i]-'a']++;
        }
        for(int i=0; i<t.size();i++){
            tArray[t[i]-'a']++;
        }
        int i = 0;
        while(i < 26 && sArray[i] == tArray[i]) i++;
        return i < 26 ? false : true;
    }
};

int main(){
    string a = "anagram";
    string b = "nagaram";
    cout<<a[1]<<endl;
    Solution slt;
    cout<<slt.isAnagram(a, b);
}