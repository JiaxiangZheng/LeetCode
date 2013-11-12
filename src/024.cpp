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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = head->next;
        
        ListNode *cur = head;
        while (cur->next != NULL) {
            ListNode *next = cur->next;
            ListNode *nnext = next->next;
            next->next = cur;
            if (nnext != NULL && nnext->next != NULL) {
                cur->next = nnext->next;
            } else {
                cur->next = nnext;
                break;
            }
            
            cur = nnext;
        }
        return newHead;
    }
};

