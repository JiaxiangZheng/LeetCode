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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return toBST(&num[0], 0, num.size() - 1);
    }
    TreeNode* toBST(int* arr, int left, int right) {
        if (left > right) return NULL;
        int mid = left + ((right - left) >> 1);
        TreeNode* node = new TreeNode(arr[mid]);
        if (left == right) return node;
        node->left = toBST(arr, left, mid - 1);
        node->right = toBST(arr, mid + 1, right);
        return node;
    }
};

