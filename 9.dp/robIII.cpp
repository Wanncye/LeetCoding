#include<iostream>
#include<vector>
#include<cmath>
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

//这个思路是错误的
// class Solution {
// public:
//     int depth;
//     vector<int> getNums(TreeNode* root){
//         vector<int> result;
//         queue<TreeNode*> que;
//         que.push(root);
//         depth = 0;
//         while(!que.empty()){
//             int size = que.size();
//             depth++;
//             for(int i=0; i<size; i++){
//                 TreeNode* tmp = que.front();
//                 if(tmp==NULL){
//                     result.push_back(0);
//                 }else{
//                     result.push_back(tmp->val);
//                     if(tmp->left || tmp->right){
//                         que.push(tmp->left);
//                         que.push(tmp->right);
//                     }
//                 }
//                 que.pop();
//             }
//             int tmpSize = pow(2,depth)-1;
//             for(int i=result.size();i<tmpSize;i++){
//                 result.push_back(0);
//             }
//         }
//         return result;
//     }

//     int rob(TreeNode* root) {
//         vector<int> nums = getNums(root);
//         for(int i:nums) cout<<i<<" ";
//         cout<<endl;
//         cout<<"depth:"<<depth<<endl;
//         vector<int> dp(depth+1, 0);
//         dp[1] = nums[0];
//         for(int i=2; i<=depth; i++){
//             int levelValue=0;
//             for(int j=pow(2,i-1)-1; j<=pow(2,i)-2; j++) levelValue += nums[j];
//             dp[i] = max(dp[i-1], dp[i-2]+levelValue);
//         }
//         for(int i=0; i<=depth; i++){
//             cout<<dp[i]<<" ";
//         }
//         cout<<endl;
//         return dp[depth];
//     }
// };

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 偷cur
        int val1 = cur->val + left[0] + right[0];
        // 不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};

int main(){
    // vector<int> nums = {3,4,5,1,3,NULL,1};
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    root->left = node1;
    node1->right = node2;
    Solution stl;
    cout<<stl.rob(root)<<endl;
}