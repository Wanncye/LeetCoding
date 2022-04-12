#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto i : matrix)
            for(auto j : i)
                cout << j << " ";
        cout << endl;
    }
};

int main(){
    vector<vector<int> > matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,8,7,6},
        {5,4,3,2}
    };
    Solution stl;
    stl.rotate(matrix);
}