#include<iostream>
#include<vector>

#include<bitset>
using namespace std;

class Solution {
public:
    // vector<int> grayCode(int n) {
    //     vector<int> ret;
    //     ret.reserve(1 << n);
    //     // cout<<ret.size()<<endl;
    //     // cout<<(1 << n)<<endl;
    //     ret.push_back(0);
    //     for (int i = 1; i <= n; i++) {
    //         int m = ret.size();
    //         for (int j = m - 1; j >= 0; j--) {
    //             ret.push_back(ret[j] | (1 << (i - 1)));
    //         }
    //     }
    //     return ret;
    // }
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
            cout << bitset<4>(ret[i]) << endl;
        }
        return ret;
    }
};

int main(){
    Solution slt;
    slt.grayCode(3);
}