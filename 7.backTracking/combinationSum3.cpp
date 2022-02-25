#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(int targetSum, int sum, int k, int startIndex){
        
        if(path.size()==k){
            if(sum == targetSum){
                for(int i:path) cout<<i<<" ";
                cout<<endl;
                result.push_back(path);
            }
            return;
        }
        for(int i=startIndex; i<=9; i++){
            sum += i;
            if (sum > targetSum) { // 剪枝操作
                return;
            }
            path.push_back(i);
            backTracking(targetSum, sum, k, i+1);
            sum -= i;
            path.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(n, 0, k, 1);
        return result;
    }
};

int main(){
    Solution stl;
    stl.combinationSum3(2, 8);
}