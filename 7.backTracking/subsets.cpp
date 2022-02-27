#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int>& nums, int startIndex){
        result.push_back(path);
        for(int i:path) cout<<i<<" ";
        cout<<endl;
        for(int i = startIndex; i<nums.size(); i++){
            path.push_back(nums[i]);
            backTracking(nums, i+1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution stl;
    stl.subsets(nums);
}