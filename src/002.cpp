/*     http://leetcode.com/onlinejudge#question_2
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* newList = NULL;
        ListNode* curNode = newList;

        int add_flag = 0;
        while (l1 || l2) {
            int val = add_flag;
            if (l1) {
                val += l1->val; l1 = l1->next;
            }
            if (l2) {
                val += l2->val; l2 = l2->next;
            }
            if (val > 9) {val -= 10; add_flag = 1;}
            else add_flag = 0;

            ListNode* newNode = new ListNode(val);
            if (!curNode) { //empty list
                newList = newNode;
            } else {
                curNode->next = newNode;
            }
            curNode = newNode;
        }

        if (add_flag != 0) {
            ListNode* newNode = new ListNode(add_flag);
            if (curNode == NULL) {
                newList = newNode;
            } else {
                curNode->next = newNode;
            }
            curNode = newNode;
        }

        return newList;
    }
};
