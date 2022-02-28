#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0 && k-->0) nums[i] *= -1;
        }
        if(k%2 == 1 && k>0) nums[nums.size()-1] *= -1;
        int ans = 0;
        for(int i : nums) ans += i;
        return ans;
    }
};

int main(){
    vector<int> g = {-4,4,-3,3,-4,-1,8,-7,-7};
    Solution stl;
    cout<<stl.largestSumAfterKNegations(g, 3)<<endl;
}