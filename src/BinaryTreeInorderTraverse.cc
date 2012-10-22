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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> out;
        _inorderTraversal(root, out);
        return out;
    }
    
private:
    void _inorderTraversal(TreeNode *node, vector<int>& out)
    {
        if (node == NULL) return;
        _inorderTraversal(node->left, out);
        out->push_back(node->val);
        _inorderTraversal(node->right, out);
    }
};

