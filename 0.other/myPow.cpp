#include<iostream>
using namespace std;

class Solution {
public:
    double quickMul_1(double x, long long N) {
        if(N == 0 ) return 1; 
        double y = quickMul(x, N / 2);
        return N % 2 == 1 ? y * y * x : y * y;
    }

    double quickMul(double x, long long N) {
        double contrib = x;
        double ans = 1;
        while(N){
            if(N % 2 == 1){
                ans = ans * contrib;
            }
            contrib *= contrib;
            N = N / 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return n >= 0 ? quickMul(x, N) : 1 / quickMul(x, -N);
    }
};


int main(){
    Solution stl;
    cout << stl.myPow(2, 10) << endl;;
}