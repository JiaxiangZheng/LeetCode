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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return validBST(root, INT_MIN, INT_MAX);        
    }
    bool validBST(TreeNode* root, int min, int max) {
        if (!root) return true;
        if (root->val > min && root->val < max) {
            return validBST(root->left , min, root->val) 
                && validBST(root->right, root->val, max);
        }
        return false;
    }
};

