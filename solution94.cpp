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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        if (root->left) {
            vector<int> left = inorderTraversal(root->left);
            for (int i=0; i<left.size(); i++) {
                result.push_back(left[i]);
            }
        }
        result.push_back(root->val);
        if (root->right) {
            vector<int> right = inorderTraversal(root->right);
            for (int i=0; i<right.size(); i++) {
                result.push_back(right[i]);
            }
        }
        return result;
    }
};