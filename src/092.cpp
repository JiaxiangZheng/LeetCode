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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // index to the m-th node

        n = n - m + 1;
    }
    ListNode* reverseN(ListNode* head, int n) {
        ListNode* tail = head;
        ListNode *prev = NULL, *cur = head;
        for (int i=1; i<n; ++i) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        tail->next = cur->next;
        return cur;
    }
};

