#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            for(int i:path) cout<<i<<" ";
            cout<<endl;
            result.push_back(path);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i]==true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), 0);
        backTracking(nums, used);
        return result;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution stl;
    stl.permute(nums);
}