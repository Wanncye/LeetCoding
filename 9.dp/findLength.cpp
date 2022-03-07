#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int result=0;
        // 超时
        // for(int i=1; i<=nums1.size(); i++){
        //     for(int j=1; j<=nums2.size(); j++){
        //         if(nums1[i-1]==nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        //         result = max(dp[i][j], result);
        //     }
        // }
        vector<int> dp(vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = nums2.size(); j > 0; j--) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                } else dp[j] = 0; // 注意这里不相等的时候要有赋0的操作
                if (dp[j] > result) result = dp[j];
            }
        }
        // for(vector<int> i: dp){
        //     for(int j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return result;
    }
};

int main(){
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    Solution stl;
    cout<<stl.findLength(nums1, nums2)<<endl;
}