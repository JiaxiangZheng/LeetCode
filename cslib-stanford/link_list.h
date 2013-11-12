#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* n = NULL) : val(x), next(n) {}
};

void list_insert(ListNode*& head, int val);
void list_print(ListNode* head); 
void list_destory(ListNode* head);
void list_append(ListNode* h1, ListNode* h2);
ListNode* list_reverse(ListNode* head); //return the head pointer

#endif/* _LINK_LIST_H_ */
