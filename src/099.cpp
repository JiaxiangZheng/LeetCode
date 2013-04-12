/* 
    http://leetcode.com/onlinejudge#question_101      

    Two elements of a binary search tree (BST) are swapped by mistake.
    Recover the tree without changing its structure
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
        if (root == NULL) return;
        if (root->left && root->right && root->left->val > root->right->val)  {
            swap(root->left->val, root->right->val);
            return;
        }
        if (root->left) {
            if (root->left->val > root->val) {
                int temp = root->val;
                root->val = root->left->val;
                root->left->val = temp;
                return;
            } else {
                recoverTree(root->left);
            }
        }

        if (root->right) {
            if (root->right->val < root->val) {
                int temp = root->val;
                root->val = root->right->val;
                root->right->val = temp;
                return;
            } else {
                recoverTree(root->right);
            }
        }
    }
};

