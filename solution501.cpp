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
    TreeNode* pre;
    int count;
    int maxCount;
    vector<int> result;

    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return result;
    }

    void traverse(TreeNode* curr) {
        if (curr == nullptr) {
            return;
        }
        traverse(curr->left);
        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == curr->val) {
            count ++;
        } else {
            count = 1;
        }
        pre = curr;
        if (count == maxCount) {
            result.push_back(curr->val);
        }
        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(curr->val);
        }
        traverse(curr->right);
    }
};
