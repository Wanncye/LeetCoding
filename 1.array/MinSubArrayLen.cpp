#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
/*
时间复杂度O(n)
空间复杂度O(1)
*/
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0; //起始位置
        int subLength = __INT32_MAX__; //子序列最短长度
        int sum = 0; //子序列之和
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                int len = j - i + 1;
                subLength = len <  subLength ? len : subLength;
                sum -= nums[i++];
            }
        }
        return subLength == __INT32_MAX__ ? 0 : subLength;
    }

};

int main() {
    vector<int> a;
    a.push_back(-4);
    a.push_back(-1);
    a.push_back(0);
    a.push_back(3);
    a.push_back(10);
    int val = 3;
    Solution bn = Solution();
    bn.sortedSquares(a);
    // cout<<bn.sortedSquares(a)<<endl;
}