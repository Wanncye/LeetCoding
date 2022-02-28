#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int result = 1;
        int curDiff = 0;
        int preDiff = 0;
        for(int i=0; i<nums.size(); i++){
            curDiff = nums[i+1]-nums[i];
            if((curDiff>0&&preDiff<=0) || (curDiff<0&&preDiff>=0)){
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

int main(){
    vector<int> g = {1,7,4,9,2,5};
    Solution stl;
    cout<<stl.wiggleMaxLength(g)<<endl;
}