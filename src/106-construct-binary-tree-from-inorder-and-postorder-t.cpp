/*
    http://leetcode.com/onlinejudge#question_105

    Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty()) return NULL;
        return buildTree(&inorder[0], &postorder[0], inorder.size());     
    }
    TreeNode* buildTree(int* inorder, int* postorder, int len) {
        if (len == 0) {
            return NULL;
        } else if (len == 1) {
            assert(*inorder == *postorder);    
            return new TreeNode(*inorder);
        }
        int rootVal = postorder[len-1];
        TreeNode* newNode = new TreeNode(rootVal);
        int rootIndex = 0;
        while (rootIndex < len && inorder[rootIndex] != rootVal) rootIndex++;
        assert (rootIndex < len);
        newNode->left = buildTree(inorder, postorder, rootIndex);
        newNode->right = buildTree(inorder+rootIndex+1, postorder+rootIndex, len - 1 - rootIndex);
        return newNode;
    }
};

