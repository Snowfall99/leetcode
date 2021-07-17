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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
        if (k == 0) {
            return head;
        }

        ListNode* p = head;
        int length = 1;
        while (p->next != nullptr) {
            p = p->next;
            length ++;
        }
        p->next = head;
        for (int i = 0; i < length - k % length; i ++) {
            p = p->next;
        }
        ListNode* result = p->next;
        p->next = nullptr;
        return result;
    }
};