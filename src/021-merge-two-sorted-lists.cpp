/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        ListNode* newHead = NULL;
        if (l1->val <= l2->val) {
            newHead = l1;
            l1 = l1->next;
        } else {
            newHead = l2;
            l2 = l2->next;
        }

        ListNode *cur = newHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        else cur->next = l2;
        return newHead;
    }
};

int main() {

    return 0;
}
