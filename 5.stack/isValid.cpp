#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') str.push(')');
            else if(s[i] == '[') str.push(']');
            else if(s[i] == '{') str.push('}');
            else{
                if(!str.empty() && str.top() == s[i]){
                    str.pop();
                }else return false;
            }
        }
        if(str.empty()) return true;
        else return false;
    }

};

int main(){
    Solution obj;
    string a = "()";
    cout<<obj.isValid(a)<<endl;
}