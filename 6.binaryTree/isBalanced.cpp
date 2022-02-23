#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
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
    int getDepth(TreeNode* node){
        if(node==NULL) return 0;
        int leftdepth = getDepth(node->left);       // 左
        if(leftdepth == -1) return -1;
        int rightdepth = getDepth(node->right);     // 右
        if(rightdepth == -1) return -1;
        return abs(leftdepth - rightdepth) > 1 ? -1 : 1 + max(leftdepth, rightdepth);
    }
    bool isBalanced(TreeNode* root) {
        return getDepth(root) == -1 ? false : true;
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
    cout<<stl.isBalanced(root)<<endl;;
    return 0;
}