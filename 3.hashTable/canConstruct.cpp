#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
//这种做法忽略了magazine中的字符不能重用的信息
    bool canConstruct_1(string ransomNote, string magazine) {
        unordered_set<char> dict;
        for(int i=0; i<magazine.size(); i++){
            dict.insert(magazine[i]);
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(dict.find(ransomNote[i]) == dict.end()) return false;
        }
        return true;
    }
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for(int i=0; i<magazine.size(); i++){
            record[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            record[ransomNote[i]-'a']--;
            if(record[ransomNote[i]-'a'] < 0) return false;
        }
        return true;
    }
};

int main(){
    string a = "aa";
    string b = "ab";
    Solution slt;
    cout<<slt.canConstruct(a,b);
}