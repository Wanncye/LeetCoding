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
    void traversal(TreeNode* node, vector<string>& result, vector<int>& path){
        path.push_back(node->val);
        if(node->left==NULL && node->right==NULL){
            string str="";
            for(int i=0; i<path.size()-1; i++) str += to_string(path[i]) + "->";
            str += to_string(path[path.size()-1]);
            cout<<str<<endl;
            result.push_back(str);
        }
        if(node->left){
            traversal(node->left, result, path);
            path.pop_back();
        }
        if(node->right){
            traversal(node->right, result, path);
            path.pop_back();
        }    
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL) return result;
        traversal(root, result, path);
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;
    Solution stl;
    stl.binaryTreePaths(root);
}