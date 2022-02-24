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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0) return NULL;
        int cur = postorder[postorder.size()-1];   //后序遍历最后一个节点是跟节点
        TreeNode* root = new TreeNode(cur);

        //在中序遍历中找到根节点的索引值
        int index;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==cur){
                index=i;
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin()+index);
        vector<int> rightInorder(inorder.begin()+index+1, inorder.end());
        vector<int> leftPosterorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPosterorder(postorder.begin()+leftInorder.size(), postorder.begin()+postorder.size()-1);

        root->left = buildTree(leftInorder, leftPosterorder);
        root->right = buildTree(rightInorder, rightPosterorder);
        return root;
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    Solution stl;
    stl.buildTree(inorder, postorder);
}