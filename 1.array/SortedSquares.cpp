#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:


    vector<int> sortedSquares(vector<int>& nums) {
        int endP = nums.size()-1;
        vector<int> result(nums.size(), 0);
        for(int startP = 0; startP <= endP; startP++){
            if(abs(nums[endP])>=abs(nums[startP])){
                result[endP] = nums[endP] * nums[endP];
                endP--;
            }else{
                result[endP] = nums[startP] * nums[startP];
                startP++;
            }
        }
        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }
        return result;
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