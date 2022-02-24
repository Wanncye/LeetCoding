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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        int val;
        if(!root1 && root2) val=root2->val;
        else if(root1 && !root2) val=root1->val;
        else if(root1 && root2) val=root1->val+root2->val;
        else if(!root1 && !root2) return NULL;

        TreeNode* newRoot = new TreeNode(val);
        newRoot->left = mergeTrees(root1->left, root2->left);
        newRoot->right = mergeTrees(root1->right, root2->right);
        return newRoot;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);

    TreeNode *root2 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    root2->left = node2;

    Solution stl;
    stl.mergeTrees(root, root2);
}