/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* next = curr->left;
                TreeNode* pre = next;
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = curr->right;
                curr->right = next;
                curr->left = nullptr;  
            }
            curr = curr->right;
        }

    }
};