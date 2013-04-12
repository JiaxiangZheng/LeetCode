/*
    http://leetcode.com/onlinejudge#question_101      

    Given a binary tree, check whether it is a mirror of itself (ie, symmetric
    around its center
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        return _isMirror(root->left, root->right);
    }
private:
    bool _isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return (left->val == right->val) && 
                _isMirror(left->left, right->right) &&
                _isMirror(left->right, right->left);
    }
};

