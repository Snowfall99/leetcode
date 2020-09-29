#include<iostream>
#include<vector>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        if (root->left != NULL) {
            vector<int> left = postorderTraversal(root->left);
            for (int i=0; i<left.size(); i++) {
                result.push_back(left[i]);
            }
        }
        if (root->right != NULL) {
            vector<int> right = postorderTraversal(root->right);
            for (int i=0; i<right.size(); i++) {
                result.push_back(right[i]);
            }
        }
        result.push_back(root->val);
        return result;
    }
};