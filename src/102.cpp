/* 
    Binary Tree Level Order Traversal
    http://leetcode.com/onlinejudge#question_102

    Given a binary tree, return the level order traversal of its nodes' values.
    (ie, from left to right, level by level)
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<TreeNode*> l;
        std::vector<int> vals;
        inorder(root, l, vals);
        std::sort(vals.begin(), vals.end());
        for (int i=0; i<l.size(); ++i) {
            l[i]->val = vals[i];
        }
    }
    void inorder(TreeNode* root, std::vector<TreeNode*>& l, std::vector<int>& val) {
        if (root == NULL) return;
        inorder (root->left, l, val);
        l.push_back(root); val.push_back(root->val);
        inorder (root->right, l, val);
        return;
    }
};

