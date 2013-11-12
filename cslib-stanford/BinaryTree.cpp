/*
 * =====================================================================================
 *
 *       Filename:  BinaryTree.cpp
 *
 *    Description:  binary trees basic operations
 *
 *        Version:  1.0
 *        Created:  2013/4/7 20:45:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct BTNode {
    int value;
    BTNode* left;
    BTNode* right;
    BTNode(int v = 0, BTNode* l_ptr = NULL, BTNode* r_ptr = NULL) 
        : value(v), left(l_ptr), right(r_ptr) {}
};
typedef BTNode CycleDualLinkListNode;
bool checkBST(BTNode* root, int low, int high) {
    if (root == NULL) return true;
    if (root->value >= low && root->value <= high) {
        return checkBST(root->left, low, root->value) && checkBST(root->right, root->value, high);
    }
    return false;
}
bool isBST(BTNode* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}
BTNode* constructBST(int* data, int left, int right) {
    if (left > right) return NULL;
    if (left == right) return new BTNode(data[left]);
    int mid = left + ((right-left)>>1);
    return new BTNode(data[mid], constructBST(data, left, mid-1), constructBST(data, mid+1, right));
}
void inorderPrint(BTNode* root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->value);
    inorderPrint(root->right);
}
void preorderPrint(BTNode* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    preorderPrint(root->left);
    preorderPrint(root->right);
}
CycleDualLinkListNode* convert2List(BTNode* root) {
    if (!root) {
        return root;
    }
	if (!root->left && !root->right) {
		root->left = root; root->right = root;
		return root;
	}
	CycleDualLinkListNode* leftList = convert2List(root->left);
    CycleDualLinkListNode* rightList = convert2List(root->right);
    root->left = root; root->right = root;
    if (!leftList) leftList = root;
    else {
        leftList->left->right = root;
        root->left = leftList->left;
        root->right = leftList;
        leftList->left = root;
    }
    if (rightList) {
        CycleDualLinkListNode* lTail = leftList->left;
        CycleDualLinkListNode* rTail = rightList->left;
        rTail->right = leftList; leftList->left = rTail;
        rightList->left = lTail; lTail->right = rightList;
    }
    return leftList;
}
void printList(BTNode* root) {
	if (root == NULL) return;
	printf("%d\t", root->value);
    for (BTNode* cur = root->right; cur != root; cur = cur->right) {
        printf("%d\t", cur->value);
    }
    printf("\n");
}
#include <ctime>
#include <stack>>
void zigZagTraverse(BTNode* root) {
    // use 2 stacks
    std::stack<BTNode*> S[2]; //---->   <----
    S[0].push(root);
    int curLevelIndex = 0;
    while (!S[0].empty() || !S[1].empty()) {
        BTNode* curNode = S[curLevelIndex].top();
        S[curLevelIndex].pop();
        printf("%d ", curNode->value);
        if (curLevelIndex == 0) {
            if (curNode->left) S[1-curLevelIndex].push(curNode->left);
            if (curNode->right) S[1-curLevelIndex].push(curNode->right);
        } else {
            if (curNode->right) S[1-curLevelIndex].push(curNode->right);
            if (curNode->left) S[1-curLevelIndex].push(curNode->left);
        }

        if (S[curLevelIndex].empty()) {
            curLevelIndex = 1 - curLevelIndex;
            printf("\n");
        }
    }
    return ;
}
#include <queue>
void levelTraverse(BTNode* root) {
    std::queue<BTNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BTNode* node = Q.front(); Q.pop();
        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
        printf("%d ", node->value);
    }
    return;
}

void convert2Mirror(BTNode* root) {
    if (!root) return;
    BTNode* swap_node = root->right;
    root->right = root->left;
    root->left = swap_node;
    convert2Mirror(root->left);
    convert2Mirror(root->right);
}

int main() {
    srand(time(NULL));
    int n = 64;
    int* data = new int[n];
    for (int i=0; i<n; ++i) { 
        data[i] = rand() % 100;
    }
    for (int i=0; i<n; ++i) printf("%d ", data[i]);
    printf("\n");
    BTNode* tree_root = constructBST(&data[0], 0, n-1);
    printf("\n*******************************************************************************\n");
    zigZagTraverse(tree_root);
    printf("\n*******************************************************************************\n");
    delete []data;
    return 0;
}

