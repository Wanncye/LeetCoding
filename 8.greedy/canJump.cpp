#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.szie()==1) return true;
        for(int i=0; i<=cover; i++){
            cover = max(i+nums[i], cover);
            if(cover>=nums.size()-1) return true;
        }
        return false;
    }
};

int main(){
    vector<int> g = {2,5,0,0};
    Solution stl;
    cout<<stl.canJump(g)<<endl;
}