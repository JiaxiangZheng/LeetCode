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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode *pre = head, *cur = head->next;
        while (cur != NULL) {
            if (cur->val != pre->val) {
                pre->next = cur;
                pre = cur;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return head;
    }
};

