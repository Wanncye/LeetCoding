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
    int ans=0;

    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int LDepth = depth(root->left);
        int RDepth = depth(root->right);
        ans = max(ans, LDepth + RDepth + 1);
        return max(LDepth, RDepth) + 1;
    };

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    };
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
    stl.pathSum(root, 30);
}