#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int, int>::iterator it = numsMap.find(target-nums[i]);
            if(it != numsMap.end()){
                return {it->second, i};
            }
            numsMap.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};

int main(){
    int a[4] = {2,7,11,15};
    vector<int> aa(a, a+3);
    Solution slt;
    
    cout<<slt.twoSum(aa, 9)[0]<<slt.twoSum(aa, 9)[1];
}