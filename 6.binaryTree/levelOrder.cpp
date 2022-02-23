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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> treeQueue;
        if(!root) return result;
        treeQueue.push(root);
        while(!treeQueue.empty()){
            vector<int> subResult;
            int size = treeQueue.size();
            for(int i=0; i<size; i++){
                TreeNode* tmp = treeQueue.front();
                treeQueue.pop();
                subResult.push_back(tmp->val);
                if(tmp->left) treeQueue.push(tmp->left);
                if(tmp->right) treeQueue.push(tmp->right);
            }
            for(int i:subResult) cout<<i<<" ";
            cout<<endl;
            result.push_back(subResult);
        }
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
    stl.levelOrder(root);
}