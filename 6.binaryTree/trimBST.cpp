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
            result.push_back(subResult);
        }
        return result;
    }

    friend ostream & operator<<( ostream & os, TreeNode* node ){
        vector<vector<int>> result = node->levelOrder(node);
        os<<"层序遍历的结果为： "<<endl;
        for(vector<int> subResult : result){
            for(int i : subResult) os<<i<<" ";
            os<<endl;
        }
        return os;
    }
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL) return NULL;
        if(root->val < low) return trimBST(root->right, low, high);
        if(root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
int main(){
    TreeNode *root = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(28);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    cout<<root<<endl;
    Solution stl;
    cout<<stl.trimBST(root, 3, 9)<<endl;;
}