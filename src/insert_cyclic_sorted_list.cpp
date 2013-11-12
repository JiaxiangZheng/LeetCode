/*
    http://leetcode.com/2011/08/insert-into-a-cyclic-sorted-list.html

    Given a node from a cyclic linked list which has been sorted, write a function
    to insert a value into the list such that it remains a cyclic sorted list. The
    given node can be any single node in the list.

    1. if current value is not less than pre_node and less than cur_node
    2. if cur_node is less than pre_node (means cur_node is the minimum value
       node in the list), than weather the current value is not less than pre_node
       or less than cur_node, the new created node should be insert between
       cur_node and pre_node.
    3. if cur_node is head, then the new node should be create before head.
*/
#include <iostream>
#include <cassert>
using namespace std;

#include "link_list.h"

/**
 * Definition for singly-linked list.
 */
class Solution {
public:
    void insert(ListNode*& head, int val) {
        ListNode* node = new ListNode(val);
        // condition 1
        if (head == NULL) {
            head = node;
            head->next = head;
        }

        ListNode* cur = head;
        ListNode* pre = NULL;
        do {
            pre = cur;
            cur = cur->next;
            if (val >= pre->val && val < cur->val) break;
            if ((pre->val > cur->val) && (val < cur->val || val >= pre->val)) break;
        } while (cur != head);

        pre->next = node;
        node->next = cur;
        return;
    }
};

void print(ListNode* head) {
    ListNode* cur = head;
    do {
        printf("%d\t", cur->val);
        cur = cur->next;
    } while (cur != head);
}

#if 1
#include <ctime>
int main() {
    Solution s;
    srand(time(NULL));
    ListNode* head = NULL;
    for (int i=0; i<100; ++i) {
        int val = rand() % 100;
        printf("%d\t", val);
        s.insert(head, val);
    }
    printf("\n");
    print(head);

    return 0;
}
#endif
