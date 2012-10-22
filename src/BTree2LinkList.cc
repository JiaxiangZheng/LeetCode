#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
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
        if (root) getList(root);
    }
private:
    TreeNode* getList(TreeNode* root)
    {
        if (root->left && root->right)
        {
            TreeNode* tail = getList(root->right);
            //root->right = root->left;
            (getList(root->left))->right = root->right;
            root->right = root->left;
            return tail;
        }
        else if (root->left)
        {
            root->right = root->left;
            return getList(root->left);
        }
        else if (root->right)
            return getList(root->right);
        else return root;
    }
};
#if 0
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void insertBST(int val, TreeNode*& root)
{
    if (!root) {
        root = new TreeNode(val);
        return;
    }
    TreeNode* node = new TreeNode(val);
    TreeNode* pre = NULL;
    TreeNode* cur = root;
    while (cur)
    {
        pre = cur;
        if (cur->val > val) cur = cur->left;
        else cur = cur->right;
    }
    if (pre->val > val) pre->left = node;
    else pre->right = node;
    return;
}
TreeNode* createBSTree(const vector<int>& arr)
{
    TreeNode* root = NULL;
    for (int i=0; i<arr.size(); ++i)
    {
        insertBST(arr[i], root);
    }
    return root;
}
void releaseBST(TreeNode* root)
{
    if (root->left) releaseBST(root->left);
    if (root->right) releaseBST(root->right);
    delete root;
    return;
}

void preorderBST(TreeNode* root)
{
    printf("%d ", root->val);
    if (root->left) preorderBST(root->left);
    if (root->right) preorderBST(root->right);
}


int main()
{
    std::vector<int> arr(100);
    for (int i=0; i<100; ++i) arr[i] = rand()%1000;
    printf("\n");
    TreeNode* root = createBSTree(arr);
    Solution solver;
    solver.flatten(root);
    TreeNode* node = root;
    for (int i=0; i<arr.size(); ++i)
        printf("%d ", node->val), node = node->right;
    return 0;
}
#endif
