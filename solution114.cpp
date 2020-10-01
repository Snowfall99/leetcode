// 前序遍历，利用栈
#include <stack>
#include <iostream>
using namespace std;
// Definition for a binary tree node.
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
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* cur;
        TreeNode* prev= NULL;
        while (!stk.empty()) {
            cur = stk.top();
            stk.pop();
            if (prev) {
                prev->right = cur;
                prev->left = NULL;
            }
            if (cur->right) {
                stk.push(cur->right);
            }
            if (cur->left) {
                stk.push(cur->left);
            }
            prev = cur;
        }
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    Solution s;
    s.flatten(root);
    while(root != NULL) {
        cout<<root->val<<"\t";
        root = root->right;
    }
    return 0;
}