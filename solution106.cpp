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
private:
    unordered_map<int, int> index;
public:
    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, int postorder_left, int postorder_right, int inorder_left, int inorder_right) {
        if (postorder_left > postorder_right) {
            return nullptr;
        }

        int inorder_root = index[postorder[postorder_right]];
        int size_right_subtree = inorder_right - inorder_root;

        TreeNode* root = new TreeNode(postorder[postorder_right]);

        root->right = myBuildTree(inorder, postorder, postorder_right - size_right_subtree, postorder_right - 1, inorder_root + 1, inorder_right);
        root->left = myBuildTree(inorder, postorder, postorder_left, postorder_right - size_right_subtree - 1, inorder_left, inorder_root -1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        for (int i = 0; i < size; i++) {
            index[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, size - 1, 0, size - 1); 
    }
};