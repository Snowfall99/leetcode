/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node *pre, *head;
public:
    void midOrder(Node* root) {
        if (root == nullptr) {
            return;
        }
        midOrder(root->left);
        if (pre != nullptr) {
            pre->right = root;
        } else {
            head = root;
        }
        root->left = pre;
        pre = root;
        midOrder(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        midOrder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};