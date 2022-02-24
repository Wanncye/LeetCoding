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
    long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);

        // 中序遍历，验证遍历的元素是不是从小到大
        // 中序遍历得到的顺序就是从小大大排序的
        if (maxVal < root->val) maxVal = root->val;
        else return false;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

int main(){
    TreeNode *root = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(16);
    TreeNode *node4 = new TreeNode(20);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    Solution stl;
    cout<<stl.isValidBST(root);
}