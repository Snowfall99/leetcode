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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto result = vector<vector<int>>();
        queue<TreeNode*> que;
        if (!root) {
            return result;
        }

        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            auto temp = vector<int>();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) 
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(temp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};