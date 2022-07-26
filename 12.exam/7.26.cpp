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

int preVal = __INT_MAX__;


bool isBST(TreeNode* root) {
    if(root == NULL) return true;

    bool left, right;

    isBST(root->left);

    if(preVal < root->val) preVal = root->val;
    else return false;

    isBST(root->right);


    return left && right;
}


int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* l1 = new TreeNode(1);
    TreeNode* r1 = new TreeNode(4);
    TreeNode* rl = new TreeNode(2);
    TreeNode* rr = new TreeNode(6);
    root->left = l1;
    root->right = r1;
    r1->left = rl;
    r1->right = rr;

    cout << isBST(root) << endl;
    return 0;
}