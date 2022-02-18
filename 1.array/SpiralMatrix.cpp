#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > generateMatrix(int n) {
        vector< vector<int> > res(n, vector<int>(n, 0));
        int loop = n / 2;
        int startx = 0, starty = 0;
        int offset = 1;  // 要遵循左闭右开的原则
        int mid = n / 2;
        int count = 1;
        while (loop--)
        {
            int i = startx;
            int j = starty;
            //从左往右，左闭右开
            for(; j < starty + n - offset; j++){
                res[i][j] = count++;
            }
            //从上往下，左闭右开
            for(; i < startx + n - offset; i++){
                res[i][j] = count++;
            }
            //从右往左，左闭右开
            for(; j > starty; j--){
                res[i][j] = count++;
            }
            //从下往上，左闭右开
            for(; i > startx; i--){
                res[i][j] = count++;
            }
            startx++;
            starty++;
            offset += 2;
        }
        if(n % 2 == 1) {
            res[mid][mid] = count;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<res[i][j]<<" "<<endl;
            }
        }
            
        return res;
    }

};

int main() {
    int n=3;
    Solution bn = Solution();
    bn.generateMatrix(n);
    // cout<<bn.sortedSquares(a)<<endl;
}