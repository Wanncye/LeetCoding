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
    int result = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) {
        if (cur == NULL) return;
        traversal(cur->left);   // 左
        if (pre != NULL){       // 中
            result = min(result, cur->val - pre->val);
        }
        pre = cur; // 记录前一个
        traversal(cur->right);  // 右
    };

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(10);
    TreeNode *node4 = new TreeNode(20);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    Solution stl;
    cout<<stl.getMinimumDifference(root);
}