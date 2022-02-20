#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumMap;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                auto it = sumMap.find(sum);
                if(it != sumMap.end()){
                    it->second++;
                }else{
                    sumMap.insert(pair<int,int>(sum, 1));
                }
            }
        }
        int count=0;
        for(int i=0; i<nums3.size(); i++){
            for(int j=0; j<nums4.size(); j++){
                int sum = nums3[i] + nums4[j];
                auto it = sumMap.find(-sum);
                if(it != sumMap.end()) count+=it->second;
            }
        }
        return count;
    }
};

int main(){
    vector<int> a={1,2};
    vector<int> b={-2,-1};
    vector<int> c={-1,2};
    vector<int> d={0,2};
    Solution slt;
    cout<<slt.fourSumCount(a,b,c,d);
}