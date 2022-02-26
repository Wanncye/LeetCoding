#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum==target){
            for(int i:path) cout<<i<<" ";
            cout<<endl;
            result.push_back(path);
            return;
        }
        if(sum>target) return;
        for(int i=startIndex; i<candidates.size(); i++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backTracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0, 0);
        return result;
    }
};

int main(){
    vector<int> candidates = {7,3,6,2};
    Solution stl;
    stl.combinationSum(candidates, 7);
}