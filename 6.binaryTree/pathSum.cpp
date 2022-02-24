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
    void traversal(TreeNode* cur, vector<TreeNode*>& path, vector<vector<int>>& result, int targetSum){
        path.push_back(cur);
        if(cur->left==NULL&&cur->right==NULL&&cur->val==targetSum){
            vector<int> tmp;
            for(TreeNode* i : path){
                tmp.push_back(i->val);
                cout<<i->val<<" ";
            }
            cout<<endl;
            result.push_back(tmp);
        }

        if(cur->left){
            traversal(cur->left, path, result, targetSum-cur->val);
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right, path, result, targetSum-cur->val);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<TreeNode*> path;
        vector<vector<int>> result;
        if(!root) return result;
        traversal(root, path, result, targetSum);
        return result;
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
    stl.pathSum(root, 30);
}