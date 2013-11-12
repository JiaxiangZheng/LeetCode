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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *lessList = NULL, *greaterList = NULL;
        ListNode* curLess = NULL, *curGreater = NULL;
        while (head != NULL) {
            if (head->val < x) {
                if (lessList == NULL) {
                    lessList = head;
                    curLess = lessList;
                } else {
                    curLess->next = head;
                    curLess = curLess->next;
                }
            } else {
                if (greaterList == NULL) {
                    greaterList = head;
                    curGreater = greaterList;
                } else {
                    curGreater->next = head;
                    curGreater = curGreater->next;
                }
            }
            head = head->next;
        }
        if (curGreater) curGreater->next = NULL;
        if (curLess) curLess->next = NULL;
        if (curLess == NULL) return greaterList;
        else {
            curLess->next = greaterList;
            return lessList;
        }
    }
};


