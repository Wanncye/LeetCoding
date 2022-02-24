#include<iostream>
#include<vector>
#include<queue>
#include<string>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(val < root->val) return searchBST(root->left, val);
        if(val > root->val) return searchBST(root->right, val);
        if(val == root->val){
            cout<<val<<endl;
            return root;
        }
    }
};

int main(){
    TreeNode *root = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(11);
    TreeNode *node4 = new TreeNode(20);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    Solution stl;
    stl.searchBST(root, 11);
}