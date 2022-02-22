#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();
                if(tokens[i]=="+") stk.push(op1+op2);
                if(tokens[i]=="-") stk.push(op1-op2);
                if(tokens[i]=="*") stk.push(op1*op2);
                if(tokens[i]=="/") stk.push(op1/op2);
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};

int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    Solution obj;
    cout<<obj.evalRPN(tokens)<<endl;
}