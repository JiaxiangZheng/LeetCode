#include <cstdio>
#include "link_list.h"

void list_insert(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    head = new ListNode(val, head);
    return;
}

void list_print(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
        printf("%d\t", cur->val);
        cur = cur->next;
    }
    printf("\n");
    return;
}

void list_destory(ListNode* head) {
    ListNode* cur = NULL;
    while (head != NULL) {
        cur = head->next;
        delete head;
        head = cur;
    }
    return;
}

// append h2 to h1, just make h1's tail node points to h2's head
// TODO: might incur the memory leak!!! 
void list_append(ListNode* h1, ListNode* h2) {
    ListNode* tail = h1;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = h2;
}

ListNode* list_reverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *pre = NULL, *cur = head, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// return head and tail
static std::pair<ListNode*, ListNode*> _merge_list(ListNode* a, ListNode* b) {

}
void merge_sort(ListNode*& head, ListNode*& tail) {
    if (head == NULL || head == tail) {
        return head;
    }
    auto l = merge_sort(head->next, );
}

int main() {
    ListNode *h1 = NULL;
    for (int i=0; i<20; ++i) {
        list_insert(h1, 2*i + 1);
    }
    list_print(h1);

    ListNode *h2 = NULL;
    for (int i=0; i<10; ++i) {
        list_insert(h2, 2*i);
    }
    list_print(h2);

    ListNode* h3 = NULL;
    for (int i=0; i<10; ++i) {
        list_insert(h3, 100 + 2*i);
    }

    list_append(h1, h3);
    list_append(h2, h3);
    list_print(h1);
    list_print(h2);

    return 0;
}

