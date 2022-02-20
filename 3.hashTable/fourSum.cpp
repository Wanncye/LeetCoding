#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#include <map>



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 这种剪枝是错误的，这道题目target 是任意值
            // 例如target为负数的时候，就不行
            // if (nums[k] > target) {
            //     return result;
            // }
            // 可以把剪枝操作改成如下
            if (target>0 && nums[k] > target) {
                return result;
            }
            // 去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 正确去重方法
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if (nums[k] + nums[i] > target - (nums[left] + nums[right])) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if (nums[k] + nums[i]  < target - (nums[left] + nums[right])) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 去重逻辑应该放在找到一个四元组之后
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
};

int main(){
    vector<int> aa{1,0,-1,0,-2,2};
    Solution slt;
    
    cout<<slt.fourSum(aa, 8)[0][0]<<endl;
}