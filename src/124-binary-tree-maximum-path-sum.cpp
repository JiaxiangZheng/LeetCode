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
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxPath = -999999;
        maxPathSum(root, maxPath);
        return maxPath;
    }
    int maxPathSum(TreeNode *root, int& maxPath) {
        if (!root) return 0;
        int maxLeft = max(0, maxPathSum(root->left, maxPath));
        int maxRight = max(0, maxPathSum(root->right, maxPath));
        maxPath = std::max(maxPath, maxLeft + maxRight + root->val);
        return max(maxLeft, maxRight) + root->val;
    }
};

