#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void dfs(int index){
        vistied[index]=1;
        for(int i=0; i<edge[index].size(); i++){
            if(vistied[edge[index][i]]==0) dfs(edge[index][i]);
            else if(vistied[edge[index][i]]==1){
                tag=false;
                return;
            }
            else if(vistied[edge[index][i]]==2){
                continue;
            }
        }
        vistied[index]=2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        vistied.resize(numCourses);
        for(auto p : prerequisites){
            edge[p[1]].push_back(p[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(vistied[i]==0) dfs(i);
        }
        return tag;
    }
private:
    vector<vector<int>> edge;
    vector<int> vistied;
    bool tag=true;
};

int main(){
    int numCourses = 3;
    vector<vector<int>> prerequisites = {
        {2,1},
        {1,0},
        {0,2}
    };
    Solution stl;
    stl.canFinish(numCourses, prerequisites);
}