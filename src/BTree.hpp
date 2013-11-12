template <typename ElemType>
class BNode;

template <typename ElemType>
class BinaryTree {
public:
    BNode<ElemType>* root;
    template <typename Func>
    void traverseInorder(Func fun) {
        traverseInorder();
        fun(root->val);
    }

private:
    void _traverseInorder(Func fun, BNode<ElemType>* root) {
        if (!root) return;
        _traverseInorder(fun, root->left);
        fun(root->val);
    }
};
