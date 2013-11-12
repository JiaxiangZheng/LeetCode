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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            cur = cur->next; len++;
        }
        if (n > len || n <= 0) return NULL;
        
        int step = len - n + 1;
        cur = head; ListNode* pre = NULL;
        for (int i=1; i<step; ++i) {
            pre = cur;
            cur = cur->next; 
        }
        if (pre == NULL) return cur->next;
        else {
            pre->next = cur->next;
            return head;
        }
    }
};


/* 
 * fast and slow pointer
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 0) return NULL;
        ListNode *fast = head, *slowPrev = NULL;
        for (int i=1; i<n; ++i) {
            fast = fast->next;
            if (fast == NULL) return NULL;
        }
        
        if (fast->next == NULL) return head->next;
        slowPrev = head; fast = fast->next;
        while (fast->next != NULL) {
            fast = fast->next;
            slowPrev = slowPrev->next;
        }
        slowPrev->next = slowPrev->next->next;
        return head;
    }
};

