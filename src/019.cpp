/*
    http://leetcode.com/onlinejudge#question_19

    Given a linked list, remove the nth node from the end of list and return its head.

    For example,

       Given linked list: 1->2->3->4->5, and n = 2.

       After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

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
        while (cur) {
            len++; cur = cur->next;
        }
        assert (n <= len && n >= 1);
        n = len - n + 1;
        cur = head;
        if (n == 1) {   //remove the head node
            cur = cur->next;
            delete head;
            head = cur;
            return head;
        } else {
            n -= 2;     //find the previous node of the node to be deleted 
            while (n-- > 0) {
                cur = cur->next;                
            }
            ListNode* del = cur->next;
            cur->next = del->next;
            delete del;          
        }
        return head;
    }
};

