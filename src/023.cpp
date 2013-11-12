/*
    http://leetcode.com/onlinejudge#question_23

    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.empty()) return NULL;
        ListNode* curList = lists[0];
            
        for (int i=1; i<lists.size(); ++i) {
            curList = mergeLists(curList, lists[i]);
        }
        return curList;
    }
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        if (l1->val <= l2->val) {
            l3 = l1; l1 = l1->next;            
        } else {
            l3 = l2; l2 = l2->next;
        }
        ListNode *cur = l3;
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
        if (l2) cur->next = l2;
        return l3;
    }
};

