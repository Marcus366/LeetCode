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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head, *p = NULL;
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
            
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                if (p == NULL)
                    head = p = l1;
                else {
                    p->next = l1;
                    p = p->next;
                }
                l1 = l1->next;
            }   else {
                if (p == NULL)
                    head = p = l2;
                else {
                    p->next = l2;
                    p = p->next;
                }
                l2 = l2->next;
            }
        }
        if (l1 != NULL) p->next = l1;
        if (l2 != NULL) p->next = l2;
        return head;
    }
};