/*
    http://leetcode.com/onlinejudge#question_101      

    Given two binary trees, write a function to check if they are equal or not.
    Two binary trees are considered equal if they are structurally identical and
    the nodes have the same value.
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (p == NULL && q == NULL) return true;
        if (p == NULL || q == NULL) return false;
        return (p->val == q->val) && 
            isSameTree(p->left, q->left) && 
            isSameTree(p->right, q->right);
    }
};

