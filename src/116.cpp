/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        std::queue<TreeLinkNode*> Q;
        Q.push(root); Q.push(NULL);
        while (!Q.empty()) {
            TreeLinkNode* cur = Q.front(); Q.pop();
            if (cur != NULL) {
                cur->next = Q.front();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            } else {
                if (Q.empty()) break;
                Q.push(NULL);
            }
        }
        return;
    }
};



/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        if (root->left) root->left->next = root->right;
        if (root->right) 
            root->right->next = (root->next == NULL) ? NULL : (root->next->left);
        connect(root->left);
        connect(root->right);
    }
};

