#include<iostream>
#include<vector>
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
    void traversal(TreeNode* cur, vector<int>& result){
        if(cur==NULL) return;
        // result.push_back(cur->val);
        traversal(cur->left, result);
        result.push_back(cur->val);
        traversal(cur->right, result);
        // result.push_back(cur->val);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        for(int i : result) cout<<i<<" ";
        cout<<endl;
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    root->right = node1;
    node1->left = node2;
    Solution stl;
    stl.inorderTraversal(root);
}