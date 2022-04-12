#include<iostream>
#include<unordered_map>
using namespace std;

class Support {
public:
    Support() {
        table = {
            {"start", {"sign", "start", "number", "end"}},
            {"sign", {"end", "end", "number", "end"}},
            {"number", {"end", "end", "number", "end"}},
            {"end", {"end", "end", "end", "end"}}
        };
        sign = 1;
        ans = 0;
        state = "start";
    };

    int getCol(char c){
        if(c == '+' || c == '-') return 0;
        else if(isspace(c)) return 1;
        else if(isdigit(c)) return 2;
        else return 3; 
    }

    void getNum(char c){
        state = table[state][getCol(c)];
        if(state == "number"){
            ans = ans * 10 + (c - '0');
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long) INT_MIN);
        }else if(state == "sign"){
            if(c == '-') sign = -1;
        }
    }

    
    unordered_map<string, vector<string> > table;
    int sign;
    long long ans;
    string state;
};


class Solution {
public:
    int myAtoi(string str) {
        Support sup;
        for(int i = 0; i < str.size(); i++){
            sup.getNum(str[i]);
        }
        return sup.ans * sup.sign;
    }
};

int main(){
    Solution stl;
    stl.myAtoi("  -12348cd");
}