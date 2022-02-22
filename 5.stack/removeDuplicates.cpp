#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
//string也可以当成栈来使用！！！！！！！！！
    string removeDuplicates(string s) {
        stack<char> stk;
        int size=0;
        for(int i=0; i<s.size(); i++){
            if(stk.empty() || stk.top() != s[i]){
                stk.push(s[i]);
                size++;
            } 
            else{
                stk.pop();
                size--;
            }
        }
        string result="";
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(){
    Solution obj;
    string a = "abbaca";
    cout<<obj.removeDuplicates(a)<<endl;
}