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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (k < 0) return NULL;
        int len = 0;
        ListNode* cur = head;
        while (cur != NULL) len++, cur = cur->next;
        if (len == 0) return NULL;
        if (k >= len) k %= len;
        if (k == 0) return head;
        ListNode* pre = head;
        for (int i=1; i<len-k; ++i) {
            pre = pre->next;
        }
        ListNode* tail = pre->next, *newHead = tail;
        pre->next = NULL;
        while (tail->next != NULL) tail = tail->next;
        tail->next = head;
        return newHead;        
    }
};

