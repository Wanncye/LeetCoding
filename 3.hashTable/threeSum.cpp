#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#include <map>



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0) return result;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left<right && nums[right] == nums[right-1]) right--;
                    while(left<right && nums[left] == nums[left+1]) left++;
                    left++;
                    right--;
                }
            }

        }
        return result;
    }
};

int main(){
    int a[6] = {-1,0,1,2,-1,-4};
    vector<int> aa(a, a+5);
    Solution slt;
    
    cout<<slt.threeSum(aa)[0][0]<<endl;
}