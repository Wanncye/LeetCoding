#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    vector<int> partitionLabels(string s) {
        vector<int> result;
        int hash[27]={0};
        int left=0;
        int right=0;
        for(int i=0; i<s.size(); i++) hash[s[i]-'a'] = i;
        for(int i=0; i<s.size(); i++){
            right = max(right, hash[s[i]-'a']);
            if(i==right){
                result.push_back(right-left+1);
                left = i+1;
            }
        }
        for(int i:result) cout<<i<<" ";
        cout<<endl;
        return result;
    }
};

int main(){
    // vector<vector<int>> g = {{10,16},{2,8},{1,6},{7,12}};
    string s = "ababcbacadefegdehijhklij";
    Solution stl;
    stl.partitionLabels(s);
}