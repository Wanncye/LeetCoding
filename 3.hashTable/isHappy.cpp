#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sumSet;
        while(n != 1){
            vector<int> nDecompose;
            while(n){
                nDecompose.push_back(n % 10);
                n = n / 10;
            }
            int sum=0;
            for (vector<int>::const_iterator i = nDecompose.begin(); i != nDecompose.end(); i++) {
                sum += (*i)*(*i);
            }
            if(sumSet.find(sum) == sumSet.end()){
                sumSet.insert(sum);
            }
            else{
                return false;
            }
            cout<<sum<<endl;
            n=sum;
        }
        return true;
    }
};

int main(){
    Solution slt;
    cout<<slt.isHappy(2);
}