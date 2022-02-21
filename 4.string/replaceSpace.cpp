#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int sLen = s.size();
        int count = 0;
        for(int i=0; i<sLen; i++){
            if(s[i]==' ') count++;
        }
        int newLen = sLen + 2*count;
        s.resize(newLen);
        for(int i = sLen, j = newLen; i < j; i--, j--){
            if(s[i] != ' '){
                s[j] = s[i];
            }else{
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
        }
        cout<<s<<endl;
        return s;
    }
};

int main(){
    string str = "We are happy.";
    Solution stl;
    stl.replaceSpace(str);
}
