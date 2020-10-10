/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *fast = head, *slow = head;
        while (fast != NULL) {
            slow = slow->next;
            if (fast->next == NULL) {
                return NULL;
            } 
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }
        return NULL;
    }
};