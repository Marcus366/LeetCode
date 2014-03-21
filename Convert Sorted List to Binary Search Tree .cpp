/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        return sortedListToBSTr(head, length(head));
    }
    
    TreeNode *sortedListToBSTr(ListNode *head, int len) {
        if (len == 0) return NULL;
        ListNode *mid = getAtIndex(head, len / 2);
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBSTr(head, len / 2);
        root->right = sortedListToBSTr(mid->next, len - len / 2 - 1);
        return root;
    }
    
    ListNode *getAtIndex(ListNode* head, int index) {
        for (int i = 0; i < index && head; ++i) {
            head = head->next;
        }
        return head;
    }
    
    int length(ListNode *head) {
        int len = 0;
        while (head) ++len, head = head->next;
        return len;
    }
};