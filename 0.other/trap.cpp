#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        //双指针法超时
        // int sum=0;
        // for(int i=1; i<height.size()-1; i++){
        //     int lHeight=height[i];
        //     int rHeight=height[i];
        //     for(int r=i+1; r<height.size(); r++)
        //         if(height[r]>rHeight) rHeight = height[r];
        //     for(int l=i-1; l>=0; l--)
        //         if(height[l]>lHeight) lHeight = height[l];
        //     sum += min(lHeight, rHeight) - height[i];
        // }
        // return sum;

        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = maxRight.size();

        // 记录每个柱子左边柱子最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }
        // 记录每个柱子右边柱子最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }
        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) sum += count;
        }
        return sum;
    }
};

int main(){
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution stl;
    cout<<stl.trap(nums)<<endl;
}