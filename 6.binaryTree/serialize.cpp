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


class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "X";
        }
        auto left = "(" + serialize(root->left) + ")";
        auto right = "(" + serialize(root->right) + ")";
        return left + to_string(root->val) + right;
    }

    inline TreeNode* parseSubtree(const string &data, int &ptr) {
        ++ptr; // 跳过左括号
        auto subtree = parse(data, ptr);
        ++ptr; // 跳过右括号
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] - '0';
        }
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
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
    Codec stl;
    cout<<stl.serialize(root)<<endl;;
}