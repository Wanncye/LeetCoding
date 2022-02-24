#include<iostream>
#include<vector>
#include<queue>
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
    bool traversal(TreeNode* cur, vector<TreeNode*>& path, int targetSum){
        path.push_back(cur);
        if(cur->left==NULL&&cur->right==NULL&&cur->val==targetSum) return true;

        if(cur->left){
            if(traversal(cur->left, path, targetSum-cur->val)) return true;
            path.pop_back();
        }
        if(cur->right){
            if(traversal(cur->right, path, targetSum-cur->val)) return true;
            path.pop_back();
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root && targetSum==0) return true;
        else if(!root && targetSum!=0) return false;
        vector<TreeNode*> path;
        return traversal(root, path, targetSum);
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->right = node2;
    root->left = node1;
    node2->left = node3;
    node2->right = node4;
    Solution stl;
    cout<<stl.hasPathSum(root, 30);
}