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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        getSummation(root);
        int sum = 0;
        addNumbers(root, sum);
        return sum;
    }
    void addNumbers(TreeNode* root, int& sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) sum += root->val;
        if (root->left) addNumbers(root->left, sum);
        if (root->right) addNumbers(root->right, sum);
    }
    void getSummation(TreeNode *root) {
        if (root == NULL) return;
        if (root->left) root->left->val += 10*root->val;
        if (root->right) root->right->val += 10*root->val;
        getSummation(root->left);
        getSummation(root->right);
        return;
    }
private:
};

