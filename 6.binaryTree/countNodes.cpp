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
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        queue<TreeNode*> que;
        que.push(root);
        int size;
        while(!que.empty()){
            size=que.size();
            count += size;
            for(int i=0;i<size;i++){
                TreeNode* front = que.front();
                que.pop();
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
        }
        return count;
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
    cout<<stl.countNodes(root)<<endl;;
}