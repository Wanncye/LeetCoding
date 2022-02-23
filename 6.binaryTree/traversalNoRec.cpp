#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tmp;
        tmp.push(root);
        while(!tmp.empty()){
            TreeNode* cur = tmp.top();
            tmp.pop();
            result.push_back(cur->val);
            if(cur->right != NULL) tmp.push(cur->right);
            if(cur->left != NULL) tmp.push(cur->left);
        }
        for(int i : result) cout<<i<<" ";
        cout<<endl;
        return result;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tmp;
        TreeNode *cur = root;
        while(cur!=NULL || !tmp.empty()){
            if(cur!=NULL){
                tmp.push(cur);
                cur=cur->left;
            }else{
                cur = tmp.top();
                tmp.pop();
                result.push_back(cur->val);
                cur=cur->right;
            }
        }
        for(int i : result) cout<<i<<" ";
        cout<<endl;
        return result;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> tmp;
        tmp.push(root);
        TreeNode* cur;
        while(!tmp.empty()){
            cur = tmp.top();
            tmp.pop();
            result.push_back(cur->val);
            if(cur->left != NULL) tmp.push(cur->left);
            if(cur->right != NULL) tmp.push(cur->right);
        }
        reverse(result.begin(), result.end());
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
    stl.postorderTraversal(root);
}