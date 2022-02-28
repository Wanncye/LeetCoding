#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(), points.end(), cmp);
        int result=1;
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > points[i-1][1]){
                result++;
            }else{
                points[i][1] = min(points[i][1], points[i-1][1]);
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> g = {{10,16},{2,8},{1,6},{7,12}};
    Solution stl;
    cout<<stl.findMinArrowShots(g)<<endl;;
}