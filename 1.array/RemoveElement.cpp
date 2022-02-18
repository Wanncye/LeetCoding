#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
/*
第一种解法：暴力解法
时间复杂度为O(n^2)
空间复杂度为O(1)
*/
    int removeElement_1(vector<int>& nums, int val) {
        int len = nums.size();
        for(int i = 0; i < len; i++){
            if(nums[i] == val){
                // 注意这里的边界问题
                for(int j = i + 1; j < len-1; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 存在第相邻的要删除的元素
                len--;
            }
        }
        return len;
    }

/*第二种解法：双指针解法
时间复杂度为O(n)
空间复杂度为O(1)
*/
    int removeElement(vector<int>& nums, int val) {
        int slowP = 0;
        for(int fastP = 0; fastP < nums.size(); fastP++){
            if(val != nums[fastP]){
                nums[slowP++] = nums[fastP];
            }
        }
        return slowP;
    }

};

int main() {
    vector<int> a;
    a.push_back(3);
    a.push_back(2);
    a.push_back(2);
    a.push_back(3);
    int val = 3;
    Solution bn = Solution();
    cout<<bn.removeElement(a, val)<<endl;
}