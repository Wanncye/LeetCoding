#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyVect(ratings.size(), 1);
        for(int i=0; i<ratings.size()-1; i++){
            //从前往后遍历
            if(ratings[i+1]>ratings[i]) candyVect[i+1] = candyVect[i]+1; 
        }
        for(int i=ratings.size()-1; i>0; i--){
            //从后往前遍历
            if(ratings[i-1]>ratings[i]){
                candyVect[i-1] = max(candyVect[i-1], candyVect[i]+1);
            }
        }
        int sum=0;
        for(int i:candyVect) sum+=i;
        return sum;
    }
};

int main(){
    vector<int> g = {1,2,3,4,5};
    Solution stl;
    cout<<stl.candy(g)<<endl;
}