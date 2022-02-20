#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> resSet;
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        for(int num : nums2){
            if(nums1Set.find(num) != nums1Set.end()){
                resSet.insert(num);
            }
        }
        vector<int> tmp(resSet.begin(), resSet.end());
        return tmp;
    }
};

int main(){
    int a[4] = {1,2,3,4};
    int b[4] = {1,2,3,5};
    vector<int> aa(a, a+3);
    vector<int> bb(b, b+3);
    cout<<a[1]<<endl;
    Solution slt;
    slt.intersection(aa, bb);
}