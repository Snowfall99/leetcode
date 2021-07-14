/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getLength(ListNode* head) {
        int result = 0;
        while (head) {
            head = head->next;
            result ++;
        }
        return result;
    }

    TreeNode* helper(ListNode*& head, int left, int right) {
        if (left > right)
            return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode();
        root->left = helper(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = helper(head, mid + 1, right);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = getLength(head);
        printf("%d\n", size);
        return helper(head, 0, size - 1);
    }
};