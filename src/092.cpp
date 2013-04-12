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
        ListNode* cur = head, *pre = NULL;
        for (int i=1; i<m; ++i) {
            pre = cur; 
            cur = cur->next;
        }
        ListNode* newHead = reverse(cur, pre, n-m+1);
        if (pre == NULL) {
            head = newHead;
        }
        return head;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* pre, int length) {
        if (length <= 1) return head;
        ListNode* cur = head; 
        for (int i=0; i<length; ++i) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = cur->next;
    }    
};

