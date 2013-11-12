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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        root = convert2List(root);
    }
    TreeNode* convert2List(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *pLeft = root->left, *pRight = root->right;
        root->left = root; root->right = root;
        pLeft = convert2List(pLeft);
        pRight = convert2List(pRight);
        root = mergeList(root, pLeft);
        root = mergeList(root, pRight);
        return root;
    }
    
    TreeNode* mergeList(TreeNode* pLeft, TreeNode* pRight) {
        if (pLeft == NULL) return pRight;
        if (pRight == NULL) return pLeft;
        TreeNode *pLTail = pLeft->left, *pRTail = pRight->left;
        pLTail->right = pRight; pRight->left = pLTail;
        pRTail->right = pLeft; pLeft->left = pRTail;
        return pLeft;
    }
};


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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if (!root->left) return;
        TreeNode* p = root->left;
        while (p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return;
    }
};


