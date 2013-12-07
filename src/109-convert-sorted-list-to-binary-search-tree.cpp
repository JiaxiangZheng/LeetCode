/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        int n = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            n++;
            cur = cur->next;
        }
        if (n > 0) return sortedListToBST(head, 0, n-1);
        else return NULL;
    }
    TreeNode* sortedListToBST(ListNode*& head, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* l = sortedListToBST(head, left, mid - 1);
        TreeNode* cur = new TreeNode(head->val);
        head = head->next;
        cur->left = l;
        cur->right = sortedListToBST(head, mid + 1, right);
        return cur;
    }
};

