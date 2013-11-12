/*  Check if a binary tree is balanced.
 *
 *  Run Status: Accepted!
 *  Program Runtime: 8 milli secs
 *
 *  Run Status: Accepted!
 *  Program Runtime: 128 milli secs
 *
 *  comment : I think there is a better way to reduce the repeat checking
 *  subtree.
 */

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        int hl = _height(root->left);
        int hr = _height(root->right);
        if (abs(hl-hr)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }    
private:
    int _height(TreeNode* root)
    {
        if (!root) return 0;
        return std::max(_height(root->left), _height(root->right))+1;
    }
};
