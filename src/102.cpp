/* 
    Binary Tree Level Order Traversal
    http://leetcode.com/onlinejudge#question_102

    Given a binary tree, return the level order traversal of its nodes' values.
    (ie, from left to right, level by level)
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
    vector< vector<int> > levelOrder(TreeNode *root) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector< std::vector<int> > orderResult;
        if (root == NULL) return orderResult;
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        orderResult.push_back(std::vector<int>());
        while (!Q.empty()) {
            if (Q.front() == NULL) { //
                orderResult.push_back(std::vector<int>());
                Q.pop();
                continue;
            }
            TreeNode* frontNode = Q.front(); Q.pop();
            if (frontNode->left) Q.push(frontNode->left);
            if (frontNode->right) Q.push(frontNode->right);
            if (Q.front() == NULL) Q.push(NULL);
            orderResult.back().push_back(frontNode->val);
        }
        orderResult.erase(orderResult.end()-1);
        orderResult.erase(orderResult.end()-1);
        return orderResult;
    }
};

