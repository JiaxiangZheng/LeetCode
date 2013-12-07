/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int>> out;
        if (root == NULL) return out;
        std::stack<TreeNode*> cur, next;
        std::stack<TreeNode*> *pcur = &cur, *pnext = &next;
        pcur->push(root);
        int left2right = 1;
        std::vector<int> lout;
        while (!pcur->empty()) {
            TreeNode* top = pcur->top(); pcur->pop();
            lout.push_back(top->val);
            if (left2right) {
                if (top->left) pnext->push(top->left);
                if (top->right) pnext->push(top->right);
            } else {
                if (top->right) pnext->push(top->right);
                if (top->left) pnext->push(top->left);
            }

            if (pcur->empty()) {  // swap
                std::swap(pcur, pnext);
                left2right = 1 - left2right;
                out.push_back(lout);
                lout.clear();
            }
        }
        return out;
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<vector<int> > res;
        if (!root) return res;
        
        std::vector<int> curRes;
        std::stack<TreeNode*> S[2];
        S[0].push(root);  int leftToRight = 0; // 
        while (!S[0].empty() || !S[1].empty()) {
            TreeNode* top = S[leftToRight].top(); S[leftToRight].pop();
            curRes.push_back(top->val);
            if (leftToRight == 0) {    // 把元素从左向右放入S[1]
                if (top->left) S[1].push(top->left);
                if (top->right) S[1].push(top->right);
            } else {
                if (top->right) S[0].push(top->right);
                if (top->left) S[0].push(top->left);
            }
            if (S[leftToRight].empty()) {
                leftToRight = 1 - leftToRight;
                res.push_back(curRes); curRes.clear();
            }
        }
        return res;
    }
};

