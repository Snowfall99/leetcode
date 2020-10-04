#include <queue>
#include <vector>
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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        int odd_or_even;

        if (root->val % 2 == 0) return false;

        queue<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            if (level % 2 == 0) odd_or_even = 1;
            else odd_or_even = 0; 


            vector<TreeNode*> vec;
            while (!stk.empty()) {
                vec.push_back(stk.front());
                stk.pop();
            }
            int len = vec.size();
            for (int i=0; i<len-1; i++) {
                if (level % 2 == 0) {
                    if (vec[i]->val >= vec[i+1]->val) return false;
                } else {
                    if (vec[i]->val <= vec[i+1]->val) return false;
                }
            }
            for (int i=0; i<len; i++) {
                if (odd_or_even == 1 && vec[i]->val % 2 == 0) return false;
                if (odd_or_even == 0 && vec[i]->val % 2 == 1) return false;
                if (vec[i]->left) stk.push(vec[i]->left);
                if (vec[i]->right) stk.push(vec[i]->right);
            }
            level++;
        }
        return true;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    Solution s;
    bool b = s.isEvenOddTree(root);
    if (b) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}