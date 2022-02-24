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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int max = INT_MIN;
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        TreeNode* root = new TreeNode(max);
        vector<int> leftNums(nums.begin(), nums.begin()+index);
        vector<int> rightNums(nums.begin()+index+1, nums.end());
        root->left = constructMaximumBinaryTree(leftNums);
        root->right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};

int main(){
    vector<int> inorder = {3,2,1,6,0,5};
    Solution stl;
    stl.constructMaximumBinaryTree(inorder);
}