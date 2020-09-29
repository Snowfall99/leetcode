#include<iostream>
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> nodelist;
        Node* cur = root;
        Node* next = NULL;
        int levelSize = 0;
        nodelist.push(root);
        while (!nodelist.empty()) {
            levelSize = nodelist.size();
            for (int i=0; i<levelSize; i++) {
                cur = nodelist.front();
                nodelist.pop();
                if (i != levelSize-1) {
                    next = nodelist.front();
                    cur->next = next;
                } else {
                    cur->next = NULL;
                }
                if (cur->left) nodelist.push(cur->left);
                if (cur->right) nodelist.push(cur->right);
            }
        }

        return root;
    }
};
