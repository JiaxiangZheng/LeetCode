/* =====================================================================================
 * 
 *       Filename:  copyRandList.cpp
 * 
 *    Description:  copy a link list with a next pointer and a random pointer
 *                  field
 *           Link:  http://tech-queries.blogspot.com/2011/04/copy-linked-list-with-next-and-random.html
 *        Version:  1.0
 *        Created:  2013/4/9 9:24:11
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 * 
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
using namespace std;

struct LinkNode {
    int val;
    LinkNode* next_ptr;
    LinkNode* rand_ptr;
    LinkNode(int _v, LinkNode* pn = NULL, LinkNode* pr = NULL) 
        : val(_v), next_ptr(pn), rand_ptr(pr)
    {}
};

void reverseList(LinkNode*& head) {
    LinkNode* cur = head;
    LinkNode* pre = NULL;
    while (cur != NULL) {
        LinkNode* next = cur->next_ptr;
        cur->next_ptr = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
    return;
}
LinkNode* buildList(const std::vector<int>& vals) {
    assert (!vals.empty());
    std::vector<LinkNode*> addressTable; addressTable.reserve(vals.size());
    LinkNode* head = new LinkNode(vals[0]); addressTable.push_back(head);
    for (int i=1; i<vals.size(); ++i) {
        head->next_ptr = new LinkNode(vals[i]);
        head = head->next_ptr;
        addressTable.push_back(head);
    }
    srand(time(NULL));
    for (int i=0; i<vals.size(); ++i) {
        int rnd = rand() % vals.size();
        addressTable[i]->rand_ptr = addressTable[rnd];
    }
    return addressTable[0];
}

void releaseList(LinkNode* head) {
    while (head) {
        LinkNode* next = head->next_ptr;
        delete head;
        head = next;
    }
    return;
}

void printList(LinkNode* head) {
    while (head) {
        LinkNode* next = head->next_ptr;
        printf("%d\t%d\t%d\n", head->val, head->next_ptr, head->rand_ptr);
        head = next;
    }
    printf("\n");
    return;
}

LinkNode* copyList(LinkNode* head) {
    LinkNode* cur = head;
    while (cur) {
        LinkNode* next = cur->next_ptr;
        LinkNode* newNode = new LinkNode(cur->val, cur->next_ptr, cur->rand_ptr);
        cur->next_ptr = newNode;
        cur = newNode->next_ptr;
    }
    cur = head; 
    while (cur) {
        cur->next_ptr->rand_ptr = cur->rand_ptr->next_ptr;
        cur = cur->next_ptr->next_ptr;
    }
    LinkNode* copy_head = head->next_ptr;
    cur = head;
    LinkNode* next = cur->next_ptr;
    while (cur && next) {
        cur->next_ptr = cur->next_ptr->next_ptr;
        cur = cur->next_ptr;
        if (next->next_ptr) {
            next->next_ptr = next->next_ptr->next_ptr;
            next = next->next_ptr;
        }
    }
    return copy_head;
}

/* http://tech-queries.blogspot.com/2010/03/swap-adjacent-element-in-link-list.html */
void swapAdjacentNode(LinkNode*& head) {
    if (head == NULL || head->next_ptr == NULL) return;
    LinkNode* cur = head; head = cur->next_ptr;
    while (cur && cur->next_ptr) {
        LinkNode* next = cur->next_ptr;
        LinkNode* nnext = next->next_ptr;
        next->next_ptr = cur;
        if (nnext) {
            if (nnext->next_ptr != NULL)
                cur->next_ptr = nnext->next_ptr;
            else cur->next_ptr = nnext;
        }
        else cur->next_ptr = nnext;
        cur = nnext;
    }
    return;
}

int main() {
    std::vector<int> Vs(21);
    for (int i=0; i<Vs.size(); ++i) Vs[i] = i;
    LinkNode* L1 = buildList(Vs);
    printList(L1);

    LinkNode* L2 = copyList(L1);
    printList(L2);

    swapAdjacentNode(L1);
    printList(L1);
    releaseList(L1);

    return 0;
}



struct MySpecialNode : public LinkNode{
    LinkNode* twin_ptr;
    MySpecialNode(int val) : LinkNode(val), twin_ptr(0) {}
};

void copyRandomList() {
}
