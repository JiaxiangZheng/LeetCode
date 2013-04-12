/*
    http://leetcode.com/onlinejudge#question_105

    Given preorder and inorder traversal of a tree, construct the binary tree.
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
    // directly recursive using this interface might incur memory exceed.
    // so we can indirectly call another function
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return _buildTree(&preorder[0], &inorder[0], preorder.size());
    }

private:
    TreeNode* _buildTree(const int *preorder, const int *inorder, int len) {
        if (len == 0) return NULL;
        else if (len == 1) return new TreeNode(*preorder);

        int splitIndex = 0;
        while (splitIndex < len && *preorder != *(inorder+splitIndex))
            splitIndex++;

        TreeNode* outNode = new TreeNode(*preorder);
        outNode->left = buildTree(preorder+1, inorder, splitIndex);
        outNode->right = buildTree(preorder+splitIndex+1, inorder+splitIndex+1, len-1-splitIndex);
        return outNode;
    }
};

