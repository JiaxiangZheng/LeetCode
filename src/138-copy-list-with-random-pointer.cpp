/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return NULL;
        RandomListNode* cur = head;
        while (cur) {
            RandomListNode* next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head; 
        RandomListNode* res = head->next;
        while (cur) {
            RandomListNode* next = cur->next; 
            cur->next = next->next;
            if (next->next) next->next = next->next->next;
            else break;
            cur = cur->next;
        }
        return res;
    }
};

