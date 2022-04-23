#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.reserve(1 << n);
        // cout<<ret.size()<<endl;
        // cout<<(1 << n)<<endl;
        ret.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = ret.size();
            for (int j = m - 1; j >= 0; j--) {
                ret.push_back(ret[j] | (1 << (i - 1)));
            }
        }
        return ret;
    }
};

int main(){
    Solution slt;
    slt.grayCode(3);
}