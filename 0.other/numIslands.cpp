#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> used(grid.size(), vector<int>(grid[0].size(), 0));
        int areaNum=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                
            }
        }
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}
                            };
    