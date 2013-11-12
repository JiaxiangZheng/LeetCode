/*
 * =====================================================================================
 *
 *       Filename:  reconstructBT.cc
 *
 *    Description:  Reconstruct a Binary Tree using the preorder and inorder
 *                  sequence.
 *
 *        Version:  1.0
 *        Created:  2012/10/27 10:32:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */
struct BNode
{
    BNode  *left, *right;
    char data;
    BNode(char _data) : data(_data) {}
};
BNode* reconstruct(const char* preOrder, int preLeft, int preRight,
                   const char* inOrder, int inLeft, int inRight)
{
    if (preRight - preLeft == 1)  return new BNode(preOrder[preLeft]);
    char root_val = preOrder[preLeft]; 
    int pos;
    for (int pos=inLeft; pos<inRight; ++pos) 
        if (root_val == inOrder[pos]) break;
    assert(pos < inRight);
    int preLength = pos - inLeft;
}
