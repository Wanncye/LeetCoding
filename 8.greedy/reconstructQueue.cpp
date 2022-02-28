#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        for(vector<int> i:people){
            for(int j:i) cout<<j<<" ";
            cout<<endl;
        }
        vector<vector<int>> result;
        sort(people.begin(), people.end(), cmp);
        for(int i=0; i<people.size(); i++){
            int position = people[i][1];
            result.insert(result.begin()+position, people[i]);
        }
        cout<<endl;
        for(vector<int> i:result){
            for(int j:i) cout<<j<<" ";
            cout<<endl;
        }
        return result;
    }
};

int main(){
    vector<vector<int>> g = {{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
    Solution stl;
    stl.reconstructQueue(g);
}