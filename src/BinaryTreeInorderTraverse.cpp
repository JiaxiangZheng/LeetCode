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
        this->sequence.clear();
        this->_traverse_iterative(root);
        return this->sequence;
    }
private:
    void _traverse_recursive(TreeNode* root) {
    //4ms   16ms
        if (!root) return;
        _traverse_recursive(root->left);
        sequence.push_back(root->val);
        _traverse_recursive(root->right);
    }
    void _traverse_iterative(TreeNode* root) {
    //8ms   12ms
		stack<TreeNode*> s;
		TreeNode *current = root;
		while (!s.empty() || current) {
			if (current) {
				s.push(current);
				current = current->left;
			} else {
				current = s.top();
				s.pop();
				sequence.push_back(current->val);
				current = current->right;
			}
		}
    }
    std::vector<int> sequence;
};

