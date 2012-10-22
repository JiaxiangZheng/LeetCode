/** 
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
       if (num.empty()) return NULL;
       TreeNode* root = NULL;
       root = arrayToBSTRecursive(num, 0, num.size()-1);
       return root;
    }
    TreeNode* arrayToBSTRecursive(vector<int>& num, int left, int right)
    {
        if (left >= right)
            return new TreeNode(num[left]);
        TreeNode* root = new TreeNode(num[(left+right)>>1]);
        root->left = arrayToBSTRecursive(num, left, (left+right)>>1-1);
        root->right = arrayToBSTRecursive(num, (left+right)>>1+1, right);
        return root;
    }
};

