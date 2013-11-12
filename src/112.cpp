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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return false;
        else if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        else return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

