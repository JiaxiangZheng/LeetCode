#ifndef TREAP_H
#define TREAP_H
#include <cstdlib>
#include <cstdio>

#define NULL 0
struct Node {
    int key; 
    int priority;  // rand generate  
    Node *left, *right;
    Node(int _key = 0, int _priority = 0,
        Node* _left = 0, Node* _right = 0) 
        : left(_left), right(_right) {
    }
};
class Treap {
public:
    Treap() : root_(0), size_(0) {}
    size_t size() const { return size_;}
    const Node* root() const { return root_; }
    int height() { return _height(root_); }

    Node* find(int key, Node* p = NULL);
    bool insert(int key);
    void remove(int key);
    void clear();

    void inorder_traverse(const Node* node) {
        if (!node) return;
        inorder_traverse(node->left);
        printf("%d ", node->key); 
        inorder_traverse(node->right);
        return;
    }
    void preorder_traverse(const Node* node) {
        if (!node) return;
        printf("%d ", node->key); 
        preorder_traverse(node->left);
        preorder_traverse(node->right);
        return;
    }
private:
    int _height(Node* root);
    Node* _left_rot(Node* node);
    Node* _right_rot(Node* node);
    Node* _insert(Node* node, int key, bool& exist_flag);
    Node* _remove(Node* node, int key);
    void _clear(Node*& node);
private:
    Node* root_;
    int size_;
};

#endif/* TREAP_H */

