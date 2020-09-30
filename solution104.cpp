/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int rightLength = maxDepth(root->right);
        int leftLength = maxDepth(root->left);
        if (!root->left) return 1 + rightLength;
        else if (!root->right) return 1 + leftLength;
        else return leftLength > rightLength ? 1 + leftLength : 1 + rightLength;
    }
};