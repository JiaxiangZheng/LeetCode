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
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = NULL, *cur = head;
        while (cur != NULL) {
            while (cur->next != NULL && cur->val == cur->next->val) {
                cur = cur->next;
            }

            if (prev == NULL) {
                head = cur;
                prev = head;
            } else {
                prev->next = cur;
                prev = cur;
            }
            if (cur != NULL) cur = cur->next;
        }
    }
};

