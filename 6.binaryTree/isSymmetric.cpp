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
    bool compare(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL) return true;
        else if(left==NULL && right!=NULL) return false;
        else if(left!=NULL && right==NULL) return false;
        else if(left->val != right->val) return false;
        bool leftEq = compare(left->left, right->right);
        bool rightEq = compare(left->right, right->left);
        return leftEq && rightEq;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compare(root->left, root->right);
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
    cout<<stl.isSymmetric(root)<<endl;;
}