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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return mDepth(root);
    }
    int mDepth(TreeNode* root) {
        if (root == NULL) return 0;
        else if ((!root->left && root->right)) { 
            return mDepth(root->right) + 1;
        } else if ((!root->right && root->left)) {
            return mDepth(root->left) + 1;
        } else return std::min(mDepth(root->left), mDepth(root->right)) + 1;
    }
};

