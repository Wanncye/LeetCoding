#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    Solution(){;};
    int search(vector<int>& nums, int target) {
        /*
        使用下面这一句为什么不对！！！！
        因为，sizeof(vector)的大小固定为24byte，其中包括开始、结束，以及分配的内存结尾三个指针！
        气得吐血～
        */
        // int len = sizeof(nums)/sizeof(nums[0]);

        int l = 0;
        int r = nums.size() - 1;
        return mBinarySearch(nums, l, r, target);
    };

    int mBinarySearch(vector<int>& nums, int l, int r, int target){
        if (l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                return mBinarySearch(nums, mid + 1, r, target);
            }
            else if(nums[mid] > target){
                return mBinarySearch(nums, l, mid - 1, target);
            }
        }
        return -1;
    };
};

int main() {
    vector<int> a;
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    int target = 5;
    Solution bn = Solution();
    cout<<bn.search(a, target)<<endl;
}