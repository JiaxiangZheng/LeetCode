/* Given a binary search tree (BST), find the lowest common ancestor of two
 * given nodes in the BST.
 */

class BNode { 
    BNode* left; 
    BNode* right; 
    int value; 
};

/* We assume this function is used for binary search tree, and the next function
 * is used for common binary tree
 */
const BNode* getCommonAnc(const BNode* root, const BNode* A, const BNode* B) 
{
    if (!root || !A || !B) return NULL;
    if (std::max(A->value, B->value) < root->value)
        return getCommonAnc(root->left, A, B);
    else if (std::min(A->value, B->value) > root->value)
        return getCommonAnc(root->right, A, B);
    else return root;
}

/* for binary tree version */
const BNode* getCommonAnc(const BNode* root, const BNode* A, const BNode* B)
{
    if (!root || !A || !B) return NULL;
    const BNode* p = getCommonAnc(root->left, A, B);
    const BNode* q = getCommonAnc(root->right, A, B);
    if (p && q) return root;
    else return p == NULL ? getCommonAnc(root->right, A, B) 
                            : getCommonAnc(root->left, A, B);
}
