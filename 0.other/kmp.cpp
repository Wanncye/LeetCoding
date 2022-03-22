#include<iostream>
#include<vector>
using namespace std;

// void getNext(int* next, const string& s) {
//     int j = 0;
//     next[0] = 0;
//     for(int i = 1; i < s.size(); i++) {
//         while (j > 0 && s[i] != s[j]) {
//             j = next[j - 1];
//         }
//         if (s[i] == s[j]) {
//             j++;
//         }
//         next[i] = j;
//     }
// }

void getNext(int* next, string target){
    int j=0;
    next[0]=0;
    for(int i=1;i<target.size();i++){
        while(j>0 && target[i] != target[j]) j=next[j-1];
        if(target[i] == target[j]) j++;
        next[i] = j;
    }
}

int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
        return 0;
    }
    int next[needle.size()];
    getNext(next, needle);
    for(int i: next) cout<<i<<" ";
    cout<<endl;
    int j = 0;
    for(int i=0; i<haystack.size(); i++){
        while(j>0 && haystack[i] != needle[j]) j = next[j-1];
        if(haystack[i] == needle[j]) j++;
        if(j==needle.size()) return true;
    }
    // for (int i = 0; i < haystack.size(); i++) {
    //     while(j > 0 && haystack[i] != needle[j]) {
    //         j = next[j - 1];
    //     }
    //     if (haystack[i] == needle[j]) {
    //         j++;
    //     }
    //     if (j == needle.size() ) {
    //         return true;
    //     }
    // }
    return false;
}

int kmp(vector<string> myStr, string target){
    int result=0;
    for(string subStr:myStr){
        if(strStr(subStr,target)) result+=1;
    }
    return result;
}

int main(){
    string target="acccacce";
    vector<string> myStr={{"xae"}, {"abc"}, {"xcx"}};
    int len = myStr.size();
    for(int i=0; i<len; i++){
        string tmp;
        for(int j=0; j<len; j++){
            tmp += myStr[j][i];
        }
        myStr.push_back(tmp);
    }
    cout<<kmp(myStr, target)<<endl;
}