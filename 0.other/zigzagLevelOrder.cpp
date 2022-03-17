#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include <algorithm> 
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            vector<int> subResult;
            for(int i =0; i<size; i++){
                TreeNode* cur = que.front();
                subResult.push_back(cur->val);
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            if(depth%2==0) result.push_back(subResult);
            else{
                reverse(subResult.begin(), subResult.end());
                result.push_back(subResult);
            }
            depth++;
        }
        for(vector<int> i:result)
            for(int j:i) 
                cout<<j<<" ";
        cout<<endl;
        return result;

    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;
    Solution stl;
    stl.zigzagLevelOrder(root);
}