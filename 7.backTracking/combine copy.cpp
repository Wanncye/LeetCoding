#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(int n, int k, int startIndex){
        if(path.size()==k){
            for(int i:path) cout<<i<<" ";
            cout<<endl;
            result.push_back(path);
            return;
        }
        for(int i=startIndex; i<=n; i++){
            path.push_back(i);
            backTracking(n, k, i+1);
            path.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }
};

int main(){
    Solution stl;
    stl.combine(4, 2);
}