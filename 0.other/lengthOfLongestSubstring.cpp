#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int array[128]={0};
        int fastPtr = 0, slowPtr = 0;
        int maxLen = 0;
        for(; fastPtr<s.size(); fastPtr++){
            array[s[fastPtr]]++;
            //>1说明有重复
            if(array[s[fastPtr]]>1){
                while(s[slowPtr] != s[fastPtr]){
                    array[s[slowPtr]]--;
                    slowPtr++;
                }
                array[s[slowPtr]]--;
                slowPtr++;
            }
            maxLen = max(maxLen, fastPtr-slowPtr+1);
        }
        return maxLen;
    }
};

int main(){
    string str = "ggububgvfk";
    Solution slt;
    cout<<slt.lengthOfLongestSubstring(str)<<endl;
}