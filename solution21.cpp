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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode();
        ListNode *dummy = head;
        ListNode *l1 = list1;
        ListNode *l2 = list2;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                dummy->next = l1;
                l1 = l1->next;
                dummy = dummy->next;
            } else {
                dummy->next = l2;
                l2 = l2->next;
                dummy = dummy->next;
            }
        }
        if (l1) {
            dummy->next = l1;
        } else {
            dummy->next = l2;
        }
        return head->next;
    }
};
