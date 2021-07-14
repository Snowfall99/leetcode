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
    TreeNode* helper(vector<int>& nums, int front, int back) {
        if (front > back) {
            return nullptr;
        }

        int mid = front + (back - front) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, front, mid - 1);
        root->right = helper(nums, mid + 1, back);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return helper(nums, 0, size - 1);
    }
};