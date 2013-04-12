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
        int k = lists.size();
        while (1) {
            
        }
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
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



const char* min_abstract(const char* text, int len_t, const char* pattern, int len_p) {
    if (len_t < len_p) return NULL;
    if (len_t == len_p && all_contain(text, len_t, pattern, len_p)) return text;

}


struct MaxStack {
    std::stack<int> S1, S2;     // data stack, max stack
    void push(int val) {
        if (S2.empty() || val >= S2.top()) {
            S2.push(val);
        }
        S1.push(val);
    }
    void pop() {
        if (S1.empty()) {
            fprintf(stderr, "pop waring: stack is already empty\n");
            return;
        }
        val = S1.top(); S1.pop();
        if (val >= S2.top()) S2.pop();
    }
    int max() {
        return S2.top();
    }
    int top() {
        return S1.top();
    }
};


