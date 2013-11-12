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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int H;
        return isBalanced(root, H);
    }
    bool isBalanced(TreeNode* root, int& height) {
        if (root == NULL) {
            height = 0; return true;
        } else {
            int lH = 0, rH = 0;
            if (NULL == isBalanced(root->left, lH)) return false;
            if (NULL == isBalanced(root->right, rH)) return false;
            height = max(lH, rH) + 1;
            if (abs(lH - rH) > 1) return false;
            else return true;
        }
    }
};

