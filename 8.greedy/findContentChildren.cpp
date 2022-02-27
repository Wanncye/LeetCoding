#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // g是胃口，s是尺寸
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int start = 0, count = 0;
        for(int i=0; i<s.size(); i++){
            if(start < g.size()&&s[i] >= g[start]){
                start++;
                count++;
            }
        }
        return count;
    }
};

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    Solution stl;
    cout<<stl.findContentChildren(g,s)<<endl;
}