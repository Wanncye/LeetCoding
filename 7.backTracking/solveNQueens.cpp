#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    
    void backTracking(int n, int row, vector<string>& chessBoard) {
        if(row==n){
            for(string i:chessBoard) cout<<i<<" ";
            cout<<endl;
            result.push_back(chessBoard);
        }
        for(int col=0; col<n; col++){
            if(isValid(chessBoard, row, col, n)){
                chessBoard[row][col] = 'Q';
                backTracking(n, row+1, chessBoard);
                chessBoard[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string>& chessBoard, int row, int col, int n){
        for (int i = 0; i < n; i++) { // 这是一个剪枝
            if (chessBoard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessBoard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessBoard(n, string(n, '.'));
        backTracking(n, 0, chessBoard);
        return result;
    }
};

int main(){
    Solution stl;
    stl.solveNQueens(5);
}