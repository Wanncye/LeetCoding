#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    void backtracking(string str, int index){
        if(index == str.size()){
            cout<<path<<endl;
            result.push_back(path);
        }
        for(int i = index; i < str.size(); i++){
            path.push_back(str[i]);
            backtracking(str, i);
            path.pop_back();
        }
    };
    vector<string> Permutation(string str) {
        backtracking(str, 0);
    }
};

int main(){
    Solution stl;
    stl.Permutation("abc");
}