#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    char target;
    cin>>target;
    target = tolower(target);
    int targetNum =0 ;
    for(int i=0; i<str.size(); i++){
        char tmp = tolower(str[i]);
        if(tmp==target) targetNum++; 
    }
    cout<<targetNum<<endl;
}