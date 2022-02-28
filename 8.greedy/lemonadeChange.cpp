#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int count20=0;
        for(int i : bills){
            if(i==5) count5++;
            else if(i==10){
                count10++;
                count5--;
            }
            else if(i==20){
                if(count10>0){
                    count5--;
                    count10--;
                }
                else{
                    count5 -= 3;
                }
            }
            if(count5<0 ) return false;
        }
        return true;
    }
};

int main(){
    vector<int> g = {5,5,10,10,20};
    Solution stl;
    cout<<stl.lemonadeChange(g)<<endl;
}