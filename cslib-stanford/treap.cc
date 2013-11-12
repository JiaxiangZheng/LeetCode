#include "treap.h"
#include <cassert>
#include <iostream>
using namespace std;

///////////////////////public functions/////////////////////////////////////////
Node* Treap::find(int key, Node* pre) {
    Node* node = root_; pre = NULL;
    while (node != NULL) {
        if (node->key == key) return node;
        else if (node->key > key) { 
            pre = node;
            node = node->left;
        } else {
            pre = node;
            node = node->right;
        }
    }
    return node;
}
bool Treap::insert(int key) {
    bool exist_flag = false;
    root_ = _insert(root_, key, exist_flag);
    if (!exist_flag) {
        size_++;
    }
    return !exist_flag;
}
void Treap::remove(int key) {
    _remove(root_, key);
}
void Treap::clear() {
    _clear(root_);
    size_ = 0;
}

///////////////////////private functions/////////////////////////////////////////
int Treap::_height(Node* root) {
    if (!root) return 0;
    int left_h = _height(root->left);
    int right_h = _height(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}
Node* Treap::_left_rot(Node* node) {   // rotate node's right child with node
    if (node == NULL) return NULL;
    else if (node->left == NULL && node->right == NULL) return node;
    else if (node->right == NULL) return node;
    Node* rnode = node->right;
    node->right = rnode->left;
    rnode->left = node;
    return rnode;
}
Node* Treap::_right_rot(Node* node) {
    if (node == NULL) return NULL;
    else if (node->left == NULL && node->right == NULL) return node;
    else if (node->left == NULL) return node;
    Node* lnode = node->left;
    node->left = lnode->right;
    lnode->right = node;
    return lnode;
}

/*
 * exist_flag 调用前为true，如果调用后为false，表明插入失败（已经存在元素）
 */
Node* Treap::_insert(Node* node, int key, bool& exist_flag) { // 插入元素并返回根结点
    if (exist_flag == true) return node;
    if (node == NULL) {
        node = new Node(key, rand() % 100, 0, 0);
    } else if (key < node->key) {
        node->left = _insert(node->left, key, exist_flag);
        if (node->left->priority < node->priority)
            node = _right_rot(node);
    } else if (key > node->key) {
        node->right = _insert(node->right, key, exist_flag);
        if (node->right->priority < node->priority)
            node = _left_rot(node);
    } else {
        exist_flag = true;
    }
    return node;
}
Node* Treap::_remove(Node* node, int key) {
    if (node == NULL) return node;
    if (key < node->key) {
        node->left = _remove(node->left, key);
    } else if (key > node->key) {
        node->right = _remove(node->right, key);
    } else {
        if (node->left->priority < node->right->priority)
            node = _right_rot(node);
        else node = _left_rot(node);

        if (node == NULL) {
            delete node->left;
            node->left = NULL;
        } else node = _remove(node, key);
    }
    return node;    
}
void Treap::_clear(Node*& node) {
    if (node->left) _clear(node->left);
    if (node->right) _clear(node->right);
    delete node; node = NULL;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

Node* treap_insert(Node* root, int key) {
    if (NULL == root) return new Node(key, 1, NULL, NULL);
    else if (root->key < key) {
        root->right = treap_insert(root->right, key);
    } else if (root->key > key) {
        root->left = treap_insert(root->left, key);
    }
    return root;
}
void treap_inorder(const Node* root) {
    if (!root) return;
    treap_inorder(root->left);
    printf("%d ", root->key); 
    treap_inorder(root->right);
    return;
}

void treap_test() {
    Node* T = NULL;
    for (int i=0; i<10; ++i) {
        T = treap_insert(T, i);
    }
    treap_inorder(T);
    return;
}
///////////////////////test functions/////////////////////////////////////////
int main() {
    treap_test();
exit(-1);
    Treap t;
    for (int i=0; i<10; ++i) 
        if (t.insert(i)) printf("successed to insert %d\n", i);
        else printf("failed to insert %d\n", i);
    printf("finished insert operation, start inorder traverse\n");
    t.inorder_traverse(t.root());
    printf("\n");
exit(-1);
    auto node = t.find(99999);
    if (node != NULL) {
        printf("node->key = %d\n", node->key);
    }
    printf("treap size: %d\n", t.size());
    printf("\n");
    t.inorder_traverse(node->left);
    printf("\n");
    t.inorder_traverse(node->right);
    printf("\n");
    printf("treap height is %d\n", t.height());
    t.clear();
    return 0;
}

