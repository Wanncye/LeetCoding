#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> result;
    vector<char> path;

    void backTracking(string digits, int index){
        if(path.size()==digits.size()){
            string tmp="";
            for(char ii:path){
                cout<<ii<<" ";
                tmp += ii;
            }
            cout<<endl;
            result.push_back(tmp);
            return;
        }
        int digit = digits[index] - '0';        // 将index指向的数字转为int
        string letters = letterMap[digit];
        for(int i=0; i<letters.size(); i++){
            path.push_back(letters[i]);
            backTracking(digits, index+1);
            path.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return result;
        }
        backTracking(digits, 0);
        return result;
    }
};

int main(){
    string dgt="23";
    Solution stl;
    stl.letterCombinations(dgt);
}