#include<iostream>
#include<vector>
using namespace std;


vector<vector<string> > result;
vector<string> path;

void backtracing(string str, int index){
    if(index==str.size()){
        result.push_back(path);
        return;
    }
    for(int i=index; i<str.size(); i++){
        string tmp;
        tmp = str.substr(index, i-index+1);
        path.push_back(tmp);
        backtracing(str, i+1);
        path.pop_back();
    }
}

int main(){
    string str="abcde";
    // cout<<str.substr(0,0)<<endl;
    backtracing(str,0);
}